/**
 * \file TextBubbleDrawable.h
 *
 * \author Stephan Hutecker
 *
 * \brief encapsulation class for the text bubble
 */

#pragma once

#include "Drawable.h"
#include "TextBubble.h"

/** \brief encapsulation class for the text bubble */
class CTextBubbleDrawable : public CDrawable
{
public:
	CTextBubbleDrawable(const std::wstring &name);
	/** \brief Default constructor disabled */
	CTextBubbleDrawable() = delete;
	/** \brief Copy constructor disabled */
	CTextBubbleDrawable(const CTextBubbleDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CTextBubbleDrawable &) = delete;
	virtual ~CTextBubbleDrawable();
	void Draw(Gdiplus::Graphics *graphics);
	bool HitTest(Gdiplus::Point pos);
	std::wstring GetText(); 
	void SetText(const std::wstring text);
	bool GetMirror();
	void SetMirror(bool mirror);
	void SetBubblePosition(int x, int y);
	int GetX();
	int GetY();
	void SetActor(CActor *actor);
	void SetKeyframe() override;
	void GetKeyframe() override;
	void SetTimeline(CTimeline *timeline) override;
	bool IsMovable();

private:
	///Our Text bubble object
	CTextBubble mTextBubble;
	///True if our bubble is mirrored
	bool mIsMirrored = false;
	/// The animation channel for animating the point of this drawable
	CAnimChannelPoint mPointChannel;
};

