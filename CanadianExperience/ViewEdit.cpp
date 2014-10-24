/**
 * \file ViewEdit.cpp
 *
 * \author Stephan Hutecker
 */


#include "stdafx.h"
#include "CanadianExperience.h"
#include "ViewEdit.h"
#include "Picture.h"
#include "DoubleBufferDC.h"
#include "MainFrm.h"


using namespace std;
using namespace Gdiplus;

IMPLEMENT_DYNCREATE(CViewEdit, CScrollView)


BEGIN_MESSAGE_MAP(CViewEdit, CScrollView)
    ON_WM_ERASEBKGND()
    ON_WM_LBUTTONDOWN()
    ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

/** \brief Constructor */
CViewEdit::CViewEdit()
{
}

/** \brief Destructor */
CViewEdit::~CViewEdit()
{
}

/** \brief Handle initial update of the window */
void CViewEdit::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal(800, 600);
	SetScrollSizes(MM_TEXT, sizeTotal);
}


/** \brief Drawing of the window 
 * \param pDC the device context to draw on */
void CViewEdit::OnDraw(CDC* pDC)
{
    CDoubleBufferDC dbDC(pDC);

    Graphics graphics(dbDC.m_hDC);    // Create GDI+ graphics context

	Gdiplus::Size size = GetPicture()->GetSize();
	SetScrollSizes(MM_TEXT, CSize(size.Width, size.Height));

	GetPicture()->Draw(&graphics);

}



/** \brief Erase the background
*
* This is disabled to eliminate flicker
* \param pDC Device context
* \returns FALSE */
BOOL CViewEdit::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}



/**
 * \brief Handle a left button click
 * \param nFlags Flags that indicate status of the mouse buttons 
 * \param point The x,y location for the mouse click
 */
void CViewEdit::OnLButtonDown(UINT nFlags, CPoint point)
{

    __super::OnLButtonDown(nFlags, point);
}


/**
 * \brief Handle mouse movement
 * \param nFlags Flags that indicate status of the mouse buttons 
 * \param point The x,y location for the mouse
 */
void CViewEdit::OnMouseMove(UINT nFlags, CPoint point)
{

    __super::OnMouseMove(nFlags, point);
}
