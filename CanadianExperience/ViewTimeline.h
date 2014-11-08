/**
* \file ViewTimeline.h
*
* \author Stephan Hutecker
*
* \brief View window for the animation timeline
*/

#pragma once

#include "PictureObserver.h"

class CMainFrame;

/** \brief View window for the animation timeline */
class CViewTimeline : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewTimeline)

public:
	static const int Height = 90;      ///< Height to make this window
	/** \brief Set the mainFrame pointer
	* \param mainFrame Pointer to the CMainFrame window */
	void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }
	/** \brief Force an update of this window when the picture changes.
	*/
	void CViewTimeline::UpdateObserver()
	{
		Invalidate();
		UpdateWindow();
	}

	void playFromBeginning();
	void playFromCurrentLocation();

protected:
	CViewTimeline();           // protected constructor used by dynamic creation
	virtual ~CViewTimeline();

private:
	/// The main frame window that uses this view
	CMainFrame  *mMainFrame = nullptr;
	/// Bitmap image for the pointer
	std::unique_ptr<Gdiplus::Bitmap> mPointer;
	/// Flag to indicate we are moving the pointer
	bool mMovingPointer = false;
	/// Flag to indicate the animation is currently playing
	bool mIsPlaying = false;
	/// Last time we read the timer
	long long mLastTime;
	/// Rate the timer updates
	double mTimeFreq;
	/// True until the first time we draw
	bool mFirstDraw = true;
	/// the current frame
	int mCurrentFrame = 0;
	/// true if playing from bg
	bool mPlayingFromBeg = false;
	/// true if first time in loop
	bool mFirstPass = true;
	/// true if playing from current location
	bool mPlayingFromCurrent = false;
	/// When to stop the playing;
	bool mStop = false;

protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnEditSetkeyframe();
	afx_msg void OnEditDeletekeyframe();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnFileSaveanimationas();
	afx_msg void OnFileLoadanimation();
	afx_msg void OnPlayPlayfrombeginning();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPlayPlay();
	afx_msg void OnPlayStop();
};
