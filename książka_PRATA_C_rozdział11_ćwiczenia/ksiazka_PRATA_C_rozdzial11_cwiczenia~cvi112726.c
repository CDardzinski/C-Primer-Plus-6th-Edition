#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial11_cwiczenia.h"

#define ROZMIAR_LANCUCHA 260

/////do cwiczenia 1
int PobierzIPrzekarz(char *TablicaDocelowa);
///////////////////////////

/////do cwiczenia 2
int PobierzIPrzekarz2(char *TablicaDocelowa);
///////////////////////////

/////do cwiczenia 3
int PobierzIPrzekarz3(char *TablicaDocelowa);
///////////////////////////

/////do cwiczenia 4
int PobierzIPrzekarz4(char *TablicaDocelowa, int liczbaZnakow);
///////////////////////////

/////do cwiczenia 5
char *PobierzIPrzekarz5(char *TablicaDocelowa, char okreslonyZnakow);
///////////////////////////

/////do cwiczenia 6
int znajduje_sie_w(char znak, char *wskaznikLancucha);
///////////////////////////

/////do cwiczenia 7
int kopiujlanuch(char wskaznikZrodla1[], char wskaznikCelu2[], int liczbaZnakow);
///////////////////////////

/////do cwiczenia 8
char *zawiera_lan(char *wskaznikZrodla, char *wskaznikaSzukanego);
///////////////////////////

static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial11_cwiczenia.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 1 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	char OtrzymanyLanuch[ROZMIAR_LANCUCHA];
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wpisz ciag znakow\n");
			PobierzIPrzekarz(OtrzymanyLanuch);
			puts(OtrzymanyLanuch);			

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 2 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char OtrzymanyLanuch[ROZMIAR_LANCUCHA];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Wpisz ciag znakow\n");
			PobierzIPrzekarz2(OtrzymanyLanuch);
			puts(OtrzymanyLanuch);	

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 3 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char OtrzymanyLanuch[ROZMIAR_LANCUCHA];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Wpisz ciag znakow\n");
			PobierzIPrzekarz3(OtrzymanyLanuch);
			puts(OtrzymanyLanuch);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 4 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char OtrzymanyLanuch[ROZMIAR_LANCUCHA];
	int liczbaZnakow = 0;
	char znak;
	
	switch (event)
	{
		case EVENT_COMMIT:		
	
			puts("Ile znakow ma przyjac lancuch?");
			scanf("%d", &liczbaZnakow);
			printf("Wpisz ciag znakow\n");
			PobierzIPrzekarz4(OtrzymanyLanuch, liczbaZnakow);
			puts(OtrzymanyLanuch);
			
			do
			{
				znak = getchar();
			}while (znak != '\n');
			

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 5 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char OtrzymanyLanuch[ROZMIAR_LANCUCHA];
	char okreslonyZnakow;
	char znak;
	char *znaleziony;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			puts("Jaki znak wyszukac?");
			scanf("%c", &okreslonyZnakow);
			printf("Wpisz ciag znakow\n");
			
			do
			{
				znak = getchar();
			}while (znak != '\n');
			
			znaleziony = PobierzIPrzekarz5(OtrzymanyLanuch, okreslonyZnakow);
			//puts(OtrzymanyLanuch);
			printf("%s", znaleziony);
			//puts(znaleziony);
			
			do
			{
				znak = getchar();
			}while (znak != '\n');

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 6 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char OtrzymanyLanuch[ROZMIAR_LANCUCHA];
	char okreslonyZnakow;
	char znak;
	char *znaleziony;
	int odnaleziony;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			puts("Jaki znak wyszukac?");
			scanf("%c", &okreslonyZnakow);
			printf("Wpisz ciag znakow\n");
			
			do
			{
				znak = getchar();
			}while (znak != '\n');
			
			fgets(OtrzymanyLanuch, ROZMIAR_LANCUCHA, stdin);
			
			for(int i = 0; i < strlen(OtrzymanyLanuch); i++)	
			{
			 	odnaleziony = znajduje_sie_w(okreslonyZnakow, OtrzymanyLanuch+i);
				if(odnaleziony) 
				{
					printf("Odnelezniono szukany znak w lancuchu");
					break;
				}
			}
			if(!odnaleziony) 
				printf("Nie odnelezniono szukanego znak w lancuchu");
			
			do
			{
				znak = getchar();
			}while (znak != '\n');

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 7 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int liczbaZnakow;
	char lancuchs2[ROZMIAR_LANCUCHA], lancuchs1[ROZMIAR_LANCUCHA];
	char znak;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			puts("Ile znakow ma zostac przepisanych z lancuch 1 do lancucha 2?");
			scanf("%d", &liczbaZnakow);
			do
			{
				znak = getchar();
			}while (znak != '\n');
			
			printf("Wpisz ciag znakow\n");
			fgets(lancuchs1, ROZMIAR_LANCUCHA, stdin);
			
			kopiujlanuch(lancuchs1, lancuchs2, liczbaZnakow);
			
			puts(lancuchs1);
			puts(lancuchs2);	
			
			do
			{
				znak = getchar();
			}while (znak != '\n');

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 8 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char OtrzymanyLanuch[ROZMIAR_LANCUCHA];
	char okreslonyZnakow[ROZMIAR_LANCUCHA];
	char *znaleziony, znak;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			puts("Jaki ciag znakow wyszukac?");
			scanf("%s", okreslonyZnakow);
			
			do
			{
				znak = getchar();
			}while (znak != '\n');
			
			printf("Wpisz ciag znakow\n");
			fgets(OtrzymanyLanuch, ROZMIAR_LANCUCHA, stdin);
			
	/*		do
			{
				znak = getchar();
			}while (znak != '\n');
	*/
			znaleziony = zawiera_lan(OtrzymanyLanuch, okreslonyZnakow);
			printf("%s", znaleziony);
			/*
			znaleziony = PobierzIPrzekarz5(OtrzymanyLanuch, okreslonyZnakow);
			//puts(OtrzymanyLanuch);
			
			//puts(znaleziony);
			*/
			
			do
			{
				znak = getchar();
			}while (znak != '\n');

			break;
	}
	return 0;
}

//////////////Wyjœcie
int CVICALLBACK QuitCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}
////////funkcje do æwiczenia 1
int PobierzIPrzekarz(char *TablicaDocelowa)
{
	fgets(TablicaDocelowa, ROZMIAR_LANCUCHA, stdin);
	
	return 0;
}
////////funkcje do æwiczenia 2
int PobierzIPrzekarz2(char *TablicaDocelowa)
{
	char temp[ROZMIAR_LANCUCHA];
	int i = 0;
	
	fgets(temp, ROZMIAR_LANCUCHA, stdin);
	for(i = 0; temp[i] != ' ' && temp[i] != '\t' && temp[i] != '\n'; i++)
		TablicaDocelowa[i] = temp[i];
	TablicaDocelowa[i] = '\0';
	
	return 0;
}

////////funkcje do æwiczenia 3
int PobierzIPrzekarz3(char *TablicaDocelowa)
{
	char znak;
	int i = 0;
	
	for(int n = 0; n < strlen(TablicaDocelowa); n++)
		TablicaDocelowa[n] = 0;
	
	do
	{
		znak = getchar();
		if(isspace(znak) && i == 0)
				continue;
		else
		{
			TablicaDocelowa[i] = znak;
			i++;
		}
		
		if(isspace(znak) && i > 0) 
			while (znak != '\n')
				znak = getchar();
				
	}while (znak != '\n');
	
	TablicaDocelowa[i] = '\0';
	
	return 0;
}

////////funkcje do æwiczenia 4
int PobierzIPrzekarz4(char *TablicaDocelowa, int liczbaZnakow)
{
	char znak;
	int i = 0;
	
	do
	{
		znak = getchar();
		
		if(isspace(znak))
			continue;
		else 
		{
			TablicaDocelowa[i] = znak;
			i++;
			liczbaZnakow--;
		}
		
	}while(liczbaZnakow);
	
	TablicaDocelowa[i] = '\0';
	return 0;
}
////////funkcje do æwiczenia 5
char *PobierzIPrzekarz5(char *TablicaDocelowa, char okreslonyZnakow)
{
	char *znalezionyZnak;
	
	fgets(TablicaDocelowa, ROZMIAR_LANCUCHA, stdin);
	
	for(int i  = 0; i < strlen(TablicaDocelowa); i++)
		if(TablicaDocelowa[i] == okreslonyZnakow)
		{
			znalezionyZnak = &TablicaDocelowa[i];
			break;
		}
		else
			znalezionyZnak = NULL;

	
	//znalezionyZnak =  strchr(TablicaDocelowa, okreslonyZnakow);
	
	return znalezionyZnak;
}
////////funkcje do æwiczenia 6
int znajduje_sie_w(char znak, char *wskaznikLancucha)
{	
	return (znak == wskaznikLancucha[0]) ? 1 : 0;
}
////////funkcje do æwiczenia 7
int kopiujlanuch(char wskaznikZrodla1[], char wskaznikCelu2[], int liczbaZnakow)
{
	int i;
	
	for(i = 0; i < liczbaZnakow; i++)
		wskaznikCelu2[i] = wskaznikZrodla1[i];	
	
	wskaznikCelu2[i] = '\0';
	return 0;
}
////////funkcje do æwiczenia 8
char *zawiera_lan(char *wskaznikZrodla, char *wskaznikaSzukanego)
{
	char *wskaznikZnalezionego;
	int i, n;
	
	for(i = 0; i < strlen(wskaznikZrodla); i++)
	{
		if(wskaznikZrodla[i] == wskaznikaSzukanego[0])
		{
			for(n = 0; n <strlen(wskaznikaSzukanego); n++, i++)
				if(wskaznikZrodla[i] == wskaznikaSzukanego[n])
					continue;
				else
					break;
			if(n == strlen(wskaznikaSzukanego))
				wskaznikZnalezionego = &wskaznikZrodla[i-n];
			else
				wskaznikZnalezionego = NULL;
		}
	}
	return wskaznikZnalezionego;
}