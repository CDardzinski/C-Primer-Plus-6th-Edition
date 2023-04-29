#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial9.h"

//biblioteka z listingu 9.10 i 9.11 do przyk³adu 9.9
#include "hotel.h" //definicje funkcji i stalych

/////do przykladu 9.1 i przyk³adu 9.2
#define NAZWA "MEGATHINK, INC."
#define ADRES "10 Megabuck Plaza"
#define MIEJSCOWOSC "Megapolis, CA 94904"
#define LIMIT 40

static int panelHandle;

void gwiazdki(void); //prototyp funkcji
////////////////////////////////////////////////////////////

/////do przyk³adu 9.2
#define ODSTEP ' '

void n_znak(char ch, int num);
/////////////////////////////////////////////////////////

/////do przyk³adu 9.3
int imin(int , int);
/////////////////////////////////////////////////////////

/////do przyk³adu 9.4
//int imax();
/////////////////////////////////////////////////////////

/////do przyk³adu 9.5
int imax(int , int);
/////////////////////////////////////////////////////////

/////do przyk³adu 9.6
void gora_i_dol(int);
/////////////////////////////////////////////////////////

/////do przyk³adu 9.7
long silnia(int n);
long rsilnia(int n);
/////////////////////////////////////////////////////////

/////do przyk³adu 9.8
void do_binar(unsigned long n);
/////////////////////////////////////////////////////////

/////do przyk³adu 9.12
void mikado(int);
/////////////////////////////////////////////////////////

/////do przyk³adu 9.13
void zmiana(int u, int v);
/////////////////////////////////////////////////////////

/////do przyk³adu 9.14
void zmiana2(int u, int v);
/////////////////////////////////////////////////////////

/////do przyk³adu 9.15
void zmiana3(int *u, int *v);
/////////////////////////////////////////////////////////

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial9.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 9.1 rodzial 9///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			gwiazdki();
			printf("%s\n", NAZWA);
			printf("%s\n", ADRES);
			printf("%s\n", MIEJSCOWOSC);
			gwiazdki();

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 9.2 rodzial 9///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int odstepy; 
	
	switch (event)
	{
		case EVENT_COMMIT:
			n_znak('*', LIMIT); //stale jako argumenty
			putchar('\n');
			n_znak(ODSTEP, 12); //stale jako argumenty
			printf("%s\n", NAZWA);
			odstepy = (LIMIT - strlen(ADRES)) / 2; //program oblicza ile odstepów nalezy wyœwietliæ 
			n_znak(ODSTEP, odstepy); //zmienna jako argument
			printf("%s\n", ADRES);
			n_znak(ODSTEP, (LIMIT - strlen(MIEJSCOWOSC)) / 2); //wyra¿enie jako argument
			printf("%s\n", MIEJSCOWOSC);
			n_znak('*', LIMIT);
			putchar('\n');
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 9.3 rodzial 9///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int zlo1, zlo2;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj dwie liczby calkowite (q konczy program):\n");
			while (scanf("%d %d", &zlo1, &zlo2) == 2)
			{
				printf("Mniejsze liczba sposrod %d i %d jest %d.\n", zlo1, zlo2, imin(zlo1, zlo2));
				printf("Podaj dwie liczby calkowite (q konczy program):\n");
			}
			printf("Gotowe.\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 9.4 rodzial 9///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
	//		printf("Wieksza liczba z %d i %d jest %d.\n", 3, 5, imax(3));
	//		printf("Wieksza liczba z %d i %d jest %d.\n", 3, 5, imax(3.0, 5.0));

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 9.5 rodzial 9///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wieksza liczba z %d i %d jest %d.\n", 3, 5, imax(3, 5));
			printf("Wieksza liczba z %d i %d jest %d.\n", 3, 5, imax(3.0, 5.0));

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 9.6 rodzial 9///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			gora_i_dol(1);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 9.7 rodzial 9///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int num;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Ten program liczy silnie.\n");
			printf("Podaj liczbe z przedzialu 0-12 (k - koniec):\n");
			while (scanf("%d", &num) == 1)
			{
				if(num < 0)
					printf("Prosze nie podawac liczb ujemnych.\n");
				else if(num > 12)
					printf("Prosze podac wartosc mniejsza od 13.\n");
				else
				{
					printf("petla: %d silnia = %ld\n", num, silnia(num));
					printf("rekurencja: %d silnia = %ld\n", num, rsilnia(num));
				}
				printf("Podaj liczbe z przedzialu 0-12 (k - koniec):\n");
			}
			printf("Gotowe.\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 9.8 rodzial 9///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	unsigned long liczba;
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj liczbe calkowita (q konczy program):\n");
			while (scanf("%ld", &liczba) == 1)
			{
				printf("odpowiednik dwojkowy: ");
				do_binar(liczba);
				putchar('\n');
				printf("Podaj liczbe calkowita (q konczy program):\n");
			}
			printf("Gotowe.\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 9.9 rodzial 9///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int noce;
	double hotel;
	int kod;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			while((kod = menu()) != KONIEC)
			{
				switch (kod)
				{
					case 1: hotel = HOTEL1;
						break;
					case 2: hotel = HOTEL2;
						break;
					case 3: hotel = HOTEL3;
						break;
					case 4: hotel = HOTEL4;
						break;
					default: hotel = 0.0;
						printf("Ups!\n");
						break;
				}
				noce = pobierz_noce();
				pokaz_cene(hotel, noce);
			}
			printf("Dziekuje i do widzenia!\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 9.12 rodzial 9///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int ach = 2, och = 5;
	switch (event)
	{
		case EVENT_COMMIT:
			printf("W funkcji main() ach = %d, a &ach = %p\n", ach, &ach);
			printf("W funkcji main() och = %d, a &och = %p\n", och, &och);
			mikado(ach);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 9.13 rodzial 9///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int x = 5, y = 10;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Poczatkowo x = %d, a y = %d.\n", x, y);
			zmiana(x, y);
			printf("A teraz x = %d, a y = %d.\n", x, y);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 9.14 rodzial 9///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad12ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int x = 5, y = 10;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Poczatkowo x = %d, a y = %d.\n", x, y);
			zmiana2(x, y);
			printf("A teraz x = %d, a y = %d.\n", x, y);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 9.15 rodzial 9///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad13ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int x = 5, y = 10;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Poczatkowo x = %d, a y = %d.\n", x, y);
			zmiana3(&x, &y); //wysylanie adresow do funkcji
			printf("A teraz x = %d, a y = %d.\n", x, y);

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
/////////////////////funkcja do przyk³adu 9.1
void gwiazdki(void)
{
	int licznik;
	for(licznik = 1; licznik <= LIMIT; licznik++)
		putchar('*');
	putchar('\n');
}
////////////////////////////funkcja do przyk³adu 9.2
void n_znak(char ch, int num)
{
	int licznik;
	for(licznik = 1; licznik <= num; licznik++)
		putchar(ch);
}
////////////////////////////funkcja do przyk³adu 9.3
int imin(int n, int m)
{
	return (n < m) ? n: m;	
}

////////////////////////////funkcja do przyk³adu 9.4
int imax(n, m)
{
	return (n > m ? n: m);	
}
////////////////////////////funkcja do przyk³adu 9.6
void gora_i_dol(int n)
{
	printf("Poziom: %d: adres zmiennej n: %p\n", n, &n);
	if(n < 4)
		gora_i_dol(n+1);
	printf("POZIOM %d: adres zmiennej n: %p\n", n, &n);
}
////////////////////////////funkcja do przyk³adu 9.7
long silnia(int n) //wersja oparta na petlach
{
	long wyn;
	for(wyn = 1; n > 1; n--)
		wyn *= n;
	return wyn;
}
long rsilnia(int n) //wersja rekurencyjna
{
	long wyn;
	if(n > 0)
		wyn = n * rsilnia(n-1);
	else
		wyn = 1;
	return wyn;
}
////////////////////////////funkcja do przyk³adu 9.8
void do_binar(unsigned long n)
{
	int r;
	r = n % 2;
	if(n >= 2)
		do_binar(n/2);
	putchar(r == 0 ? '0' : '1');
	return;
}
////////////////////////////funkcja do przyk³adu 9.12
void mikado(int och)
{
	int ach = 10;
	printf("W funkcji mikado() ach = %d, a &ach = %p\n", ach, &ach);
	printf("W funkcji mikado() och = %d, a &och = %p\n", och, &och);
}
////////////////////////////funkcja do przyk³adu 9.13
void zmiana(int u, int v)
{
	int temp;
	temp = u;
	u = v;
	v = temp;
}
////////////////////////////funkcja do przyk³adu 9.14
void zmiana2(int u, int v)
{
	int temp;
	printf("Poczatkowo u = %d, a v = %d.\n", u, v);
	temp = u;
	u = v;
	v = temp;
	printf("A teraz u = %d, a v = %d.\n", u, v);
}
////////////////////////////funkcja do przyk³adu 9.15
void zmiana3(int *u, int *v)
{
	int temp;
	temp = *u;
	*u = *v;
	*v = temp;	
}