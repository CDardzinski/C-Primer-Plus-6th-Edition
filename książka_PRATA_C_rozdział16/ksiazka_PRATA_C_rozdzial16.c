#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial16.h"

//do przyk³adu 5
#include <math.h>

//do przyk³adu 8 (wykorzystuje kod z przyk³adu 6 i 7 w odzielnych plikach)
//#include "daneos.h" //tymczasowo wy³aczone do wykonania przyk³¹du 11

//do przyk³adu 11
#include "daneos1.h"
#include "daneos1.h"

//do przyk³adu 15
//#include <tgmath.h>

//do przyk³adu 18
#include <assert.h>

//do przyk³adu 19
#include <limits.h>

//do przyk³adu 1
#define DWA 2 //mo¿na korzystaæ z komentarzy
#define OW "Konsekwencja jest ostatnim schronieniem ludzi pozba\
wionych fantazji.\n- Oscar Wilde" //lewy ukosnik przenosi definicje do nastepnego wiersza
#define CZTERY DWA*DWA
#define PX printf("X wynosi %d.\n", x)
#define FMT "X wynosi %d.\n"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//do przyk³adu 2
#define KWADR(X) X*X
#define PR(X) printf("Wynik to %d.\n", X)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//do przyk³adu 3
#define PKW(x) printf("Kwadratem " #x " jest %d.\n", ((x)*(x)))//#x nazwa parametru w postaci ³añcucha
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//do przyk³adu 4
#define XNAZWA(n) x ## n
#define WYPISZ_XN(n) printf("x" #n " = %d\n", x ## n)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 5
#define PR1(X, ...) printf("Wiadomosc " #X ": " __VA_ARGS__)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 9
#define TYLKO_SPRAWDZAM
#define GRANICA 4
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 12
void czemu_ja(void);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 13
#define MOJTYP(X) _Generic((X),\
int: "int",\
float: "float",\
double: "double",\
default: "inny"\
)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 14
#define RAD_NA_ST (180/(4 * atan(1))) //i przyk³adu 15
typedef struct biegun {
	double dlugosc;
	double kat;
} Biegun;
typedef struct kartez {
	double x;
	double y;
} Kartez;
Biegun kart_na_bieg(Kartez);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 15
 //uogolniona wersja pierwiastka kwadratowego
#define SQRT(X) _Generic((X),\
long double: sqrtl,\
default: sqrt,\
float: sqrtf)(X)
 //uogolniona wersja sinusa (kat wyrazony w stopniach)
#define SIN(X) _Generic((X),\
long double: sinl((X)/RAD_NA_ST),\
default: sin((X)/RAD_NA_ST),\
float: sinf((X)/RAD_NA_ST)\
)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 16
void koniec(void);
void wpadka(void);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 17
#define NUM 40
void wypelnij_tab(double tab[], int n);
void pokaz_tab(const double tab[], int n);
int porownaj(const void * w1, const void *w2);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 19
		//_Static_assert(CHAR_BIT == 16, "niepoprawne zalozenie: 16-bitowy char");
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 20
#define ROZMIAR 10
void pokaz_tabele(const int tab[], int n);
	//usunac dla kompilatorow sprzed C11
	//_Static_assert(sizeod(double) == 2 * sizeof(int), "double nie jest 2-krotnie wiekszy niz int);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 21
double sumuj(int, ...);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
static int panelHandle;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial16.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.1 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{	
	switch (event)
	{
		case EVENT_COMMIT:
			
			int x = DWA;
			PX;
			x = CZTERY;
			printf(FMT, x);
			printf("%s\n", OW);
			printf("DWA: OW\n");		

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.2 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int x = 5;
			int z;
			printf("x = %d\n", x);
			z = KWADR(x);
			printf("Wartosc SQUARE(x): ");
			PR(z);
			z = KWADR(2);
			printf("Wartosc SQUARE(2): ");
			PR(z);
			printf("Wartosc SQUARE(x+2): ");
			PR(KWADR(x+2));
			printf("Wartosc 100/SQUARE(2): ");
			PR(100/KWADR(2));
			printf("x wynosi %d.\n", x);
			printf("Wartosc SQUARE(++x): ");
			PR(KWADR(++x));
			printf("Po zwiekszeiu x wynosi %x.\n", x);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.3 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int y = 5;
			PKW(y);
			PKW(2+4);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.4 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{		
	switch (event)
	{
		case EVENT_COMMIT:
			
			int XNAZWA(1) = 14; //rozwijanie do int x1 = 14
			int XNAZWA(2) = 20; //rozwijanie do int x2 = 20;
			int x3 = 30;
			
			WYPISZ_XN(1); //rozwijanie do printf("x1 = %d\n", x1)
			WYPISZ_XN(2); //rozwijanie do printf("x2 = %d\n", x2)
			WYPISZ_XN(3); //rozwijanie do printf("x3 = %d\n", x3)

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.5 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			double x =48;
			double y;
			
			y = sqrt(x);
			PR1(1, "x = %g\n", x);
			PR1(2, "x = %.2f, y = %.4f\n", x, y);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.8 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			daneos kandydat;
			
			wprowadz(&kandydat);
			printf("Witamy ");
			wyswietl(&kandydat);
			printf(" w naszym programie!\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.9 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int i;
			int suma = 0;
			
			for(i = 1; i <= GRANICA; i++)
			{
				suma += 2*i*i + 1;
				
#ifdef TYLKO_SPRAWDZAM
				printf("i = %d, suma = %d\n", i, suma);
#endif		
			}
			printf("Suma koncowa = %d\n", suma);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.11 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			daneos zwyciezca = { "Less", "Ismoor"};
			printf("Zwyciezca jest %s %s\n", zwyciezca.imie, zwyciezca.nazw);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.12 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad12ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Plik: %s.\n", __FILE__);//identyfikatory predefiniowane
			printf("Data: %s.\n", __DATE__);
			printf("Czas: %s.\n", __TIME__);
			printf("Wersja: %ld.\n", __STDC_VERSION__);
			printf("Wiersz nr: %d.\n", __LINE__);
			printf("Nazwa funkcji: %s.\n", __func__);
			czemu_ja();
			break;
	}
	return 0;
}
void czemu_ja(void)
{
	printf("Nazwa funkcji: %s\n", __func__);
	printf("Wiersz nr: %d.\n", __LINE__);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.13 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad13ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			int d = 5;
			
			printf("%s\n", MOJTYP(d)); //d jest typu int
			printf("%s\n", MOJTYP(2.0 * d)); //2.0 * d jest typu double
			printf("%s\n", MOJTYP(3L)); //3L jest typu long
			printf("%s\n", MOJTYP(&d)); //&d jest typu int *

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.14 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad14ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			Kartez wejscie;
			Biegun wynik;
			puts("Podaj wspolrzedne x i y; wpisanie q konczy program:");
			while(scanf("%lf %lf", &wejscie.x, &wejscie.y) == 2)
			{
				wynik = kart_na_bieg(wejscie);
				printf("dlugosc = %0.2f, kat = %0.2f\n", wynik.dlugosc, wynik.kat);
			}
			puts("Gotowe!.\n");

			break;
	}
	return 0;
}
Biegun kart_na_bieg(Kartez k)
{
	Biegun b;
	b.dlugosc = sqrt(k.x * k.x + k.y * k.y);
	if(b.dlugosc == 0)
		b.kat = 0.0;
	else
		b.kat =  RAD_NA_ST * atan2(k.y, k.x);
	return b;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.15 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad15ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
/*			
			float x = 45.0f;
			double xx = 45.0;
			long double xxx = 45.0L;
			long double y = SQRT(x);
			long double yy = SQRT(xx);
			long double yyy= SQRT(xxx);
			
			printf("%.17Lf\n", y); //dla typu float
			printf("%.17Lf\n", yy); //dla typu domyslnego
			printf("%.17Lf\n", yyy); //dla typu long double
			
			int i = 45;
			yy = SQRT(i); //dla typu domyslnego
			printf("%.17Lf\n", yy); 
			yyy = SIN(xxx); //dla typu long double
			printf("%.17Lf\n", yyy); 
*/
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.16 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad16ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int n;
			atexit(koniec); //rejestruje funkcje koniec
			puts("Podaj liczbe calkowita:");
			if(scanf("%d", &n) != 1)
			{
				puts("To nie jest liczba calkowita!");
				atexit(wpadka); //rejestruje funkcje wpadka
				exit(EXIT_FAILURE);
			}
			printf("%d jest %s.\n", n, (n % 2 == 0) ? "parzysta" : "nieparzysta");			

			break;
	}
	return 0;
}
void koniec(void)
{
	puts("Na tym konczymy kolejny wspanialy program firmy");
	puts("Hustawka Software!");
}
void wpadka(void)
{
	puts("Firma Hustawka Software sklada szczere kondolencje");
	puts("z powodu awarii programu.");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.17 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad17ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			double wart[NUM];
			
			wypelnij_tab(wart, NUM);
			puts("Lista losowa:");
			pokaz_tab(wart, NUM);
			qsort(wart, NUM, sizeof(double), porownaj);
			puts("\nLista uporzadkowana:");
			pokaz_tab(wart, NUM);

			break;
	}
	return 0;
}
void wypelnij_tab(double tab[], int n)
{
	int index;
	
	for(index = 0; index < n; index++)
		tab[index] = (double)rand()/((double)rand() + 0.1);
}
void pokaz_tab(const double tab[], int n)
{
	int index;
	
	for(index = 0; index < n; index++)
	{
		printf("%9.4f ", tab[index]);
		if(index % 6 == 5)
			putchar('\n');
	}
	if(index % 6 != 0)
		putchar('\n');
}
//porzadkuje w kolejnosc rosnacej
int porownaj(const void * w1, const void *w2)
{
	//do odczytania wartosci potrzbne sa wskazniki do double
	const double *a1 = (const double *) w1;
	const double *a2 = (const double *) w2;
	if(*a1 < *a2)
		return -1;
	else if(*a1 == *a2)
		return 0;
	else
		return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.18 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad18ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			double x, y, z;
			
			puts("Podaj pare liczb (0 0 konczy program): ");
			while(scanf("%lf%lf", &x, &y) == 2 && (x != 0 || y != 0))
			{
				z = x * x - y * y; //powinno byc : +
				assert(z >= 0);
				printf("wynik wynosi %f\n", sqrt(z));
				puts("Kolejna para liczb: ");
			}
			puts("Gotowe!");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.19 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad19ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			puts("char ma 16 bitow.");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.20 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad20ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int zrodlo[ROZMIAR] = {1,2,3,4,5,6,7,8,9,10};
			int cel[ROZMIAR];
			double ciekawostka[ROZMIAR/2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};
			
			puts("uzyto memcpy(): ");
			puts("zrodla (dane orginalne): ");
			pokaz_tabele(zrodlo, ROZMIAR);
			memcpy(cel, zrodlo, ROZMIAR * sizeof(int));
			puts("cel (kopiowanie zrodla):");
			pokaz_tabele(cel, ROZMIAR);
			puts("\nUzycie funkcji memmove() z nakladajacymi sie obszarami:");
			memmove(zrodlo+2, zrodlo, 5*sizeof(int));
			puts("zrodlo -- elementy 0-5 kopiowanie do 2-7:");
			pokaz_tabele(zrodlo, ROZMIAR);
			
			puts("\nUzycie memcpy() do skopiowania double do int:");
			memcpy(cel, ciekawostka, (ROZMIAR/2) * sizeof(double));
			puts("cel -- 5 double do 10 int:");
			pokaz_tabele(cel, ROZMIAR);
			pokaz_tabele(cel + 5, ROZMIAR/2);

			break;
	}
	return 0;
}
void pokaz_tabele(const int tab[], int n)
{
	int i;
	
	for(i = 0; i < n; i++)
		printf("%d ", tab[i]);
	putchar('\n');
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 16.21 rodzial 16///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad21ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			double s, t;
			
			s = sumuj(3, 1.1, 2.5, 13.3);
			t = sumuj(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
			printf("zwroc wartosc "
				   "suma(3, 1.1, 2.5, 13.3):			%g\n", s);
			printf("zwroc wartosc "
				   "suma(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1):	%g\n", t);	

			break;
	}
	return 0;
}
double sumuj(int lim, ...)
{
	va_list ap; //deklaracja obiektu przechowujacego argumenty
	double suma = 0;
	int i;
	va_start(ap, lim); //zainicjalizowanie ap lista argumentow
	for(i = 0; i < lim; i++)
		suma += va_arg(ap, double); //dostep do kazdego elementu w liscie argumentow
	
	va_end(ap); //czyszczenie
	
	return suma;
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