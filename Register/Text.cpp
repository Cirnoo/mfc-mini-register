#include "stdafx.h"
#include "Text.h"
#include "Sys.h"

CText::CText(void)
{
}


CText::~CText(void)
{
}

BOOL CText::Create(Rect rect,CStringW str,Gdiplus::Font * font, Gdiplus::Color color/*=Gdiplus::Color::Black */, StringAlignment format/*=StringAlignmentCenter*/)
{
	str_rect=RectFTransform(rect);
	mFont=font;
	mBuf=str;
	mStr=mBuf.GetBuffer();
	mFormat=format;
	mColor=color;
	return TRUE;
}

void CText::Show(Graphics* & g)
{
	SolidBrush brush(mColor);
	StringFormat format;
	format.SetAlignment(mFormat);
	g->DrawString(mStr,-1,mFont,str_rect,&format,&brush);
}

void CText::Show(Graphics* & g,RectF rec)
{
	auto temp=str_rect;
	str_rect=rec;
	Show(g);
	str_rect=temp;
}

RectF CText::GetRect()
{
	return str_rect;
}

CStringW CText::GetStr()
{
	return mBuf;
}