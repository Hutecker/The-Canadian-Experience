#pragma once

#include "Timeline.h"

// CTimelineDlg dialog

class CTimelineDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:
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
	}

	/** \brief Transfer dialog values to the Timeline object
	*/
	void CTimelineDlg::Take()
	{
		mTimeline->SetNumFrames(mNumFrames);
	}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	/// current number of frames
	int mNumFrames;
	/// The timeline we are editing
	CTimeline *mTimeline = nullptr;
};
