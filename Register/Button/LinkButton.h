#pragma once
#include "BaseControl.h"
#include "Text.h"
// CLinkButton

class CLinkButton : public CBaseControl
{
	DECLARE_DYNAMIC(CLinkButton)
public:
	CLinkButton();
	virtual ~CLinkButton();
	
public:
	void SetText(const CStringW str,Gdiplus::Font * font,
		Gdiplus::Color color_normal=Color(20, 109, 175),Gdiplus::Color color_hover=Color(21, 112, 235));
	
	BOOL Create(const Rect rect,CWnd * const pParentWnd,const UINT nID);
	virtual void Show(Graphics* const g);
protected:
	DECLARE_MESSAGE_MAP()
	CText mText;
	void OnTrack();
	Gdiplus::Color m_color_normal,m_color_hover;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};


