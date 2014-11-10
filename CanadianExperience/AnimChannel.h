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
#include <vector>
#include "XmlNode.h"

class CTimeline;

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
		* \param frame the frame we are setting
		* \returns the frame
		*/
		void SetFrame(int frame) { mFrame = frame; }

		/**
		* \brief use as keyframe 1
		*/
		virtual void UseAs1()
		{}

		/**
		* \brief use as keyframe 2
		*/
		virtual void UseAs2()
		{}

		/**
		* \brief use as only keyframe
		*/
		virtual void UseOnly()
		{}

		/** \brief Save this keyframe to an XML node
		* \param node The node we are going to be a child of
		* \returns the node we saved
		*/
		virtual std::shared_ptr<xmlnode::CXmlNode> CAnimChannel::Keyframe::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
		{
			auto itemNode = node->AddChild(L"keyframe");

			itemNode->SetAttribute(L"frame", mFrame);

			return itemNode;
		}

	protected:
		/// our frame
		int mFrame;

		/** \brief Constructor
		* \param channel Channel we are associated with */
		Keyframe(CAnimChannel *channel) : mChannel(channel) {}
		/** \brief Default constructor disabled */
		Keyframe() = delete;
		/** \brief Copy constructor disabled */
		Keyframe(const Keyframe &) = delete;
		/** \brief Assignment operator disabled */
		void operator=(const Keyframe &) = delete;

	private:
		/// The channel this keyframe is associated with
		CAnimChannel *mChannel;
	};

	/** \brief Is the channel valid, meaning has keyframes?
	* \returns true if the channel is valid. */
	bool IsValid() { return mKeyframe1 >= 0 || mKeyframe2 >= 0; }

	void SetFrame(int currFrame);

	void DeleteFrame(int currentFrame);

	/**
	* \brief get the timeline
	* \returns the timeline
	*/
	CTimeline* GetTimeline() { return mTimeline; }

	/**
	* \brief get the timeline
	* \param timeline a pointer to our timeline
	* \returns the timeline
	*/
	void SetTimeline(CTimeline *timeline) { mTimeline = timeline; }

	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node);
	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node);
	void Clear();

	/** \brief Channel type specific loading and keyframe creation
	* \param node Node to load from */
	virtual void XmlLoadKeyframe(const std::shared_ptr<xmlnode::CXmlNode> &node) = 0;

protected:
	void InsertKeyframe(std::shared_ptr<Keyframe> keyframe);
	virtual void Tween(double t);

private:
	/// animation name
	std::wstring mName;
	/// keyframe 1
	int mKeyframe1 = -1;
	/// keyframe 2
	int mKeyframe2 = -1;
	/// The timeline object
	CTimeline *mTimeline = nullptr;
	/// The collection of keyframes for this channel
	std::vector<std::shared_ptr<Keyframe>> mKeyframes;
};

