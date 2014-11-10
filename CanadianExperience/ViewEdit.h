/**
 * \file ViewEdit.h
 *
 * \author Stephan Hutecker
 *
 * \brief View class the provides a window for editing our pixture
 */

#pragma once

#include "PictureObserver.h"
#include "Actor.h"
#include "Drawable.h"

class CMainFrame;

/** \brief View class the provides a window for editing our pixture */
class CViewEdit : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewEdit)

public:
	CViewEdit();           // protected constructor used by dynamic creation
	virtual ~CViewEdit();
	/** \brief Set the mainFrame pointer
	* \param mainFrame Pointer to the CMainFrame window */
	void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }
	/** \brief Force an update of this window when the picture changes.
	*/
	void CViewEdit::UpdateObserver()
	{ 
		Invalidate(); 
		UpdateWindow();
	}

protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()

public:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);

    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
	/// The main frame window that uses this view
	CMainFrame  *mMainFrame = nullptr;
	/// the actor we have selected
	std::shared_ptr<CActor> mSelectedActor;
	/// the actor we last selected
	std::shared_ptr<CActor> mPreviouslySelectedActor;
	/// the drawable that is selected
	std::shared_ptr<CDrawable> mSelectedDrawable;
	/// The last mouse position
	Gdiplus::Point mLastMouse = Gdiplus::Point(0, 0);
public:
	afx_msg void OnEditAddtextbubble();
};


