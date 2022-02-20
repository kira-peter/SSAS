// Snake.cpp: implementation of the CSnake class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StarrySkyAndSnake.h"
#include "Snake.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSnake::CSnake()
{
	row = 32;
	col = 32;
	m_GameOverflag = 0;
	start = 0;
	direction = 4;
	m_difficulty = 1;
	m_MoveBlank = 4;
	m_MoveCount = 0;
	m_UnDead = false;
	goon = 0;
	Add(32,32);
	srand((unsigned int)time(0));
	apple.m=(rand()%30)*16;
	apple.n=(rand()%30)*16;
}

CSnake::~CSnake()
{

}
void CSnake::Move(CDC *pDC){
	if (start)
	{
		levelUp();
		GameOver();
		if(ShouldMove()){
			GameGoOn(pDC);
			return;
		}
		Show(pDC);
	}
}

void CSnake::levelUp()
{
	switch(m_difficulty){
		case 0:
			switch (m_list.GetCount())
			{
			case 5:
				m_MoveBlank = 8;
				break;
			case 15:
				m_MoveBlank = 6;
				break;
			case 20:
				m_MoveBlank = 5;
				break;
			case 25:
				m_MoveBlank = 4;
				break;
			case 30:
				m_MoveBlank = 3;
				break;
			case 35:
				m_MoveBlank = 1;
				break;
			case 40:
				m_MoveBlank = 0;
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,60,NULL);
				break;
			case 45:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,40,NULL);
				break;
			case 50:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,20,NULL);
				break;
			case 55:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,10,NULL);
				break;
			case 60:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,5,NULL);
				break;
			case 65:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,1,NULL);
				break;
			}
			break;
		case 1:
			switch (m_list.GetCount())
			{
			case 5:
				m_MoveBlank = 5;
				break;
			case 15:
				m_MoveBlank = 3;
				break;
			case 20:
				m_MoveBlank = 2;
				break;
			case 25:
				m_MoveBlank = 1;
				break;
			case 30:
				m_MoveBlank = 0;
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,80,NULL);
				break;
			case 35:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,60,NULL);
				break;
			case 40:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,40,NULL);
				break;
			case 45:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,20,NULL);
				break;
			case 50:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,10,NULL);
				break;
			case 55:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,5,NULL);
				break;
			case 60:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,3,NULL);
				break;
			case 65:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,1,NULL);
				break;
			}
			break;	
		case 2:
			switch (m_list.GetCount())
			{
			case 5:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,60,NULL);
				break;
			case 15:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,50,NULL);
				break;
			case 20:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,40,NULL);
				break;
			case 25:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,30,NULL);
				break;
			case 30:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,20,NULL);
				break;
			case 35:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,10,NULL);
				break;
			case 40:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,5,NULL);
				break;
			case 45:
				m_pWnd->KillTimer(1);
				m_pWnd->SetTimer(1,1,NULL);
				break;
			}
			break;		
	}
}

void CSnake::GameOver()
{
	if(m_UnDead && !m_UnDeadGameOver) return;
	m_pWnd->GetWindowRect(&rect);
	POSITION pos = m_list.GetHeadPosition();
	for (int i = 0;i<m_list.GetCount()-1;i++)
	{
		nodep L = (nodep) m_list.GetNext(pos);
		if (L->a==col&&L->b==row)
		{
			m_GameOverflag = 1;
			break;
		}
	}
	if (row > rect.bottom/16*16 || col>rect.right/16*16||col<0||row<0|| m_GameOverflag || m_UnDeadGameOver)
	{
		//m_pWnd->KillTimer(1);
		CString s;
		s.Format("%d",m_list.GetCount());
		s = "\n\n你最后的得分是：" + s;
		s = "GAME OVER !" + s;
		row = 0;
		col = 0;
		direction = 4;
		m_list.RemoveAll();
		Add(32,32);
		srand((unsigned int)time(0));
		apple.m=(rand()%10)*16;
		apple.n=(rand()%10)*16;
		glo=0;
		m_GameOverflag = 0;
		m_UnDeadGameOver = 0;
		start = 0;
		goon=1;
		AfxMessageBox(s);
	}
}
void CSnake::SetpWnd(CWnd *pWnd){
	m_pWnd = pWnd;
}
void CSnake::GameGoOn(CDC* pDC)
{
	if(goon==0){
		m_pWnd->GetClientRect(&rect);
		rand1 = rect.Width()/16-2;
		rand2 = rect.Height()/16-2;
		if (glo == 0) {
			switch (direction){
			case 1: {
				row-=16;
				if (row<16)
				{
					break;
				}
				Add(row,col);
				if (row!=apple.n||col!=apple.m)
				{
					m_list.RemoveHead();
				}
				else {
					apple.m=(rand()%rand1)*16;
					apple.n=(rand()%rand2)*16;
				}
				Show(pDC);
				break;
					}
			case 2: {
				col-=16;
				if (col<0)
				{
					break;
				}
				Add(row,col);
				if (row!=apple.n||col!=apple.m)
				{
					m_list.RemoveHead();
				}
				else {
					apple.m=(rand()%rand1)*16;
					apple.n=(rand()%rand2)*16;
				}
				Show(pDC);
				break;
					}
			case 3: {
				col+=16;
				if (col>rect.Width()-25)
				{
					break;
				}
				Add(row,col);
				if (row!=apple.n||col!=apple.m)
				{
					m_list.RemoveHead();
				}
				else {
					apple.m=(rand()%rand1)*16;
					apple.n=(rand()%rand2)*16;
				}
				Show(pDC);
				break;
					}
			case 4: {
				row+=16;
				if (row>rect.Height()-41)
				{
					break;
				}
				Add(row,col);
				if (row!=apple.n||col!=apple.m)
				{
					m_list.RemoveHead();
				}
				else {
					apple.m=(rand()%rand1)*16;
					apple.n=(rand()%rand2)*16;
				}
				Show(pDC);
				break;
					}
			default:break;
			}
		}
		else switch(glo){
			case 1:
				if (direction != 4){
					direction = 1;
					row-=16;
					Add(row,col);
					if (row!=apple.n||col!=apple.m)
					{
						m_list.RemoveHead();
					}
					else {
						apple.m=(rand()%rand1)*16;
						apple.n=(rand()%rand2)*16;
					}
					Show(pDC);
					break;
				}
				glo = 0;
				break;
			case 2:
				if ( direction != 3){
					direction = 2;
					glo = 0;
					col-=16;
					Add(row,col);
					if (row!=apple.n||col!=apple.m)
					{
						m_list.RemoveHead();
					}
					else {
						apple.m=(rand()%rand1)*16;
						apple.n=(rand()%rand2)*16;
					}
					Show(pDC);
					break;
				}
				glo = 0;
				break;
			case 3:
				if (direction != 2 ){
					direction = 3;
					col+=16;
					Add(row,col);
					if (row!=apple.n||col!=apple.m)
					{
						m_list.RemoveHead();
					}
					else {
						apple.m=(rand()%rand1)*16;
						apple.n=(rand()%rand2)*16;
					}
					Show(pDC);
					break;
				}
				glo = 0;
				break;
			case 4:
				if (direction != 1){
					direction = 4;
					row+=16;
					Add(row,col);
					if (row!=apple.n||col!=apple.m)
					{
						m_list.RemoveHead();
					}
					else {
						apple.m=(rand()%rand1)*16;
						apple.n=(rand()%rand2)*16;
					}
					Show(pDC);
					break;
				}
				glo = 0;
				break;
			default:break;
		}
	}
}

void CSnake::Show(CDC *pDC)
{
	POSITION pos = m_list.GetHeadPosition();
	for (int i = 0;i<m_list.GetCount();i++)
	{
		int BodyFlag;			//蛇身标志
		int TailFlag;			//蛇尾标志
		int CornerFlag = 0;		//拐角标志
		nodep L,L1,L3;
		L = (nodep) m_list.GetAt(pos);
		m_list.GetNext(pos);

		if (pos != NULL)
		{
			if (i==0 || (i==1 && m_list.GetCount()<3)){		//如果 是末尾元素 就直接跳过 拐角标志的判断				
				L1 = (nodep) m_list.GetAt(pos);				//如果 是倒数第二个元素 还要判断总长度是否大于3 小于3 也直接跳过
			} 
			else{											//做拐角标志的判断
				(nodep) m_list.GetPrev(pos);
				(nodep) m_list.GetPrev(pos);
				L3 = (nodep) m_list.GetAt(pos);
				(nodep) m_list.GetNext(pos);
				(nodep) m_list.GetNext(pos);
				L1 = (nodep) m_list.GetAt(pos);
				if ((L1->a>L3->a&&L1->b>L3->b&&L->a==L3->a)||(L1->a<L3->a&&L1->b<L3->b&&L->a==L1->a)){
					CornerFlag=1;
				}
				if ((L1->a>L3->a&&L1->b<L3->b&&L->a==L1->a)||(L1->a<L3->a&&L1->b>L3->b&&L->a==L3->a)){
					CornerFlag=2;
				}
				if ((L1->a>L3->a&&L1->b>L3->b&&L->a==L1->a)||(L1->a<L3->a&&L1->b<L3->b&&L->a==L3->a)){
					CornerFlag=3;
				}
				if ((L1->a>L3->a&&L1->b<L3->b&&L->a==L3->a)||(L1->a<L3->a&&L1->b>L3->b&&L->a==L1->a)){
					CornerFlag=4;
				}
			}
			if (L->b==L1->b&&L->a>L1->a){				//蛇身 蛇尾 标志判断
				BodyFlag=1;
				TailFlag=1;
			} 
			if (L->b==L1->b&&L->a<L1->a){
				BodyFlag=1;
				TailFlag=2;
			} 
			if (L->b>L1->b&&L->a==L1->a){
				BodyFlag=0;
				TailFlag=3;
			} 
			if (L->b<L1->b&&L->a==L1->a){
				BodyFlag=0;
				TailFlag=4;
			} 
		}
		if (i==0&&m_list.GetCount()!=1){	//元素个数大于1 画蛇尾
			switch (TailFlag)
			{
			case 3:pDC->DrawIcon(L->a,L->b,tailupicon);
				break;
			case 1:pDC->DrawIcon(L->a,L->b,taillefticon);
				break;
			case 2:pDC->DrawIcon(L->a,L->b,tailrighticon);
				break;
			case 4:pDC->DrawIcon(L->a,L->b,taildownicon);
				break;
			}
		}
		else if((i == m_list.GetCount()-1&&m_list.GetCount()>=1)){ //元素个数大于1 画蛇头 以方向为标志
			switch (direction)
			{
			case 1:pDC->DrawIcon(L->a,L->b,headupicon);
				break;
			case 2:pDC->DrawIcon(L->a,L->b,headlefticon);
				break;
			case 3:pDC->DrawIcon(L->a,L->b,headrighticon);
				break;
			case 4:pDC->DrawIcon(L->a,L->b,headdownicon);
				break;
			}
		}
		else{
			if (CornerFlag==0){			//无拐角标志 绘制蛇身
				if (BodyFlag==1)
					pDC->DrawIcon(L->a,L->b,snaiconhor);
				else
					pDC->DrawIcon(L->a,L->b,snaiconver);
			} 
			else{						//有拐角标志 绘制拐角
				switch(CornerFlag){
				case 1:
					pDC->DrawIcon(L->a,L->b,snacorner1);
					break;
				case 2:
					pDC->DrawIcon(L->a,L->b,snacorner2);
					break;
				case 3:
					pDC->DrawIcon(L->a,L->b,snacorner3);
					break;
				case 4:
					pDC->DrawIcon(L->a,L->b,snacorner4);
					break;
				}
				CornerFlag=0;
			}	
		}
	}
	pDC->DrawIcon(apple.m,apple.n,appicon);	//绘制苹果
}

void CSnake::Add(int x, int y)
{
	nodep p = new node;
	p->a = y;
	p->b = x;
	m_list.AddTail(p);
}

void CSnake::InitSanke()
{
	appicon = AfxGetApp()->LoadIcon(IDI_APPLE);
	snaiconhor = AfxGetApp()->LoadIcon(IDI_SNAKEhorizontal);
	snaiconver = AfxGetApp()->LoadIcon(IDI_SNAKEvertical);
	snacorner1 = AfxGetApp()->LoadIcon(IDI_SNAKEcorner1);
	snacorner2 = AfxGetApp()->LoadIcon(IDI_SNAKEcorner2);
	snacorner3 = AfxGetApp()->LoadIcon(IDI_SNAKEcorner3);
	snacorner4 = AfxGetApp()->LoadIcon(IDI_SNAKEcorner4);
	headupicon = AfxGetApp()->LoadIcon(IDI_SNAKEHEADup);
	headdownicon = AfxGetApp()->LoadIcon(IDI_SNAKEHEADdown);
	headlefticon = AfxGetApp()->LoadIcon(IDI_SNAKEHEADleft);
	headrighticon = AfxGetApp()->LoadIcon(IDI_SNAKEHEADright);
	tailupicon = AfxGetApp()->LoadIcon(IDI_SNAKETAILup);
	taildownicon = AfxGetApp()->LoadIcon(IDI_SNAKETAILdown);
	taillefticon = AfxGetApp()->LoadIcon(IDI_SNAKETAILleft);
	tailrighticon = AfxGetApp()->LoadIcon(IDI_SNAKETAILright);
}

void CSnake::Veer(UINT direction)
{
	switch (direction)
	{
	case VK_UP: glo = 1;break;
	case VK_LEFT: glo = 2;break;
	case VK_RIGHT: glo = 3;break;
	case VK_DOWN: glo = 4;break;
	case VK_BACK: m_UnDeadGameOver = 1;break;
	default:break;
	}
}

void CSnake::SetGameDifficulty(int difficulty)
{
	m_difficulty = difficulty;
	switch(m_difficulty){
		case 0:
			m_MoveBlank = 8;
			break;
		case 1:
			m_MoveBlank = 4;
			break;
		case 2:
			m_MoveBlank = 0;
	}
}

int CSnake::GetGameDifficulty()
{
	return m_difficulty;
}

void CSnake::GameStart()
{
	SetMoveRect();
	start = TRUE;
	m_UnDeadGameOver = 0;
	goon = 0;
}

bool CSnake::ShouldMove()
{
	if(++m_MoveCount>=m_MoveBlank)
		m_MoveCount = 0;
	return !m_MoveCount;
}

void CSnake::SetMoveRect()
{
	RECT rect = {0};
	AfxGetMainWnd()->GetClientRect(&rect);
	m_rect.left = m_rect.top = 16;
	m_rect.right = rect.right/16*16;
	m_rect.bottom = rect.bottom/16*16;
}

void CSnake::SetUnDead(bool UnDead)
{
	m_UnDead = UnDead;
	m_UnDeadGameOver = 0;
}

bool CSnake::GetUndead()
{
	return m_UnDead;
}

void CSnake::EndGame()
{
	m_GameOverflag = 0;
}
