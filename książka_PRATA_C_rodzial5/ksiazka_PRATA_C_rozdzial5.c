#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial5.h"

//Sta³a
#define KOREKTA -1 //jeden rodzaj sta³ej //listing 5.1
#define POLA 64//pola na szachownicy //do przyk³adu 5.5
#define SEK_NA_MIN 60 // sekundy na minuty //do przyk³adu 5.9
#define  MAX 100 // do przyk³adu 5.12

//prototypy funkcji
void hash(int n); //prototyp do listingu 5.15

static int panelroz5;

int main (int argc, char *argv[])
	{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelroz5 = LoadPanel (0, "ksiazka_PRATA_C_rozdzial5.uir", PANELROZ5)) < 0)
		return -1;
	DisplayPanel (panelroz5);
	RunUserInterface ();
	DiscardPanel (panelroz5);
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.1 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	const double MNOZNIK = 0.666666;//drugi rodzaj sta³ej
	double but, stopa;
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			but = 42.0;
			stopa = MNOZNIK * but + KOREKTA;
			printf("Rozmiar buta	Dlugosc stopy\n");
			printf("%8.2f %15.2f cm\n", but, stopa);
			printf("------------------------------------------------------------------------------------\n");

			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.2 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	const double MNOZNIK = 0.666666;//drugi rodzaj sta³ej
	double but, stopa;
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			printf("Rozmiar buta	Dlugosc stopy\n");
			but = 24.0;
			
			while(but < 45)	//Poczatek petli while
				{	//poczatek bloku
					stopa = MNOZNIK * but + KOREKTA;
					printf("%8.1f %15.2f cm\n", but, stopa);
					but = but + 1.0;
				} //koniec bloku
			
			printf("Jesli but pasuje, nos go.\n");
			printf("------------------------------------------------------------------------------------\n");

			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.3 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int jane, tarzan, gepard;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			gepard = tarzan = jane = 68;
			printf("			gepard	tarzan	 jane\n");
			printf("Wynik pierwszej rundy  %4d %8d %8d\n", gepard, tarzan, jane);
			printf("------------------------------------------------------------------------------------\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.4 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int num = 1;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			while(num < 21)
			{
				printf("%4d %6d\n", num, num*num);
				num = num + 1;
			}

			printf("------------------------------------------------------------------------------------\n");
			
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.5 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const double PLON = 2E16; //roczna swiatowa produkcja przenicy
	double biezace, suma;
	int licznik = 1;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("pole	dodane ziarna	suma ziaren		");
			printf("czesc rocznej\n");
			printf("                                                          ");
			printf("produkcji swiatowej\n");
			
			suma = biezace = 1.0;	//zaczynamy od jednego ziarna
			printf("%3d %15.2e %14.2e %14.2e\n", licznik, biezace, suma, suma/PLON);
			
			while (licznik < POLA)
			{
				licznik = licznik + 1;
				biezace = 2.0 * biezace; //podwojona lizna ziaren na nastepnym polu
				suma = suma + biezace; //aktualizacja sumy
				printf("%3d %15.2e %14.2e %14.2e\n", licznik, biezace, suma, suma/PLON);
			}

			printf("------------------------------------------------------------------------------------\n");
			
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.6 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("dzielenie calkowite:	5/4	is %d\n", 5/4);
			printf("dzielenie calkowite:	6/3	is %d\n", 6/3);
			printf("dzielenie calkowite:	7/4	is %d\n", 7/4);
			printf("dzielenie zmienneorz.:	7./4.	is %1.2f\n", 7./4.);
			printf("dzielenie mieszane:	7./4	is %1.2f\n", 7./4);
			
			printf("------------------------------------------------------------------------------------\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.7 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int rekord, wynik;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			rekord = wynik = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
			printf("rekord %d, wynik = %d\n", rekord, wynik);
			
			printf("------------------------------------------------------------------------------------\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.8 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int  n = 0;
	size_t intsize;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			intsize = sizeof(int);
			printf("n = %d, n ma %zd bajty; wszystkie liczby calkowiete maja %zd bajty.\n", n, sizeof n, intsize);
			
			printf("------------------------------------------------------------------------------------\n");
			

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.9 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int sec, min, left;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Konwertuje sekundy na minuty i sekundy!\n");
			printf("Podaj liczbe sekund (<= 0 to koniec):\n");
			scanf("%d", &sec); //wczytaj liczbe sekund
			
			while (sec > 0)
			{
				min = sec/SEK_NA_MIN; //obcina liczbe minut
				left = sec % SEK_NA_MIN; //pozostala liczba sekund
				printf("%d sekund to %d minut, %d sekund.\n", sec, min, left);
				printf("Podaj kolejna wartosc (<= 0 to koniec):\n");
				scanf("%d", &sec);
			}
			printf("Koniec!\n");
			printf("------------------------------------------------------------------------------------\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.10 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int ultra = 0, super = 0;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			while (super < 5)
			{
				super++;
				++ultra;
				printf("super = %d, ultra = %d \n", super, ultra);
				
			}
			printf("------------------------------------------------------------------------------------\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.11 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int a = 1, b = 1;
	int aplus, plusb; 
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			aplus = a++; //wartoœæ a++ w momencie przypisania
			plusb = ++b; //wartosc ++b w momencie  przypisania
			
			printf("a		aplus		b		plusb\n");
			printf("%1d 	%5d 		%5d 		%5d\n", a, aplus, b, plusb);
			printf("------------------------------------------------------------------------------------\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.12 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad12ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int licznik = MAX + 1;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			while (--licznik > 0)
			{
				printf("%d butelek piwa na stole,"
					   	 "%d butelek piwa!\n", licznik, licznik);
				printf("Wez jedna i pusc ja w krag,\n");
				printf("%d butelek piwa!\n\n", licznik - 1);
				
			}
			
			printf("------------------------------------------------------------------------------------\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.13 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad13ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{ 
	int licznik, suma; //instrukcja deklaracji
	
	switch (event)
	{
		case EVENT_COMMIT:
			licznik = 0; //instrukcja przypisania
			suma = 0; //jak wy¿ej
			
			while (licznik++ < 20)//winstrukcja
				suma = suma + licznik; //while
			printf("suma = %d\n", suma); //instrukcja wywolania funkcji
			
			printf("------------------------------------------------------------------------------------\n");
			break;
	}
	return 0; //instrukcja zwrotu
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.14 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad14ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char ch;
	int i;
	float fl;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			fl = i = ch = 'C';
			printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
			ch = ch + 1;
			i = fl + 2 * ch;
			fl = 2.0 * ch + i;
			printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
			ch = 1107;
			printf("Teraz ch = %c\n", ch);
			ch = 80.89;
			printf("Teraz ch = %c\n", ch);
			
			printf("------------------------------------------------------------------------------------\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.15 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad15ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	int razy = 5; 
	char ch = '!'; //kod ASCII wykrzyknika to 33
	float  f = 6.0;
	switch (event)
		{
		case EVENT_COMMIT:
			
			hash(razy);	//argument typu int
			hash(ch);	//char jest automatycznie przetwarzany na int
			hash(f);	//rzutowanie wymusza konwersje f do int
			
			printf("------------------------------------------------------------------------------------\n");
			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 5.16 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad16ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const int S_W_M = 60; //liczba sekund w 1 minucie
	const int S_W_H = 3600; // liczba sekund w 1 godzinie
	
	double dyst; //pokonany dystans w km
	double predkosc; // srednia predkosc w km/h
	int min, sek; // minuty i sekundy czasu biegu
	int czas; //czas biegu w samych sekundach
	double czas_km; // czas na 1km w sekundach
	int min_km, sek_km; //minuty i sekundy czasu na 1 km
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Ten program zmienia Twój czas w biegu na dowolny dystans\n");
			printf("na czas przebiegniecia 1km oraz na srednia predkosc w km/h. \n");
			printf("Wpisz pokonana odleglosc w kilometrach. \n");
			scanf("%lf", &dyst); //%lf odczytuje wartosc typu double
			printf("Wpisz swoj czas w minutach i sekundach. \n");
			printf("Zacznij od podania liczny minut. \n");
			scanf("%d", &min);
			printf("Teraz podaj liczbe sekund. \n");
			scanf("%d", &sek);
			
			czas = S_W_M * min + sek; //zmienia czas na lcizbe sekund
			predkosc = dyst / czas * S_W_H; //km na sek x liczba sek w godzinie = km\h
			czas_km = (double) czas / dyst; //czas/dystans = czas na km
			min_km = (int) czas_km / S_W_M; //oblicza liczbe pelnych minut
			sek_km = (int) czas_km % S_W_M; //oblicza liczbe pozostalych sekund
			
			printf("Przebiegles %1.2f km w  czasie %d minut, %d sekund. \n", dyst, min, sek);
			printf("Odpowiada to przebiegnieciu 1 km w  czasie %d minut, ", min_km);
			printf("%d sekund.\nTwoja srednia predkosc to %1.2f km/h.\n", sek_km, predkosc);
			
			printf("------------------------------------------------------------------------------------\n");		
			break;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Wyjœcie//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////Funkcja do listingu 5.15 rodzial 5///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void hash(int n)//naglowek funkcji w stylu ANSI informuje,
	{			//ze funkcja pobiera jeden argument typu int
		while (n-- > 0)
			printf("#");
		printf("\n");	
	}