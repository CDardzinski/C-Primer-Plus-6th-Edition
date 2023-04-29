#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include <time.h>
#include "ksiazka_PRATA_C_rozdzial12.h"

#include "czescb.h"
#include "rand0.h"
#include "rand1.c"
#include "rzutkosc.c"

//do przyk³adu 12.3
void sprawdz_stat(void);
//////////////////////////////////////////////////////

//do przyk³adu 12.4
int jednostki = 0; //zmienna zewnêtrzna (globalna)
void krytyka(void);
//////////////////////////////////////////////////////

//do przyk³adu 12.5
void podaj_liczbe(void);
int liczba = 0; //zasieg plikowu, lacznosc zewnetrzna
//////////////////////////////////////////////////////

//do przyk³adu 12.8
extern int randO(void);
//////////////////////////////////////////////////////

//do przyk³adu 12.10
extern void srand1(unsigned int x);
extern int rand1(void);
//////////////////////////////////////////////////////

//do przyk³adu 12.15
int obszar_statyczny = 30;
const char * lcz = "Literal ciagu znakow";
//////////////////////////////////////////////////////


static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial12.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 12.1 rodzial 12///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int x = 30; //oryginalna zmienna x
			
			printf(" x w zewnetrzym bloku: %d spod adresu %p\n", x, &x);
			
			{
				int x = 77; //nowe x przeslania oryginalne x
				printf(" x w wewnetrzym bloku: %d spod adresu %p\n", x, &x);
			}
			
			printf(" x w zewnetrzym bloku: %d spod adresu %p\n", x, &x);
			while (x++ < 33)//oryginalne x
			{
				int x = 100;//nowe x przeslania oryginalne x
				x++;
				printf("x w petli while: %d spod adresu %p\n", x, &x);				
			}
			printf(" x w zewnetrzym bloku: %d spod adresu %p\n", x, &x);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 12.2 rodzial 12///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int n = 8;
			
			printf("Poczatkowo n = %d, pod adresem %p\n", n, &n);
			for(int n = 1; n < 3; n++)
				printf("petla 1: n = %d, pod adresem %p\n", n, &n);
			printf("Po petli 1, n = %d, pod adresem %p\n", n, &n);
			for(int n = 1; n < 3; n++)
			{
				printf("petla 2 indeks n = %d, pod adresem %p\n", n, &n);
				int n = 6;
				printf("petla 2 : n =%d, pod adresem %p\n", n, &n);
				n++;
			}
			printf("Po petli 2, n = %d, pod adresem %p\n", n, &n);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 12.3 rodzial 12///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			int licznik;
			for(licznik = 1; licznik <= 3; licznik++)
			{
				printf("Iteracja nr: %d\n", licznik);
				sprawdz_stat();
			}

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 12.4 rodzial 12///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			extern int jednostki; //powtórna (opcjonalna) deklaracja
			
			printf("Ile funtów masla miesci sie w barylce?\n");
			scanf("%d", &jednostki);
			while (jednostki != 56)
				krytyka();
			printf("Musiales podejrzec!\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 12.5 rodzial 12///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			int wartosc; //zmienna automatyczna
			register int i; //zmienna rejestrowa
			
			printf("Podaj dodatnia liczbe calkowita (0 to koniec): ");
			while (scanf("%d", &wartosc) == 1 && wartosc > 0)
			{
				++liczba; //zmienna o zasiegu plikowym
				for(i = wartosc; i >= 0; i--)
					sumuj(i);
				printf("Podaj dodatnia liczbe calkowita (0 to koniec): ");
			}
			podaj_liczbe();

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 12.8 rodzial 12///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			int liczba;
			for(liczba = 0; liczba < 5; liczba++)
				printf("%hd\n", randO());
	
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 12.10 rodzial 12///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			int liczba;
			unsigned ziarno;
			
			printf("Podaj wartosc ziarna: \n");
			while(scanf("%u", &ziarno) == 1)
			{
				srand1(ziarno); //reset ziarna
				for(liczba = 0; liczba < 5; liczba++)
					printf("%hd\n", rand1());
				printf("Podaj nastepna wartosc ziarna (k to koniec):\n");
			}
			printf("Koniec\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 12.13 rodzial 12///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad13ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int rzuty, wynik;
			int scianki, status;
			
			srand((unsigned int) time(0)); //losowe ziarno
			printf("Podaj liczbe scianek, 0 oznacza koniec.\n");
			while (scanf("%d", &scianki) == 1 && scianki > 0)
			{
				printf("Ile rzutow?\n");
				if((status = scanf("%d", &rzuty)) != 1)
				{
					if(status == EOF)
						break; //przerwanie petli
					else
					{
						printf("Nalezy podac liczbe calkowita.");
						printf("Sprobujmy jeszcze raz.\n");
						while (getchar() != '\n')
							continue; //odrzucenie niepoprawnego wejscia
						printf("Ile scianek? 0 oznacza koniec.\n");
						continue; //nowy przebieg petli
					}
				}
				
				wynik = rzucaj_n_razy(rzuty, scianki);
				printf("Wyrzucono razem %d uzywajac %d %d-sciennych kosci.\n", wynik, rzuty, scianki);
				printf("Podaj liczbe scianke, 0 oznacza koniec.\n");
			}
			
			printf("Funkcja rzucaj() zostala wywolana %d razy.\n", liczba_rzutow);
			
			printf("ZYCZE DUZO SZCZESCIA!\n");									

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 12.14 rodzial 12///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad14ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			double *wsk;
			int max = 0;
			int liczba;
			int i = 0;
			
			puts("Podaj maksymalna liczbe elementow (typu double):");
			if(scanf("%d", &max) != 1)
			{
				puts("Niepoprawna liczba, do widzenia.");
				exit(EXIT_FAILURE);
			}
			wsk = (double *) malloc(max * sizeof (double));
			if(wsk == NULL)
			{
				puts("Przydzial pamieci nie powiodl sie.");
				exit(EXIT_FAILURE);
			}
			//wsk wskazuje na tablice o liczbe elementow rownej max
			puts("Podaj elementy (k to koniec):\n");
			while(i < max && scanf("%lf", &wsk[i]) == 1)
					++i;
			printf("Oto %d wprowadzonych elementow:\n", liczba = i);
			for(i = 0; i < liczba; i++)
			{
				printf("%7.2f ", wsk[i]);
				if(i % 7 == 6)
					putchar('\n');
			}
			if(i % 7 != 0)
				putchar('\n');
			puts("Koniec.");
			free(wsk);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 12.15 rodzial 12///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad15ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int obszar_automatyczny = 40;
			char ciag_automatyczny[] = "Automatyczny przydzial tablicy znakow";
			int *wski;
			char *wskl;
			
			wski = (int *) malloc(sizeof(int));
			*wski = 35;
			wskl = (char*) malloc(strlen("Ciag przydzielony dynamicznie") + 1);
			strcpy(wskl, "Ciag przydzielony dynamicznie");
			
			printf(" obszar_statyczny: %d pod adresem %p\n", obszar_statyczny, &obszar_statyczny);
			printf(" obszar_automatyczny: %d pod adresem %p\n", obszar_automatyczny, &obszar_automatyczny);
			printf(" *wski: %d pod adresem %p\n", *wski, wski);
			printf(" %s pod adresem %p\n", lcz, lcz);
			printf(" %s pod adresem %p\n", ciag_automatyczny, ciag_automatyczny);
			printf(" %s pod adresem %p\n", wskl, wskl);
			printf(" %s pod adresem %p\n", "Literal w kodzie", "Literal w kodzie");
			free(wski);
			free(wskl);
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
//do przyk³adu 12.3
void sprawdz_stat(void)
{
	int znikam = 1;
	static int trwam = 1;
	printf("znikam = %d, a trwam = %d\n", znikam++, trwam++);
}
//do przyk³adu 12.4
void krytyka(void)
{
	//pominieto powtorna (opcjonalna) deklaracje zmiennej jednostki
	
	printf("Nie masz szczescia, sprobuj ponownie.\n");
	scanf("%d", &jednostki);
}
//do przyka³adu 12.5
void podaj_liczbe(void)
{
	printf("Petle opuszczono po %d cyklach\n", liczba);
}