// 2048.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

typedef unsigned int   uint16_t;
typedef unsigned char  uint8_t;
typedef int            int16_t;
typedef char           int8_t;

#define  TRUE          1
#define  FALSE         0


void RunGame(void);
void RestartGame(void);

void HandleOprations(char oprations);

void MoveLeft(void);
void MoveRight(void);
//上下即由左右矩阵转置可得。
void MoveUp(void);
void MoveDown(void);

void RefreshDisplay(void);
void RefreshBest(void);

void GenerateANewRandomNum(void);
void JudgeGameOver(void);


int16_t  GetNumOfNull(void);


uint16_t  Grid[4][4] = {0};
uint16_t  Score;
uint16_t  Best;

uint16_t  IsNeedARandom;
uint16_t  IsGameOver;

int _tmain(int argc, _TCHAR* argv[])
{
	RunGame();
	return 0;
}

void RunGame(void)
{
	char Opration;
	RestartGame();



	while (1)
	{

		Opration = _getch();
		if (IsGameOver == TRUE)
		{
			if (Opration == 'y' || Opration == 'Y')
			{
				RestartGame();
				continue;
			}
			else if (Opration == 'n' || Opration == 'N')
			{
				return;
			}
			else
			{
				continue;
			}
		}

		
		IsNeedARandom = FALSE;

		HandleOprations(Opration);
		RefreshBest();
	
		RefreshDisplay();
		
		if (IsNeedARandom)
		{
			GenerateANewRandomNum();
		}

	}

}


void  RestartGame(void)
{
	Score = 0;
	IsNeedARandom = TRUE;
	IsGameOver = FALSE;
	uint16_t  GridX=0;

	srand(time(0));
	GridX= rand() % 16;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Grid[i][j] = (GridX-- == 0 ? 2 : 0);
		}
	}

	GenerateANewRandomNum();
	system("cls");
	RefreshDisplay();

}
 
void HandleOprations(char oprations)
{
	switch (oprations)        // oprations:					  
	{                         //             W->UP 
		case 'a':             //             D->RIGHT
		case 'A':	          //		     S->DOWN
				MoveLeft();   //             A->LIFT
				break;
		case 's':
		case 'S':
				MoveDown();
				break;
		case 'w':
		case 'W':
				MoveUp();
				break;
		case 'd':
		case 'D':
				MoveRight();
				break;
		default :  break;

	}

}

void RefreshBest(void)
{
	Best =Score > Best ? Score : Best;
}

void GenerateANewRandomNum(void )
{
	uint16_t  GridX;
	uint16_t   GridN;
	srand(time(0));
	GridN = GetNumOfNull();
	GridX = GridN ? rand() % GridN : 0;/* To ensure where to Generate a random number */

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Grid[i][j] == 0 && GridX-- == 0) /* Locate the place */
			{
				Grid[i][j] = (rand() % 3 ? 2 : 4);/* Ensure the value 2  or 4 */
				return;
			}
		}
	}
}



void JudgeGameOver(void)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			/* Compare the two elements Horizontally and vertically .If they are the same，Game is not over.*/
			if (Grid[i][j] == Grid[i][j + 1] || Grid[j][i] == Grid[j + 1][i])
			{
				IsGameOver = FALSE;
				return;
			}
		}
	}
	IsGameOver = TRUE;
}


int16_t  GetNumOfNull(void)
{
	int GridN= 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Grid[i][j] == 0 ? GridN++ : 1;
		}
	}
	return GridN;
}




void MoveLeft(void)
{

	for ( int i = 0; i < 4; i++ )
	for (int j = 1, k = 0 ; j < 4; j++)
	{
		if (Grid[i][j] > 0) /* if the Grid aren't NULL*/
		{
			if (Grid[i][k] == Grid[i][j]) /* CASE 1:[i,k] equal to [i,j] ,merge two grids*/
			{
				Score += (Grid[i][k++]<<=1);
				Grid[i][j] = 0;
				IsNeedARandom = TRUE;
				
			}
			else if (Grid[i][k] == 0) /* CASE 2:[i,k] equal to NULL,[i,k] =[i,j]  */
			{
				Grid[i][k] = Grid[i][j];
				Grid[i][j] = 0;
				IsNeedARandom = TRUE;
			}
			else /*CASE 3:[i,k] don't  equal to NULL and don't equal to [i,j] ，[i,k+1] =[i,j]*/
			{
				Grid[i][++k] = Grid[i][j];
				if (j != k) /*if k+1!=j, it need Refresh.*/
				{
					Grid[i][j] = 0;
					IsNeedARandom = TRUE;
				}
			}
		}
	}
  

}
void MoveRight(void)
{
	for (int i = 0; i < 4; i++)
	for (int j = 2, k = 3; j >=0; j--)
	{
		if (Grid[i][j] > 0) /* if the Grid aren't NULL*/
		{
			if (Grid[i][k] == Grid[i][j]) /* CASE 1:[i,k] equal to [i,j] ,merge two grids*/
			{
				Score += (Grid[i][k--] <<= 1);
				Grid[i][j] = 0;
				IsNeedARandom = TRUE;

			}
			else if (Grid[i][k] == 0) /* CASE 2:[i,k] equal to NULL,[i,k] =[i,j]  */
			{
				Grid[i][k] = Grid[i][j];
				Grid[i][j] = 0;
				IsNeedARandom = TRUE;
			}
			else /*CASE 3:[i,k] don't  equal to NULL and don't equal to [i,j] ，[i,k-1] =[i,j]*/
			{
				Grid[i][--k] = Grid[i][j];
				if (j != k) /*if k-1!=j, it need Refresh.*/
				{
					Grid[i][j] = 0;
					IsNeedARandom = TRUE;
				}
			}
		}
	}

}


void MoveUp(void)
{
	for (int i = 0; i < 4; i++)
	for (int j = 1, k = 0; j < 4; j++)
	{
		if (Grid[j][i] > 0) /* if the Grid aren't NULL*/
		{
			if (Grid[k][i] == Grid[j][i]) /* CASE 1:[k,i] equal to [j,i] ,merge two grids*/
			{
				Score += (Grid[k++][i] <<= 1);
				Grid[j][i] = 0;
				IsNeedARandom = TRUE;

			}
			else if (Grid[k][i] == 0) /* CASE 2:[k,i] equal to NULL,[k,i] =[j,i]  */
			{
				Grid[k][i] = Grid[j][i];
				Grid[j][i] = 0;
				IsNeedARandom = TRUE;
			}
			else /*CASE 3:[k,i] don't  equal to NULL and don't equal to [j,i] ，[k+1,i] =[j,i] */
			{
				Grid[++k][i] = Grid[j][i];
				if (j != k) /*if k+1!=j, it need Refresh.*/
				{
					Grid[j][i] = 0;
					IsNeedARandom = TRUE;
				}
			}
		}
	}



}
void MoveDown(void)
{
	for (int i = 0; i < 4; i++)
	for (int j = 2, k = 3; j >=0; j--)
	{
		if (Grid[j][i] > 0) /* if the Grid aren't NULL*/
		{
			if (Grid[k][i] == Grid[j][i]) /* CASE 1:[k,i] equal to [j,i] ,merge two grids*/
			{
				Score += (Grid[k--][i] <<= 1);
				Grid[j][i] = 0;
				IsNeedARandom = TRUE;

			}
			else if (Grid[k][i] == 0) /* CASE 2:[k,i] equal to NULL,[k,i] =[j,i]  */
			{
				Grid[k][i] = Grid[j][i];
				Grid[j][i] = 0;
				IsNeedARandom = TRUE;
			}
			else /*CASE 3:[k,i] don't  equal to NULL and don't equal to [j,i] ，[k-1,i] =[j,i]*/
			{
				Grid[--k][i] = Grid[j][i];
				if (j != k) /*if k-1!=j, it need Refresh.*/
				{
					Grid[j][i] = 0;
					IsNeedARandom = TRUE;
				}
			}
		}
	}


}


void RefreshDisplay(void)
{
	/* 重设光标输出位置方式清屏可以减少闪烁，system("cls")为备用清屏命令，均为Windows平台相关*/
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	printf("\n\n\n\n");
	printf("                  Welcome to catfood's 2048 world!!!!\n");
	printf("                GAME: 2048     SCORE: %06d    BEST: %06d\n", Score, Best);
	printf("             --------------------------------------------------\n\n");

	
	printf("                        ┌──┬──┬──┬──┐\n");
	for (int i = 0; i < 4; i++)
	{
		printf("                        │");
		for (int j = 0; j < 4; j++)
		{
			if (Grid[i][j] != 0)
			{
				if (Grid[i][j] < 10)
				{
					printf("  %d │", Grid[i][j]);
				}
				else if (Grid[i][j] < 100)
				{
					printf(" %d │", Grid[i][j]);
				}
				else if (Grid[i][j] < 1000)
				{
					printf(" %d│", Grid[i][j]);
				}
				else if (Grid[i][j] < 10000)
				{
					printf("%4d│", Grid[i][j]);
				}
				else
				{
					int GridX = Grid[i][j];
					for (int k = 1; k < 20; k++)
					{
						GridX >>= 1;
						if (GridX == 1)
						{
							printf("2^%02d│", k); /* 超过四位的数字用2的幂形式表示，如2^13形式 */
							break;
						}
					}
				}
			}
			else printf("    │");
		}

		if (i < 3)
		{
			printf("\n                        ├──┼──┼──┼──┤\n");
		}
		else
		{
			printf("\n                        └──┴──┴──┴──┘\n");
		}
	}

	printf("\n");
	printf("             --------------------------------------------------\n");
	printf("                            W↑  A←  →D  ↓S");

	if (GetNumOfNull() == 0)
	{
		JudgeGameOver();
		if (IsGameOver) /* 判断是否输掉游戏 */
		{
			printf("\r             Hello,Catfood's Friends ,The Game is over! TRY  AGAIN? [Y / N]");
		}
	}
}