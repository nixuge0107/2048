#include "windows.h"
#include "includes.h"
#include "GUI.h"
#include "stdio.h"
#include "timer.h"
/*
******************************************************************
**                      uCGUIBuilder                            **
**                  Version:   4.0.0.0                          **
**                     2012 / 04                               **
**                   CpoyRight to: wyl                          **
**              Email:ucguibuilder@163.com                        **
**          This text was Created by uCGUIBuilder               **
******************************************************************/

#include <stddef.h>
#include "GUI.h"
#include "DIALOG.h"

#include "WM.h"
#include "BUTTON.h"
#include "CHECKBOX.h"
#include "DROPDOWN.h"
#include "EDIT.h"
#include "FRAMEWIN.h"
#include "LISTBOX.h"
#include "MULTIEDIT.h"
#include "RADIO.h"
#include "SLIDER.h"
#include "TEXT.h"
#include "PROGBAR.h"
#include "SCROLLBAR.h"
#include "LISTVIEW.h"


#define NUMBER1_1   GUI_ID_USER+1
#define NUMBER2_1   GUI_ID_USER+2
#define NUMBER3_1   GUI_ID_USER+3
#define NUMBER4_1   GUI_ID_USER+4
#define NUMBER1_2   GUI_ID_USER+5
#define NUMBER2_2   GUI_ID_USER+6
#define NUMBER3_2   GUI_ID_USER+7
#define NUMBER4_2   GUI_ID_USER+8
#define NUMBER1_3   GUI_ID_USER+9
#define NUMBER2_3   GUI_ID_USER+10
#define NUMBER3_3   GUI_ID_USER+11
#define NUMBER4_3   GUI_ID_USER+12
#define NUMBER1_4   GUI_ID_USER+13
#define NUMBER2_4   GUI_ID_USER+14
#define NUMBER3_4   GUI_ID_USER+15
#define NUMBER4_4   GUI_ID_USER+16
#define BUTTON_UP   GUI_ID_USER+17
#define BUTTON_LEFT   GUI_ID_USER+18
#define BUTTON_RIGHT   GUI_ID_USER+19
#define BUTTON_DOWN   GUI_ID_USER+20
#define BUTTON_START   GUI_ID_USER+21

extern char datatemp[4];
int stop = 0;
extern int size[4][4];
extern void move_up(void);
extern void move_down(void);
extern void move_left(void);
extern void move_right(void);
extern void button_start(void);
extern void Begin(void);
extern void High_Score(void);
extern int score;
char h_score[4]={0};
char a[4]={0};

void number_show()
{
	WM_HWIN hWin;

	if(size[0][0] !=0)
	{
		
		sprintf(a,"%d",size[0][0]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER1_1),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER1_1),"");
	
	if(size[0][1] !=0)
	{
	
		sprintf(a,"%d",size[0][1]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER2_1),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER2_1),"");
	
	if(size[0][2] !=0)
	{
	
		sprintf(a,"%d",size[0][2]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER3_1),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER3_1),"");
	
	if(size[0][3] !=0)
	{
	
		sprintf(a,"%d",size[0][3]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER4_1),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER4_1),"");
		
	if(size[1][0] !=0)
	{
		
		sprintf(a,"%d",size[1][0]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER1_2),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER1_2),"");
			
	if(size[1][1] !=0)
	{
	
		sprintf(a,"%d",size[1][1]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER2_2),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER2_2),"");
				
	if(size[1][2] !=0)
	{
		
		sprintf(a,"%d",size[1][2]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER3_2),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER3_2),"");
					
	if(size[1][3] !=0)
	{
		
		sprintf(a,"%d",size[1][3]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER4_2),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER4_2),"");
	
	if(size[2][0] !=0)
	{
		
		sprintf(a,"%d",size[2][0]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER1_3),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER1_3),"");
			
	if(size[2][1] !=0)
	{
		
		sprintf(a,"%d",size[2][1]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER2_3),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER2_3),"");
				
	if(size[2][2] !=0)
	{
		
		sprintf(a,"%d",size[2][2]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER3_3),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER3_3),"");
					
	if(size[2][3] !=0)
	{
		
		sprintf(a,"%d",size[2][3]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER4_3),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER4_3),"");
	
	if(size[3][0] !=0)
	{
	
		sprintf(a,"%d",size[3][0]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER1_4),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER1_4),"");
			
	if(size[3][1] !=0)
	{
	
		sprintf(a,"%d",size[3][1]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER2_4),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER2_4),"");
				
	if(size[3][2] !=0)
	{
		
		sprintf(a,"%d",size[3][2]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER3_4),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER3_4),"");
					
	if(size[3][3] !=0)
	{
		
		sprintf(a,"%d",size[3][3]);
	    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER4_4),a);
	}
	else EDIT_SetText(WM_GetDialogItem(hWin,NUMBER4_4),"");
	
	EDIT_SetDecMode(WM_GetDialogItem(hWin,GUI_ID_EDIT1),score,0,9999,0,0);
	
	
}
/*********************************************************************
*
*       Dialog resource
*
* This table conatins the info required to create the dialog.
* It has been created by ucGUIbuilder.
*/

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
    { FRAMEWIN_CreateIndirect,  "Caption",           0,                       0,  0,  320,480,FRAMEWIN_CF_MOVEABLE,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER1_1,               34, 91, 63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER2_1,               95, 91, 63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER3_1,               156,91, 63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER4_1,               215,91, 63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER1_2,               34, 149,63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER2_2,               95, 149,63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER3_2,               156,149,63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER4_2,               215,149,63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER1_3,               34, 208,63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER2_3,               95, 208,63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER3_3,               156,208,63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER4_3,               215,208,63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER1_4,               34, 266,63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER2_4,               95, 266,63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER3_4,               156,266,63, 62, 0,0},
    { EDIT_CreateIndirect,       NULL,               NUMBER4_4,               215,266,63, 62, 0,0},
    { BUTTON_CreateIndirect,    "UP",                BUTTON_UP,               132,334,48, 46, 0,0},
    { BUTTON_CreateIndirect,    "LEFT",              BUTTON_LEFT,             78, 386,48, 46, 0,0},
    { BUTTON_CreateIndirect,    "RIGHT",             BUTTON_RIGHT,            186,386,48, 46, 0,0},
    { BUTTON_CreateIndirect,    "DOWN",              BUTTON_DOWN,             132,386,48, 46, 0,0},
	{ BUTTON_CreateIndirect,    "START",             BUTTON_START,            236,21, 52, 28, 0,0},
    { TEXT_CreateIndirect,      "SCORE:",            GUI_ID_TEXT0,            15, 10, 40, 18, 0,0},
    { TEXT_CreateIndirect,      "HIGH SCORE:",       GUI_ID_TEXT1,            15, 34, 71, 17, 0,0},
	{ EDIT_CreateIndirect,       NULL,               GUI_ID_EDIT1,            54, 10, 47, 20, 0,0},
    { TEXT_CreateIndirect,      "By Wx",             GUI_ID_TEXT2,            229,442,85, 32, 0,0},
	{ EDIT_CreateIndirect,       NULL,               GUI_ID_EDIT2,            86, 26, 47, 20, 0,0}
	
};



/*****************************************************************
**      FunctionName:void PaintDialog(WM_MESSAGE * pMsg)
**      Function: to initialize the Dialog items
**                                                      
**      call this function in _cbCallback --> WM_PAINT
*****************************************************************/

void PaintDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hWin = pMsg->hWin;

}



/*****************************************************************
**      FunctionName:void InitDialog(WM_MESSAGE * pMsg)
**      Function: to initialize the Dialog items
**                                                      
**      call this function in _cbCallback --> WM_INIT_DIALOG
*****************************************************************/

void InitDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hWin = pMsg->hWin;
    //
    //FRAMEWIN
    //
	FRAMEWIN_SetClientColor(hWin,0x808080);
    FRAMEWIN_SetTitleVis(hWin,0);
    //
    //NUMBER1_1
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER1_1),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER1_1),&GUI_FontComic24B_1);
	EDIT_SetText(WM_GetDialogItem(hWin,NUMBER1_1),"");
    //
    //NUMBER2_1
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER2_1),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER2_1),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER2_1),"");
    //
    //NUMBER3_1
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER3_1),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER3_1),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER3_1),"");
    //
    //NUMBER4_1
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER4_1),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER4_1),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER4_1),"");
    //
    //NUMBER1_2
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER1_2),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER1_2),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER1_2),"");
    //
    //NUMBER2_2
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER2_2),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER2_2),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER2_2),"");
    //
    //NUMBER3_2
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER3_2),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER3_2),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER3_2),"");
    //
    //NUMBER4_2
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER4_2),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER4_2),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER4_2),"");
    //
    //NUMBER1_3
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER1_3),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER1_3),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER1_3),"");
    //
    //NUMBER2_3
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER2_3),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER2_3),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER2_3),"");
    //
    //NUMBER3_3
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER3_3),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER3_3),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER3_3),"");
    //
    //NUMBER4_3
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER4_3),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER4_3),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER4_3),"");
    //
    //NUMBER1_4
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER1_4),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER1_4),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER1_4),"");
    //
    //NUMBER2_4
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER2_4),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER2_4),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER2_4),"");
    //
    //NUMBER3_4
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER3_4),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER3_4),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER3_4),"");
    //
    //NUMBER4_4
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,NUMBER4_4),1,0x00d7ff);
    EDIT_SetFont(WM_GetDialogItem(hWin,NUMBER4_4),&GUI_FontComic24B_1);
    EDIT_SetText(WM_GetDialogItem(hWin,NUMBER4_4),"");
    //
    //GUI_ID_TEXT2
    //
    TEXT_SetFont(WM_GetDialogItem(hWin,GUI_ID_TEXT2),&GUI_FontComic24B_1);
	//
    //BUTTON_START
    //
    BUTTON_SetTextColor(WM_GetDialogItem(hWin,BUTTON_START),BUTTON_CI_UNPRESSED,0x0000ff);
    //
    //GUI_ID_EDIT1
    //
    EDIT_SetBkColor(WM_GetDialogItem(hWin,GUI_ID_EDIT1),1,0x808080);
    EDIT_SetMaxLen(WM_GetDialogItem(hWin,GUI_ID_EDIT1),4);
    EDIT_SetDecMode(WM_GetDialogItem(hWin,GUI_ID_EDIT1),0,0,9999,0,0);
	//
    //GUI_ID_EDIT2
    //
	EDIT_SetBkColor(WM_GetDialogItem(hWin,GUI_ID_EDIT2),1,0x808080);
    EDIT_SetMaxLen(WM_GetDialogItem(hWin,GUI_ID_EDIT2),4);
    EDIT_SetDecMode(WM_GetDialogItem(hWin,GUI_ID_EDIT2),0,0,9999,0,0);

}




/*********************************************************************
*
*       Dialog callback routine
*/
static void _cbCallback(WM_MESSAGE * pMsg) 
{
    int NCode, Id;

    WM_HWIN hWin = pMsg->hWin;
    switch (pMsg->MsgId) 
    {
        case WM_PAINT:
            PaintDialog(pMsg);
		
            break;
        case WM_INIT_DIALOG:			
            InitDialog(pMsg);
			
            break;
        case WM_KEY:
            switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) 
            {
                case GUI_KEY_ESCAPE:
                    GUI_EndDialog(hWin, 1);
                    break;
                case GUI_KEY_ENTER:
                    GUI_EndDialog(hWin, 0);
                    break;
            }
            break;
        case WM_NOTIFY_PARENT:
            Id = WM_GetId(pMsg->hWinSrc); 
            NCode = pMsg->Data.v;        
            switch (Id) 
            {
                case GUI_ID_OK:
                    if(NCode==WM_NOTIFICATION_RELEASED)						
                        GUI_EndDialog(hWin, 0);
                    break;
                case GUI_ID_CANCEL:
                    if(NCode==WM_NOTIFICATION_RELEASED)
                        GUI_EndDialog(hWin, 0);
                    break;
				case BUTTON_UP:
					if(NCode==WM_NOTIFICATION_RELEASED)
						move_up();
						delay_ms(30);
					break;
				case BUTTON_DOWN:
					if(NCode==WM_NOTIFICATION_RELEASED)
						move_down();
						delay_ms(30);
					break;
				case BUTTON_LEFT:
					if(NCode==WM_NOTIFICATION_RELEASED)
						move_left();
						delay_ms(30);
					break;
				case BUTTON_RIGHT:
					if(NCode==WM_NOTIFICATION_RELEASED)
						move_right();
						delay_ms(30);
					break;
				case BUTTON_START:
					if(NCode==WM_NOTIFICATION_RELEASED)
					{
						int l;
						if(stop==0)
						{
							for(l=1;l<3;l++)
							{
								button_start();
								EDIT_SetText(WM_GetDialogItem(hWin,GUI_ID_EDIT2),datatemp);
							}
							number_show();
							stop = 1;
							BUTTON_SetText(WM_GetDialogItem(hWin,BUTTON_START),"EXTI");
						}
						else{
							High_Score();
							}
					break;

            }
            break;
        default:
            WM_DefaultProc(pMsg);
    }
}
}


/*********************************************************************
*
*       MainTask
*
**********************************************************************
*/
void Windows() 
{
	NVIC_Configuration();//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	TIM3_Int_Init(100,7199);//10Khz的计数频率，计数到5000为500ms 
    WM_SetDesktopColor(GUI_WHITE);      /* Automacally update desktop window */
    WM_SetCreateFlags(WM_CF_MEMDEV);  /* Use memory devices on all windows to avoid flicker */
    //PROGBAR_SetDefaultSkin(PROGBAR_SKIN_FLEX);
    //FRAMEWIN_SetDefaultSkin(FRAMEWIN_SKIN_FLEX);
    //PROGBAR_SetDefaultSkin(PROGBAR_SKIN_FLEX);
    //BUTTON_SetDefaultSkin(BUTTON_SKIN_FLEX);
    //CHECKBOX_SetDefaultSkin(CHECKBOX_SKIN_FLEX);
    //DROPDOWN_SetDefaultSkin(DROPDOWN_SKIN_FLEX);
    //SCROLLBAR_SetDefaultSkin(SCROLLBAR_SKIN_FLEX);
    //SLIDER_SetDefaultSkin(SLIDER_SKIN_FLEX);
    //HEADER_SetDefaultSkin(HEADER_SKIN_FLEX);
    //RADIO_SetDefaultSkin(RADIO_SKIN_FLEX);
	while(1)
	{
        GUI_ExecDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), &_cbCallback, 0, 0, 0);
	}
}

