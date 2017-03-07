// Star.cpp: implementation of the CStar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StarrySkyAndSnake.h"
#include "Star.h"
#include "stdlib.h"
#include "time.h"

inline int P(int x) {
	int val = 1;
	for(int i=0; i<x; i++){
		val *= 2;
	}
	return val;
	//return x*x;
}
#define INCREMENT 10

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStar::CStar(int count) :m_MaxCount(count)
{
	srand(time(0));
	m_StarStyle = S_WHITE;
	m_FlashFlag = TRUE;
	m_sizeIncrement = 1;
	m_FlyBlank = 1;
	m_FlyCount = 0;
	m_Transparent = 255;
	m_PureStyle = 0;
}

CStar::~CStar()
{

}

void CStar::Show()
{
	if (m_StarList.size() < m_MaxCount)
		NewStar();
	RECT Rect;
	AfxGetMainWnd()->GetClientRect(&Rect);
	for(list<PSI>::iterator it = m_StarList.begin(); it!= m_StarList.end(); ){
		int a = (*it)->m_x;
		if((*it)->m_x > Rect.right/2 || (*it)->m_x < -Rect.right/2 || (*it)->m_angle*(*it)->m_x > Rect.bottom/2 || (*it)->m_angle*(*it)->m_x < -Rect.bottom/2){
			delete (*it);
			list<PSI>::iterator itt = ++it;
			m_StarList.erase(--it);
			it = itt;
			if (m_StarList.size() < m_MaxCount)
				NewStar();
			continue;
		}
		int x =(*it)->m_x + Rect.right/2;
		int y =(*it)->m_angle*(*it)->m_x + Rect.bottom/2;
		POINT pos = {x, y};
		StarFly(pos, (*it)->m_size, (*it)->m_color);
		int count = (*it)->m_flycount++;
		for(int i=1; i<300; i++){
			if(count <= i*2 && count>i*2-2){
				(*it)->m_x += (*it)->m_x>0?P((*it)->m_size):-P((*it)->m_size);
				if(count == i*2 && count > 5)
					(*it)->m_size+=m_sizeIncrement;
			}
		}
		it++;
	}
}

void CStar::StarFly(POINT pos, int width, COLORREF& color)
{
	CWindowDC dc(AfxGetMainWnd());
	//CWindowDC dc(AfxGetMainWnd());
	unsigned char r = GetRValue(color);
	unsigned char g = GetGValue(color);
	unsigned char b = GetBValue(color);
	if(m_FlashFlag){
		switch(m_StarStyle){
		case S_CUSTOMCOLOR:
			if(rand()%3){
				r = g = b = 0;
				break;
			}
			r = GetRValue(m_CustomColor);
			g = GetGValue(m_CustomColor);
			b = GetBValue(m_CustomColor);
			break;
		case S_MULTIPLECOLOR:
			r += INCREMENT;
			g += INCREMENT;
			b += INCREMENT;
			break;
		case S_WHITE:
			r += INCREMENT;
			g += INCREMENT;
			b += INCREMENT;
			break;
		case S_RED:
			r += INCREMENT;
			break;
		case S_GREEN:
			g += INCREMENT;
			break;
		case S_BLUE:
			b += INCREMENT;
			break;
		}
		color = RGB(r, g, b);
	}
	
	CPen cPen(PS_SOLID, 1, RGB(r, g, b));
	CBrush cBrush(RGB(r, g, b));
	HBRUSH hOldBrush = (HBRUSH)dc.SelectObject(&cBrush);
	HPEN hOldPen = (HPEN)dc.SelectObject(&cPen);
	if (width == 1){
		dc.SetPixel(pos, RGB(r, g, b));
	}
	dc.Ellipse(pos.x, pos.y, pos.x+width, pos.y+width);
	dc.SelectObject(hOldPen);
	dc.SelectObject(hOldBrush);
}

void CStar::NewStar(int x, int size, double angle)
{
	RECT Rect;
	AfxGetMainWnd()->GetClientRect(&Rect);
	int base_x = Rect.right/1;
	int base_y = Rect.bottom/1;
	if(size == 0){
		PSI pStar = new SI;
		pStar->m_x = rand()%2 ? (-rand()%base_x)-1 : (rand()%base_x)+1;
		int y = rand()%2 ? -rand()%base_y : rand()%base_y;
		pStar->m_angle = (double)y/pStar->m_x;
		pStar->m_size = 1;
		pStar->m_flycount = 0;
		unsigned char r = 0;
		unsigned char g = 0;
		unsigned char b = 0;
		switch(m_StarStyle){
		case S_CUSTOMCOLOR:
			r = GetRValue(m_CustomColor);
			g = GetGValue(m_CustomColor);
			b = GetBValue(m_CustomColor);
			break;
		case S_MULTIPLECOLOR:
			r = rand()%255;
			g = rand()%255;
			b = rand()%255;
			break;
		case S_WHITE:
			r = g = b = 255;
			break;
		case S_RED:
			r = rand()%255;
			break;
		case S_GREEN:
			g = rand()%255;
			break;
		case S_BLUE:
			b = rand()%255;
			break;
		}
		pStar->m_color = RGB(r, g, b);
		m_StarList.push_back(pStar);
		return;
	}
	PSI pStar = new SI;
	pStar->m_x = x;
	pStar->m_angle = angle;
	pStar->m_size = size;
	m_StarList.push_back(pStar);
	return;
}

void CStar::SetStarStyle(STARSTYLE style, BOOL flash)
{
	m_StarStyle = style;
	m_FlashFlag = flash;
}

STARSTYLE CStar::GetStarStyle()
{
	return m_StarStyle;
}

BOOL CStar::GetFlashFlag()
{
	return m_FlashFlag;
}

void CStar::SetMaxCount(int maxcount)
{
	m_MaxCount = maxcount;
}

COLORREF CStar::GetCustomColor(){
	return m_CustomColor;
}

void CStar::SetCustomColor(COLORREF color)
{
	m_CustomColor = color;
}


int CStar::GetMaxCount()
{
	return m_MaxCount;
}

void CStar::SetSizeIncrement(int Increment)
{
	m_sizeIncrement = Increment;
}

int CStar::GetSizeIncrement()
{
	return m_sizeIncrement;
}
BYTE CStar::GetTransparent(){
	return m_Transparent;
}
void CStar::SetTransparent(BYTE Trans){
	m_Transparent = Trans;
}
BOOL CStar::GetPureStyle(){
	return m_PureStyle;
}
void CStar::SetPureStyle(BOOL Pure){
	m_PureStyle = Pure;
}