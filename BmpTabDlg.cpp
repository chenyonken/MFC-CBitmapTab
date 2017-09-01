// BmpTabDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BmpTab.h"
#include "BmpTabDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpTabDlg dialog

CBmpTabDlg::CBmpTabDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBmpTabDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBmpTabDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBmpTabDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBmpTabDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBmpTabDlg, CDialog)
	ON_NOTIFY(TCN_SELCHANGE,IDC_TAB,OnSelChangeTab)
	//{{AFX_MSG_MAP(CBmpTabDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpTabDlg message handlers

BOOL CBmpTabDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	UINT nIDs[]={IDI_NORMAL,IDI_SELECT,IDI_TRACK};
	m_iList.Create(16,16,ILC_COLOR32|ILC_MASK,8,8);
	//这里统一所有的标签项使用相同的三态图片
	//若想不同标签项使用不同三态图片，需要在这里将资源加进入，
	//然后m_tab.InsertItem()的时候使用不同的图片
	for(int i=0;i<sizeof(nIDs)/sizeof(nIDs[0]);i++)
	{
		m_iList.Add(AfxGetApp()->LoadIcon(nIDs[i]));
	}
	
//BOOL CBitmapTab::InsertItem(int nItem, LPCTSTR lpszItem,
//	int nItemNormal,int nItemSel, int nItemTrack)

	m_tab.Create(WS_VISIBLE,CRect(0,0,400,30),this,IDC_TAB);
	m_tab.SetImageList(&m_iList);
	m_tab.InsertItem(0,_T("查杀病毒"),0,1,2);
	m_tab.InsertItem(1,_T("防范未然"),0,1,2);//
	m_tab.InsertItem(2,_T("专业保护"),0,1,2);
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

void CBmpTabDlg::OnPaint() 
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
HCURSOR CBmpTabDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBmpTabDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CBmpTabDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CBmpTabDlg::OnSelChangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	int nSel=m_tab.GetCurSel();
	CString str;
	str.Format("第%d页:",nSel+1);
	str+=m_tab.GetItemText(nSel);
	SetWindowText(str);
	*pResult=0;
}
