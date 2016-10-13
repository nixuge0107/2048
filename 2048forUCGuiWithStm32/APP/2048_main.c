#include "2048_main.h"
#include "windows.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "app.h"
#include "includes.h"

#include "spi.h"
#include "flash.h"

#define Random(x) (rand() % x) //通过取余取得指定范围的随机数
extern int random_number;
extern void number_show(void);
char datatemp[4];

#define SIZE sizeof(TEXT_Buffer)
char TEXT_Buffer[4]={0,0};
u32 FLASH_SIZE;

int size[4][4]={0};
int score;
int highscore;
int change = 0;
int temp[5]={0};
int Num=0;
int i,j;

int Move()
{
	int k,t;
	for(t=3;t>=0;t--)
	{
		for(k=0;k<=3;k++)
		{
			if(temp[k]==0)
			{
				temp[k] = temp[k+1];
				temp[k+1] = 0;
								
			}
		}
	}

	for(k=1;k<=3;k++)
	{
		if(temp[k]==temp[k-1])
		{
			temp[k-1] = 2*temp[k];
			temp[k] = 0;
			score += temp[k-1];
			
		}
	}
	for(t=2;t>=0;t--)
	{
		for(k=0;k<=3;k++)
		{
			if(temp[k]==0)
			{
				temp[k] = temp[k+1];
				temp[k+1] = 0;
			}
		}
	}
	return(change);
}

int Get_null_number()
{
	int i,j;
	int null_num = 0;
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	{
		size[i][j]==0 ? null_num++ : 1;
	}
}
	return null_num;
}


void Get_new_number()
{
	int  null_num;
	int  x_num;
	int i,j;
	srand (random_number);   //每次执行种子不同，生成不同的随机数
	null_num = Get_null_number();
	x_num = null_num ? Random(null_num) : 0;
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	{
		if(size[i][j]==0 && x_num--==0)
		{
			size[i][j] = Random(4)==0 ? 4 :2;
		}
	}
}
	
}


void Begin()
{
//	srand (random_number);   //每次执行种子不同，生成不同的随机数


	Get_new_number();

	
	if(Get_null_number()==0)
		GUI_MessageBox("Game Over","Notice",GUI_MESSAGEBOX_CF_MOVEABLE);
	
	number_show();

}

void button_start()
{
	int a,b;

	FLASH_SIZE=8*1024*1024;	//FLASH 大小为8M字节
	SPI_Flash_Init();  		//SPI FLASH 初始化
	SPI_Flash_Read(datatemp,FLASH_SIZE-100,4);				//从倒数第100个地址处开始,读出SIZE个字节


	
	do
	{
		a = Random(4);
		b = Random(4);
	}while(size[a][b]!=0);
	
	if(Random(4)==0)
		size[a][b] = 4;
	else 
		size[a][b] = 2;
}


void High_Score()
{

//	highscore = score > highscore ? score : highscore;
	highscore = score ;
	sprintf(TEXT_Buffer,"%d",highscore);

	SPI_Flash_Write((u8*)TEXT_Buffer,FLASH_SIZE-100,4);		//从倒数第100个地址处开始,写入SIZE长度的数据
	
}

//void move_up()
//{
//	int i,j,k = 0;
//	for(j=0;j<4;j++)
//	{
//	for(i=1;i<4;i++)
//		{
//			if(size[i][j]>0)
//			{
//				
//				if(size[k][j]==size[i][j])
//				{
//					size[k++][j] = size[i][j] *2;
//					size[i][j] = 0;
//					change = 1;
//					
//				}
//				else if(size[k][j]==0)
//				{
//					size[k][j] = size[i][j];
//					size[i][j] = 0;
//					change = 1;
//				}				
//				else
//				{
//					size[++k][j] = size[i][j];
//					if(k!=i)
//					{
//						size[i][j] = 0;
//						change = 1;
//					}
//				}
//				
//			}
//		}
//	}
//	number_show();
//}

//void move_down()
//{
//	int i,j,k = 3;
//	for(j=0;j<4;j++)
//	{
//	for(i=1;i<4;i++)
//		{
//			if(size[3-i][j]>0)
//			{
//				if(size[k][j]==size[3-i][j])
//				{
//					size[k--][j] = size[3-i][j] *2;
//					size[3-i][j] = 0;
//					
//				}				
//				else if(size[k][j]==0)
//				{
//					size[k][j] = size[3-i][j];
//					size[3-i][j] = 0;
//				}
//				else
//				{
//					size[--k][j] = size[3-i][j];
//					if(k!=3-i)
//					{
//						size[3-i][j] = 0;
//					}
//				}
//				change = 1;
//			}
//		}
//	}
//	Begin();
//}

//void move_left()
//{
//	int i,j,k = 0;
//	for(i=0;i<4;i++)
//	{
//	for(j=1;j<4;j++)
//		{
//			if(size[i][j]>0)
//			{
//				if(size[i][k]==0)
//				{
//					size[i][k] = size[i][j];
//					size[i][j] = 0;
//				}
//				else if(size[i][k]==size[i][j])
//				{
//					size[i][k++] = size[i][j] *2;
//					size[i][j] = 0;
//					
//				}				
//				else
//				{
//					size[i][++k] = size[i][j];
//					if(k!=j)
//					{
//						size[i][j] = 0;
//					}
//				}
//				change = 1;
//			}
//		}
//	}
//	Begin();
//}

//void move_right()
//{
//	int i,j,k = 3;
//	for(i=0;i<4;i++)
//	{
//	for(j=1;j<4;j++)
//		{
//			if(size[i][3-j]>0)
//			{
//				if(size[i][k]==0)
//				{
//					size[i][k] = size[i][3-j];
//					size[i][3-j] = 0;
//				}
//				else if(size[i][k]==size[i][3-j])
//				{
//					size[i][k--] = size[i][3-j] *2;
//					size[i][3-j] = 0;
//					
//				}				
//				else
//				{
//					size[i][--k] = size[i][3-j];
//					if(k!=3-j)
//					{
//						size[i][3-j] = 0;
//					}
//				}
//				change = 1;
//			}
//		}
//	}
//	Begin();
//}


void move_up()
{
	for(j=0;j<=3;j++)
	{
		for(i=0;i<=3;i++)
		{
			temp[i] = size[i][j];
		}	
		temp[4] = 0;

		Move();
		for(i=0;i<=3;i++)
		{
			size[i][j] = temp [i];
		}
		
	}
	Begin();
}

void move_down()
{
	for(j=0;j<=3;j++)
	{
		for(i=0;i<=3;i++)
		{
			temp[i] = size[3-i][j];	

		}
		temp[4] = 0;
		Move();
		for(i=0;i<=3;i++)
		{
			size[3-i][j] = temp[i];
		}
	}
	Begin();
}

void move_left()
{
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			temp[j] = size[i][j];
		}
		temp[4] = 0;
		Move();
		for(j=0;j<=3;j++)
		{
			size[i][j] = temp[j];
		}
	}
	Begin();
}

void move_right()
{
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			temp[j] = size[i][3-j];	

		}
		temp[4] = 0;
		Move();
		for(j=0;j<=3;j++)
		{
			size[i][3-j] = temp [j];
		}
	}
	Begin();
}

