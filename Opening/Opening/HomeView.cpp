// HomeView.cpp : ���� �����Դϴ�.
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


// CHomeView �׸����Դϴ�.

void CHomeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOutA( 200,200,"����� Ȩȭ���Դϴ�" );
}


// CHomeView �����Դϴ�.

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


// CHomeView �޽��� ó�����Դϴ�.
