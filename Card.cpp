
// Card.cpp : implementation of the Card class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Solitaire.h"
#endif

#include "SaveRestore.h"
#include "Card.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Card

IMPLEMENT_DYNCREATE(Card, CView)

BEGIN_MESSAGE_MAP(Card, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Card construction/destruction

Card::Card() noexcept
{
	// TODO: add construction code here

}

Card::~Card()
{
}

BOOL Card::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Card drawing

void Card::OnDraw(CDC* /*pDC*/)
{
	SaveRestore* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void Card::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Card::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Card diagnostics

#ifdef _DEBUG
void Card::AssertValid() const
{
	CView::AssertValid();
}

void Card::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

SaveRestore* Card::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(SaveRestore)));
	return (SaveRestore*)m_pDocument;
}
#endif //_DEBUG


// Card message handlers
