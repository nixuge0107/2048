
#include "includes.h"



static OS_STK startup_task_stk[STARTUP_TASK_STK_SIZE]; 

 int main(void)
 {	
	BSP_Init();
	OSInit();
	OSTaskCreate(Task_STARTUP,(void *)0, &startup_task_stk[STARTUP_TASK_STK_SIZE-1], STARTUP_TASK_PRIO);
	OSStart();
	return 0;
 }


