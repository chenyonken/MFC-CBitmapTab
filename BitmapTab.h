#if !defined(AFX_BITMAPTAB_H__C8216CE8_1E5D_4FFE_9603_252D2A8657F2__INCLUDED_)
#define AFX_BITMAPTAB_H__C8216CE8_1E5D_4FFE_9603_252D2A8657F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BitmapTab.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBitmapTab window

/****************提示**********************
如果有三态的的完整图片，即包含图标，背景，文字的图片，
即可直接使用位图输出无需涉及到文字和背景设置，只需在不同状态
下显示不同的位图即可，但由于本程序没有可用的位图，只能
手动画背景和文字，然后导入图标
*****************************************/

class CBitmapTab : public CWnd
{
// Construction
public:
	struct SItem
	{
		CString szText;	//保留，每项文字
		int nImageNormal;	//正常状态图片
		int nImageSel;		//选择状态图片
		int nImageTrack;	//跟踪状态图片
		int nWidth;			//每项宽度
	};
	CArray<SItem,SItem>m_arr;		//标签项的数据集合
	CImageList* m_pList;			//图像集合
	int m_nCurSel,m_nTrack;			//选择状态和跟踪状态的索引
	CFont m_font,m_fontSel;			//普通标签字体和选中标签字体
	static const COLORREF m_clNormal,m_clSel,m_clTrack;		//三态标签项的背景色
	static const COLORREF m_clTextNormal,m_clTextSel,m_clTextTrack;//三态标签项的文本颜色
	static const CPen m_pen;		//选择状态的边框
	
public:
	void Register();				//注册窗口类
	int GetTextWidth(CString szText);		//根据文字和字体计算每项宽度
	CString GetItemText(int nItem)const;	//获取标签项文本

public:

public:
	CBitmapTab();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapTab)
	//}}AFX_VIRTUAL

// Implementation
public:

	BOOL DeleteAllItems();
	BOOL DeleteItem(int nItem);
	int SetCurSel(int nItem);
	int GetCurSel()const;
	int GetItemCount()const;
	BOOL GetItemRect(int nItem,LPRECT lpRect);
	CImageList* SetImageList(CImageList* pImageList);
	CImageList* GetImageList()const;
	BOOL InsertItem(int nItem, LPCTSTR lpszItem,int nItemNormal,int nItemSel,int nItemTrack);

	BOOL Create(DWORD dwStyle,const RECT& rect,CWnd* ParentWnd,UINT nID);
	virtual ~CBitmapTab();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBitmapTab)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPTAB_H__C8216CE8_1E5D_4FFE_9603_252D2A8657F2__INCLUDED_)
