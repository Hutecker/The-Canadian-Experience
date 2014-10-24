/**
 * \file Drawable.cpp
 *
 * \author Stephan Hutecker
 */


#include "stdafx.h"
#include "Drawable.h"




/**
* \brief Constructor
* \param name The drawable name
*/
CDrawable::CDrawable(const std::wstring &name) : mName(name)
{

}

/** \brief Destructor */
CDrawable::~CDrawable()
{
}


/**
* \brief Set the actor using this drawable
* \param actor Actor using this drawable
*/
void CDrawable::SetActor(CActor *actor)
{
	mActor = actor;
}

/**
* \brief Place this drawable relative to its parent
* \param offset Parent offset
* \param rotate Parent rotation
*/
void CDrawable::Place(Gdiplus::Point offset, double rotate)
{

}


/**
* \brief Add a child drawable to this drawable
* \param child The child to add
*/
void CDrawable::AddChild(std::shared_ptr<CDrawable> child)
{

}


/**
* \brief Test to see if we clicked on this drawable
* \param pos Position we clicked
* \returns True if we clicked on it
*/
bool CDrawable::HitTest(Gdiplus::Point pos)
{
	return false;
}


/**
* \brief Move this drawable some amount
* \param delta The amount to move
*/
void CDrawable::Move(Gdiplus::Point delta)
{

}


/**
* \brief Rotate a point by some angle
* \param point Point to rotate
* \param angle Angle in radians
* \returns Rotated point
*/
Gdiplus::Point CDrawable::RotatePoint(Gdiplus::Point point, double angle)
{
	return Gdiplus::Point(0, 0);
}
