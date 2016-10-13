
#include "includes.h"
#include "GUI.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "24cxx.h"
#include "touch.h"
#include "GUI_X.h"
#include "BSP.h"


void BSP_Init()
{	
	
	
	delay_init();	
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600	
	
	SysTick_Init();	

	AT24CXX_Init();                //��ʼ��24C02
	GUI_Init();	
	GUI_X_Init();
	tp_dev.init();								//��ʼ������	
}

void SysTick_Init(void)
{
	SysTick_Config(SystemCoreClock/OS_TICKS_PER_SEC);
}
