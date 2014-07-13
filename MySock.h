#if !defined(AFX_MYSOCK_H__5FB7DE81_8B47_4909_9B18_E4F6C7AB3D00__INCLUDED_)
#define AFX_MYSOCK_H__5FB7DE81_8B47_4909_9B18_E4F6C7AB3D00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MySock.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CMySock command target

class CMySock : public CAsyncSocket
{
// Attributes
public:

	BOOL m_bConnected;
	UINT m_nLength;
	char m_szBuffer[4096];
// Operations
public:
	CMySock();
	virtual ~CMySock();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySock)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMySock)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSOCK_H__5FB7DE81_8B47_4909_9B18_E4F6C7AB3D00__INCLUDED_)
