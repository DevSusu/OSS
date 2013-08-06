
// OpeningView.cpp : COpeningView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Opening.h"
#endif

#include "OpeningDoc.h"
#include "OpeningView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpeningView

IMPLEMENT_DYNCREATE(COpeningView, CView)

BEGIN_MESSAGE_MAP(COpeningView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
//	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// COpeningView 생성/소멸

COpeningView::COpeningView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

COpeningView::~COpeningView()
{
}

BOOL COpeningView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// COpeningView 그리기

void COpeningView::OnDraw(CDC* pDC)
{
	COpeningDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	Graphics graphics(pDC->m_hDC);
	HRSRC hResource = FindResource(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_PNG1), "PNG");
    if(!hResource) return ;   
    
    DWORD imageSize = SizeofResource(AfxGetApp()->m_hInstance, hResource);
    HGLOBAL hGlobal = LoadResource(AfxGetApp()->m_hInstance, hResource);
    LPVOID pData = LockResource(hGlobal);
    
    HGLOBAL hBuffer = GlobalAlloc(GMEM_MOVEABLE, imageSize);
    LPVOID pBuffer = GlobalLock(hBuffer);
    
    CopyMemory(pBuffer,pData,imageSize);
    GlobalUnlock(hBuffer);
    
    IStream *pStream;
    HRESULT hr = CreateStreamOnHGlobal(hBuffer, TRUE, &pStream);
    
    Image imagePNG(pStream);
    
    pStream->Release();
    if (imagePNG.GetLastStatus() != Ok) return;

	CRect client_rect; GetClientRect( client_rect );

	double wi = 510, he = 400; int dx = client_rect.right - wi , dy = client_rect.bottom - he;
	
	if( dx<0 || dy<0 )
	{
		if( dx > dy ){ he = client_rect.bottom; wi = wi * he / 400; }
		else{ wi = client_rect.right; he = he * wi / 510; }
	}
	dx = client_rect.right - wi; dy = client_rect.bottom - he;
	
	graphics.DrawImage( &imagePNG , dx/2 , dy/2 , wi , he  );
}

void COpeningView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void COpeningView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// COpeningView 진단

#ifdef _DEBUG
void COpeningView::AssertValid() const
{
	CView::AssertValid();
}

void COpeningView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpeningDoc* COpeningView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpeningDoc)));
	return (COpeningDoc*)m_pDocument;
}
#endif //_DEBUG


// COpeningView 메시지 처리기


//void COpeningView::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	//ONMESSAGEHOME 발생시키기
//	CView::OnLButtonDown(nFlags, point);
//}