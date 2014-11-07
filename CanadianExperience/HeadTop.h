/**
 * \file HeadTop.h
 *
 * \author Stephan Hutecker
 *
 * \brief draws harolds head
 */

#pragma once

#include "ImageDrawable.h"
#include "AnimChannelPoint.h"
#include "Timeline.h"

/**
* \brief draws harolds head
*/
class CHeadTop : public CImageDrawable
{
public:
	CHeadTop();
	CHeadTop(const std::wstring &name, const std::wstring &filename);
	virtual ~CHeadTop();
	void Draw(Gdiplus::Graphics *graphics);
	Gdiplus::Point TransformPoint(Gdiplus::Point p);
	bool IsMovable() override;

	/**
	* \brief sets the eye brow location
	* \param point1 first point in the eyebrow
	* \param point2 second point in the eyebrow
	*/
	void SetFirstEyebrow(Gdiplus::Point point1, Gdiplus::Point point2) { mEyeBrow11 = point1, mEyeBrow12 = point2; }
	
	/**
	* \brief sets the eye brow location
	* \param point1 first point in the eyebrow
	* \param point2 second point in the eyebrow
	*/
	void SetSecondEyebrow(Gdiplus::Point point1, Gdiplus::Point point2) { mEyeBrow21 = point1, mEyeBrow22 = point2; }

	/**
	* \brief sets the eye location
	* \param point center of the eye
	*/
	void SetFirstEye(Gdiplus::Point point) { mEye1 = point; }

	/**
	* \brief sets the eye location
	* \param point center of the eye
	*/
	void SetSecondEye(Gdiplus::Point point) { mEye2 = point; }


	virtual void SetKeyframe() override;
	virtual void GetKeyframe() override;
	virtual void SetTimeline(CTimeline *timeline) override;
	void SetActor(CActor *actor);
private:
	/// first positions of the 1 eyebrow
	Gdiplus::Point mEyeBrow11;
	/// second positions of the 1 eyebrow
	Gdiplus::Point mEyeBrow12;
	/// first positions of the 2 eyebrow
	Gdiplus::Point mEyeBrow21;
	/// first positions of the 2 eyebrow
	Gdiplus::Point mEyeBrow22;
	/// position of the first eye
	Gdiplus::Point mEye1;
	/// position of the second eye
	Gdiplus::Point mEye2;
	/// The animation channel for animating the point of this drawable
	CAnimChannelPoint mPointChannel;
};

