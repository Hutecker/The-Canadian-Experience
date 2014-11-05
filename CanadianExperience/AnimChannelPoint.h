/**
 * \file AnimChannelPoint.h
 *
 * \author Stephan Hutecker
 *
 * \brief Animation for a point
 */


#pragma once

#include "AnimChannel.h"

/** \brief Animation for a point */
class CAnimChannelPoint : public CAnimChannel
{
public:
	/** \brief Copy constructor disabled */
	CAnimChannelPoint(const CAnimChannelPoint &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CAnimChannelPoint &) = delete;
	CAnimChannelPoint();
	virtual ~CAnimChannelPoint();

	/**
	* \brief get the a point
	* \returns the a point
	*/
	Gdiplus::Point GetPoint() { return mPoint; }

	/** \brief Class that represents a keyframe */
	class KeyframePoint : public Keyframe
	{
	public:

		/** \brief Default constructor disabled */
		KeyframePoint() = delete;
		/** \brief Copy constructor disabled */
		KeyframePoint(const KeyframePoint &) = delete;
		/** \brief Assignment operator disabled */
		void operator=(const KeyframePoint &) = delete;

		/** \brief Constructor
		* \param channel The channel we are for
		* \param angle The angle for the keyframe */
		KeyframePoint(CAnimChannelPoint *channel, Gdiplus::Point point) :
			Keyframe(channel), mChannel(channel), mPoint(point) {}


		/**
		* \brief get the a point
		* \returns the a point
		*/
		Gdiplus::Point GetPoint() { return mPoint; }

		/** \brief Use this keyframe as keyframe 1 */
		virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

		/** \brief Use this keyframe as keyfraem 2 */
		virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

		/** \brief Use this keyframe as the angle */
		virtual void UseOnly() override 
		{
			mChannel->mPoint = mPoint;
		}

	private:
		/// point a
		Gdiplus::Point mPoint;
		/// The channel this keyframe is associated with
		CAnimChannelPoint *mChannel;
	};

void SetKeyframe(Gdiplus::Point point);

protected:
	void Tween(double t);

private:
	/// point 
	Gdiplus::Point mPoint;
	/// The first frame
	KeyframePoint *mKeyframe1 = nullptr;
	/// The second frame
	KeyframePoint *mKeyframe2 = nullptr;
};

