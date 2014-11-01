/**
 * \file PictureFactory.cpp
 *
 * \author Stephan Hutecker
 */

#include "stdafx.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "HelgaFactory.h"
#include "ImageDrawable.h"

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

	// Create the background and add it
	auto background = make_shared<CActor>(L"Background");
	background->SetClickable(false);
	background->SetPosition(Point(-100, 0));
	auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
	background->AddDrawable(backgroundI);
	background->SetRoot(backgroundI);
	picture->AddActor(background);

	// Create and add Harold
	CHaroldFactory factory;
	auto harold = factory.Create();

	// Create and add Helga
	CHelgaFactory factory1;
	auto helga = factory1.Create();

	// This is where Harold will start out.
	harold->SetPosition(Point(400, 500));

	// This is where Helga will start out.
	helga->SetPosition(Point(200, 500));

	picture->AddActor(harold);
	picture->AddActor(helga);

	return picture;
}
