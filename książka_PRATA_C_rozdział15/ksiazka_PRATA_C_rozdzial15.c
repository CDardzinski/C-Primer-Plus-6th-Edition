#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial15.h"

//do przykladu 1 i przyk³adu 2 i przyk³adu 4
#include <limits.h> //CHAR_BIT, liczba bitów w typie char

//do przyk³adu 3 i przyk³adu 4
#include <stdbool.h> //C99, definicje bool, true i false

static int panelHandle;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//do przyk³adu 1 i przyk³adu 2
char *do_binar(int, char*);
void pokaz_binar (const char*);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//do przyk³adu 2
int odwroc_koniec(int num, int bity);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//do przyk³adu 3 i przyk³adu 4
// Komentarz do przyk³adu 4 -> STALE DO POL BITOWYCH
//style linii 
#define CIAGLA 0
#define KROPKI 1
#define KRESKI 2
//barwy podstawowe
#define NIEB 4
#define ZIEL 2
#define CZER 1
//barwy mieszane
#define CZARNY 0
#define ZOLTY (CZER | ZIEL)
#define FIOLET (CZER | NIEB)
#define ZIELNIEB (ZIEL | NIEB)
#define BIALY (CZER | ZIEL | NIEB)

const char *kolory[8] = {"czarny", "czerwony", "zielony", "zolty", "niebieski", "fioletowy", "zielono-niebieski", "bialy"};

struct wl_okna{
	bool				przezrocz		:1; //unsigned int przed C99
	unsigned int		kolor_wyp		:3;
	unsigned int						:4;
	bool				wid_ramki		:1; //unsigned int przed C99
	unsigned int		kolor_ramki		:3;
	unsigned int		styl_ramki 		:2;
	unsigned int						:2;
};

void pokaz_ustawienia(const struct wl_okna *pb);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//do przyk³adu 4
//STALE DLA OPERATORÓW BITOWYCH
#define PRZEZR				0x1
#define WYP_NIEB 			0x8
#define WYP_ZIEL	 		0x4
#define WYP_CZER 			0x2
#define WYP_MASKA 			0xE
#define RAMKA		 		0x100
#define RAMKA_NIEB			0x800
#define RAMKA_ZIEL			0x400
#define RAMKA_CZER			0x200
#define RAMKA_MASKA			0xE00
#define R_CIAGLA			0x0000
#define R_KROPKI			0x1000
#define R_KRESKI			0x2000
#define STYL_MASKA			0x3000

union Widoki //dane jako struktura i jako wartosc unsigned short
{
	struct wl_okna widok_st;
	unsigned short widok_sh;
};

void wyswietl(const struct wl_okna *wsk_ok);
void wyswietl1(unsigned short);
char *int_do_binar(int n, char *wl);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial15.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 15.1 rodzial 15///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char bin_lan[CHAR_BIT * sizeof(int) +1];
	int liczba;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			puts("Ten program przelicza liczby calkowite na system binarny.");
			puts("Wpisanie danych nienumerycznych konczy "
				 	" dzialanie programu.");
			
			while (scanf("%d", &liczba) == 1)
			{
				do_binar(liczba, bin_lan);
				printf("%d to inaczej ", liczba);
				pokaz_binar(bin_lan);
				putchar('\n');
			}
			puts("Gotowe!\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 15.2 rodzial 15///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char bin_lan[CHAR_BIT * sizeof(int) +1];
	int liczba;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			puts("Ten program przelicza liczby calkowite na system binarny.");
			puts("Wpisanie danych nienumerycznych konczy "
				 	" dzialanie programu.");
			
			while (scanf("%d", &liczba) == 1)
			{
				do_binar(liczba, bin_lan);
				printf("%d to inaczej\n", liczba);
				pokaz_binar(bin_lan);
				putchar('\n');
				liczba = odwroc_koniec(liczba , 4);
				printf("Odwrocenie ostatnich 4 bitow daje\n");
				pokaz_binar(do_binar(liczba,bin_lan));
				putchar('\n');
			}
			puts("Gotowe!\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 15.3 rodzial 15///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	struct wl_okna okno = {true, ZOLTY, true, ZIEL, KRESKI};
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Pierwotne ustawienia okna:\n");
			pokaz_ustawienia(&okno);
			okno.przezrocz = false;
			okno.kolor_wyp = BIALY;
			okno.kolor_ramki = FIOLET;
			okno.styl_ramki = CIAGLA;
			printf("\nPo dokonaniu zmian ustawien okna:\n");
			pokaz_ustawienia(&okno);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 15.4 rodzial 15///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			//tworzy unie okno typu Widoki i inicjalizuje ja korzystajac ze struktury
			union Widoki okno = {{false, ZOLTY, true, ZIEL, KRESKI}};
			char bin_lan[8*sizeof(int)+1];
			
			printf("Poczatkowe ustawienia okna:\n");
			wyswietl(&okno.widok_st);
			printf("\nUstawienia okna w postaci unsigned short:\n");
			wyswietl1(okno.widok_sh);
			printf("Uklad bitow jest nastepujacy: %s\n", int_do_binar(okno.widok_sh, bin_lan));
			
			okno.widok_sh &= ~WYP_MASKA; //czysci bity wypelnienia
			okno.widok_sh |= (WYP_NIEB | WYP_ZIEL); //ustawia wypelnienie
			okno.widok_sh ^= PRZEZR; //przelacza przezroczystosc
			okno.widok_sh |= RAMKA_CZER; //zle podejscie
			okno.widok_sh &= ~STYL_MASKA; //czysci bity stylu
			okno.widok_sh |= R_KROPKI; //ustawia styl ramki
			
			printf("\nPo dokonaniu zmian:\n");
			wyswietl(&okno.widok_st);
			printf("\nUstawienia okna w postaci unsigned short\n");
			wyswietl1(okno.widok_sh);
			printf("Uklad bitow jest nastepujacy: %s \n", int_do_binar(okno.widok_sh, bin_lan));

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 15.5 rodzial 15///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			double dx;
			char ca;
			char cx;
			double dz;
			char cb;
			char _Alignas(double) cz;
			
			printf("wyrownanie char : %zd\n", _Alignof(char));
			printf("wyrownanie double : %zd\n", _Alignof(double));
			printf("&dx: %p\n", &dx);
			printf("&ca: %p\n", &ca);
			printf("&cx: %p\n", &cx);
			printf("&dz: %p\n", &dz);
			printf("&cb: %p\n", &cb);
			printf("&cz: %p\n", &cz);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przesuwanie bitów////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int bityWlewo = 1;
	int bityWprawo = 128;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			for(int i = 0; i < 8; i++)
			{
				printf("Bity przesuwane w prawo %i\n", bityWprawo >>= 1);
				printf("Bity przesuwane w lewo  %i\n", bityWlewo <<= 1);
			}

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
////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 1 i przyk³adu 2
char *do_binar(int n, char *wsk)
{
	int i;
	static int liczba = CHAR_BIT*sizeof(int);
	for(i = liczba - 1; i >= 0; i--, n>>=1)
		wsk[i] = (01 & n) +'0'; //zakladamy kodowanie ASCII
	wsk[liczba] = '\0';
	return wsk;
}
//wyswietl lancuch binarny w blokach po 4
void pokaz_binar (const char *lan)
{
	int i = 0;
	while (lan[i]) //nie jest znakiem NULL
	{
		putchar(lan[i]);
		if(++i % 4 == 0 && lan[i])
			putchar(' ');
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 2
int odwroc_koniec(int num, int bity)
{
	int maska = 0;
	int wartbit = 1;
	
	while (bity-- > 0)
	{
		maska |= wartbit;
		wartbit <<= 1;
	}
	return num^maska;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 3
void pokaz_ustawienia(const struct wl_okna *okno)
{
	printf("Okno jest %s.\n", okno->przezrocz == true? "przezroczyste" : "nieprzezroczyste");
	printf("Kolorem wypelnienia jest %s.\n", kolory[okno->kolor_wyp]);
	printf("Ramka jest %s.\n", okno->wid_ramki == true? "widoczna" : "niewidoczna");
	printf("Kolorem ramki jest %s.\n", kolory[okno->kolor_ramki]);
	printf("Ramka jest narysowana linia ");
	switch (okno->styl_ramki)
	{
		case CIAGLA: printf("ciagla.\n"); break;
		case KROPKI: printf("wykropkowana.\n"); break;
		case KRESKI: printf("kreskowana.\n");break;
		default: printf("nieznanego typu.\n");
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
// do przyk³adu 4
void wyswietl(const struct wl_okna *okno)
{
	printf("Okno jest %s.\n", okno->przezrocz == true ? "przezroczyste" : "nieprzezroczyste");
	printf("Kolorem wypelnienia jest %s.\n", kolory[okno->kolor_wyp]);
	printf("Ramka jest %s.\n", okno->wid_ramki == true? "widoczna" : "niewidoczna");
	printf("Ramka jest narysowana linia ");
	switch (okno->styl_ramki)
	{
		case CIAGLA: printf("ciagla.\n"); break;
		case KROPKI: printf("wykropkowana.\n"); break;
		case KRESKI: printf("kreskowana.\n");break;
		default: printf("nieznanego typu.\n");
	}
	printf("Kolorem ramki jest %s.\n", kolory[okno->kolor_ramki]);
}
void wyswietl1(const unsigned short us)
{
	printf("Okno jest %s.\n", (us & PRZEZR) == PRZEZR? "przezroczyste" : "nieprzezroczyste");
	printf("Kolorem wypelnienia jest %s.\n", kolory[(us >> 1) & 07]);
	printf("Ramka jest %s.\n", (us & RAMKA) == RAMKA? "widoczna" : "niewidoczna");
	printf("Ramka jest narysowana linia ");
	switch (us & STYL_MASKA)
	{
		case R_CIAGLA: printf("ciagla.\n"); break;
		case R_KROPKI: printf("wykropkowana.\n"); break;
		case R_KRESKI: printf("kreskowana.\n");break;
		default: printf("nieznanego typu.\n");
	}
	printf("Kolorem ramki jest %s.\n", kolory[(us >> 9) & 07]);
}
char *int_do_binar(int n, char *wl)
{
	int i;
	static int rozmiar = CHAR_BIT * sizeof(unsigned int);
	
	for(i = rozmiar - 1; i >= 0; i--, n>>=1)
		wl[i] = (01 & n) + '0';
	wl[rozmiar] = '\0';
	return wl;
}