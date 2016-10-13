
#ifndef __APP_CFG_H__
#define __APP_CFG_H__




/*******************设置任务优先级*******************/

#define STARTUP_TASK_PRIO 3

#define TOUCH_TASK_PRIO 5

#define WINDOWS_TASK_PRIO 6








/************设置栈大小（单位为 OS_STK ）************/

#define STARTUP_TASK_STK_SIZE 256

#define TOUCH_TASK_STK_SIZE 128

#define WINDOWS_TASK_STK_SIZE 4096





#endif
