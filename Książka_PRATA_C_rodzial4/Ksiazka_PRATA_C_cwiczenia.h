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
#define  PANEL_PRZYKLAD4BUTTON            3       /* control type: command, callback function: Przyklad4ButtonCallback */
#define  PANEL_PRZYKLAD3BUTTON_2          4       /* control type: command, callback function: Przyklad3ButtonCallback */
#define  PANEL_PRZYKLAD2BUTTON            5       /* control type: command, callback function: Przyklad2ButtonCallback */
#define  PANEL_PRZYKLAD1BUTTON            6       /* control type: command, callback function: Przyklad1ButtonCallback */
#define  PANEL_PRZYKLAD18BUTTON           7       /* control type: command, callback function: Przyklad18ButtonCallback */
#define  PANEL_PRZYKLAD17BUTTON           8       /* control type: command, callback function: Przyklad17ButtonCallback */
#define  PANEL_PRZYKLAD16BUTTON           9       /* control type: command, callback function: Przyklad16ButtonCallback */
#define  PANEL_PRZYKLAD15BUTTON           10      /* control type: command, callback function: Przyklad15ButtonCallback */
#define  PANEL_PRZYKLAD14BUTTON           11      /* control type: command, callback function: Przyklad14ButtonCallback */
#define  PANEL_PRZYKLAD13BUTTON           12      /* control type: command, callback function: Przyklad13ButtonCallback */
#define  PANEL_PRZYKLAD12BUTTON           13      /* control type: command, callback function: Przyklad12ButtonCallback */
#define  PANEL_PRZYKLAD11BUTTON_2         14      /* control type: command, callback function: Przyklad11ButtonCallback */
#define  PANEL_PRZYKLAD5BUTTON            15      /* control type: command, callback function: Przyklad5ButtonCallback */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Przyklad11ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad12ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad13ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad14ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad15ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad16ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad17ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad18ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad1ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad2ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad3ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad4ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Przyklad5ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif