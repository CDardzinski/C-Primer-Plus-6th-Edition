#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "maszaCW9.h"

static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "maszaCW9.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK QuitCallback (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK MaszaCallback (int panel, int control, int event,
							   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			for(;;){
  	  int num_words=0, flag=0, i=0, k=0;
    char **str=NULL;
    char c='\0';
    char separator[] = " ,/'\\'";

    printf("How many words would you like to write down?\n Number of Words = ");
    fflush(stdin);
    flag = scanf("%d", &num_words);
    if(flag<1 || num_words<=0) return 0;


    str=(char**)malloc(num_words*sizeof(char*));
    if(!str) return 0;
    printf("Please type the sequence of words, separated by one of the following separators: space, comma, /, \\ \n");




    for(i=0;i<num_words;i++){
    k=0;
    do{
        c=getchar();
    }while(strchr(separator, c) && c!='\n' && c!='\0');

    str[i]=(char*)malloc(1*sizeof(char));
    if(!str[i]) return 0;

    do{

    *(*(str+i)+k)=c;
    k++;
    str[i] = (char*)realloc(str[i],k+1);
    }while((c=getchar())!='\n' && !strchr(separator, c));
    *(*(str+i)+k)='\0';

    }


    printf("\nHere is the full list of words:\n");
    for(i=0;i<num_words;i++)
    {
        printf("%s\n", str[i]);
    }
    for(i=0;i<num_words;i++)
    {
        free(str[i]);
    }
    free(str);

}

			break;
	}
	return 0;
}
