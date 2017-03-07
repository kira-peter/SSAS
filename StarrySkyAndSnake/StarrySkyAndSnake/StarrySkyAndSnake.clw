; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSkySet
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "StarrySkyAndSnake.h"

ClassCount=5
Class1=CStarrySkyAndSnakeApp
Class2=CStarrySkyAndSnakeDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_STARRYSKYANDSNAKE_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG_SKYSET
Resource4=IDD_DIALOG_CLOSEWND
Resource5=IDD_ABOUTBOX
Class4=CSkySet
Class5=CSnakeSet
Resource6=IDD_DIALOG_SNAKESET

[CLS:CStarrySkyAndSnakeApp]
Type=0
HeaderFile=StarrySkyAndSnake.h
ImplementationFile=StarrySkyAndSnake.cpp
Filter=N

[CLS:CStarrySkyAndSnakeDlg]
Type=0
HeaderFile=StarrySkyAndSnakeDlg.h
ImplementationFile=StarrySkyAndSnakeDlg.cpp
Filter=D
LastObject=CStarrySkyAndSnakeDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=StarrySkyAndSnakeDlg.h
ImplementationFile=StarrySkyAndSnakeDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_STARRYSKYANDSNAKE_DIALOG]
Type=1
Class=CStarrySkyAndSnakeDlg
ControlCount=0

[DLG:IDD_DIALOG_CLOSEWND]
Type=1
Class=?
ControlCount=4
Control1=IDC_CLOSEWND,button,1342242816
Control2=IDC_EDIT,edit,1350631552
Control3=IDC_STATIC,static,1342308864
Control4=IDC_DESTROYWND,button,1342242816

[DLG:IDD_DIALOG_SNAKESET]
Type=1
Class=CSnakeSet
ControlCount=9
Control1=IDC_STATIC,button,1342177287
Control2=IDC_EASY,button,1342308361
Control3=IDC_NORMAL,button,1342177289
Control4=IDC_HARD,button,1342177289
Control5=IDC_CANCEL,button,1342242816
Control6=IDC_SAVE,button,1342242816
Control7=IDC_RESET,button,1342242816
Control8=IDC_STATIC,button,1342177287
Control9=IDC_UNDEAD,button,1342242819

[CLS:CSkySet]
Type=0
HeaderFile=SkySet.h
ImplementationFile=SkySet.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_TRANSPARENT_PURL
VirtualFilter=dWC

[DLG:IDD_DIALOG_SKYSET]
Type=1
Class=CSkySet
ControlCount=29
Control1=IDC_RED,button,1342308361
Control2=IDC_GREEN,button,1342177289
Control3=IDC_BLUE,button,1342177289
Control4=IDC_WHITE,button,1342177289
Control5=IDC_MULTIPLECOLOR,button,1342177289
Control6=IDC_CUSTOMCOLOR,button,1342177289
Control7=IDC_COLORVIEW,static,1342177295
Control8=IDC_SLIDER_RED,msctls_trackbar32,1342242832
Control9=IDC_SLIDER_GREEN,msctls_trackbar32,1342242840
Control10=IDC_SLIDER_BLUE,msctls_trackbar32,1342242836
Control11=IDC_STATIC,static,1342308353
Control12=IDC_STATIC,static,1342308353
Control13=IDC_STATIC,static,1342308353
Control14=IDC_FLASH,button,1342242819
Control15=IDC_EDIT_COUNT,edit,1350639744
Control16=IDC_SPIN_COUNT,msctls_updown32,1342177335
Control17=IDC_SLIDER_COUNT,msctls_trackbar32,1342242840
Control18=IDC_SET_CANCEL,button,1342242816
Control19=IDC_SET_SAVE,button,1342242816
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,button,1342177287
Control22=IDC_STATIC,button,1342177287
Control23=IDC_STATIC,button,1342177287
Control24=IDC_SET_RESET,button,1342242816
Control25=IDC_STATIC,static,1342308352
Control26=IDC_EDIT_SIZEINCREMENT,edit,1350639744
Control27=IDC_TRANSPARENT,button,1342242819
Control28=IDC_SLIDER_TRANSPARENT,msctls_trackbar32,1342242872
Control29=IDC_TRANSPARENT_PURL,button,1342242819

[CLS:CSnakeSet]
Type=0
HeaderFile=SnakeSet.h
ImplementationFile=SnakeSet.cpp
BaseClass=CDialog
Filter=D
LastObject=CSnakeSet

