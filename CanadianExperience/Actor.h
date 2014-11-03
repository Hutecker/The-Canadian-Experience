/**
 * \file Actor.h
 *
 * \author Stephan Hutecker
 *
 * \brief Contains our actors
 */

#pragma once

#include "Drawable.h"

#include <string>
#include <memory>
#include <vector>

class CPicture;

/**
* \brief Class for actors in our drawings.
*
* An actor is some graphical object that consists of
* one or more parts. Actors can be animated.
*/
class CActor
{
public:
	CActor(const std::wstring &name);

	/** \brief Default constructor disabled */
	CActor() = delete;
	/** \brief Copy constructor disabled */
	CActor(const CActor &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CActor &) = delete;

	virtual ~CActor();

	void SetRoot(std::shared_ptr<CDrawable> root);
	void Draw(Gdiplus::Graphics *graphics);
	std::shared_ptr<CDrawable> HitTest(Gdiplus::Point pos);
	void AddDrawable(std::shared_ptr<CDrawable> drawable);

	/** \brief Get the actor name
	* \returns Actor name */
	std::wstring GetName() const { return mName; }

	/** \brief The actor position
	* \returns The actor position as a point */
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** \brief The actor position
	* \param pos The new actor position */
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }


	/** \brief Actor is enabled
	* \returns enabled status */
	bool IsEnabled() const { return mEnabled; }

	/** \brief Set Actor Enabled
	* \param enabled New enabled status */
	void SetEnabled(bool enabled) { mEnabled = enabled; }

	/** \brief Actor is clickable
	* \returns true if actor is clickable */
	bool IsClickable() const { return mClickable; }

	/** \brief Actor clickable
	* \param clickable New clickable status */
	void SetClickable(bool clickable) { mClickable = clickable; }

	/** \brief Get the picture
	* \returns picture the picture this actor points to */
	CPicture* GetPicture() { return mPicture; }

	void SetPicture(CPicture* picture);

	virtual void SetKeyframe();

	virtual void GetKeyframe();

private:
	/// actors name
	std::wstring mName;
	/// whether it is enabled
	bool mEnabled = true;
	/// where its located at
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	/// Whtether it is clickable
	bool mClickable = true;
	/// The root drawable
	std::shared_ptr<CDrawable> mRoot;
	/// The drawables in drawing order
	std::vector<std::shared_ptr<CDrawable>> mDrawablesInOrder;
	/// The actors picture
	CPicture *mPicture;
};