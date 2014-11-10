/**
 * \file AnimChannelText.h
 *
 * \author Stephan Hutecker
 *
 * \brief the animation channel for text
 */

#pragma once

#include "AnimChannel.h"

/** \brief the animation channel for text */
class CAnimChannelText : public CAnimChannel
{
public:
	CAnimChannelText();
	/** \brief Copy constructor disabled */
	CAnimChannelText(const CAnimChannelText &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CAnimChannelText &) = delete;
	virtual ~CAnimChannelText();

	/**
	* \brief get the text
	* \returns the text of this channel
	*/
	std::wstring GetText(){ return mText; }

	/** \brief Class that represents a keyframe */
	class KeyframeText : public Keyframe
	{
	public:

		/** \brief Default constructor disabled */
		KeyframeText() = delete;
		/** \brief Copy constructor disabled */
		KeyframeText(const KeyframeText &) = delete;
		/** \brief Assignment operator disabled */
		void operator=(const KeyframeText &) = delete;

		/** \brief Constructor
		* \param channel The channel we are for
		* \param text the text for the keyframe */
		KeyframeText(CAnimChannelText *channel, std::wstring text) :
			Keyframe(channel), mChannel(channel), mText(text) {}

		/**
		* \brief get the a text
		* \returns the text
		*/
		std::wstring GetText() { return mText; }

		/** \brief Use this keyframe as keyframe 1 */
		virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

		/** \brief Use this keyframe as keyfraem 2 */
		virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

		/** \brief Use this keyframe as the angle */
		virtual void UseOnly() override
		{
			mChannel->mText = mText;
		}

		/** \brief Save this keyframe to an XML node
		* \param node The node we are going to be a child of
		* \returns the node we saved
		*/
		std::shared_ptr<xmlnode::CXmlNode> CAnimChannelText::KeyframeText::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
		{
			auto itemNode = CAnimChannel::Keyframe::XmlSave(node);
			itemNode->SetAttribute(L"text", mText);

			return itemNode;
		}

	private:
		/// The current text of the animation
		std::wstring mText;
		/// The channel this keyframe is associated with
		CAnimChannelText *mChannel;
	};

	void SetKeyframe(std::wstring text);
	void XmlLoadKeyframe(const std::shared_ptr<xmlnode::CXmlNode> &node);

protected:
	void Tween(double t);

private:
	/// The current text of the animation
	std::wstring mText;
	/// The first frame
	KeyframeText *mKeyframe1 = nullptr;
	/// The second frame
	KeyframeText *mKeyframe2 = nullptr;
};

