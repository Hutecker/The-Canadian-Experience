/**
 * \file Timeline.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include "Timeline.h"


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
*
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