#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial16_cwiczenia.h"

//definicja z pytañ sprawdzajacych pkt. 5
#define PRZYKLAD5(X,Y) printf(#X " to %d, a " #Y " to %d\n", X, Y);
//definicja z pytañ sprawdzajacych pkt. 7
#define WYSW(X) printf("nazwa: " #X "; wartosc: %d; adres %p\n", X, &X)
//definicja z pytañ sprawdzajacych pkt. 9
#define PR_DATE (__DATE__)

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//do æwiczenia 2
#define SREDNIA_HARMONICZNA(A,B) (2/(1/(A) + 1/(B))) 
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//do æwiczenia 3
#define STOPNIE_NA_RADIANY(N) ((N*(4*atan(1)))/180)
typedef struct biegun {
	double dlugosc;
	double kat;
} Biegun;
typedef struct kartez {
	double x;
	double y;
} Kartez;
Kartez DaneBiegunoweNaKartezjanskie(double DlugoscWektora, double Kat);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//do æwiczenia 4
clock_t clock(void);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//do æwiczenia 5
#define ROZMIAR_TABLICY 30
int WyswietlTablice(const int *Tablica,int RozmiarTAB, int LiczbaPozycji);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 6
#define LISTA_OSOB 10
void pokaz_tab(void);
int porownaj(const void * w1, const void *w2);

struct osoba {
	char imie[40];
	char nazwisko[40];
};
struct osoba zaloga[LISTA_OSOB] = {
		{"Kapitan", "Wrona"},
		{"Maly", "Skrzat"},
		{"Brudna", "Jola"},
		{"Garbaty", "Pajak"},
		{"Mistrz", "Swiata"},
		{"Ciezka", "Berta"},
		{"Brat", "Albert"},
		{"Lysy", "Kolo"},
		{"Tokyo", "Abado"},
		{"Stephen", "Prat"},
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 7
void pokaz_tablice(const double tab[], int n);
double *nowa_tablica(int n, ...);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
static int panelHandle;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial16_cwiczenia.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
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
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Extra rozdzia³ 16//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK PrzykladExtraButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			//int mistrz = 4;
			
			//PRZYKLAD5 (3+4, 4*12);	
			//WYSW(mistrz);
			//printf("Data  = %s\n", PR_DATE);

			break;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 1 rozdzia³ 16//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
		//Opracowaæ plik nag³ówkowy zawierajacy definicje makr, które bêdê wykorzystywa³ w swoich programach

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 2 rozdzia³ 16//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			double J = 8.3, K = 3.5;
			
			printf("Srednia harmoniczna z %f i %f to %f", J, K, SREDNIA_HARMONICZNA(J,K));

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 3 rozdzia³ 16//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			Kartez wynik;
			Biegun daneWejsciowe;
			
			puts("Podaj dlugosc wektora oraz kat; wpisanie q konczy program:");
			while(scanf("%lf %lf", &daneWejsciowe.dlugosc, &daneWejsciowe.kat) == 2)
			{
				wynik = DaneBiegunoweNaKartezjanskie(daneWejsciowe.dlugosc, daneWejsciowe.kat);
				printf(" X = %0.2f, Y = %0.2f\n", wynik.x, wynik.y);
			}
			puts("Gotowe!.\n");

			break;
	}
	return 0;
}
Kartez DaneBiegunoweNaKartezjanskie(double DlugoscWektora, double Kat)
{
	Kartez Wsporzedne;
	
	Wsporzedne.x = DlugoscWektora * cos(STOPNIE_NA_RADIANY(Kat));
	Wsporzedne.y = DlugoscWektora * sin(STOPNIE_NA_RADIANY(Kat));
	
	return Wsporzedne;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 4 rozdzia³ 16//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			long double ActualTime1 = clock();
			long double ActualTime2 = clock();
			long double diiference;
			
			for(int i = 0; i < 100; i++)
			{
				ActualTime2 = clock();
				printf("%.2lf\n", ActualTime2);
			}
			printf("%.2lf\n", ActualTime1);
			
			diiference = (ActualTime2-ActualTime1)/(double)CLOCKS_PER_SEC;
			
			printf("Czas startu %.4lf, Czas konca %.4lf, Roznica czasu %.4lf", ActualTime1, ActualTime2, diiference);
			
			
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 5 rozdzia³ 16//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int TestTab[ROZMIAR_TABLICY];	
			
			time_t zmiennaDoziarna;
			time(&zmiennaDoziarna);
			srand(zmiennaDoziarna);
			
			puts("Tablica poczatkowa:");
			for(int i = 0; i < ROZMIAR_TABLICY; i++)
			{
				TestTab[i] = (rand() % 100);		
				printf("%d -> %d  ", i, TestTab[i]);
				if((i+1) % 5 == 0) putchar('\n');
			}
			
			WyswietlTablice(TestTab, ROZMIAR_TABLICY, 10);

			break;
	}
	return 0;
}
int WyswietlTablice(const int *Tablica, int RozmiarTAB, int LiczbaPozycji)
{
	int TablicaPozycji[LiczbaPozycji];

	for(int i = 0; i < LiczbaPozycji; i++)
	{
		TablicaPozycji[i] = rand() % RozmiarTAB;		
		
		for(int n = LiczbaPozycji-1; n >= 0; n--)
		{
			if(TablicaPozycji[i] == TablicaPozycji[n])
			{
				if(i == n) continue;
				TablicaPozycji[i] = rand() % RozmiarTAB;
				n = LiczbaPozycji;
			}
		}
		printf("Wybrana pozycja to %d jej wartosc to %d\n", TablicaPozycji[i], Tablica[TablicaPozycji[i]]);		
	}	
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 6 rozdzia³ 16//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			puts("Lista zalogi (nieuporzadkowana):");
			pokaz_tab();
			qsort(zaloga, LISTA_OSOB, sizeof(struct osoba), porownaj);
			puts("\nLista uporzadkowana:");
			pokaz_tab();

			break;
	}
	return 0;
}

void pokaz_tab(void)
{
	
	for(int index = 0; index < LISTA_OSOB; index++)
		printf("Pozycja %d; Imie: %s Nazwisko: %s\n", index+1, zaloga[index].imie, zaloga[index].nazwisko);
	
	
	putchar('\n');
}
//porzadkuje w kolejnosc rosnacej
int porownaj(const void * w1, const void *w2)
{
	const struct osoba *a1 = (const struct osoba *) w1;
	const struct osoba *a2 = (const struct osoba *) w2;
	
	int wynik;
	
	wynik = strcmp(a1->nazwisko, a2->nazwisko);
	
	if(wynik != 0)
		return wynik;
	else
		return strcmp(a1->imie, a2->imie);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 7 rozdzia³ 16//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			double *w1;
			double *w2;
			
			w1 = nowa_tablica(5, 1.2, 2.3, 3.4, 4.5, 5.6);
			w2 = nowa_tablica(4, 100.0, 20.00, 8.08, -1890.0);
			
			pokaz_tablice(w1, 5);
			pokaz_tablice(w2, 4);
			
			free(w1);
			free(w2);

			break;
	}
	return 0;
}
void pokaz_tablice(const double tab[], int n)
{
	printf("Tablica o liczbe %d elementow:\n", n);
	for(int i = 0; i < n; i++)
		printf("Element %d tablicy wynosi %.2f\n", i, tab[i]);
	putchar('\n');
}
double *nowa_tablica(int n, ...)
{
	va_list ObiektPrzechowujacyArgumenty;
	double *wskaznik, *wpiszDoPamieci;
	wskaznik = (double *) malloc(n*sizeof(double));
	
	va_start(ObiektPrzechowujacyArgumenty, n); //zainicjalizowanie listy argumentow
	
	wpiszDoPamieci = wskaznik; 
	
	for(int i = 0; i < n; i++)
	{
		*wpiszDoPamieci = va_arg(ObiektPrzechowujacyArgumenty, double);
		wpiszDoPamieci += 1; 
	}
	
	va_end(ObiektPrzechowujacyArgumenty);	
	
	return wskaznik;
}