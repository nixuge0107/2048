#include "2048_random.h"
#include "includes.h"
#include "windows.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <conio.h>

#define Random(x) (rand() % x) //通过取余取得指定范围的随机数
extern int size[4][4];

int XY;
int num;

int Random_XY()
{
	int a;
//	srand (time(NULL));   //每次执行种子不同，生成不同的随机数
	a = Random(4);
	XY = a;
	return XY;

}

int Random_number()
{
	int a;
//	srand (time(NULL));     //每次执行种子不同，生成不同的随机数
	a = Random(2);
	a = (a+1)*2;
	num = a;
	return num;
}

void Random_begin()
{
	int a,b,c,d;
	do{
	a = Random_XY();
	b = Random_XY();
	c = Random_XY();
	d = Random_XY();
	}while(a==c&&b==d);
	size[a][b] = Random_number();
	size[c][d] = Random_number();
	number_show();
}

void Random_appear()
{
	int i,j;
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j--)
		{
			if(size[i][j]==0)
			{
				
			}
		}
	}
}
