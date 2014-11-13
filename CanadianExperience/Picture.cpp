/**
 * \file Picture.cpp
 *
 * \author Stephan Hutecker
 */


#include "stdafx.h"
#include <memory>
#include "Picture.h"

using namespace Gdiplus;
using namespace std;

/**
 * \brief constructor
 */
CPicture::CPicture()
{
	auto controller = make_shared<CSnowflakeController>();
	this->AddSnowController(controller);
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
* \param graphics The device context to draw on
*/
void CPicture::Draw(Gdiplus::Graphics *graphics)
{
	for (auto actor : mActors)
	{
		actor->Draw(graphics);
	}

	if (mIsPlaying == true)
	{
		if (mSnowController->GetPoolSize() == 1)
		{
			mSnowController->InitializePool();
		}
		mSnowController->Draw(graphics);
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

/** \brief Set the current animation time
*
* This forces the animation of all
* objects to the current animation location.
* \param time The new time.
*/
void CPicture::SetAnimationTime(double time)
{
	mTimeline.SetCurrentTime(time);
	UpdateObservers();

	for (auto actor : mActors)
	{
		actor->GetKeyframe();
	}
}

/**
 * \brief sets our snow controller
 * \param controller the snow controller
 */
void CPicture::AddSnowController(std::shared_ptr<CSnowflakeController> controller)
{
	mSnowController = controller;
	controller->SetPicture(this);
}