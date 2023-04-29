#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "Ksiazka_PRATA_C_rodzial5_cwiczenia.h"

static int panelHandle;

//prototyp funkcji
int PrzeliczFloatDoTrzeciePotegi(float liczba, float *liczbaWTrzeciejPotedze);
int PrzeliczFahrenheitaNaCelsjuszaKelwina(double TempFahrenheit);



int main (int argc, char *argv[])
	{
	
	//setlocale("", LC_ALL);
	
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "Ksiazka_PRATA_C_rodzial5_cwiczenia.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////Æwiczenie 1 rodzia³ 5 strona 212///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1Callback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	
	const int stala = 60;
	int sek, min, godz, left;
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			
			printf("Konwertuje sekundy na minuty i godziny!\n");
			printf("Podaj liczbe sekund (<= 0 to koniec):\n");
			scanf("%d", &sek); //wczytaj liczbe sekund
	
			while (sek > 0)
			{
				min = sek/stala; //obcina liczbe minut
				if(min >= 60) 
					{
					godz = min/60; 
					min = min - (godz * 60);
					}
				else godz = 0;
				left = sek % stala; //pozostala liczba sekund
				
				printf("%d sekund to %d godzin, %d minut, %d sekund.\n", sek, godz, min, left);
				printf("Podaj kolejna wartosc (<= 0 to koniec):\n");
				scanf("%d", &sek);
			}
			printf("Koniec!\n");
			printf("------------------------------------------------------------------------------------\n");

			break;
		}
	return 0;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////Æwiczenie 2 rodzia³ 5 strona 212///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2Callback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	int liczba, liczba1;
	switch (event)
		{			
		case EVENT_COMMIT:
			
			printf("Podaj liczbe calkowita\n");
			scanf("%d", &liczba); //wczytaj liczbe sekund
			
			if(liczba != 0)
				{
				liczba1 = liczba;
				printf("Kolejne liczby calkowite:\t");
				printf("%d ", liczba);
				while(liczba1++ < (liczba + 10)) printf("%d ", liczba1);
				}
			
			printf("\nKoniec!\n");
			printf("------------------------------------------------------------------------------------\n");

			break;
		}
	return 0;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////Æwiczenie 3 rodzia³ 5 strona 212///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3Callback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	const int stala = 7;
	int dni, tygodnie, reszta;
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			printf("Konwertuje dni na  tygodnie i dni!\n");
			printf("Podaj iloœc dni (<= 0 to koniec):\n");
			scanf("%d", &dni); //wczytaj liczbe sekund
	
			while (dni > 0)
			{
				tygodnie = dni/stala; //obcina liczbe minut
				reszta = dni % stala; //pozostala liczba sekund
				
				printf("%d dni to %d tygodni i %d dni.\n", dni, tygodnie, reszta);
				printf("Podaj kolejna wartosc (<= 0 to koniec):\n");
				scanf("%d", &dni);
			}
			printf("Koniec!\n");
			printf("------------------------------------------------------------------------------------\n");

			break;
		}
	return 0;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////Æwiczenie 4 rodzia³ 5 strona 212///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4Callback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	float wzrost;
	const double CALE = 2.54, STOPA = 30.48;
	double stopy, reszta;
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			printf("Podaj wzrost w cm: ");
			//printf("Podaj wzrost w cm (<= 0 to koniec):\n");
			scanf("%f", &wzrost); 
			
			while (wzrost > 0)
			{
				stopy = (wzrost-STOPA)/STOPA; 
				reszta = wzrost/CALE;
				
				printf("%.1f cm to %1.f stop,  %.2f cali.\n", wzrost, stopy, reszta);
				printf("Podaj kolejna wartosc (<= 0 to koniec):\n");
				scanf("%f", &wzrost); 
			}
			

			printf("Koniec!\n");
			printf("------------------------------------------------------------------------------------\n");
			break;
		}
	return 0;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////Æwiczenie 5 rodzia³ 5 strona 213///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5Callback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	int licznik, suma, wartosc; //instrukcja deklaracji
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			printf("Podaj ilosc elementow do zsumowania: ");
			scanf("%d", &wartosc); 
			
			licznik = 0; //instrukcja przypisania
			suma = 0; //jak wy¿ej
			
			while (licznik++ < wartosc)//instrukcja
				suma = suma + licznik; //while
			printf("suma = %d\n", suma); //instrukcja wywolania funkcji
			
			printf("Koniec!\n");
			printf("------------------------------------------------------------------------------------\n");
			

			break;
		}
	return 0;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////Æwiczenie 6 rodzia³ 5 strona 213///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6Callback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	int licznik, suma, wartosc; //instrukcja deklaracji
	switch (event)
		{
		case EVENT_COMMIT:
			
			printf("Podaj ilosc elementow do zsumowania sumy kwadratow: ");
			scanf("%d", &wartosc); 
			
			licznik = 0; //instrukcja przypisania
			suma = 0; //jak wy¿ej
			
			while (licznik++ < wartosc)//instrukcja
				{
				suma = suma + (licznik*licznik); //while
				printf("%d\n", suma);
				}
			printf("suma = %d\n", suma); //instrukcja wywolania funkcji
			
			printf("Koniec!\n");
			printf("------------------------------------------------------------------------------------\n");

			break;
		}
	return 0;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////Æwiczenie 7 rodzia³ 5 strona 213///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7Callback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	float liczba;
 	float liczbaWTrzeciejPotedze; 
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			printf("Podaj liczbe rzeczywista:  ");
			scanf("%f", &liczba); 
			
			PrzeliczFloatDoTrzeciePotegi(liczba, &liczbaWTrzeciejPotedze);
			
			printf("Koniec!\n");
			printf("------------------------------------------------------------------------------------\n");
			break;
		}
	return 0;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////Æwiczenie 8 rodzia³ 5 strona 213///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8Callback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	
	int dzielnik, dzielna, wynik;
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			printf("Program obliczajacy reszte z dzielnia.\n");
			printf("Podaj dzielnik (liczba calkowita): ");
			scanf("%d", &dzielnik); 
			
			printf("Podaj dzielna: ");
			scanf("%d", &dzielna);
			
			while (dzielna > 0)//instrukcja
				{
				wynik = dzielna % dzielnik;
				printf("%d %% %d wynosi %d\n", dzielna, dzielnik, wynik);
				
				printf("Podaj dzielna (<= 0 to koniec):\n");
				scanf("%d", &dzielna);
				}
			
			printf("Koniec!\n");
			printf("------------------------------------------------------------------------------------\n");


			break;
		}
	return 0;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////Æwiczenie 9 rodzia³ 5 strona 213///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9Callback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	
	float TempFahrenheit;
 	int	status;
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			printf("Program obliczajacy temperatur.\n");
			printf("Podaj temperature w stopniach Fahrenheita: ");
			status = scanf("%f", &TempFahrenheit); 
			
			while (TempFahrenheit > 0)//instrukcja
				{
					if(status == 1)
						{
							PrzeliczFahrenheitaNaCelsjuszaKelwina(TempFahrenheit);
							printf("Podaj temperature w stopniach Fahrenheita:(wartosc 0 lub inna niz liczba => WYJSCIE)  ");
							status = scanf("%f", &TempFahrenheit); 
						}
					else break;
				}
				
			
			printf("Koniec!\n");
			printf("------------------------------------------------------------------------------------\n");

			break;
		}
	return 0;
	}
/////////////////////////////Wyjœcie
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
/////////////////////////////////////////////////////Funkcje pomocnicze
int PrzeliczFloatDoTrzeciePotegi(float liczba, float *liczbaWTrzeciejPotedze)
	{
	*liczbaWTrzeciejPotedze = liczba * liczba * liczba;
	printf("Podana liczba w trzeciej potedze: %.3f\n", *liczbaWTrzeciejPotedze);
	return 0;
	}

int PrzeliczFahrenheitaNaCelsjuszaKelwina(double TempFahrenheit)
	{
	const double Kelwin = 273.16;
	double TempCelsujsz, TempKelwina;
	
	TempCelsujsz = 5.0/9.0 * (TempFahrenheit - 32.0);
	TempKelwina = TempCelsujsz + Kelwin;
	
	printf("Stopnie Fahrenheita: %.2f\n"
		   "Stopnie Celsujsza:   %.2f\n"
		   "Stopnie Kelwina:     %.2f\n", TempFahrenheit, TempCelsujsz, TempKelwina);
	
	return 0;
	}