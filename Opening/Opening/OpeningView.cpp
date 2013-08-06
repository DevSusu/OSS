
// OpeningView.cpp : COpeningView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// COpeningView ����/�Ҹ�

COpeningView::COpeningView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

COpeningView::~COpeningView()
{
}

BOOL COpeningView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// COpeningView �׸���

void COpeningView::OnDraw(CDC* pDC)
{
	COpeningDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

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


// COpeningView ����

#ifdef _DEBUG
void COpeningView::AssertValid() const
{
	CView::AssertValid();
}

void COpeningView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpeningDoc* COpeningView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpeningDoc)));
	return (COpeningDoc*)m_pDocument;
}
#endif //_DEBUG


// COpeningView �޽��� ó����


//void COpeningView::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//	//ONMESSAGEHOME �߻���Ű��
//	CView::OnLButtonDown(nFlags, point);
//}