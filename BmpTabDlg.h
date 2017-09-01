// BmpTabDlg.h : header file
//

#if !defined(AFX_BMPTABDLG_H__34C8D6A2_C960_4AB8_B94D_1A9603B9AEA3__INCLUDED_)
#define AFX_BMPTABDLG_H__34C8D6A2_C960_4AB8_B94D_1A9603B9AEA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBmpTabDlg dialog
#include "BitmapTab.h"
class CBmpTabDlg : public CDialog
{
// Construction
public:
	enum{IDC_TAB=1234};
	enum{IMAGE_CNT=3};
	CBitmapTab m_tab;
	CImageList m_iList;
public:
	void OnSelChangeTab(NMHDR* pNMHDR,LRESULT* pResult);
	CBmpTabDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBmpTabDlg)
	enum { IDD = IDD_BMPTAB_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpTabDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBmpTabDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPTABDLG_H__34C8D6A2_C960_4AB8_B94D_1A9603B9AEA3__INCLUDED_)
