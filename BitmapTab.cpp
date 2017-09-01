// BitmapTab.cpp : implementation file
//

#include "stdafx.h"
#include "BmpTab.h"
#include "BitmapTab.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBitmapTab
#ifndef COLOR_GRADIENTINACTIVECAPTION
#define COLOR_GRADIENTINACTIVECAPTION 28
#endif

#define BITMAP_TAB "__BITMAP_TAB__"
#define PICTRUEWIDTH	60				//实际图标像素为16*16
#define LABCORNORDEG	10
#define LABDISTANCE		10
const COLORREF CBitmapTab::m_clNormal
=RGB(0,0,0),							//白色
CBitmapTab::m_clSel=RGB(255,255,255),	//黑色
CBitmapTab::m_clTrack=RGB(200,200,200),//灰色
CBitmapTab::m_clTextNormal=RGB(255,255,255),
CBitmapTab::m_clTextSel=RGB(0,0,0),
CBitmapTab::m_clTextTrack=m_clTextNormal;
const CPen CBitmapTab::m_pen(0,1,RGB(123,158,189));


CBitmapTab::CBitmapTab()
{
	m_nCurSel=0;
	m_nTrack=-1;
	m_pList=NULL;
}

CBitmapTab::~CBitmapTab()
{
	if(m_font.GetSafeHandle())
		m_font.DeleteObject();
	if(m_fontSel.GetSafeHandle())
		m_fontSel.DeleteObject();
}


BEGIN_MESSAGE_MAP(CBitmapTab, CWnd)
	//{{AFX_MSG_MAP(CBitmapTab)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CBitmapTab message handlers

void CBitmapTab::Register()				//注册窗口类
{
	WNDCLASS wc={0};
	wc.hInstance=AfxGetInstanceHandle();
	wc.lpfnWndProc=::DefWindowProc;
	wc.cbClsExtra=0;
	wc.cbWndExtra=0;
	wc.hIcon=NULL;
	wc.hCursor=AfxGetApp()->LoadStandardCursor(IDC_ARROW);
	wc.hbrBackground=::GetSysColorBrush(COLOR_BTNSHADOW);//COLOR_HIGHLIGHT,COLOR_BTNSHADOW

	wc.lpszClassName=BITMAP_TAB;
	wc.lpszMenuName=NULL;
	wc.style=CS_HREDRAW|CS_VREDRAW;
	AfxRegisterClass(&wc);
}


BOOL CBitmapTab::Create(DWORD dwStyle, const RECT &rect, CWnd *ParentWnd, UINT nID)
{
	static b=TRUE;
	if(b)
	{
		//只执行一次
		b=FALSE;
		Register();
	}
	CFont* pFont=ParentWnd->GetFont();
	if(!pFont)
	{
		HFONT hFont=(HFONT)::GetStockObject(DEFAULT_GUI_FONT);
		pFont=CFont::FromHandle(hFont);
	}
	LOGFONT lf;
	pFont->GetLogFont(&lf);
	m_font.CreateFontIndirect(&lf);
	lf.lfWeight=700;
	m_fontSel.CreateFontIndirect(&lf);
	return CWnd::Create(BITMAP_TAB,NULL,dwStyle,rect,ParentWnd,nID);
}



BOOL CBitmapTab::InsertItem(int nItem, LPCTSTR lpszItem,int nItemNormal,int nItemSel, int nItemTrack)
{
	SItem item;
	item.nImageNormal=nItemNormal;
	item.nImageSel=nItemSel;
	item.nImageTrack=nItemTrack;
	item.szText=lpszItem;
	item.nWidth=GetTextWidth(lpszItem)+PICTRUEWIDTH;
	m_arr.InsertAt(nItem,item);
	return TRUE;
}

CImageList* CBitmapTab::GetImageList() const
{
	return m_pList;
}

CImageList* CBitmapTab::SetImageList(CImageList *pImageList)
{
	ASSERT(pImageList);
	CImageList* p=m_pList;
	m_pList=pImageList;
	return p;
}

BOOL CBitmapTab::GetItemRect(int nItem, LPRECT lpRect)
{
	ASSERT(nItem<m_arr.GetSize()&&nItem>=0);
	return m_arr[nItem].nWidth;
}

int CBitmapTab::GetItemCount() const
{
	return m_arr.GetSize();
}

int CBitmapTab::GetCurSel() const
{
	return m_nCurSel;
}

int CBitmapTab::SetCurSel(int nItem)
{
	ASSERT(nItem<m_arr.GetSize()&&nItem>=0);
	m_nCurSel=nItem;
	return TRUE;
}

BOOL CBitmapTab::DeleteItem(int nItem)
{
	ASSERT(nItem<m_arr.GetSize()&&nItem>=0);
	m_arr.RemoveAt(nItem);
	return TRUE;
}

BOOL CBitmapTab::DeleteAllItems()
{
	m_arr.RemoveAll();
	return TRUE;
}



int CBitmapTab::GetTextWidth(CString szText)
{
	CClientDC dc(this);
	dc.SelectObject(&m_font);
	CSize size=dc.GetTextExtent(szText);
	return size.cx;
}

CString CBitmapTab::GetItemText(int nItem) const
{
	ASSERT(nItem<m_arr.GetSize()&&nItem>=0);
	return m_arr[nItem].szText;
}

BOOL CBitmapTab::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;
}

void CBitmapTab::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	GetClientRect(rect);
	int i=-1,nCount=GetItemCount();
	rect.right=rect.left;
	while(++i<nCount)
	{
		//循环测试每个标签项的空间
		rect.left=rect.right+LABDISTANCE;
		rect.right+=m_arr[i].nWidth;
		if(rect.PtInRect(point))
		{
			m_nCurSel=i;
			Invalidate(FALSE);
			//模拟发送CBitmapTab的TCN_SELCHANGE反射型消息
			NMHDR hdr={m_hWnd,GetDlgCtrlID(),TCN_SELCHANGE};
			GetParent()->SendMessage(WM_NOTIFY,(WPARAM)m_hWnd,(LPARAM)&hdr);
			return;
		}
	}
	CWnd::OnLButtonDown(nFlags, point);
}

void CBitmapTab::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CWnd::OnMouseMove(nFlags, point);
	CRect rect;
	GetClientRect(rect);
	if(!rect.PtInRect(point))
	{
		ReleaseCapture();
		return;
	}
	if(GetCapture()-this)
		SetCapture();

	int i=-1,nCount=GetItemCount();
	rect.right=rect.left;
	while(++i<nCount)
	{
		//循环测试每个标签项的空间
		rect.left=rect.right+LABDISTANCE;
		rect.right+=m_arr[i].nWidth;
		if(rect.PtInRect(point))
		{
			if(m_nTrack!=i)
			{
				m_nTrack=i;
				Invalidate(FALSE);
			}
			return ;
		}
	}
}

void CBitmapTab::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	dc.SelectObject(m_font);
	dc.SetBkMode(TRANSPARENT);
	dc.SelectObject(m_pen);
	CString szText;
	CRect rect,rc;
	GetClientRect(rc);
	rect=rc;
	rect.right=rect.left;
	int i=-1,nCount=GetItemCount(),nSel=GetCurSel();
	while(++i<nCount)
	{
		rect.left=rect.right+LABDISTANCE;
		rect.right+=m_arr[i].nWidth;
		szText=GetItemText(i);

		CPoint point=rect.TopLeft();
		point.Offset(10,6);
		if(nSel!=i)
		{
			//跟踪态(加亮)和正常态
			CBrush br(i==m_nTrack?m_clTrack:m_clNormal);
			CBrush* pOldBrush=dc.SelectObject(&br);
			
			dc.RoundRect(rect.left,rect.top,rect.right,rect.bottom,LABCORNORDEG,LABCORNORDEG);
			m_pList->Draw(&dc,i==m_nTrack?m_arr[i].nImageTrack:m_arr[i].nImageNormal,
				point,ILD_TRANSPARENT);
			rect.left+=16;
//			dc.DrawEdge(rect,BDR_RAISEDINNER,BF_RIGHT);//画边界就会使圆角矩形有角
			COLORREF cl=dc.SetTextColor(i==m_nTrack?m_clTextTrack:m_clTextNormal);
			dc.DrawText(szText,szText.GetLength(),rect,
				DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			
			dc.SelectObject(pOldBrush);
			dc.SetTextColor(cl);
			br.DeleteObject();
		}
		else
		{
			//选择态
			COLORREF cl=dc.SetTextColor(m_clTextSel);
			CBrush br(m_clSel);
			CBrush* pOldBrush=dc.SelectObject(&br);
			dc.RoundRect(rect.left,rect.top,rect.right,rect.bottom,LABCORNORDEG,LABCORNORDEG);
			m_pList->Draw(&dc,m_arr[i].nImageSel,
				point,ILD_TRANSPARENT);
			rect.left+=16;
			dc.DrawText(szText,szText.GetLength(),rect,
				DT_SINGLELINE|DT_VCENTER|DT_CENTER);
			dc.SetTextColor(cl);
			dc.SelectObject(pOldBrush);
			br.DeleteObject();
		}
		rect.top=rc.top;
		rect.bottom=rc.bottom;
	}

}
