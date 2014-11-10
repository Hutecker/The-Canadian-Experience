/**
 * \file TextBubbleDrawable.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include "TextBubbleDrawable.h"
#include "Timeline.h"
#include "Actor.h"
#include "TextBubbleDlg.h"

using namespace std;
using namespace Gdiplus;

/**
* \brief constructor
*/
CTextBubbleDrawable::CTextBubbleDrawable(const std::wstring &name)
	: CDrawable(name)
{
	mTextBubble.SetMirrored(false);
}


/**
 * \brief Destructor
 */
CTextBubbleDrawable::~CTextBubbleDrawable()
{
}

/**
 * \brief Draws our text bubble
 * \param graphics our graphics context
 */
void CTextBubbleDrawable::Draw(Gdiplus::Graphics *graphics)
{
	if (mTextBubble.GetText() != L"")
	{
		mTextBubble.SetBubblePosition(mPlacedPosition.X, mPlacedPosition.Y);
		mTextBubble.DrawMe(graphics);
	}
}

/**
 * \brief checks if were are clicking the bubble
 * \param pos the mouse position
 * \returns true if bubble is hit
 */
bool CTextBubbleDrawable::HitTest(Gdiplus::Point pos)
{
	return mTextBubble.IsPointInside(pos.X, pos.Y);
}

/**
 * \brief gets the text in the bubble
 * \returns the text in the bubble
 */
wstring CTextBubbleDrawable::GetText()
{
	return mTextBubble.GetText();
}

/**
 * \brief sets the text in the bubble
 * \param text the text we want in the bubble
 */
void CTextBubbleDrawable::SetText(const std::wstring text)
{
	mTextBubble.SetText(text);
}

/**
 * \brief determines whether this bubble is being drawn mirrored or not
 * \returns true is mirrored
 */
bool CTextBubbleDrawable::GetMirror()
{
	return mTextBubble.GetMirror();
}

/**
 * \brief sets whether or not it is drawn mirrored or not
 * \param mirror true if you want the bubble to be mirrored
 */
void CTextBubbleDrawable::SetMirror(bool mirror)
{
	mTextBubble.SetMirrored(mirror);
	mIsMirrored = mirror;
}

/**
 * \brief sets the bubble position
 * \param x the x location
 * \param y the y location
 */
void CTextBubbleDrawable::SetBubblePosition(int x, int y)
{
	CDrawable::SetPosition(Point(x, y));
	mTextBubble.SetBubblePosition(x, y);
}

/**
 * \brief gets the x location of the bubble
 * \returns returns the x location of the bubble
 */
int CTextBubbleDrawable::GetX()
{
	return mTextBubble.GetX();
}

/**
 * \brief gets the y location of the bubble
 * \returns the y location of the bubble
 */
int CTextBubbleDrawable::GetY()
{
	return mTextBubble.GetY();
}

/**
* \brief Set the actor. This is where we set the channel name
* \param actor Actor to set
*/
void CTextBubbleDrawable::SetActor(CActor *actor)
{
	CDrawable::SetActor(actor);

	// Set the channel name
	mPointChannel.SetName(actor->GetName() + L":" + GetName() + L":position");
	mTextChannel.SetName(actor->GetName() + L":" + GetName() + L":text");
}

/** Add the channels for this drawable to a timeline
* \param timeline The timeline class.
*/
void CTextBubbleDrawable::SetTimeline(CTimeline *timeline)
{
	CDrawable::SetTimeline(timeline);
	timeline->AddChannel(&mPointChannel);
	timeline->AddChannel(&mTextChannel);
}

/** \brief Set the keyframe based on the current status.
*/
void CTextBubbleDrawable::SetKeyframe()
{
	CDrawable::SetKeyframe();
	mPointChannel.SetKeyframe(CDrawable::GetPosition());
	mTextChannel.SetKeyframe(GetText());
}

/** \brief Get the current channel from the animation system.
*/
void CTextBubbleDrawable::GetKeyframe()
{
	CDrawable::GetKeyframe();
	if (mPointChannel.IsValid())
		CDrawable::SetPosition(mPointChannel.GetPoint());
	if (mTextChannel.IsValid())
		SetText(mTextChannel.GetText());
}

/**
* \brief check whether an object is movable or not
* \returns a bool
*/
bool CTextBubbleDrawable::IsMovable()
{
	return true;
}

/**
 * \brief Opens the dialog to set the text
 */
void CTextBubbleDrawable::OpenDialog()
{
	// Create the dialog box object
	CTextBubbleDlg dlg;

	// Tell it about the text bubble
	dlg.SetTextBubble(&mTextBubble);
	if (dlg.DoModal() == IDOK)
	{
		// Take the changes to the text bubble
		dlg.Take();
	}
}