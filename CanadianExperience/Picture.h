/**
 * \file Picture.h
 *
 * \author Stephan Hutecker
 *
 * \brief The picture we are drawing.
 */

#pragma once

#include <vector>
#include "PictureObserver.h"
#include "Actor.h"

using namespace Gdiplus;

/**
* \brief The picture we are drawing.
*
* There will be one picture object that contains all of
* our actors, which then contains the drawables.
*/
class CPicture
{
public:
	CPicture();
	virtual ~CPicture();
	/// \brief Copy Constructor (Disabled)
	CPicture(const CPicture &) = delete;
	/// \brief Assignment Operator (Disabled)
	CPicture &operator=(const CPicture &) = delete;

	/** \brief The picture size
	* \returns Size */
	Gdiplus::Size GetSize() { return mSize; }

	/** \brief The picture size
	* \param size The new picture size */
	void SetSize(Gdiplus::Size size) { mSize = size; }

	void AddObserver(CPictureObserver *observer);
	void RemoveObserver(CPictureObserver *observer);
	void UpdateObservers();
	void Draw(Gdiplus::Graphics *graphics);
	void AddActor(std::shared_ptr<CActor> actor);

private:
	/// The picture size
	Gdiplus::Size mSize = Gdiplus::Size(800, 600);
	/// The observers of this picture
	std::vector<CPictureObserver *> mObservers;
	///The actors
	std::vector<std::shared_ptr<CActor> > mActors;
};

