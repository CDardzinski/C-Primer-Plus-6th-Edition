#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial10.h"

/////do przykladu 10.1, u¿yty te¿ do przyk³adu 10.5 i przyk³adu 10.7 i przyk³adu 10.9
#define MIESIACE 12
///////////////////////////

/////do przykladu 10.2 , u¿yty te¿ do przyk³adu 10.3 i 10.6 i 10.8
#define ROZMIAR 4
///////////////////////////

/////do przykladu 10.7
#define LATA 5
///////////////////////////

/////do przykladu 10.10 i do przyk³adu 10.11
#define ROZMIAR2 10
///////////////////////////

/////do przykladu 10.14
#define ROZMIAR3 5
///////////////////////////

/////do przykladu 10.17 i do przyk³adu 10.18 i przyk³adu 10.19
#define WIERSZE 3
#define KOLUMNY 4
///////////////////////////


//prototyp funkcji u¿yty do przyk³adu 10.10
long sumuj(int tab[], int n);
//////////////////////////////////////////////////

//prototyp funkcji u¿yty do przyk³adu 10.11
long sumujw(int *poczatek, int *koniec);
//////////////////////////////////////////////////

//prototypy funkcji u¿yty do przyk³adu 10.14
void pokaz_tablice(const double tab[], int n);
void pomnoz_tablice(double tab[], int n, double mnoz);
//////////////////////////////////////////////////

//prototypy funkcji u¿yty do przyk³adu 10.17
void sumuj_wiersze(int tab[][KOLUMNY], int wiersze);
void sumuj_kolumny(int tab[][KOLUMNY], int wiersze);
int sumuj2d(int(*tab)[KOLUMNY], int wiersze);
//////////////////////////////////////////////////

//prototypy funkcji u¿yty do przyk³adu 10.18
int sumuj2d_2(int wiersze, int kolumny, int tab[wiersze][kolumny]);
//////////////////////////////////////////////////

//prototypy funkcji u¿yty do przyk³adu 10.19
int sumuj2d_3(const int tab[][KOLUMNY], int wiersze);
int sumuj_1(const int tab[], int n);
//////////////////////////////////////////////////

static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial10.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.1 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int dni[MIESIACE] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
	int index;
	
	switch (event)
	{
		case EVENT_COMMIT:
			for(index = 0; index < MIESIACE; index++)
				printf("Miesiac %d ma %d dni.\n", index+1, dni[index]);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.2 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int brak_danych[ROZMIAR];
	int i;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("%2s%14s\n", "i", " brak_danych[i]");
			for(i = 0; i < ROZMIAR; i++)
				printf("%2d%14d\n", i, brak_danych[i]);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.3 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int troche_danych[ROZMIAR] = {1492, 1066};
	int i;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("%2s%14s\n", "i", " troche_danych[i]");
			for(i = 0; i < ROZMIAR; i++)
				printf("%2d%14d\n", i, troche_danych[i]);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.4 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int dni[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
	int index;
	
	switch (event)
	{
		case EVENT_COMMIT:
			for(index = 0; index < sizeof dni/ sizeof (int); index++)
				printf("Miesiac %d ma %d dni.\n", index+1, dni[index]);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.5 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int dni[MIESIACE] = {31, 28, [4] = 31, 30, 31, [1] = 29};
	int i;
	
	switch (event)
	{
		case EVENT_COMMIT:
			for(i = 0; i < MIESIACE; i++)
				printf("%2d %d\n", i + 1, dni[i]);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.6 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int zm1 = 44;
	int tab[ROZMIAR];
	int zm2 = 88;
	int i;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("zm1 = %d, zm2 = %d\n", zm1, zm2);
			for(i = -1; i <= ROZMIAR; i++)
				tab[i] = 2 * i + 1;
			for(i = -1; i < 7; i++)
				printf("%2d %d\n", i, tab[i]);
			printf("zm1 = %d, zm2 = %d\n", zm1, zm2);
			printf("adres tab[-1]: %p\n", &tab[-1]);
			printf("adres tab[4]: %p\n", &tab[4]);
			printf("adres zm1: %p\n", &zm1);
			printf("adres zm2: %p\n", &zm2);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.7 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	//inicjalizacja danych o opadach z lat 2010 - 2014
	const float deszcz[LATA][MIESIACE] = 
		{
			{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
			{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
			{9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
			{7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
			{7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2},
		};
	int rok, miesiac;
	float podsuma, suma;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf(" ROK		OPADY (w calach)\n");
			for(rok = 0, suma = 0; rok < LATA; rok++)
			{	//dla ka¿dego roku sumuj opady dla kazdego miesiaca
				for(miesiac = 0, podsuma = 0; miesiac < MIESIACE; miesiac++)
					podsuma += deszcz[rok][miesiac];
				printf("%5d %12.1f\n", 2010+rok, podsuma);
				suma += podsuma; //suma dla wszystkich lat
			}
			printf("\nRoczna srednia wynosi %.1f cale\n\n", suma/LATA);
			printf("SREDNIE MIESIECZNE:\n\n");
			printf(" Sty	Lut	Mar	Kwi	Maj	Cze	Lip	Sie	Wrz	Paz	Lis	Gru\n");
			
			for(miesiac = 0; miesiac < MIESIACE; miesiac++)
			{	//dla kazdego miesiaca, sumuj opady w ciagu lat
				for(rok = 0, podsuma = 0; rok < LATA; rok++)
					podsuma += deszcz[rok][miesiac];
				printf("%4.1f	",podsuma/LATA);
			}
			printf("\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.8 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	short daty[ROZMIAR];
	short *wski;
	short indeks;
	double rachunki[ROZMIAR];
	double *wskf;
	
	switch (event)
	{
		case EVENT_COMMIT:
			wski = daty; //przypisanie wskaznikowi adresu tablicy
			wskf = rachunki; 
			printf("%23s %10s\n", "short", "double");
			for(indeks = 0; indeks < ROZMIAR; indeks++)
				printf("wskaznik+ %d: %10p %10p\n", indeks, wski + indeks, wskf + indeks);		
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.9 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int dni[MIESIACE] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int index;
	
	switch (event)
	{
		case EVENT_COMMIT:
			for(index = 0; index < MIESIACE; index++)
				printf("Miesiace %d ma %d dni.\n", index +1, *(dni + index)); //rownowazenie dni[index]

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.10 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int kulki[ROZMIAR2] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
	long wynik;
	
	switch (event)
	{
		case EVENT_COMMIT:
			wynik = sumuj(kulki, ROZMIAR2);
			printf("Calkowita liczba kulek wynosi %ld.\n", wynik);
			printf("Rozmiar tablicy kulki wynosi %d bajtow.\n", sizeof kulki);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.11 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int kulki[ROZMIAR2] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
	long wynik;
	
	switch (event)
	{
		case EVENT_COMMIT:
			wynik = sumujw(kulki, kulki + ROZMIAR2);
			printf("Calkowita liczba kulek wynosi %ld.\n", wynik);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.12 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad12ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int dane[2] = {100, 200};
	int wiecejdanych[2] = {300, 400};
	int *w1, *w2, *w3;
	switch (event)
	{
		case EVENT_COMMIT:
			w1 = w2 = dane;
			w3 = wiecejdanych;
			printf("	*w1 = %d,	*w2 = %d,	*w3 = %d\n", *w1, *w2, *w3);
			printf("	*w1++ = %d,	*++w2 = %d,	(*w3)++ = %d\n", *w1++, *++w2, (*w3)++);
			printf("	*w1 = %d,	*w2 = %d,	*w3 = %d\n", *w1, *w2, *w3);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.13 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad13ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int urna[5] = {100, 200, 300, 400, 500};
	int *wsk1, *wsk2, *wsk3;
	switch (event)
	{
		case EVENT_COMMIT:
	
			wsk1 = urna; // przypisuje adres wskaznikowi
			wsk2 = &urna[2]; //jw.
							// pobranie wskaznika i pobranie wskazywanej wartosci
			printf("wartosc wskaznika, wskazywana wartosc, adres wskaznika:\n");
			printf("wsk1 = %p, *wsk1 = %d, &wsk1 = %p\n", wsk1, *wsk1, &wsk1);
			
			//dodawanie wskaznikow
			wsk3 = wsk1 + 4;
			
			printf("\ndodawanie int do wskaznika:\n");
			printf("wsk1 + 4 = %p, *(wsk4 + 3) = %d\n", wsk1 + 4, *(wsk1 + 3));
			wsk1++; //ikrementacja wskaznika
			printf("\nwartosci po wsk1++:\n");
			printf("wks1 = %p, *wsk1 = %d, &wsk1 = %p\n", wsk1, *wsk1, &wsk1);
			wsk2--; //dekrementacja wskaznika
			printf("\nwartosci po --wsk2:\n");
			printf("wks2 = %p, *wsk2 = %d, &wsk2 = %p\n", wsk2, *wsk2, &wsk2);
			--wsk1;	//przywrocenie wartosci poczatkowych
			++wsk2;	//przywrocenie wartosci poczatkowych
			printf("\nWskazniki przywrocone do swoich poczatkowych wartosci:\n");
			printf("wsk1 = %p, wsk2 = %p\n", wsk1, wsk2); 
			//odejmowanie jednego wskaznika od drugiego
			printf("\nOdejmowanie jednego wskaznika od drugiego:\n");
			printf("wsk2 = %p, wsk1 = %p, wsk2 - wsk1 = %d\n", wsk2, wsk1, wsk2 - wsk1);
			//odejmowanie zmiennej typu int od wskaznika
			printf("\nOdejmowanie zmiennej typu int od wskaznka:\n");
			printf("wsk3 = %p, wsk3 - 2 = %p\n", wsk3, wsk3 - 2);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.14 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad14ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double dip[ROZMIAR3] = {20.0, 17.66, 8.2, 15.3, 22.22};
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Poczatkowa tablica dip:\n");
			pokaz_tablice(dip, ROZMIAR3);
			pomnoz_tablice(dip, ROZMIAR3, 2.5);
			printf("Tablica dip po wywyolaniu funkcji pomnoz_tablice():\n");
			pokaz_tablice(dip, ROZMIAR3);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.15 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad15ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("  zippo = %p,  zippo + 1 = %p\n",  zippo, zippo + 1);
			printf("  zippo[0] = %p,  zippo[0] + 1 = %p\n",  zippo[0], zippo[0] + 1);
			printf("  *zippo = %p,  *zippo + 1 = %p\n",  *zippo, *zippo + 1);
			printf("zippo[0][0] = %d\n", zippo[0][0]);
			printf(" *zippo[0] = %d\n", *zippo[0]);
			printf("  **zippo = %d\n", **zippo);
			printf("    zippo[2][1] = %d\n", zippo[2][1]);
			printf("*(*(zippo + 2) + 1) = %d\n", *(*(zippo + 2) + 1));
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.16 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad16ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}}; 
	int (*pz)[2];
	
	switch (event)
	{
		case EVENT_COMMIT:
			pz = zippo;
			
			printf("	pz = %p,	pz + 1 = %p\n", pz, pz + 1);
			printf("pz[0] = %p,	pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
			printf("	*pz = %p,	*pz + 1 = %p\n", *pz, *pz + 1);
			printf("pz[0][0] = %d\n", pz[0][0]);
			printf("	*pz[0] = %d\n", *pz[0]);
			printf("		**pz = %d\n", **pz);
			printf("			pz[2][1] = %d\n", pz[2][1]);
			printf("*(*(pz + 2) + 1) = %d\n", *(*(pz+2) + 1));

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.17 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad17ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int graty[WIERSZE][KOLUMNY] = {
		{2, 4, 6, 8},
		{3, 5, 7, 9},
		{12, 10, 8, 6}
	};
	
	switch (event)
	{
		case EVENT_COMMIT:
			sumuj_wiersze(graty, WIERSZE);
			sumuj_kolumny(graty, WIERSZE);
			printf("Suma wszystkich elementow = %d\n", sumuj2d(graty, WIERSZE));
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.18 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad18ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int i, j;
	int rw = 3;
	int rk = 10;
	int graty[WIERSZE][KOLUMNY] = {
		{2, 4, 6, 8},
		{3, 5, 7, 9},
		{12, 10, 8, 6}
	};
	int wiecejgratow[WIERSZE - 1][KOLUMNY + 2] = {
		{20, 30, 40, 50, 60, 70},
		{5, 6, 7 , 8, 9, 10}
	};
	int zmtab[rw][rk]; //VLA
	
	switch (event)
	{
		case EVENT_COMMIT:
			for(i = 0; i < rw; i++)
				for(j = 0; j < rk; j++)
					zmtab[i][j] = i * j + j;
			printf("tablica 3x5\n");
			printf("Suma wszystkich elementow = %d\n", sumuj2d_2(WIERSZE, KOLUMNY, graty));
			printf("tablica 2x6\n");
			printf("Suma wszystkich elementow = %d\n", sumuj2d_2(WIERSZE -1, KOLUMNY +2, wiecejgratow));
			printf("VLA 3x10\n");
			printf("Suma wszystkich elementow = %d\n", sumuj2d_2(rw, rk, zmtab));
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 10.19 rodzial 10///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad19ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int suma1, suma2, suma3;
	int *wsk1;
	int (*wsk2)[KOLUMNY];
	
	switch (event)
	{
		case EVENT_COMMIT:
			wsk1 = (int [2]) {10, 20};
			wsk2 = (int [2] [KOLUMNY]) {{1, 2, 3, -9}, {4, 5, 6, -8}};
			
			suma1 = sumuj_1(wsk1, 2);
			suma2 = sumuj2d_3(wsk2, 2);
			suma3 = sumuj_1((int []) {4, 4, 4, 5, 5, 5}, 6);
			printf("suma1 = %d\n", suma1);
			printf("suma2 = %d\n", suma2);
			printf("suma3 = %d\n", suma3);
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
//definicja funkcji do przyk³adu 10.10
long sumuj(int tab[], int n)
{
	int i;
	int suma = 0;
	for(i = 0; i < n; i++)
		suma += tab[i];
	printf("Rozmiar tablicy tab wynosi %zd bajtow.\n", sizeof tab);
	return suma;
}
//definicja funkcji do przyk³adu 10.11
long sumujw(int *poczatek, int *koniec)
{
	int suma = 0;
	while(poczatek < koniec)
	{
		suma += *poczatek; //dodaje wartosc do sumy
		poczatek++;			//przenosi wskaznik do nastepnego elementu
	}
	return suma;
}
//definicje funkcji do przyk³adu 10.11
void pokaz_tablice(const double tab[], int n) //wyswiwetla zawartosc tablicy
{
	int i;
	for(i = 0; i < n; i++)
		printf("%8.3f ", tab[i]);
	putchar('\n');
}
void pomnoz_tablice(double tab[], int n, double mnoz) //mnozy kazdy element tablicy przez te sama liczbe
{
	int i;
	for(i = 0; i < n; i++)
		tab[i] *= mnoz;
}
//definicje funkcji do przyk³adu 10.17
void sumuj_wiersze(int tab[][KOLUMNY], int wiersze)
{
	int w;
	int k;
	int suma;
	for(w = 0; w < wiersze; w++)
	{
		suma = 0;
		for(k = 0; k < KOLUMNY; k++)
			suma += tab[w][k];
		printf("Wiersz %d: suma = %d\n", w, suma);
	}	
}
void sumuj_kolumny(int tab[][KOLUMNY], int wiersze)
{
	int w;
	int k;
	int suma;
	for(k = 0; k < KOLUMNY; k++)
	{
		suma = 0;
		for(w = 0; w < wiersze; w++)
			suma += tab[w][k];
		printf("Kolumna %d: suma = %d\n", k, suma);
	}	
}
int sumuj2d(int(*tab)[KOLUMNY], int wiersze)
{
	int w;
	int k;
	int suma = 0;
	for(w = 0; w < wiersze; w++)
		for(k = 0; k < KOLUMNY; k++)
			suma += tab[w][k];
	return suma;
}
//definicje funkcji do przyk³adu 10.18
int sumuj2d_2(int wiersze, int kolumny, int tab[wiersze][kolumny]) //funkcja z parametrem VLA
{
	int w;
	int k;
	int suma = 0;
	for(w = 0; w < wiersze; w++)
		for(k = 0; k < kolumny; k++)
			suma += tab[w][k];
	return suma;
}
//definicje funkcji do przyk³adu 10.19
int sumuj2d_3(const int tab[][KOLUMNY], int wiersze)
{
	int w;
	int k;
	int suma = 0;
	for(w = 0; w < wiersze; w++)
		for(k = 0; k < KOLUMNY; k++)
			suma += tab[w][k];
	return suma;
}
int sumuj_1(const int tab[], int n)
{
	int i;
	int suma = 0;
	for(i = 0; i < n; i++)
		suma += tab[i];
	return suma;
}