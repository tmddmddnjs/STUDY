
// MFCImageExamDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCImageExam.h"
#include "MFCImageExamDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCImageExamDlg 대화 상자



CMFCImageExamDlg::CMFCImageExamDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCIMAGEEXAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCImageExamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCImageExamDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCImageExamDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCImageExamDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCImageExamDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCImageExamDlg::OnBnClickedButton4)
	ON_WM_GETMINMAXINFO()
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCImageExamDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CMFCImageExamDlg 메시지 처리기

BOOL CMFCImageExamDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	//cimage에 외부 이미지 로드

	//로드시
	m_image.Load(L"basic.bmp");

	//버튼 입력시
	button_image.Load(L"button.PNG");

	//회전, m_image와 동일한 크기의 image create
	m_rotat_image.Create(m_image.GetWidth(), m_image.GetHeight(), m_image.GetBPP(), 0);

	//이미지 확대 2, 3배
	m_image2.Create(m_image.GetWidth() * 2, m_image.GetHeight() * 2, m_image.GetBPP(), 0);
	m_image3.Create(m_image.GetWidth() * 3, m_image.GetHeight() * 3, m_image.GetBPP(), 0);
	CClientDC dc(this);
	int h = m_image.GetHeight();
	int w = m_image.GetWidth();
	int rate_2 = 2;//2배
	for (int y = 0; y < rate_2 * h; y++) {
		for (int x = 0; x < rate_2 * w; x++) {
			BYTE r = GetRValue(m_image.GetPixel(x / rate_2, y / rate_2));
			BYTE g = GetGValue(m_image.GetPixel(x / rate_2, y / rate_2));
			BYTE b = GetBValue(m_image.GetPixel(x / rate_2, y / rate_2));
			m_image2.SetPixel(x, y, RGB(r, g, b));
		}
	}
	int rate_3 = 3;//3배
	for (int y = 0; y < rate_3 * h; y++) {
		for (int x = 0; x < rate_3 * w; x++) {
			BYTE r = GetRValue(m_image.GetPixel(x / rate_3, y / rate_3));
			BYTE g = GetGValue(m_image.GetPixel(x / rate_3, y / rate_3));
			BYTE b = GetBValue(m_image.GetPixel(x / rate_3, y / rate_3));
			m_image3.SetPixel(x, y, RGB(r, g, b));
		}
	}

	//색반전
	invert_image.Create(m_image.GetWidth(), m_image.GetHeight(), m_image.GetBPP(), 0);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCImageExamDlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	if (IsIconic())
	{
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
	//화면 로드시 바로 그림 그려놓기
	else {
		m_image.Draw(dc, 10, 10);
		//CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCImageExamDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//button누를시 이미지 가져오기
void CMFCImageExamDlg::OnBnClickedButton1()
{
	CClientDC dc(this);
	//image2가 아닌 image1의 사이즈 만큼만 가져오기
	int h = m_image.GetHeight(); //이미지의 세로길이
	int w = m_image.GetWidth(); // 이미지의 가로길이
	button_image.Draw(dc, 10, 10, w, h); // (10,10)을 시작으로 이미지 draw
}


//이미지 회전 - 여기 안됨
void CMFCImageExamDlg::OnBnClickedButton2()
{
	CClientDC dc(this);

	int h = m_image.GetHeight(); //이미지의 세로길이
	int w = m_image.GetWidth(); // 이미지의 가로길이
	COLORREF* temp_color = new COLORREF[w]; // 배열 동적할당

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			//픽셀을 하나씩 가져와서 temp_color에 저장
			temp_color[x] = m_image.GetPixel(x, y);
			// 원본 이미지의 픽셀을 getpixel로 얻고 temp_color배열에 잠시 저장
			m_rotat_image.SetPixel(y, x, temp_color[x]);
			// temp_color에 저장된 픽셀의 x,y점을 바꿔서 m_rotat_image에 setpixel로 넣어줌
		}
	}
	m_rotat_image.Draw(dc, 10, 10); // (10,10)을 시작으로 이미지 draw

	delete[] temp_color;
}

//이미지2배확대
void CMFCImageExamDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CClientDC dc(this);
	m_image2.Draw(dc, 10, 10);
}

//이미지3배확대
void CMFCImageExamDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CClientDC dc(this);
	m_image3.Draw(dc, 10, 10);
}

//창크기
void CMFCImageExamDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}

//이미지 반전
void CMFCImageExamDlg::OnBnClickedButton5()
{
	// TODO:여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CClientDC dc(this);
	COLORREF temp_color;
	for (int y = 0; y < m_image.GetHeight(); y++) {
		for (int x = 0; x < m_image.GetWidth(); x++) {
			temp_color = m_image.GetPixel(x, y);
			int r = GetRValue(temp_color);
			int g = GetGValue(temp_color);
			int b = GetBValue(temp_color);
			int new_r = 255 - r;
			int new_g = 255 - g;
			int new_b = 255 - b;
			invert_image.SetPixel(x, y, RGB(new_r, new_g, new_b));
		}
	}
	int b = m_image.GetHeight();
	invert_image.Draw(dc, 10, b + 20);
}
