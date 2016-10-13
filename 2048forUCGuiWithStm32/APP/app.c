#include "includes.h"
#include "GUI.h"
#include "app_cfg.h"
#include "app.h"
#include "bsp.h"
#include "windows.h"


/********************ϵͳ��ջ**********************************/

OS_STK WINDOWS_Task_Stk[WINDOWS_TASK_STK_SIZE];		         //����ջ	
OS_STK TOUCH_Task_Stk[TOUCH_TASK_STK_SIZE];		         //����ջ

/********************��������**********************************/

void Task_STARTUP(void *p_arg);
static void Task_Create(void);
void Task_WINDOWS(void *p_arg);
void Task_TOUCH(void *p_arg);





void Task_STARTUP(void *p_arg)
{
	(void)p_arg; 
	Task_Create();
	while(1)
	{
		delay_ms(50);
	}
}


static void Task_Create(void)
{	   
	 

	OSTaskCreate(Task_WINDOWS,(void *)0,&WINDOWS_Task_Stk[WINDOWS_TASK_STK_SIZE-1], WINDOWS_TASK_PRIO);   //���������
	OSTaskCreate(Task_TOUCH,(void *)0,&TOUCH_Task_Stk[TOUCH_TASK_STK_SIZE -1], TOUCH_TASK_PRIO);   //����������
 	
   //while(1);	
}


void Task_TOUCH(void *p_arg)
{
	(void)p_arg; // 'p_arg' ��û���õ�����ֹ��������ʾ����

	while(1)
	{
		GUI_TOUCH_Exec();
		delay_ms(5);
//		 GUI_Exec();
	}

}




void Task_WINDOWS(void *p_arg)
{

	Windows();	

} 



