#pragma once
#include <afxwin.h>
class CustomStatic :
    public CStatic
{
public:
    
    CustomStatic();
    void drawCircle(CDC* pDC, int x, int y);
    int mx, my;

    void reDraw()
    {
        Invalidate();
        UpdateWindow();
    }

    DECLARE_MESSAGE_MAP()
        afx_msg void OnPaint();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

