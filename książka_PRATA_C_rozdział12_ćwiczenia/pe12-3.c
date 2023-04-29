#include <stdio.h>
#include <ansi_c.h>
#include "pe12-3.h"

#define SYSTEM_USA "(US)"
#define SYSTEM_EU "(EU)"

int wybierz_tryb_auto(int wybrany, int tryb)
{		
	if((tryb == 0) || (tryb == 1)) wybrany = tryb;
	else
	{ 
		printf("Podano nieprawidlowa wartosc. Wybrano system ");
		if(wybrany) printf( "%d%s.\n", wybrany, SYSTEM_USA);
		else printf( "%d%s.\n", wybrany, SYSTEM_EU);
	}
	return wybrany;
}
void pobierz_dane_auto(int *dystans, double *paliwo, int wybrany)
{
	if(!wybrany)
		printf("Wprowadz przebyta odleglosc w kilometrach: ");
	else
		printf("Wprowadz przebyta odleglosc w milach: ");
	
	scanf("%d", dystans);
	
	if(!wybrany)
		printf("Wprowadz zuzyte paliwo w litrach: ");
	else
		printf("Wprowadz zuzyte paliwo w galonach: ");
	
	scanf("%lf", paliwo);
}
void wyswietl_dane_auto(int dystans, double paliwo, int wybrany)
{
	if(!wybrany)
		printf("Zyzycie paliwa wynioslo: %.2lf litrow na 100km\n", (double)paliwo/((double)dystans/100.0));
	else
		printf("Zyzycie paliwa wynioslo: %.1lf mil na galon\n", (double)dystans/paliwo);
	
	while (getchar() != '\n');
}