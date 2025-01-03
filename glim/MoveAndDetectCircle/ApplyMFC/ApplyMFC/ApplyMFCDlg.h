
// ApplyMFCDlg.h: 헤더 파일
//

#pragma once



#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>




using namespace std;
using namespace cv;

#include "CustomStatic.h"


// CApplyMFCDlg 대화 상자
class CApplyMFCDlg : public CDialogEx
{
// 생성입니다.
public:





	CApplyMFCDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	void initCoord();
	void DrawNormalImage();
	Mat FindCircleDrawX(Mat src);


	Mat m_matImage; // 이미지 정보를 담고 있는 객체.
	BITMAPINFO* m_pBitmapInfo; // Bitmap 정보를 담고 있는 구조체.
	void CreateBitmapInfo(int w, int h, int bpp);
	void DrawImage(Mat img);



	int mx , my;
	int mRadius;


	int mstartX, mstartY;
	int mendX, mendY;
	void drawCircle(int x, int y);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_APPLYMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
	

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAction();

	afx_msg void OnBnClickedButtonSetCoord();
	afx_msg void OnBnClickedButtonOpen();
};
