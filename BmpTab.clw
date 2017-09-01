; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBmpTabDlg
LastTemplate=generic CWnd
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BmpTab.h"

ClassCount=3
Class1=CBmpTabApp
Class2=CBmpTabDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CBitmapTab
Resource2=IDD_BMPTAB_DIALOG

[CLS:CBmpTabApp]
Type=0
HeaderFile=BmpTab.h
ImplementationFile=BmpTab.cpp
Filter=N

[CLS:CBmpTabDlg]
Type=0
HeaderFile=BmpTabDlg.h
ImplementationFile=BmpTabDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CBmpTabDlg



[DLG:IDD_BMPTAB_DIALOG]
Type=1
Class=CBmpTabDlg
ControlCount=0

[CLS:CBitmapTab]
Type=0
HeaderFile=BitmapTab.h
ImplementationFile=BitmapTab.cpp
BaseClass=CWnd
Filter=W
VirtualFilter=WC
LastObject=CBitmapTab

