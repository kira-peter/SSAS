// Star.h: interface for the CStar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STAR_H__B22FA012_61EA_4350_A4B0_2F75F1D21367__INCLUDED_)
#define AFX_STAR_H__B22FA012_61EA_4350_A4B0_2F75F1D21367__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <list>
using namespace std;

typedef struct StarInfo{
	int m_x;
	double m_angle;
	int m_size;
	int m_flycount;
	COLORREF m_color;
}SI, *PSI;

typedef enum {S_RED, S_GREEN, S_BLUE, S_WHITE, S_MULTIPLECOLOR, S_CUSTOMCOLOR} STARSTYLE;

class CStar  
{
public:
	BOOL GetPureStyle();
	void SetPureStyle(BOOL Pure);
	int GetSizeIncrement();
	void SetSizeIncrement(int Increment);
	unsigned int GetMaxCount();
	void SetCustomColor(COLORREF color);
	void SetMaxCount(unsigned int maxcount);
	BYTE GetTransparent();
	void SetTransparent(BYTE Trans);
	BOOL GetFlashFlag();
	COLORREF GetCustomColor();
	STARSTYLE GetStarStyle();
	void SetStarStyle(STARSTYLE style, BOOL flash);
	void NewStar(int x=0, int size=0, double angle=0);
	void StarFly(POINT pos, int width, COLORREF& color);
	void Show();
	CStar(int count=20);
	virtual ~CStar();
private:
	int m_FlyBlank;
	int m_FlyCount;
	int m_sizeIncrement;
	COLORREF	m_CustomColor;
	list<PSI>	m_StarList;
	unsigned int m_MaxCount;
	STARSTYLE	m_StarStyle;
	BOOL		m_FlashFlag;
	BOOL		m_SmoothFlag;
	BYTE		m_Transparent;
	BOOL		m_PureStyle;
};
#endif // !defined(AFX_STAR_H__B22FA012_61EA_4350_A4B0_2F75F1D21367__INCLUDED_)
