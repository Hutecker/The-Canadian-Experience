/**
 * \file PictureObserver.h
 *
 * \author Stephan Hutecker
 *
 * \brief Observer base class for a picture.
 */

#pragma once
#include <memory>

class CPicture;

/**
* \brief Observer base class for a picture.
*
* This class implements the base class functionality for
* an observer in the observer pattern.
*/
class CPictureObserver
{
public:
	virtual ~CPictureObserver();
	//! \brief Copy Constructor (Disabled)
	CPictureObserver(const CPictureObserver &) = delete;
	//! \brief Assignment Operator (Disabled)
	CPictureObserver &operator=(const CPictureObserver &) = delete;
	/// \brief This function is called to update any observers
	virtual void UpdateObserver() = 0;

	/** \brief get the picture
	* \returns a pointer to the picture*/
	std::shared_ptr<CPicture> GetPicture() { return mPicture; }

	void SetPicture(std::shared_ptr<CPicture> picture);

protected:
	CPictureObserver();

private:
	/// Picture we are observing
	std::shared_ptr<CPicture> mPicture;
};

