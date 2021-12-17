
// MFCListBoxExamDlg.h: 헤더 파일
//

#pragma once


// CMFCListBoxExamDlg 대화 상자
class CMFCListBoxExamDlg : public CDialogEx
{
// 생성입니다.
	
public:
	CMFCListBoxExamDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCLISTBOXEXAM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	CListBox m_listbox1;
	CButton m_button;
	CEdit m_text1;
	CEdit m_text2;
	CEdit m_text3;

	CButton delete_button;
	
	CButton update_button;
	CEdit update_text_before;
	CEdit update_text_after;

	CEdit error_text;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
