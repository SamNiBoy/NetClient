; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNetDlg
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Net.h"

ClassCount=3
Class1=CNetApp
Class2=CNetDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CMySock
Resource2=IDD_NET_DIALOG

[CLS:CNetApp]
Type=0
HeaderFile=Net.h
ImplementationFile=Net.cpp
Filter=N

[CLS:CNetDlg]
Type=0
HeaderFile=NetDlg.h
ImplementationFile=NetDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CNetDlg



[DLG:IDD_NET_DIALOG]
Type=1
Class=CNetDlg
ControlCount=9
Control1=IDC_Connect,button,1342242816
Control2=IDC_Send,button,1342242816
Control3=IDC_Exit,button,1342242816
Control4=IDC_LISTMSG,listbox,1352728835
Control5=IDC_EDITMSG,edit,1350631552
Control6=IDC_ServerAddr,edit,1350631552
Control7=IDC_ServerPort,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352

[CLS:CMySock]
Type=0
HeaderFile=MySock.h
ImplementationFile=MySock.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CMySock

