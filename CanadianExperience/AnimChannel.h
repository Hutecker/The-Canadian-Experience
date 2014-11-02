/**
 * \file AnimChannel.h
 *
 * \author Stephan Hutecker
 *
 * \brief Base class for animation channels
 */

#pragma once

#include <string>
#include <memory>

/** \brief Base class for animation channels
*
* This class provides basic functionality and a polymorphic
* representation for animation channels. */
class CAnimChannel
{
public:
	/** \brief Copy constructor disabled */
	CAnimChannel(const CAnimChannel &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CAnimChannel &) = delete;
	CAnimChannel();
	virtual ~CAnimChannel();
	
	/**
	* \brief get the name
	* \returns the name
	*/
	std::wstring GetName() { return mName; }

	/**
	* \brief sets the name
	* \param name the name to set
	*/
	void SetName(std::wstring name) { mName = name; }

	/** \brief Class that represents a keyframe */
	class Keyframe
	{
	public:
		/**
		* \brief get the frame
		* \returns the frame
		*/
		int GetFrame() { return mFrame; }

		/**
		* \brief get the frame
		* \returns the frame
		*/
		void SetFrame(int frame) { mFrame = frame; }

		/**
		* \brief keyframe the channel
		* \param channel the animation channel
		*/
		void KeyFrame(CAnimChannel channel)
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

	protected:
		/// our frame
		int mFrame;
	private:
	};

	bool IsValid();
	void SetFrame(int currFrame);

protected:
	void InsertKeyframe(std::shared_ptr<Keyframe> keyframe);
	void Tween(double t);

private:
	/// animation name
	std::wstring mName;
	/// keyframe 1
	int mKeyFrame1 = -1;
	/// keyframe 2
	int mKeyFrame2 = -1;
};

