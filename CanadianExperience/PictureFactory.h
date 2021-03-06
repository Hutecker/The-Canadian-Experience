/**
 * \file PictureFactory.h
 *
 * \author Stephan Hutecker
 *
 * \brief A factory class that builds our picture.
 */

#pragma once

#include <memory>
#include "Picture.h"

/**
* \brief A factory class that builds our picture.
*/
class CPictureFactory
{
public:
	CPictureFactory();
	virtual ~CPictureFactory();
	std::shared_ptr<CPicture> Create();
};

