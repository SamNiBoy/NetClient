// MySock.cpp : implementation file
//

#include "stdafx.h"
#include "Net.h"
#include "MySock.h"
#include "NetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySock

CMySock::CMySock()
{
	m_nLength = 0;
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
	m_bConnected = false;
}

CMySock::~CMySock()
{
	if(this->m_hSocket != INVALID_SOCKET)
		Close();
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CMySock, CAsyncSocket)
	//{{AFX_MSG_MAP(CMySock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CMySock member functions

void CMySock::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_nLength = Receive(m_szBuffer, sizeof(m_szBuffer), 0);

	CNetApp *pApp = (CNetApp*) AfxGetApp();
	CNetDlg *pDlg = (CNetDlg*) pApp->m_pMainWnd;
	pDlg->m_MSGS.InsertString(0, m_szBuffer);
	memset(m_szBuffer, 0, sizeof(m_szBuffer));

	CAsyncSocket::OnReceive(nErrorCode);
}

void CMySock::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	Send(m_szBuffer, m_nLength, 0);
	m_nLength = 0;
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
	this->AsyncSelect(FD_READ);
	CAsyncSocket::OnSend(nErrorCode);
}

void CMySock::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(!nErrorCode)
	{
		m_bConnected = TRUE;
	    CNetApp *pApp = (CNetApp*) AfxGetApp();
	    CNetDlg *pDlg = (CNetDlg*) pApp->m_pMainWnd;
		memcpy(m_szBuffer, "Connected to ",13);
		strncat(m_szBuffer, (LPCTSTR)pDlg->m_szServerAddr, pDlg->m_szServerAddr.GetLength());
		pDlg->m_MSGS.InsertString(0, m_szBuffer);
		this->AsyncSelect(FD_READ);
	}

	CAsyncSocket::OnConnect(nErrorCode);
}
