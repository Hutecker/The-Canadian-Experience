/**
 * \file TimelineDlg.h
 *
 * \author Stephan Hutecker
 *
 * \brief Our timeline dialog
 */


#pragma once

#include "Timeline.h"

/** \brief Our timeline dialog */
class CTimelineDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:
	/**
	* \brief constructor
	*/
	CTimelineDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTimelineDlg();

	// Dialog Data
	enum { IDD = IDD_TIMELINEDLG };

	/**
	* \brief Pass a timeline object to this dialog box class.
	* \param timeline The timeline object.
	*/
	void CTimelineDlg::SetTimeline(CTimeline *timeline)
	{
		mTimeline = timeline;
		mNumFrames = mTimeline->GetNumFrames();
		mFrameRate = mTimeline->GetFrameRate();
	}

	/** \brief Transfer dialog values to the Timeline object
	*/
	void CTimelineDlg::Take()
	{
		mTimeline->SetNumFrames(mNumFrames);
		mTimeline->SetFrameRate(mFrameRate);
	}

protected:
	/**
	* \brief DDX/DDV support
	* \param pDX a CDataExchange
	*/
	virtual void DoDataExchange(CDataExchange* pDX);   

	DECLARE_MESSAGE_MAP()
private:
	/// current number of frames
	int mNumFrames;
	/// The timeline we are editing
	CTimeline *mTimeline = nullptr;
	/// The frame rate of the animation
	int mFrameRate;
};
