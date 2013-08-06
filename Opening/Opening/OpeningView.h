
// OpeningView.h : COpeningView 클래스의 인터페이스
//

#pragma once

#include "OpeningDoc.h"

class COpeningView : public CView
{
public: // serialization에서만 만들어집니다.
	COpeningView();
	DECLARE_DYNCREATE(COpeningView)

// 특성입니다.
public:
	COpeningDoc* GetDocument() const;
	
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~COpeningView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // OpeningView.cpp의 디버그 버전
inline COpeningDoc* COpeningView::GetDocument() const
   { return reinterpret_cast<COpeningDoc*>(m_pDocument); }
#endif

