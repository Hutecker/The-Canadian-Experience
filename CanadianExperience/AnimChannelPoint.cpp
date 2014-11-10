/**
 * \file AnimChannelPoint.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include <memory>
#include "AnimChannelPoint.h"

using namespace std;
using namespace Gdiplus;

/**
 * \brief constructor
 */
CAnimChannelPoint::CAnimChannelPoint()
{
}


/**
 * \brief destructor
 */
CAnimChannelPoint::~CAnimChannelPoint()
{
}

/**
* \brief Set a keyframe
*
* This function allocates a new keyframe and sends it to
* CAnimChannel, which will insert it into the collection of keyframes.
* \param point point to set
*/
void CAnimChannelPoint::SetKeyframe(Gdiplus::Point point)
{
	// Create a keyframe of the appropriate type
	// Telling it this channel and the angle
	shared_ptr<KeyframePoint> keyframe = make_shared<KeyframePoint>(this, point);

	// Insert it into the collection
	InsertKeyframe(keyframe);
}


/**
* \brief Compute a point that is an interpolation between two keyframes
*
* This function is called after Use1 and Use2, so we have pointers to
* to valid keyframes of the type KeyframeAngle. This function does the
* tweening.
* \param t A t value. t=0 means keyframe1, t=1 means keyframe2. Other values
* interpolate between.
*/
void CAnimChannelPoint::Tween(double t)
{
	Point a = mKeyframe1->GetPoint();
	Point b = mKeyframe2->GetPoint();
	Point c(int(a.X + t * (b.X - a.X)), int(a.Y + t * (b.Y - a.Y)));
	mPoint = c;
}

/**
* \brief Handle loading this channel's keyframe type
* \param node keyframe tag node
*/
void CAnimChannelPoint::XmlLoadKeyframe(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	int x = node->GetAttributeIntValue(L"x", 0);
	int y = node->GetAttributeIntValue(L"y", 0);

	// Set a keyframe there
	SetKeyframe(Gdiplus::Point(x, y));
}