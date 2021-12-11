
// MFCExam01.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "MFCExam01.h"
#include "MFCExam01Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExam01App

BEGIN_MESSAGE_MAP(CMFCExam01App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMFCExam01App 생성

CMFCExam01App::CMFCExam01App()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CMFCExam01App 개체입니다.

CMFCExam01App theApp;


// CMFCExam01App 초기화

BOOL CMFCExam01App::InitInstance()
{
	CWinApp::InitInstance();

	CMFCExam01Dlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}

