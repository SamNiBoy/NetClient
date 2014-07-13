// NetDlg.h : header file
//

#if !defined(AFX_NETDLG_H__2FC64AA6_DB32_4F69_ABBA_88750E8A4709__INCLUDED_)
#define AFX_NETDLG_H__2FC64AA6_DB32_4F69_ABBA_88750E8A4709__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"MySock.h"
/////////////////////////////////////////////////////////////////////////////
// CNetDlg dialog

class CNetDlg : public CDialog
{
// Construction
public:
	int tryCount;
	CMySock m_clientSocket;
	CNetDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNetDlg)
	enum { IDD = IDD_NET_DIALOG };
	CEdit	m_MSG;
	CListBox	m_MSGS;
	CString	m_szServerAddr;
	int		m_szPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSend();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETDLG_H__2FC64AA6_DB32_4F69_ABBA_88750E8A4709__INCLUDED_)
