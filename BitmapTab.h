#if !defined(AFX_BITMAPTAB_H__C8216CE8_1E5D_4FFE_9603_252D2A8657F2__INCLUDED_)
#define AFX_BITMAPTAB_H__C8216CE8_1E5D_4FFE_9603_252D2A8657F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BitmapTab.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBitmapTab window

/****************��ʾ**********************
�������̬�ĵ�����ͼƬ��������ͼ�꣬���������ֵ�ͼƬ��
����ֱ��ʹ��λͼ��������漰�����ֺͱ������ã�ֻ���ڲ�ͬ״̬
����ʾ��ͬ��λͼ���ɣ������ڱ�����û�п��õ�λͼ��ֻ��
�ֶ������������֣�Ȼ����ͼ��
*****************************************/

class CBitmapTab : public CWnd
{
// Construction
public:
	struct SItem
	{
		CString szText;	//������ÿ������
		int nImageNormal;	//����״̬ͼƬ
		int nImageSel;		//ѡ��״̬ͼƬ
		int nImageTrack;	//����״̬ͼƬ
		int nWidth;			//ÿ����
	};
	CArray<SItem,SItem>m_arr;		//��ǩ������ݼ���
	CImageList* m_pList;			//ͼ�񼯺�
	int m_nCurSel,m_nTrack;			//ѡ��״̬�͸���״̬������
	CFont m_font,m_fontSel;			//��ͨ��ǩ�����ѡ�б�ǩ����
	static const COLORREF m_clNormal,m_clSel,m_clTrack;		//��̬��ǩ��ı���ɫ
	static const COLORREF m_clTextNormal,m_clTextSel,m_clTextTrack;//��̬��ǩ����ı���ɫ
	static const CPen m_pen;		//ѡ��״̬�ı߿�
	
public:
	void Register();				//ע�ᴰ����
	int GetTextWidth(CString szText);		//�������ֺ��������ÿ����
	CString GetItemText(int nItem)const;	//��ȡ��ǩ���ı�

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
