// NetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Net.h"
#include "NetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNetDlg dialog

CNetDlg::CNetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetDlg)
	m_szServerAddr = _T("");
	m_szPort = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetDlg)
	DDX_Control(pDX, IDC_EDITMSG, m_MSG);
	DDX_Control(pDX, IDC_LISTMSG, m_MSGS);
	DDX_Text(pDX, IDC_ServerAddr, m_szServerAddr);
	DDX_Text(pDX, IDC_ServerPort, m_szPort);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetDlg, CDialog)
	//{{AFX_MSG_MAP(CNetDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Connect, OnConnect)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_Send, OnSend)
	ON_BN_CLICKED(IDC_Exit, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetDlg message handlers

BOOL CNetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNetDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNetDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNetDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	this->m_clientSocket.ShutDown(2);
	this->m_clientSocket.m_hSocket = INVALID_SOCKET;
	this->m_clientSocket.m_bConnected = FALSE;
	UpdateData();
	if(this->m_szServerAddr.GetLength() <=0 || this->m_szPort == 0)
	{
		AfxMessageBox("Invalid server address or port!");
		return;
	}
	SetTimer(1, 1000, NULL);
	tryCount = 0;
}

void CNetDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if (this->m_clientSocket.m_hSocket == INVALID_SOCKET)
	{
		BOOL bFlag = m_clientSocket.Create(0, SOCK_STREAM, FD_CONNECT);
		if(!bFlag)
		{
			AfxMessageBox("Socket error!");
			m_clientSocket.Close();
			PostQuitMessage(0);
			return;
		}
	}

	m_clientSocket.Connect(m_szServerAddr, m_szPort);
	tryCount++;

	if(tryCount >= 10 || m_clientSocket.m_bConnected)
	{
		KillTimer(1);
		if(tryCount >= 10)
		{
			CString s;
			s.Format("Connection failed with %d", m_clientSocket.GetLastError());
			AfxMessageBox(s);
		}
		return;
	}
	CDialog::OnTimer(nIDEvent);
}

void CNetDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	if(m_clientSocket.m_bConnected)
	{
		m_clientSocket.m_nLength = m_MSG.GetWindowText(
			m_clientSocket.m_szBuffer, sizeof(m_clientSocket.m_szBuffer));
		m_clientSocket.AsyncSelect(FD_WRITE);
		m_MSG.SetWindowText("");
	}
}
s
void CNetDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	m_clientSocket.ShutDown(2);
	EndDialog(0);
}
