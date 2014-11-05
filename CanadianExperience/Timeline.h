/**
 * \file Timeline.h
 *
 * \author Stephan Hutecker
 *
 * \brief This class implements a timeline that manages the animation
 */

#pragma once

#include <vector>
#include "AnimChannel.h"

/** \brief This class implements a timeline that manages the animation
*
* A timeline consists of animation channels for different parts of our
* actors, each with keyframes that set the position, orientation, etc
* at that point in time. */
class CTimeline
{
public:
	CTimeline();
	/** \brief Copy constructor disabled */
	CTimeline(const CTimeline &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CTimeline &) = delete;
	virtual ~CTimeline();

	/** \brief Get the number of frames in the animation
	* \returns Number of frames in the animation
	*/
	int GetNumFrames() const { return mNumFrames; }

	/** \brief Set the number of frames in the animation
	* \param numFrames Number of frames in the animation
	*/
	void SetNumFrames(int numFrames) { mNumFrames = numFrames; }

	/** \brief Get the frame rate
	* \returns Animation frame rate in frames per second
	*/
	int GetFrameRate() const { return mFrameRate; }

	/** \brief Set the frame rate
	* \param frameRate Animation frame rate in frames per second
	*/
	void SetFrameRate(int frameRate) { mFrameRate = frameRate; }

	/** \brief Get the current time
	* \returns Current animation time in seconds
	*/
	double GetCurrentTime() const { return mCurrentTime; }

	void SetCurrentTime(double currentTime);

	/*! \brief Get the current frame.
	*
	* This is the frame associated with the current time
	* \returns Current frame
	*/
	int GetCurrentFrame() const { return static_cast<int>(mCurrentTime * mFrameRate); }

	/*! \brief Get the animation duration
	* \returns Animation duration in seconds
	*/
	double GetDuration() const { return static_cast<double>(mNumFrames) / mFrameRate; }

	/*! \brief add a channel to mchannels
	* \param channel the channel we are adding.
	*/
	void AddChannel(CAnimChannel* channel)
	{
		mChannels.push_back(channel);
		channel->SetTimeline(this);
	}

	/**
	* \brief get the animation channels
	* \returns a vector of channels
	*/
	std::vector<CAnimChannel*> GetChannels() { return mChannels; }

private:
	/// Number of frames in the animation
	int mNumFrames = 300;
	/// Frame rate per second
	int mFrameRate = 30;
	/// the current time
	double mCurrentTime = 0;
	/// List of all animation channels
	std::vector<CAnimChannel *> mChannels;
};

