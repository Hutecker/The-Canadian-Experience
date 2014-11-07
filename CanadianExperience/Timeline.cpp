/**
 * \file Timeline.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include "Timeline.h"

using namespace xmlnode;

/**
 * \brief Constructor
 */
CTimeline::CTimeline()
{
}


/**
 * \brief Destructor
 */
CTimeline::~CTimeline()
{
}

/** \brief Sets the current time
*	\param t the current time
* Ensures all of the channels are
* valid for that point in time.
*/
void CTimeline::SetCurrentTime(double t)
{
	// Set the time
	mCurrentTime = t;

	for (auto channel : mChannels)
	{
		channel->SetFrame(GetCurrentFrame());
	}
}

/**
* \brief Save the timeline animation to a file
* \param filename File to save to.
*/
void CTimeline::Save(const std::wstring &filename)
{
	//
	// Create an XML document
	//
	auto root = CXmlNode::CreateDocument(L"anim");

	root->SetAttribute(L"numframes", mNumFrames);
	root->SetAttribute(L"framerate", mFrameRate);

	for (auto channel : mChannels)
	{
		  channel->XmlSave(root);
	}

	try
	{
		root->Save(filename);
	}
	catch (CXmlNode::Exception ex)
	{
		AfxMessageBox(ex.Message().c_str());
	}
}