// Snake.h: interface for the CSnake class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNAKE_H__348FE5FF_6544_4072_B4A2_752A9B5CF17A__INCLUDED_)
#define AFX_SNAKE_H__348FE5FF_6544_4072_B4A2_752A9B5CF17A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct node 
{
	int a;
	int b;
}node,*nodep;

typedef struct apple{
	int m;
	int n;
}Apple,*Applep;

class CSnake  
{
public:
	void EndGame();
	bool GetUndead();
	void SetUnDead(bool UnDead);
	void SetMoveRect();
	bool ShouldMove();
	void GameStart();
	int GetGameDifficulty();
	void SetGameDifficulty(int difficulty);
	void Veer(UINT direction);
	void InitSanke();
	void Add(int x, int y);
	void Move(CDC *pDC);
	void Show(CDC *pDC);
	void GameGoOn(CDC *pDC);
	void GameOver();
	void levelUp();
	void SetpWnd(CWnd *pWnd);
	CSnake();
	virtual ~CSnake();
	
private:
	bool m_UnDeadGameOver;
	bool m_UnDead;
	CRect m_rect;
	CWnd* m_pWnd;
	int glo;
	int row;
	int col;
	CPtrList m_list;
	int direction;
	Apple apple;
	CRect rect;
	int rand1;
	int rand2;
	HICON appicon;
	HICON snaiconhor;
	HICON snaiconver;
	HICON snacorner1;
	HICON snacorner2;
	HICON snacorner3;
	HICON snacorner4;
	HICON headupicon;
	HICON headdownicon;
	HICON headlefticon;
	HICON headrighticon;
	HICON tailupicon;
	HICON taildownicon;
	HICON taillefticon;
	HICON tailrighticon;
	int m_GameOverflag;
	int start;
	int goon;
	int m_difficulty;
	int m_MoveBlank;
	int m_MoveCount;
};

#endif // !defined(AFX_SNAKE_H__348FE5FF_6544_4072_B4A2_752A9B5CF17A__INCLUDED_)
