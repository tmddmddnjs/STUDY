
// MFCListBoxExamDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCListBoxExam.h"
#include "MFCListBoxExamDlg.h"
#include "afxdialogex.h"

#include <mysql.h>
#pragma comment (lib, "libmysql.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMFCListBoxExamDlg::CMFCListBoxExamDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCLISTBOXEXAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCListBoxExamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST1, m_listbox1);
	DDX_Control(pDX, IDC_BUTTON1, m_button);
	DDX_Control(pDX, IDC_EDIT1, m_text1);
	DDX_Control(pDX, IDC_EDIT2, m_text2);
	DDX_Control(pDX, IDC_EDIT3, m_text3);
	DDX_Control(pDX, IDC_EDIT4, error_text);
	DDX_Control(pDX, IDC_BUTTON2, delete_button);
	DDX_Control(pDX, IDC_BUTTON3, update_button);
	DDX_Control(pDX, IDC_EDIT6, update_text_before);
	DDX_Control(pDX, IDC_EDIT7, update_text_after);
}

BEGIN_MESSAGE_MAP(CMFCListBoxExamDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCListBoxExamDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCListBoxExamDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCListBoxExamDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCListBoxExamDlg 메시지 처리기
MYSQL* cons = mysql_init(NULL);
BOOL CMFCListBoxExamDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	mysql_real_connect(cons, MYSQLIP, MYSQLUSER, MYSQLPASSWORD, NULL, 0, NULL, 0);
	mysql_set_character_set(cons, "euckr");
	mysql_query(cons, "select * from opentutorials.c_test");
	MYSQL_RES* result = mysql_store_result(cons);
	//int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))
	{
		m_listbox1.AddString(row[0]);
	}
	return 0;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCListBoxExamDlg::OnPaint()
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
HCURSOR CMFCListBoxExamDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//insert
void CMFCListBoxExamDlg::OnBnClickedButton1()
{
	int text1;
	CString text2, text3;
	CString strSql;
	char query[2048];
	text1 = GetDlgItemInt(IDC_EDIT1);
	GetDlgItemText(IDC_EDIT2, text2);
	GetDlgItemText(IDC_EDIT3, text3);
	try {
		strSql = "insert into opentutorials.c_test(id,col1,col2) values('%d','%s','%s')";
		sprintf(query, strSql, text1, text2, text3);
		mysql_query(cons, query);
		m_listbox1.Invalidate();
	}
	catch (CException* e) {
		SetDlgItemText(IDC_EDIT4, "에러남");
		//e->ReportError()
	}
}

//delete
void CMFCListBoxExamDlg::OnBnClickedButton2()
{
	CString strSql;
	char query[2048];	
	//선택 값 가져오기
	CString strstr; //리스트박스에서 선택한 값을 가져올 변수 지정
	CListBox* p_list = (CListBox*)GetDlgItem(IDC_LIST1);
	int index = p_list->GetCurSel();
	if (index != LB_ERR) {
		p_list->GetText(index, strstr);
	}
	try {
		strSql = "delete from opentutorials.c_test where id = '%s'";
		//리스트를 선택하여 해당 위치의 인덱스를 지운다.
		sprintf(query, strSql, strstr);
		mysql_query(cons, query);
		m_listbox1.Invalidate();
	}
	catch (CException* e) {
		SetDlgItemText(IDC_EDIT4, "에러남");
	}
}

//update
void CMFCListBoxExamDlg::OnBnClickedButton3()
{
	CString text6, text7;
	CString strSql;
	char query[2048];
	GetDlgItemText(IDC_EDIT6, text6);
	GetDlgItemText(IDC_EDIT7, text7);
	try {
		//where값을 set의 값으로 바꾼다.
		strSql = "update opentutorials.c_test set id='%s' where id='%s'";
		sprintf(query, strSql, text7, text6);
		mysql_query(cons, query);
	}
	catch (CException* e) {
		SetDlgItemText(IDC_EDIT4, "에러남");
		//e->ReportError()
	}
}
