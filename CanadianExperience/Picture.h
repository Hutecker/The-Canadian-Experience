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


	/** \brief Contains iterator class for iterating through actors in picture **/
	class Iter
	{
	public:
		/** /breif Constructor
		*\param picture The collection we are iterating over
		*\param pos the index
		**/
		Iter(CPicture *picture, int pos) : mPicture(picture), mPos(pos) {}

		/** /breif Test for end of iterator
		* \param other the thing we are comparing to
		*\returns True if this position equals not equal to the other position*/
		bool operator != (const Iter &other) const
		{
			return mPos != other.mPos;
		}

		/** /breif Get value at current position
		*\returns Value at mPos in teh collection */
		std::shared_ptr<CActor> operator *() const { return mPicture->mActors[mPos]; }

		/** /breif Increment the iterator
		*\returns Refrence to this iterator */
		const Iter& operator++()
		{
			mPos++;
			return *this;
		}

	private:
		CPicture *mPicture;   ///< Collection we are iterating over
		int mPos;             ///< Position in the collection
	};

	/** \brief Get the begigning of the picture items collection
	* \returns iterater at first element
	**/
	Iter begin() { return Iter(this, 0); }

	/** /brief Get the end of the picture items collection
	* \returns  iterater one past last element
	**/
	Iter end() { return Iter(this, mActors.size()); }


private:
	/// The picture size
	Gdiplus::Size mSize = Gdiplus::Size(800, 600);
	/// The observers of this picture
	std::vector<CPictureObserver *> mObservers;
	///The actors
	std::vector<std::shared_ptr<CActor> > mActors;
};

