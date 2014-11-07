/**
 * \file HeadTop.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include <memory>
#include "HeadTop.h"
#include "Actor.h"
#include "Picture.h"

using namespace Gdiplus;
using namespace std;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

// possible loss of data warning
#pragma warning(disable : 4244)

/** \brief Constructor
* \param name The drawable name
* \param filename The filename for the image */
CHeadTop::CHeadTop(const std::wstring &name, const std::wstring &filename)
	: CImageDrawable(name, filename)
{
	mImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}


/**
 * \brief Destructor
 */
CHeadTop::~CHeadTop()
{
}


/**
 * \brief Draws the head
 * \param graphics the context of where we are drawing
 */
void CHeadTop::Draw(Graphics *graphics)
{
	CImageDrawable::Draw(graphics);
	Pen eyebrowPen(Color::Black, 2);
	SolidBrush brush(Color::Black);

	// first eyebrow
	Point p1 = TransformPoint(mEyeBrow11);
	Point p2 = TransformPoint(mEyeBrow12);
	graphics->DrawLine(&eyebrowPen, p1, p2);

	//second eyebrow
	Point p3 = TransformPoint(mEyeBrow21);
	Point p4 = TransformPoint(mEyeBrow22);
	graphics->DrawLine(&eyebrowPen, p3, p4);

	float wid = 15.0f;
	float hit = 20.0f;

	//first eye
	Point p5 = TransformPoint(mEye1);

	auto state = graphics->Save();
	graphics->TranslateTransform(p5.X, p5.Y);
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state); 

	//second eye
	Point p6 = TransformPoint(mEye2);

	auto state1 = graphics->Save();
	graphics->TranslateTransform(p6.X, p6.Y);
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state1);
}


/**
 * \brief check whether an object is movable or not
 * \returns a bool
 */
bool CHeadTop::IsMovable()
{
	return true;
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Point CHeadTop::TransformPoint(Point p)
{
	// Make p relative to the image center
	p = p - GetCenter();

	// Rotate as needed and offset
	return RotatePoint(p, mPlacedR) + mPlacedPosition;
}


/** Add the channels for this drawable to a timeline
* \param timeline The timeline class.
*/
void CHeadTop::SetTimeline(CTimeline *timeline)
{
	CDrawable::SetTimeline(timeline);
	timeline->AddChannel(&mPointChannel);
}

/** \brief Set the keyframe based on the current status.
*/
void CHeadTop::SetKeyframe()
{
	CDrawable::SetKeyframe();
	mPointChannel.SetKeyframe(CDrawable::GetPosition());
}

/** \brief Get the current channel from the animation system.
*/
void CHeadTop::GetKeyframe()
{
	CDrawable::GetKeyframe();
	if (mPointChannel.IsValid())
		CDrawable::SetPosition(mPointChannel.GetPoint());
}

/**
* \brief Set the actor. This is where we set the channel name
* \param actor Actor to set
*/
void CHeadTop::SetActor(CActor *actor)
{
	CImageDrawable::SetActor(actor);

	// Set the channel name
	mPointChannel.SetName(actor->GetName() + L":" + GetName() + L":position");
}