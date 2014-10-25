/**
 * \file Picture.cpp
 *
 * \author Stephan Hutecker
 */


#include "stdafx.h"
#include "Picture.h"
#include <iostream>

using namespace Gdiplus;
using namespace std;

CPicture::CPicture()
{
	cout << "Testing github" << endl;
}


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
	Pen pen(Color(0, 128, 0), 1);
	graphics->DrawRectangle(&pen, 250, 150, 250, 100);

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush brush(Color(0, 0, 0));
	graphics->DrawString(L"Welcome to Canada!",  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&font,      // The font to use
		PointF(275, 170),   // Where to draw
		&brush);    // The brush to draw the text with

	CString time = CTime::GetCurrentTime().Format("%H:%M:%S");
	graphics->DrawString(time,  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&font,      // The font to use
		PointF(325, 200),   // Where to draw
		&brush);    // The brush to draw the text with

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