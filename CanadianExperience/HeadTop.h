/**
 * \file HeadTop.h
 *
 * \author Stephan Hutecker
 *
 * \brief draws harolds head
 */

#pragma once

#include "ImageDrawable.h"

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
};

