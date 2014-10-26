/**
 * \file ImageDrawable.h
 *
 * \author Stephan Hutecker
 *
 * \brief Draws an image
 */

#pragma once

#include "Drawable.h"


/**
* \brief Draws an image
*/ 
class CImageDrawable : public CDrawable
{
public:
	CImageDrawable(const std::wstring &name, const std::wstring &filename);
	CImageDrawable();
	virtual ~CImageDrawable();
	void Draw(Gdiplus::Graphics *graphics);
	bool HitTest(Gdiplus::Point pos);

	/**
	* /brief gets the center point
	* /returns the center point
	*/
	Gdiplus::Point GetCenter() { return mCenter; }
	/**
	* /brief sets the center point
	* /param point the point you want set
	*/
	void SetCenter(Gdiplus::Point point) { mCenter = point; }


protected:
	/// The image for this drawable
	std::unique_ptr<Gdiplus::Bitmap> mImage;
private:
	/// The point where we are drawing
	Gdiplus::Point mCenter = Gdiplus::Point(0, 0);
};

