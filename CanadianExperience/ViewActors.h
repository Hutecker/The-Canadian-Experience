/**
 * \file ViewActors.h
 *
 * \author Stephan Hutecker
 *
 * \brief Class that provides a view windows for actors.
 */

#pragma once

#include "PictureObserver.h"

class CMainFrame;

/** \brief Class that provides a view windows for actors. */
class CViewActors : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewActors)
public:
    static const int Width = 150;  ///< Width we want for this window 
	/** \brief Set the mainFrame pointer
	* \param mainFrame Pointer to the CMainFrame window */
	void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }
	/** \brief Force an update of this window when the picture changes.
	*/
	void CViewActors::UpdateObserver(){ Invalidate(); }

private:
	/// The main frame window that uses this view
	CMainFrame  *mMainFrame = nullptr;

protected:
	CViewActors();           // protected constructor used by dynamic creation
	virtual ~CViewActors();

protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()

public:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


