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
	class KeyframeAngle : public Keyframe
	{
	public:

		/** \brief Default constructor disabled */
		KeyframeAngle() = delete;
		/** \brief Copy constructor disabled */
		KeyframeAngle(const KeyframeAngle &) = delete;
		/** \brief Assignment operator disabled */
		void operator=(const KeyframeAngle &) = delete;

		/** \brief Constructor
		* \param channel The channel we are for
		* \param angle The angle for the keyframe */
		KeyframeAngle(CAnimChannelAngle *channel, double angle) :
			Keyframe(channel), mChannel(channel), mAngle(angle) {}

		/**
		* \brief get the angle
		* \returns the angle
		*/
		double GetAngle() { return mAngle; }

		/** \brief Use this keyframe as keyframe 1 */
		virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

		/** \brief Use this keyframe as keyfraem 2 */
		virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

		/** \brief Use this keyframe as the angle */
		virtual void UseOnly() override { mChannel->mAngle = mAngle; }

		/** \brief Save this keyframe to an XML node
		* \param node The node we are going to be a child of
		* \returns the node we saved
		*/
		std::shared_ptr<xmlnode::CXmlNode> CAnimChannelAngle::KeyframeAngle::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
		{
			auto itemNode = CAnimChannel::Keyframe::XmlSave(node);
			itemNode->SetAttribute(L"angle", mAngle);

			return itemNode;
		}

	private:
		/// the angle
		double mAngle;
		/// The channel this keyframe is associated with
		CAnimChannelAngle *mChannel;
	};

	void SetKeyframe(double angle);
	void XmlLoadKeyframe(const std::shared_ptr<xmlnode::CXmlNode> &node);

protected:
	void Tween(double t);

private:
	/// the angle
	double mAngle = 0;
	/// The first angle keyframe
	KeyframeAngle *mKeyframe1 = nullptr;
	/// The second angle keyframe
	KeyframeAngle *mKeyframe2 = nullptr;
};

