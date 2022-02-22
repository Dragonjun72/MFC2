// ImageLoadTestDlg.h : header file
//
#include "atlimage.h"

#pragma once


// CImageLoadTestDlg dialog
class CImageLoadTestDlg : public CDialog
{
// Construction
private:
	CImage m_image;
 //cimage ���� ����
public:
	CImageLoadTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_IMAGELOADTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
