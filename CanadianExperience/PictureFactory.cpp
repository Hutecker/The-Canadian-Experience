/**
 * \file PictureFactory.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include "PictureFactory.h"

using namespace std;

/**
 * \brief constructor
 */
CPictureFactory::CPictureFactory()
{
}


/**
 * \brief destructor
 */
CPictureFactory::~CPictureFactory()
{
}

/** \brief Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
	shared_ptr<CPicture> picture = make_shared<CPicture>();


	return picture;
}
