/**
 * \file PictureObserver.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include "PictureObserver.h"
#include "picture.h"

CPictureObserver::CPictureObserver()
{
}

/** \brief Set the picture for this observer
* \param picture The picture to set */
void CPictureObserver::SetPicture(std::shared_ptr<CPicture> picture)
{
	mPicture = picture;
	mPicture->AddObserver(this);
}

/** \brief Destructor */
CPictureObserver::~CPictureObserver()
{
	if (mPicture != nullptr)
	{
		mPicture->RemoveObserver(this);
	}
}
