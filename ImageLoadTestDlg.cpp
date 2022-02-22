// ImageLoadTestDlg.cpp : implementation file
//
#include "atlimage.h"
#include "stdafx.h"
#include "ImageLoadTest.h"
#include "ImageLoadTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageLoadTestDlg dialog




CImageLoadTestDlg::CImageLoadTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImageLoadTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImageLoadTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CImageLoadTestDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CImageLoadTestDlg::OnBnClickedButton1)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CImageLoadTestDlg message handlers

BOOL CImageLoadTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
//	m_image.Load(CString("test.bmp"));  //아래도 가능 둘다 가능 
	m_image.Load(_T("test.bmp"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CImageLoadTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CImageLoadTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CImageLoadTestDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CClientDC dc(this);

	m_image.Draw(dc, 0, 0);

}

void CImageLoadTestDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);
	SetWindowPos(NULL,0,0,1500,1300,SWP_NOZORDER);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
