#pragma once


// CHomeView ���Դϴ�.

class CHomeView : public CView
{
	DECLARE_DYNCREATE(CHomeView)

public:
	CHomeView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CHomeView();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


