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

#define  PANELROZ4                        1
#define  PANELROZ4_QUITBUTTON             2       /* control type: command, callback function: QuitCallback */
#define  PANELROZ4_CWICZENIE8BUTTON       3       /* control type: command, callback function: Cwiczenie8ButtonCallback */
#define  PANELROZ4_CWICZENIE7BUTTON       4       /* control type: command, callback function: Cwiczenie7ButtonCallback */
#define  PANELROZ4_CWICZENIE6BUTTON       5       /* control type: command, callback function: Cwiczenie6ButtonCallback */
#define  PANELROZ4_CWICZENIE5BUTTON       6       /* control type: command, callback function: Cwiczenie5ButtonCallback */
#define  PANELROZ4_CWICZENIE4BUTTON       7       /* control type: command, callback function: Cwiczenie4ButtonCallback */
#define  PANELROZ4_CWICZENIE3BUTTON       8       /* control type: command, callback function: Cwiczenie3ButtonCallback */
#define  PANELROZ4_CWICZENIE2BUTTON       9       /* control type: command, callback function: Cwiczenie2ButtonCallback */
#define  PANELROZ4_CWICZENIE1BUTTON       10      /* control type: command, callback function: Cwiczenie1ButtonCallback */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Cwiczenie1ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Cwiczenie2ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Cwiczenie3ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Cwiczenie4ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Cwiczenie5ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Cwiczenie6ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Cwiczenie7ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Cwiczenie8ButtonCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif