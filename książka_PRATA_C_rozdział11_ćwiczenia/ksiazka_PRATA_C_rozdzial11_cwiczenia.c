#include <utility.h>
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

/////do cwiczenia 9
int odwrocenieLancucha(char *lanuch);
///////////////////////////

/////do cwiczenia 10
char usunSpacje(char *lanuch);
///////////////////////////

/////do cwiczenia 11
char *PobierzLancuch(char *z, int ile);
///////////////////////////

/////do cwiczenia 14
double PotegaDouble(double podstawa, int wykladnik);
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
			printf("%s%p\n", OtrzymanyLanuch, OtrzymanyLanuch);
			printf("%s%p\n", znaleziony, znaleziony);
			
			do
			{
				znak = getchar();
			}while (znak != '\n');

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 9 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char  znak;
	char OtrzymanyLanuch[ROZMIAR_LANCUCHA];
		
	switch (event)
	{
		case EVENT_COMMIT:
			do
			{
				printf("Wpisz ciag znakow (0 - konczy program)\n");
				
				fgets(OtrzymanyLanuch, ROZMIAR_LANCUCHA, stdin);
				
				if(OtrzymanyLanuch[0] == 0)
					znak = OtrzymanyLanuch[0];
				else
					znak = OtrzymanyLanuch[0];
			
				odwrocenieLancucha(OtrzymanyLanuch);
				
				puts(OtrzymanyLanuch);
			
			}while(znak != '0');
				
			printf("Koniec programu!");	

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 10 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char  znak;
	char OtrzymanyLanuch[ROZMIAR_LANCUCHA];
	
	switch (event)
	{
		case EVENT_COMMIT:
			do
			{
				printf("Wpisz ciag znakow (znak nowej linii konczy program)\n");
				
				znak = usunSpacje(OtrzymanyLanuch);
				
				puts(OtrzymanyLanuch);
			
			}while(znak != 10);
				
			printf("Koniec programu!");	

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 11 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	
	char WpisaneLanuchy[10][ROZMIAR_LANCUCHA];
	char LancuchyASCII[10][ROZMIAR_LANCUCHA];
	char LancuchySlowo[10][ROZMIAR_LANCUCHA];
	char temp[ROZMIAR_LANCUCHA];
	int i = 0, koniec = 0, dlugosc = 0;
	char znak, znak1;
	char kolejnySymbol = 97;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			
			printf("Podaj %d slow\n", 10);
			while (i < 10 && PobierzLancuch(temp, ROZMIAR_LANCUCHA))
			{
					strcpy(WpisaneLanuchy[i], temp);
					i++;
			}
			
			do
			{	
				printf("Co chcialbys zrobic?\n");
				printf("1) Wyswietlic pierwotna liste			2) Wyswietlic liste w porzadku ASCII\n");
				printf("3) Wyswietlic lancuchy wedlug dlugosc		4) Wyswietlic lanuchy wedlug pierwszego slowa\n");
				printf("5) Koniec\n");
			
				znak = getchar();
			
				switch (znak)
				{
					case '1':
						puts("Oto przyjete slowa: ");
						for(i = 0; i < 10; i++)
							puts(WpisaneLanuchy[i]);
						break;
					case '2':
						puts("Lancuchy w porzadku ASCII");
						i = 0;
						kolejnySymbol = 97;
						
						while (i != 10)
						{
							for(int t = 0; t < 10; t++)
								if(WpisaneLanuchy[t][0] ==  kolejnySymbol)
								{
									strcpy(LancuchyASCII[i], WpisaneLanuchy[t]);
									i++;
								}
							kolejnySymbol++;
						}
						
						for(i = 0; i < 10; i++)
							puts(LancuchyASCII[i]);
						
						break;
					case '3':
						puts("Lancuchy wedlug dlugosci");
						i = 0;
						dlugosc = 0;
						
						while(i != 10)
						{
							//if((strlen(WpisaneLanuchy[i]) == dlugosc)
							for(int t = 0; t <10; t++)
								if((strlen(WpisaneLanuchy[t])) == dlugosc) 
								{
									strcpy(LancuchyASCII[i], WpisaneLanuchy[t]);
									i++;
								}
							dlugosc++;
						}
						
						for(i = 0; i < 10; i++)
							puts(LancuchyASCII[i]);
						
						break;
					case '4':
						puts("Lancuchy wedlug dlugosci pierwszego slowa");
						i = 0;
						int t =0;
						dlugosc = 0;
						
						for(int n = 0; n < 10; n++)
						{
							do
							{
								znak1 = WpisaneLanuchy[i][t];
								LancuchyASCII[i][t] = znak1;
								t++;	
							}while(!isspace(znak1));
							LancuchyASCII[i][t] = '\0';
							i++;
							t = 0;
						}
						i = 0;
						while(i != 10)
						{
							for(int t = 0; t <10; t++)
								if((strlen(LancuchyASCII[t])) == dlugosc) 
								{
									strcpy(LancuchySlowo[i], WpisaneLanuchy[t]);
									i++;
								}
							dlugosc++;
						}
					
						for(i = 0; i < 10; i++)
							puts(LancuchySlowo[i]);
						
						break;
					case '5':
						koniec = 1;
						break;
				}
			
			
				do
				{
					znak = NULL;
					znak = getchar();
				}while (znak != '\n');
			
			
			}while(koniec != 1);
			
			printf("\nKoniec programu!");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 12 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad12ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char pobranyLancuch[ROZMIAR_LANCUCHA];
	char znak;
	int wielkieLitery = 0, maleLitery = 0, znakPrzestan = 0, cyfra = 0, slowa = 0;
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wpisz dane wejsciowe\n");
			
			PobierzLancuch(pobranyLancuch, ROZMIAR_LANCUCHA);
			
			for(int i = 0; i < strlen(pobranyLancuch); i++)
			{
				znak = pobranyLancuch[i];
				if(isupper(znak))
					wielkieLitery++;
				else if(islower(znak))
					maleLitery++;
				else if(ispunct(znak))
					znakPrzestan++;
				else if(isdigit(znak))
					cyfra++;
				else if(isspace(znak))
					slowa++;
				}
				
				printf("Ten lancuch zawiera %d slow, %d wielkich liter, %d malych liter, %d znakow przestankowych, %d cyfr.\n", slowa, wielkieLitery, maleLitery, znakPrzestan, cyfra);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 13 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad13ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char CompletPath[ROZMIAR_LANCUCHA];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			sprintf(CompletPath, "%s, %s %s %s %s %s %s %s", "idz_do_domu.exe ", "\"" , "idz", "\"", "do", "\"", "domu", "\"");
			
			LaunchExecutableEx(CompletPath, LE_SHOWNORMAL, NULL);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 14 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad14ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double podstawa;
	int wykladnik;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj podstawe potegi\n");
			scanf("%lf", &podstawa);
			printf("Podaj wykladnik potegi\n");
			scanf("%d", &wykladnik);
			
			printf("Wynik potegowania %.4lf\n", PotegaDouble(podstawa, wykladnik));

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 15 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad15ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char OtrzymanyLanuch[ROZMIAR_LANCUCHA];
	int wynik1, wynik2 = 0, wczytane = 0;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Wpisz liczbe:\n");
				
			fgets(OtrzymanyLanuch, ROZMIAR_LANCUCHA, stdin);
			
			wynik1 = atoi(OtrzymanyLanuch);
			
			for(int t = 0; t < strlen(OtrzymanyLanuch)-1; t++)
			{
				if(isdigit(OtrzymanyLanuch[t]))
					wczytane = 1;
				else
				{
					wczytane = 0;
					wynik2 = 0;
					break;
				}
			}
				
			if(wczytane)
				for (int i = 0; OtrzymanyLanuch[i] != '\n'; ++i)
        			wynik2 = wynik2 * 10 + OtrzymanyLanuch[i] - '0';
	
			
			printf("\nWynik konwersji stringa za pomoca atoi %d, wynik moich obliczen %d\n\n", wynik1, wynik2);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 16 rodzial 11//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad16ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			//Obsluga programu odczyt_pliku

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
	char *wskaznikZnalezionego = NULL;
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
	
	if(wskaznikZnalezionego == NULL)
		wskaznikZnalezionego = &wskaznikZrodla[i];
	
	return wskaznikZnalezionego;
}
////////funkcje do æwiczenia 9
int odwrocenieLancucha(char *lanuch)
{
	char temp[ROZMIAR_LANCUCHA];
	int dlugosc;
	int t;
	
	dlugosc = strlen(lanuch);
	
	for(int i = 0; i < strlen(lanuch); i++, dlugosc--)
		temp[dlugosc-1] = lanuch[i];
	
	for(t = 0; t < strlen(lanuch); t++)
		lanuch[t] = temp[t];
		
	lanuch[t] = '\0';	
	
	return 0;
}
////////funkcje do æwiczenia 10
char usunSpacje(char *lanuch)
{
	char znak;
	int i = 0;
	
	lanuch[0] = 0;
				 
	for(int n = 0; n < strlen(lanuch); n++)
		lanuch[n] = 0;
	
do
	{
		znak = getchar();
		if(isspace(znak))
				continue;
		else
		{
			lanuch[i] = znak;
			i++;
		}				
	}while (znak != '\n');
	
	lanuch[i] = '\0';
	
	if(znak == '\n' && lanuch[0] == 0)
		znak = '\n';
	else
		znak = 97;
	
return znak;
}
////////funkcje do æwiczenia 11
char *PobierzLancuch(char *z, int ile)
{
	char *wynik;
	int i = 0;
	
	wynik = fgets(z, ile, stdin);
	if(wynik)//wynik roczny od NULL
	{
		while (z[i] != '\n' && z[i] != '\0')
			i++;
		if(z[i] == '\n')
			z[i] = '\0'; //znak nowego wiersza -> znak pusty
		else //z[i] == '\0'
			while(getchar() != '\n')
				continue;
	}
	return wynik;
}
////////funkcje do æwiczenia 14
double PotegaDouble(double podstawa, int wykladnik)
{
	double wynik = 1.0;
	
	for(int i = 0; i < wykladnik; i++)
		wynik *= podstawa;
	
	return wynik;
}
