// Net.h : main header file for the NET application
//

#if !defined(AFX_NET_H__EC28376F_715C_4F12_9232_B2DE39348023__INCLUDED_)
#define AFX_NET_H__EC28376F_715C_4F12_9232_B2DE39348023__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNetApp:
// See Net.cpp for the implementation of this class
//

class CNetApp : public CWinApp
{
public:
	CNetApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNetApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NET_H__EC28376F_715C_4F12_9232_B2DE39348023__INCLUDED_)
