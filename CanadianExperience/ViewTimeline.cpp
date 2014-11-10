/**
* \file ViewTimeline.cpp
*
* \author Stephan Hutecker
*/


#include "stdafx.h"
#include <sstream>
#include "CanadianExperience.h"
#include "ViewTimeline.h"
#include "DoubleBufferDC.h"
#include "MainFrm.h"
#include "Timeline.h"
#include "Picture.h"

/// The window height
const int WindowHeight = 65;

/// The spacing between ticks in the timeline
const int TickSpacing = 3;

/// The length of a short tick mark
const int TickShort = 10;

/// The length of a long tick mark
const int TickLong = 20;

/// The amount of space to leave under the tick marks
const int TickUnder = 10;

/// Space to the left of the scale
const int BorderLeft = 10;

/// Space to the right of the scale
const int BorderRight = 10;

using namespace std;
using namespace Gdiplus;

#pragma warning (disable : 4244)
IMPLEMENT_DYNCREATE(CViewTimeline, CScrollView)

/** \brief Constructor */
CViewTimeline::CViewTimeline()
{
	mPointer = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/pointer.png"));
	assert(mPointer->GetLastStatus() == Ok);
}

/** \brief Destructor */
CViewTimeline::~CViewTimeline()
{
}


BEGIN_MESSAGE_MAP(CViewTimeline, CScrollView)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_EDIT_SETKEYFRAME, &CViewTimeline::OnEditSetkeyframe)
	ON_COMMAND(ID_EDIT_DELETEKEYFRAME, &CViewTimeline::OnEditDeletekeyframe)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_FILE_SAVEANIMATIONAS, &CViewTimeline::OnFileSaveanimationas)
	ON_COMMAND(ID_FILE_LOADANIMATION, &CViewTimeline::OnFileLoadanimation)
	ON_COMMAND(ID_PLAY_PLAYFROMBEGINNING, &CViewTimeline::OnPlayPlayfrombeginning)
	ON_WM_TIMER()
	ON_COMMAND(ID_PLAY_PLAY, &CViewTimeline::OnPlayPlay)
	ON_COMMAND(ID_PLAY_STOP, &CViewTimeline::OnPlayStop)
END_MESSAGE_MAP()


/** \brief Handle the initial update for this window */
void CViewTimeline::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	int sbHeight = GetSystemMetrics(SM_CXHSCROLL);
	CSize sizeTotal(200, Height - sbHeight - 20);
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/** \brief Draw this window
* \param pDC Device context */
void CViewTimeline::OnDraw(CDC* pDC)
{
	// Get the timeline
	CTimeline *timeline = GetPicture()->GetTimeline();

	// Set the scroll system correctly
	CSize sizeTotal(timeline->GetNumFrames() * TickSpacing + BorderLeft + BorderRight, WindowHeight);
	SetScrollSizes(MM_TEXT, sizeTotal);

	CDoubleBufferDC dbDC(pDC);

	Graphics graphics(dbDC.m_hDC);    // Create GDI+ graphics context

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	CRect rect;
	GetClientRect(&rect);
	int hit = rect.Height();
	int wid = rect.Width();

	Pen tickPen(Color::Black, 1);
	SolidBrush brush(Color(0, 0, 0));
	int tickNum = 0;
	int x1, x2, y1, y2;

	// draw timeline
	while (tickNum <= timeline->GetNumFrames())
	{

		x1 = BorderLeft + (TickSpacing * tickNum);
		x2 = BorderLeft + (TickSpacing * tickNum);
		y1 = hit - TickUnder;

		if (tickNum == 0 || (tickNum % timeline->GetFrameRate()) == 0)
		{
			y2 = (hit - TickUnder) - TickLong;

			// Convert the tick number to seconds in a string
			std::wstringstream str;
			str << tickNum / timeline->GetFrameRate();
			std::wstring wstr = str.str();

			RectF size;
			PointF origin((BorderLeft + (TickSpacing * tickNum)), ((hit - TickUnder) - TickLong) - 25);
			graphics.MeasureString(wstr.c_str(), wstr.size(), &font, origin, &size);
			origin.X = origin.X - size.Width / 2;

			graphics.DrawString(wstr.c_str(), wstr.size(), &font, origin, &brush);
		}
		else
		{
			y2 = (hit - TickUnder) - TickShort;
		}

		graphics.DrawLine(&tickPen, x1, y1, x2, y2);
		tickNum++;
	}

	//draws our pointer
	graphics.DrawImage(mPointer.get(), TickSpacing * timeline->GetFrameRate() * timeline->GetCurrentTime() + 3, hit - 35);

	int totalFrames = GetPicture()->GetTimeline()->GetNumFrames();
	int framesPerSec = GetPicture()->GetTimeline()->GetFrameRate();

	if (mFirstDraw)
	{
		mCurrentFrame = GetPicture()->GetTimeline()->GetCurrentFrame();
		mFirstDraw = false;
		SetTimer(1, (totalFrames / framesPerSec), nullptr);

		/*
		* Initialize the elapsed time system
		*/
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}
}


/** \brief Erase the background
*
* This is disabled to eliminate flicker
* \param pDC Device context
* \returns FALSE */
BOOL CViewTimeline::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}

/** \brief Handle the Edit>Set Keyframe menu option */
void CViewTimeline::OnEditSetkeyframe()
{
	for (auto actor : *GetPicture())
	{
		actor->SetKeyframe();
	}
}


/** \brief Handle the Edit>Delete Keyframe menu option */
void CViewTimeline::OnEditDeletekeyframe()
{
	CTimeline *timeline = GetPicture()->GetTimeline();
	int currentFrame = timeline->GetCurrentFrame();
	for (auto channel : timeline->GetChannels())
	{
		channel->DeleteFrame(currentFrame);
	}
}


/** Handle a left button mouse press event
* \param nFlags flags associated with the mouse press
* \param point The location of the mouse press
*/
void CViewTimeline::OnLButtonDown(UINT nFlags, CPoint point)
{
	// Convert mouse coordinates to logical coordinates
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);

	int x = point.x;

	// Get the timeline
	CTimeline *timeline = GetPicture()->GetTimeline();
	int pointerX = (int)(timeline->GetCurrentTime() * timeline->GetFrameRate() * TickSpacing + BorderLeft);

	mMovingPointer = x >= pointerX - (int)mPointer->GetWidth() / 2 && x <= pointerX + (int)mPointer->GetWidth() / 2;

	__super::OnLButtonDown(nFlags, point);
}

/**
* \brief Determines what happens when we move the mouse
* \param nFlags flags
* \param point location of mouse
*/
void CViewTimeline::OnMouseMove(UINT nFlags, CPoint point)
{
	// Convert mouse coordinates to logical coordinates
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);

	int x = point.x;

	if (mMovingPointer)
	{
		CTimeline *timeline = GetPicture()->GetTimeline();

		double pointerX = (static_cast<double>(x) / static_cast<double>(timeline->GetFrameRate()))
			/ static_cast<double>(TickSpacing);

		if (pointerX >= (timeline->GetNumFrames() / timeline->GetFrameRate()))
		{
			GetPicture()->SetAnimationTime(timeline->GetNumFrames() / timeline->GetFrameRate());
			GetPicture()->UpdateObservers();
		}
		else if (pointerX <= 0)
		{
			GetPicture()->SetAnimationTime(0);
			GetPicture()->UpdateObservers();
		}
		else
		{
			GetPicture()->SetAnimationTime(pointerX);
			GetPicture()->UpdateObservers();
		}
	}

	__super::OnMouseMove(nFlags, point);
}


/**
* \brief what to do on left mouse release
* \param nFlags flags
* \param point point of our mouse
*/
void CViewTimeline::OnLButtonUp(UINT nFlags, CPoint point)
{
	mMovingPointer = false;

	__super::OnLButtonUp(nFlags, point);
}

/**
* \brief Handle the File/Save Animation As menu option
*/
void CViewTimeline::OnFileSaveanimationas()
{
	CFileDialog dlg(false,  // false = Save dialog box
		L".anim",           // Default file extension
		nullptr,            // Default file name (none)
		OFN_OVERWRITEPROMPT,      // Flags (none)
		L"Animation Files (*.anim)|*.anim|All Files (*.*)|*.*||");    // Filter 
	if (dlg.DoModal() != IDOK)
		return;

	wstring filename = dlg.GetPathName();
	auto picture = GetPicture();
	picture->GetTimeline()->Save(filename);
}


/**
* \brief Handle the File/Open Animation menu option
*/
void CViewTimeline::OnFileLoadanimation()
{
	CFileDialog dlg(true,  // true = Open dialog box
		L".anim",           // Default file extension
		nullptr,            // Default file name (none)
		0,      // Flags (none)
		L"Animation Files (*.anim)|*.anim|All Files (*.*)|*.*||");    // Filter 
	if (dlg.DoModal() != IDOK)
		return;

	wstring filename = dlg.GetPathName();

	auto picture = GetPicture();
	picture->GetTimeline()->Load(filename);
	picture->SetAnimationTime(0);
	picture->UpdateObservers();
}

/**
* \brief When this button is clicked the animation start playing from the beginning
*/
void CViewTimeline::OnPlayPlayfrombeginning()
{
	mPlayingFromBeg = true;
	mStop = false;
	GetPicture()->SetAnimationTime(0);
	GetPicture()->UpdateObservers();
	mIsPlaying = true;
}


/**
* \brief the timer to enable animations
* \param nIDEvent an event id
*/
void CViewTimeline::OnTimer(UINT_PTR nIDEvent)
{
	Invalidate();

	LARGE_INTEGER time, freq;
	QueryPerformanceCounter(&time);
	QueryPerformanceFrequency(&freq);

	mLastTime = time.QuadPart;
	mTimeFreq = double(freq.QuadPart);

	if (mPlayingFromBeg && mStop == false)
	{	
		if (mFirstPass)
		{
			mCurrentFrame = 0;
			playFromBeginning();
			mFirstPass = false;
		}
		else
		{
			playFromBeginning();
		}
	}
	else if (mPlayingFromCurrent && mStop == false)
	{
		if (mFirstPass)
		{
			int totalFrames = GetPicture()->GetTimeline()->GetNumFrames();
			int framesPerSec = GetPicture()->GetTimeline()->GetFrameRate();
			mCurrentFrame = GetPicture()->GetTimeline()->GetCurrentTime() * static_cast<double>(static_cast<double>(totalFrames) / framesPerSec);
			playFromCurrentLocation();
			mFirstPass = false;
		}
		else
		{
			playFromCurrentLocation();
		}
	}

	__super::OnTimer(nIDEvent);
}

/**
 * \brief plays the animation from the beginning
 */
void CViewTimeline::playFromBeginning()
{
	int totalFrames = GetPicture()->GetTimeline()->GetNumFrames();
	int framesPerSec = GetPicture()->GetTimeline()->GetFrameRate();

	double elapsed = 0;
	double frameTime = static_cast<double>(GetPicture()->GetTimeline()->GetFrameRate()) / static_cast<double>(GetPicture()->GetTimeline()->GetNumFrames());
	double max = totalFrames * (static_cast<double>(static_cast<double>(totalFrames) / framesPerSec) / framesPerSec);

	if (mCurrentFrame <= max)
	{
		/*
		* Compute the elapsed time since the last draw
		*/
		LARGE_INTEGER time;
		QueryPerformanceCounter(&time);
		long long diff = time.QuadPart - mLastTime;
		elapsed = double(diff) / mTimeFreq;
		mLastTime = time.QuadPart;

		GetPicture()->SetAnimationTime(mCurrentFrame * frameTime);
	}
	else
	{
		mPlayingFromBeg = false;
		mFirstPass = true;
	}

	mCurrentFrame++;
}

/**
* \brief When the button is clicked the animation will play from where the pointer is
*/
void CViewTimeline::OnPlayPlay()
{
	mStop = false;
	mPlayingFromCurrent = true;
	mIsPlaying = true;
}

/**
 * \brief plays the animation from the current location
 */
void CViewTimeline::playFromCurrentLocation()
{
	int totalFrames = GetPicture()->GetTimeline()->GetNumFrames();
	int framesPerSec = GetPicture()->GetTimeline()->GetFrameRate();

	double elapsed = 0;
	double frameTime = static_cast<double>(GetPicture()->GetTimeline()->GetFrameRate()) / static_cast<double>(GetPicture()->GetTimeline()->GetNumFrames());
	double max = totalFrames * (static_cast<double>(static_cast<double>(totalFrames) / framesPerSec) / framesPerSec);

	if (mCurrentFrame <= max)
	{
		/*
		* Compute the elapsed time since the last draw
		*/
		LARGE_INTEGER time;
		QueryPerformanceCounter(&time);
		long long diff = time.QuadPart - mLastTime;
		elapsed = double(diff) / mTimeFreq;
		mLastTime = time.QuadPart;

		GetPicture()->SetAnimationTime(mCurrentFrame * frameTime);
	}
	else
	{
		mPlayingFromCurrent = false;
		mFirstPass = true;
	}

	mCurrentFrame++;
}


/**
 * \brief stops the animation
 */
void CViewTimeline::OnPlayStop()
{
	if (mIsPlaying)
	{
		mStop = true;
		mFirstPass = true;
		mPlayingFromBeg = false;
		mPlayingFromCurrent = false;
	}
}
