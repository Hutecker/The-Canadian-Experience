/**
 * \file Drawable.h
 *
 * \author Stephan Hutecker
 *
 * \brief Abstract base class for drawable elements of our picture.
 */

#pragma once

#include <memory>
#include <string>
#include <vector>

class CActor;


/**
* \brief Abstract base class for drawable elements of our picture
*/
class CDrawable
{
public:
	virtual ~CDrawable();

	/** \brief Default constructor disabled */
	CDrawable() = delete;
	/** \brief Copy constructor disabled */
	CDrawable(const CDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CDrawable &) = delete;

	void SetActor(CActor *actor);
	virtual void Draw(Gdiplus::Graphics *graphics) = 0;
	void Place(Gdiplus::Point offset, double rotate);
	void AddChild(std::shared_ptr<CDrawable> child);
	virtual bool HitTest(Gdiplus::Point pos) = 0;
	virtual bool IsMovable() { return false; }
	void Move(Gdiplus::Point delta);

	/** \brief Set the drawable position
	* \param pos The new drawable position*/
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

	/** \brief Get the drawable position
	* \returns The drawable position*/
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** \brief Set the rotation angle in radians
	* \param r The new rotation angle in radians*/
	void SetRotation(double r) { mRotation = r; }

	/** \brief Get the rotation angle in radians
	* \returns The rotation angle in radians*/
	double GetRotation() const { return mRotation; }

	/** \brief Get the drawable name
	* \returns The drawable name */
	std::wstring GetName() const { return mName; }

	/** \brief Set the parent
	* \param parent the nodes parent*/
	void SetParent(CDrawable* parent) { mParent = parent; }

	/** \brief Get the parent
	* \returns the parent*/
	CDrawable* GetParent() const { return mParent; }

protected:
	CDrawable(const std::wstring &name);
	Gdiplus::Point RotatePoint(Gdiplus::Point point, double angle);

	/// The actual postion in the drawing
	Gdiplus::Point mPlacedPosition = Gdiplus::Point(0, 0);

	/// The actual rotation in the drawing
	double mPlacedR = 0;

private:
	/// The drawable name
	std::wstring mName;

	/// The position of this drawable relative to its parent
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// The rotation of this drawable relative to its parent
	double mRotation = 0;

	/// The actor using this drawable
	CActor *mActor = nullptr;

	/// Contains this nodes children
	std::vector<std::shared_ptr<CDrawable> > mChildren;
	 
	/// the drawables parent
	CDrawable* mParent;
};
