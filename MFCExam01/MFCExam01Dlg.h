
// MFCExam01Dlg.h: 헤더 파일
//

#pragma once


// CMFCExam01Dlg 대화 상자
class CMFCExam01Dlg : public CDialogEx
{
// 생성입니다.
private:
	//원형, 네모 그리기
	CPoint rect_start_pos;
	//키보드의 방향키로 이동
	CRect m_rect;
	int x_pos = 0, y_pos = 0;
	//랜덤색
	
public:
	CMFCExam01Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCEXAM01_DIALOG };
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
};
