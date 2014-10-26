/**
 * \file PolyDrawable.h
 *
 * \author Stephan Hutecker
 *
 * \brief A drawable based on polygon images.
 */

#pragma once

#include <vector>
#include "Drawable.h"

/**
* \brief A drawable based on polygon images.
*
* This class has a list of points and draws a polygon
* drawable based on those points.
*/
class CPolyDrawable: public CDrawable
{
public:
	/** \brief Constructor
	* \param name The drawable name */
	CPolyDrawable::CPolyDrawable(const std::wstring &name) : CDrawable(name)
	{
	}

	/** \brief Default constructor disabled */
	CPolyDrawable() = delete;

	/** \brief Copy constructor disabled */
	CPolyDrawable(const CPolyDrawable &) = delete;

	/** \brief Assignment operator disabled */
	void operator=(const CPolyDrawable &) = delete;

	virtual ~CPolyDrawable();

	/** \brief The actor position
	* \returns The color as a color */
	Gdiplus::Color GetColor() const { return mColor; }

	/** \brief The Color
	* \param color our new color */
	void SetColor(Gdiplus::Color color) { mColor = color; }

	/** \brief The Points
	* \returns The Points */
	std::vector<Gdiplus::Point> GetPoints() const { return mPoints; }

	/** \brief The Points
	* \param point point to add */
	void AddPoint(Gdiplus::Point point) { mPoints.push_back(point); }

	void Draw(Gdiplus::Graphics *graphic);

	bool HitTest(Gdiplus::Point pos);

private:
	/// The polygon color
	Gdiplus::Color mColor = Gdiplus::Color::Black;

	/// The array of point objects
	std::vector<Gdiplus::Point> mPoints;
};

