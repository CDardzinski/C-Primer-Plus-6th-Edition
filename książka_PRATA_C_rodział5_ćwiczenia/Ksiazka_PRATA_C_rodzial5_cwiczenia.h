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
#define  PANEL_PRZYKLAD9                  3       /* control type: command, callback function: Przyklad9Callback */
#define  PANEL_PRZYKLAD8                  4       /* control type: command, callback function: Przyklad8Callback */
#define  PANEL_PRZYKLAD7                  5       /* control type: command, callback function: Przyklad7Callback */
#define  PANEL_PRZYKLAD6                  6       /* control type: command, callback function: Przyklad6Callback */
#define  PANEL_PRZYKLAD5                  7       /* control type: command, callback function: Przyklad5Callback */
#define  PANEL_PRZYKLAD4                  8       /* control type: command, callback function: Przyklad4Callback */
#define  PANEL_PRZYKLAD3                  9       /* control type: command, callback function: Przyklad3Callback */
#define  PANEL_PRZYKLAD2                  10      /* control type: command, callback function: Przyklad2Callback */
#define  PANEL_PRZYKLAD1                  11      /* control type: command, callback function: Przyklad1Callback */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Przyklad1Callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad2Callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad3Callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad4Callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad5Callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad6Callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad7Callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad8Callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad9Callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif