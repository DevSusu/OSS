// HomeView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Opening.h"
#include "HomeView.h"


// CHomeView

IMPLEMENT_DYNCREATE(CHomeView, CView)

CHomeView::CHomeView()
{

}

CHomeView::~CHomeView()
{
}

BEGIN_MESSAGE_MAP(CHomeView, CView)
END_MESSAGE_MAP()


// CHomeView 그리기입니다.

void CHomeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
	pDC->TextOutA( 200,200,"여기는 홈화면입니다" );
}


// CHomeView 진단입니다.

#ifdef _DEBUG
void CHomeView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CHomeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CHomeView 메시지 처리기입니다.
