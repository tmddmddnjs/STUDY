﻿
// MFCImageExamDlg.h: 헤더 파일
//

#pragma once


// CMFCImageExamDlg 대화 상자
class CMFCImageExamDlg : public CDialogEx
{
// 생성입니다.
private:
	//화면 로드시 부르는 이미지
	CImage m_image;
	//버튼 입력시 부르는 이미지
	CImage button_image;
	//이미지 회전
	CImage m_rotat_image;
	//이미지 확대
	CImage m_image2;
	CImage m_image3;
	//이미지 색 반전
	CImage invert_image;
public:
	CMFCImageExamDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCIMAGEEXAM_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnBnClickedButton5();
};