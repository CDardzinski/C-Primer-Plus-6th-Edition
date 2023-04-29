/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1
#define  PANEL_QUITBUTTON                 2       /* control type: command, callback function: QuitCallback */
#define  PANEL_PRZYKLAD8BUTTON            3       /* control type: command, callback function: Przyklad8ButtonCallback */
#define  PANEL_PRZYKLAD7BUTTON            4       /* control type: command, callback function: Przyklad7ButtonCallback */
#define  PANEL_PRZYKLAD6BUTTON            5       /* control type: command, callback function: Przyklad6ButtonCallback */
#define  PANEL_PRZYKLAD5BUTTON            6       /* control type: command, callback function: Przyklad5ButtonCallback */
#define  PANEL_PRZYKLAD4BUTTON            7       /* control type: command, callback function: Przyklad4ButtonCallback */
#define  PANEL_PRZYKLAD3BUTTON            8       /* control type: command, callback function: Przyklad3ButtonCallback */
#define  PANEL_PRZYKLAD2BUTTON            9       /* control type: command, callback function: Przyklad2ButtonCallback */
#define  PANEL_PRZYKLAD1BUTTON            10      /* control type: command, callback function: Przyklad1ButtonCallback */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Przyklad1ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad2ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad3ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad4ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad5ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad6ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad7ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad8ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif