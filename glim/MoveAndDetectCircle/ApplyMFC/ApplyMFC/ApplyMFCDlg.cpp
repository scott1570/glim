
// ApplyMFCDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ApplyMFC.h"
#include "ApplyMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



#pragma comment(lib, "opencv_world490d.lib")


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CApplyMFCDlg 대화 상자



CApplyMFCDlg::CApplyMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_APPLYMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	mx = 5;
	my = 5;
	mRadius = 3;
}

void CApplyMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CApplyMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ACTION, &CApplyMFCDlg::OnBnClickedButtonAction)
	ON_BN_CLICKED(IDC_BUTTON_SET_COORD, &CApplyMFCDlg::OnBnClickedButtonSetCoord)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CApplyMFCDlg::OnBnClickedButtonOpen)
END_MESSAGE_MAP()


// CApplyMFCDlg 메시지 처리기

BOOL CApplyMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.


	initCoord();



	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	srand(time(NULL));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CApplyMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CApplyMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{


		CClientDC dc(GetDlgItem(IDC_STATIC_PICTURE));
		CWnd* pWnd = GetDlgItem(IDC_STATIC_PICTURE);

		CRect rect;
		pWnd->GetClientRect(&rect);
		dc.FillSolidRect(&rect, RGB(0, 0, 0));



		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CApplyMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CApplyMFCDlg::OnBnClickedButtonAction()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	


//	Invalidate(FALSE);
#if 0
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_READONLY, _T("image file(*.jpg;*.bmp;*.png;)|*.jpg;*.bmp;*.png;|All Files(*.*)|*.*||"));
	if (fileDlg.DoModal() == IDOK)
	{
		CString path = fileDlg.GetPathName();

		CT2CA pszString(path);
		std::string strPath(pszString);

		m_matImage = imread(strPath, IMREAD_UNCHANGED);

	



		CreateBitmapInfo(m_matImage.cols, m_matImage.rows, m_matImage.channels() * 8);

		DrawImage(m_matImage);
	}
#else

	Mat img = Mat::zeros(800, 800, CV_8U);
	CreateBitmapInfo(800, 800, img.channels() * 8);



	Mat img_circle;
	img.copyTo(img_circle);



	int range = 80 - 30 + 1;
	mRadius = rand() % range + 30;




	float fsx = mstartX;
	float fsy = mstartY;

	float fex = mendX;
	float fey = mendY;

	float stepX = (float)(fex -fsx) / 5.0;
	float stepY = ((float)(fey - fsy) / 5.0);


	mx += stepX;
	my += stepY;

	TRACE("stepX : %f, step : %f\n", stepX, stepY);
	TRACE("mx : %d, my : %d\n", mx, my);
	circle(img_circle, Point(mstartX+mx, mstartY+my), mRadius, Scalar(255, 0, 255), 1, 8, 0);



	DrawImage(img_circle);


	imwrite("input.jpg", img_circle);
#endif

}


void CApplyMFCDlg::CreateBitmapInfo(int w, int h, int bpp)
{
	if (m_pBitmapInfo != NULL)
	{
		delete m_pBitmapInfo;
		m_pBitmapInfo = NULL;
	}

	if (bpp == 8)
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO) + 255 * sizeof(RGBQUAD)];
	else // 24 or 32bit
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)];

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_pBitmapInfo->bmiHeader.biPlanes = 1;
	m_pBitmapInfo->bmiHeader.biBitCount = bpp;
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	m_pBitmapInfo->bmiHeader.biSizeImage = 0;
	m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biClrUsed = 0;
	m_pBitmapInfo->bmiHeader.biClrImportant = 0;

	if (bpp == 8)
	{
		for (int i = 0; i < 256; i++)
		{
			m_pBitmapInfo->bmiColors[i].rgbBlue = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbGreen = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbRed = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbReserved = 0;
		}
	}

	m_pBitmapInfo->bmiHeader.biWidth = w;
	m_pBitmapInfo->bmiHeader.biHeight = -h;
}


void CApplyMFCDlg::DrawImage(Mat img)
{


#if 0
	CClientDC dc(GetDlgItem(IDC_STATIC_PICTURE));

	CRect rect;
	GetDlgItem(IDC_STATIC_PICTURE)->GetClientRect(&rect);

	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, m_matImage.cols, m_matImage.rows, m_matImage.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
#else
	CClientDC dc(GetDlgItem(IDC_STATIC_PICTURE));

	CRect rect;
	GetDlgItem(IDC_STATIC_PICTURE)->GetClientRect(&rect);

	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, img.cols, img.rows, img.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
	

#endif
	

}


void CApplyMFCDlg::DrawNormalImage()
{



	CClientDC dc(GetDlgItem(IDC_STATIC_PICTURE));

	CRect rect;
	GetDlgItem(IDC_STATIC_PICTURE)->GetClientRect(&rect);

	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, m_matImage.cols, m_matImage.rows, m_matImage.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);



}


void CApplyMFCDlg::OnBnClickedButtonSetCoord()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	initCoord();





	Mat img = Mat::zeros(800, 800, CV_8U);
	CreateBitmapInfo(800, 800, img.channels() * 8);



	Mat img_circle;
	img.copyTo(img_circle);


	int range = 80 - 30 + 1;
	mRadius = rand() % range + 30;
	//mRadius = rand() % 50;

	circle(img_circle, Point(mstartX, mstartY), mRadius, Scalar(255, 0, 255), 1, 8, 0);

	


	DrawImage(img_circle);

}


void CApplyMFCDlg::initCoord()
{
	GetDlgItem(IDC_EDIT_X1)->SetWindowText(_T("5"));
	GetDlgItem(IDC_EDIT_Y1)->SetWindowText(_T("15"));
	GetDlgItem(IDC_EDIT_X2)->SetWindowText(_T("100"));
	GetDlgItem(IDC_EDIT_Y2)->SetWindowText(_T("100"));



	CString strX1, strY1, strX2, strY2;
	GetDlgItem(IDC_EDIT_X1)->GetWindowText(strX1);
	GetDlgItem(IDC_EDIT_Y1)->GetWindowText(strY1);
	GetDlgItem(IDC_EDIT_X2)->GetWindowText(strX2);
	GetDlgItem(IDC_EDIT_Y2)->GetWindowText(strY2);


	int startX = _ttoi(strX1);
	int startY = _ttoi(strY1);
	int endX = _ttoi(strX2);
	int endY = _ttoi(strY2);


	mstartX = startX;
	mstartY = startY;
	mendX = endX;
	mendY = endY;
}

void CApplyMFCDlg::OnBnClickedButtonOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_READONLY, _T("image file(*.jpg;*.bmp;*.png;)|*.jpg;*.bmp;*.png;|All Files(*.*)|*.*||"));
	if (fileDlg.DoModal() == IDOK)
	{
		CString path = fileDlg.GetPathName();

		CT2CA pszString(path);
		std::string strPath(pszString);

		Mat src = imread(strPath, IMREAD_UNCHANGED);

		CreateBitmapInfo(src.cols, src.rows, src.channels() * 8);

		//DrawNormalImage();


		Mat ret = FindCircleDrawX(src);

		//DrawImage(ret);
	}

}

Mat CApplyMFCDlg::FindCircleDrawX(Mat org_src)
{



	cv::Mat src = org_src;//= cv::imread("../input.jpg", cv::IMREAD_COLOR);
	if (src.empty()) return src;

	cv::Mat src_gray;
	//cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
	src_gray = src;

	cv::Mat blurred;
	cv::blur(src_gray, blurred, cv::Size(7, 7));

	std::vector<cv::Vec3f> circles;

	cv::HoughCircles(blurred, circles, cv::HOUGH_GRADIENT, 1, 30, 150, 60);
	for (const auto& c : circles) {
		cv::Point center(cvRound(c[0]), cvRound(c[1]));
		int radius = cvRound(c[2]);
		cv::circle(src, center, 2, cv::Scalar(255, 0, 0), 2, cv::LINE_AA);
		cv::circle(src, center, radius, cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
		cv::drawMarker(src, cv::Point(center.x, center.y), cv::Scalar(255, 255, 255), MARKER_CROSS);


		char text[256] = { 0 };
		sprintf_s(text, "center x : %d, center y : %d", center.x, center.y);


		putText(src, text, cv::Point(300, 30), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cv::Scalar(255, 255, 255), 1);

	}
	circles.clear();

	
	
	imshow("detected circles", src);
	//waitKey();
	return src;

	
}