#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "Ksi¹¿ka_PRATA_C_rodzial4_cwiczenia.h"
#include <float.h>

#define DZIELNIK 100 //do cwiczenia 4

static int panelroz4;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelroz4 = LoadPanel (0, "Ksi¹¿ka_PRATA_C_rodzial4_cwiczenia.uir", PANELROZ4)) < 0)
		return -1;
	DisplayPanel (panelroz4);
	RunUserInterface ();
	DiscardPanel (panelroz4);
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////Æwiczenie 1 rodzia³ 4 strona 167///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Cwiczenie1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char imie[40], nazwisko[40];
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj swoje imie\n");
			scanf("%s", imie);
			printf("Podaj swoje nazwisko\n");
			scanf("%s", nazwisko);
			printf("%s , %s\n", nazwisko, imie);
			printf("-------------------------------------------------------------------------------------------------------------------\n");

			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////Æwiczenie 2 rodzia³ 4 strona 167///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Cwiczenie2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char imie[40];
	int dlugosc;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj swoje imie\n");
			scanf("%s", imie);
			printf("\"%s\"\n", imie); //pkt a
			printf("\"%20s\"\n", imie); //pkt b
			printf("\"%-20s\"\n", imie); //pkt c
			dlugosc = strlen(imie);
			dlugosc = dlugosc + 3;
			printf("%*s\n",dlugosc, imie); //pkt d
			printf("-------------------------------------------------------------------------------------------------------------------\n");
			

			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////Æwiczenie 3 rodzia³ 4 strona 167///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Cwiczenie3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	float liczba;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj liczbe zmiennoprzecinkowa\n");
			scanf("%f", &liczba);
			printf("Wpisana liczbe %.1f lub %.1e\n", liczba, liczba); //pkt a
			printf("Wpisana liczbe %+.3f lub %.3E\n", liczba, liczba); //pkt b
			printf("-------------------------------------------------------------------------------------------------------------------\n");		

			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////Æwiczenie 4 rodzia³ 4 strona 167///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Cwiczenie4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	float wzrostcm, wzrostm;
	char imie[40];
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj swoje imie\n");
			scanf("%s", imie);
			printf("Podaj wzrost w cm.\n");
			scanf("%f", &wzrostcm);
			wzrostm = wzrostcm/DZIELNIK;
			printf("%s, masz %.2f metra wzrostu.\n", imie, wzrostm);
			printf("-------------------------------------------------------------------------------------------------------------------\n");		

			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////Æwiczenie 5 rodzia³ 4 strona 167///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Cwiczenie5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	float rozmiarPliku;
	float predkoscPobierania;
	float czasPobierania;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Predkoœc pobierania w megabitach na sekunde:\n");
			scanf("%f", &predkoscPobierania);
			printf("Rozmiar pliku w megabajtach\n");
			scanf("%f", &rozmiarPliku);
			czasPobierania = (rozmiarPliku*8)/predkoscPobierania;
			printf("Przy  %.2f megabitow na sekunde plik o rozmiarze %.2f megabajta zostanie pobrany w %.2f sekundy.\n", predkoscPobierania, rozmiarPliku, czasPobierania);
			printf("-------------------------------------------------------------------------------------------------------------------\n");	

			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////Æwiczenie 6 rodzia³ 4 strona 167///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Cwiczenie6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char imie[40], nazwisko[40];
	int dlugoscImie, dlugoscNazwisko;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj swoje imie\n");
			scanf("%s", imie);
			printf("Podaj swoje nazwisko\n");
			scanf("%s", nazwisko);
			dlugoscImie = strlen(imie);
			dlugoscNazwisko = strlen(nazwisko);
			printf("%s %s\n", imie, nazwisko);
			printf("%*d %*d\n", dlugoscImie, dlugoscImie, dlugoscNazwisko, dlugoscNazwisko); //pierwszy przyk³ad
			printf("+++++++++++++++++++++++++++++++\n");
			printf("%s %s\n", imie, nazwisko);//drugi przyk³ad
			printf("%d %*d\n", dlugoscImie, dlugoscImie, dlugoscNazwisko);
			printf("-------------------------------------------------------------------------------------------------------------------\n");	

			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////Æwiczenie 7 rodzia³ 4 strona 168///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Cwiczenie7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	float wartosc1 = 1.0/3.0;
	double wartosc2 = 1.0/3.0;
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			printf("float -> %.4f\n", wartosc1);
			printf("double -> %.4f\n", wartosc2);
			printf("=============================\n");
			printf("float -> %.12f\n", wartosc1);
			printf("double -> %.12f\n", wartosc2);
			printf("=============================\n");
			printf("float -> %.16f\n", wartosc1);
			printf("double -> %.16f\n", wartosc2);
			printf("float prezycja => %d\n", FLT_DIG);
			printf("double prezycja => %d\n", DBL_DIG);
			printf("-------------------------------------------------------------------------------------------------------------------\n");

			break;
		}
	return 0;
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////Æwiczenie 8 rodzia³ 4 strona 168///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Cwiczenie8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	float galons;
	float miles;
	
	const float galonToLiter = 3.785;
	const float MilesToKilometers = 1.609;
	
	switch (event)
		{
		case EVENT_COMMIT:
			printf("Ile mil przebyles?\n");
			scanf("%f", &miles);
			printf("Ile galonow paliwa zuzyles?\n");
			scanf("%f", &galons); 
			printf("Spalenie wynosi %.1f mil/galon\n", miles/galons);
			printf("Spalanie wynosi %.1f l/100km\n", (((galonToLiter*galons)/(miles*MilesToKilometers))*100.0));
			printf("-------------------------------------------------------------------------------------------------------------------\n");
			break;
		}
	return 0;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////Wyjœcie////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


