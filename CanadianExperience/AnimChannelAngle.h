/**
 * \file AnimChannelAngle.h
 *
 * \author Stephan Hutecker
 *
 * \brief Animation channel for angles.
 */

#pragma once

#include "AnimChannel.h"

/** \brief Animation channel for angles.
*/
class CAnimChannelAngle : public CAnimChannel
{
public:
	/** \brief Copy constructor disabled */
	CAnimChannelAngle(const CAnimChannelAngle &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CAnimChannelAngle &) = delete;
	CAnimChannelAngle();
	virtual ~CAnimChannelAngle();
	
	/**
	* \brief get the angle
	* \returns the angle
	*/
	double GetAngle() { return mAngle; }

	/** \brief Class that represents a keyframe */
	class KeyFrameAngle : public Keyframe
	{
	public:
		/**
		* \brief get the angle
		* \returns the angle
		*/
		double GetAngle() { return mAngle; }

		/**
		* \brief keyframe the angle
		* \param channel the angle channel
		* \param angle the current angle
		*/
		void KeyframeAngle(CAnimChannelAngle channel, double angle)
		{

		}

		/**
		* \brief use as keyframe 1
		*/
		virtual void UseAs1()
		{

		}

		/**
		* \brief use as keyframe 2
		*/
		virtual void UseAs2()
		{

		}

		/**
		* \brief use as only keyframe
		*/
		virtual void UseOnly()
		{

		}
	private:
		/// the angle
		double mAngle;
	};

	void SetKeyframe(double angle);

protected:
	void Tween(double t);

private:
	/// the angle
	double mAngle = 0;
};

