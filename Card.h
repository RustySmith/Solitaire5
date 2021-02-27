
// Card.h : interface of the Card class
//

#pragma once


class Card : public CView
{
protected: // create from serialization only
	Card() noexcept;
	DECLARE_DYNCREATE(Card)

// Attributes
public:
	SaveRestore* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~Card();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Card.cpp
inline SaveRestore* Card::GetDocument() const
   { return reinterpret_cast<SaveRestore*>(m_pDocument); }
#endif

