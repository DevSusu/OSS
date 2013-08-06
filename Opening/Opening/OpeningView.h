
// OpeningView.h : COpeningView Ŭ������ �������̽�
//

#pragma once

#include "OpeningDoc.h"

class COpeningView : public CView
{
public: // serialization������ ��������ϴ�.
	COpeningView();
	DECLARE_DYNCREATE(COpeningView)

// Ư���Դϴ�.
public:
	COpeningDoc* GetDocument() const;
	
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~COpeningView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // OpeningView.cpp�� ����� ����
inline COpeningDoc* COpeningView::GetDocument() const
   { return reinterpret_cast<COpeningDoc*>(m_pDocument); }
#endif

