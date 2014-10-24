/**
 * \file PolyDrawable.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include "PolyDrawable.h"


CPolyDrawable::~CPolyDrawable()
{
}


/**
 * \brief How to draw our drawable
 * \param graphic our graphic context
 */
void CPolyDrawable::Draw(Gdiplus::Graphics *graphic)
{

}

/**
* \brief Test to see if we clicked on this drawable
* \param pos Position we clicked
* \returns True if we clicked on it
*/
bool CPolyDrawable::HitTest(Gdiplus::Point pos)
{
	return false;
}