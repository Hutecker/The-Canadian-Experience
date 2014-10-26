/**
 * \file Picture.cpp
 *
 * \author Stephan Hutecker
 */


#include "stdafx.h"
#include "Picture.h"

using namespace Gdiplus;


/**
 * \brief constructor
 */
CPicture::CPicture()
{
}


/**
 * \brief destructor
 */
CPicture::~CPicture()
{
}

/** \brief Add an observer to this picture.
* \param observer The observer to add
*/
void CPicture::AddObserver(CPictureObserver *observer)
{
	mObservers.push_back(observer);
}

/** \brief Remove an observer from this picture
* \param observer The observer to remove
*/
void CPicture::RemoveObserver(CPictureObserver *observer)
{
	auto loc = find(std::begin(mObservers), std::end(mObservers), observer);
	if (loc != std::end(mObservers))
	{
		mObservers.erase(loc);
	}
}

/** \brief Update all observers to indicate the picture has changed.
*/
void CPicture::UpdateObservers()
{
	for (auto observer : mObservers)
	{
		observer->UpdateObserver();
	}
}

/** \brief Draw this picture on a device context
* \param dc The device context to draw on
*/
void CPicture::Draw(Gdiplus::Graphics *graphics)
{
	for (auto actor : mActors)
	{
		actor->Draw(graphics);
	}
}


/**
 * \brief Adds an actor to mActors
 * \param actor The actor we are adding
 */
void CPicture::AddActor(std::shared_ptr<CActor> actor)
{
	mActors.push_back(actor);
	actor->SetPicture(this);
}