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
};

