#include "pch.h"
#include "CustomStatic.h"
BEGIN_MESSAGE_MAP(CustomStatic, CStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

CustomStatic::CustomStatic()
{
	mx = 0;
	my = 0;
}

void CustomStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.
	CRect rect;
	GetClientRect(&rect);
	
	TRACE("onPaint Static");
	SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

	//drawCircle(&dc, 100, 100);
	ReleaseDC(&dc);

	
}

void CustomStatic::drawCircle(CDC *pDC, int x, int y)
{

	
	//pDC->Ellipse(x++, y++,  200,  200);
	
//	CDC* pDC = GetDC();

	CRect rect;
	rect.left = 10+mx;
	rect.right = 100+mx;
	rect.top = 10;
	rect.bottom = 100;

	// Paint transparent rectangle
	
	pDC->Rectangle(&rect);

	

	

	
	

}

BOOL CustomStatic::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CStatic::OnEraseBkgnd(pDC);
}
