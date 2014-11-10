/**
 * \file AnimChannelText.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include <memory>
#include "AnimChannelText.h"

using namespace std;
using namespace Gdiplus;

/**
 * \brief constructor
 */
CAnimChannelText::CAnimChannelText()
{
}

/**
 * \brief destructor
 */
CAnimChannelText::~CAnimChannelText()
{
}

/**
* \brief Set a keyframe
*
* This function allocates a new keyframe and sends it to
* CAnimChannel, which will insert it into the collection of keyframes.
* \param text text to set
*/
void CAnimChannelText::SetKeyframe(wstring text)
{
	// Create a keyframe of the appropriate type
	// Telling it this channel and the angle
	shared_ptr<KeyframeText> keyframe = make_shared<KeyframeText>(this, text);

	// Insert it into the collection
	InsertKeyframe(keyframe);
}

/**
* \brief Compute text between two keyframes
*
* This function is called after Use1 and Use2, so we have pointers to
* to valid keyframes of the type KeyframeAngle. This function does the
* tweening.
* \param t A t value. t=0 means keyframe1, t=1 means keyframe2. Other values
* interpolate between.
*/
void CAnimChannelText::Tween(double t)
{
	if (t < .95)
	{
		mText = mKeyframe1->GetText();
	}
	else if (t >= .95)
	{
		mText = mKeyframe2->GetText();
	}
}

/**
* \brief Handle loading this channel's keyframe type
* \param node keyframe tag node
*/
void CAnimChannelText::XmlLoadKeyframe(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	wstring text = node->GetAttributeValue(L"text", L"");
	// Set a keyframe there
	SetKeyframe(text);
}