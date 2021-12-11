
// MFCExam01Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCExam01.h"
#include "MFCExam01Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExam01Dlg 대화 상자



CMFCExam01Dlg::CMFCExam01Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCEXAM01_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCExam01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCExam01Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// CMFCExam01Dlg 메시지 처리기

BOOL CMFCExam01Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCExam01Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCExam01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCExam01Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//마우스를 처음 누를 위치의 포인트를 rect_start_pos로 기억시킨다.
	rect_start_pos = point;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCExam01Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	//펜 만들어서 dc에 연결, 테두리만 있는 투명 도형 : NULL_BRUSH
	CPen my_pen(PS_SOLID, 5, RGB(0, 0, 255));
	dc.SelectObject(&my_pen);
	SelectObject(dc, GetStockObject(NULL_BRUSH));
	//컨트롤을 누르면서 드래그하면 동그라미
	/*
	nFlags는 마우스 클릭
	rect_start_pos 는 마우스 누른 시점의 포인트
	point는 마우스를 뗀 시점의 포인트

	아래는 마우스와 컨트롤키를 같이 누르고 있을 때를 말한다.
	*/
	if (nFlags & MK_CONTROL) {
		dc.Ellipse(rect_start_pos.x, rect_start_pos.y, point.x, point.y);
	}
	//그냥 드래그만 할 시에는 네모를 그림
	else {
		dc.Rectangle(rect_start_pos.x, rect_start_pos.y, point.x, point.y);
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}
