#include <stdio.h>
#include <ansi_c.h>
#include "pe12-2a.h"

#define SYSTEM_USA "(US)"
#define SYSTEM_EU "(EU)"

static int wybrany;
static int dystans;
static double paliwo;

void wybierz_tryb(int tryb)
{	
	if((tryb == 0) || (tryb == 1)) wybrany = tryb;
	else
	{ 
		printf("Podano nieprawidlowa wartosc. Wybrano system ");
		if(wybrany) printf( "%d%s.\n", wybrany, SYSTEM_USA);
		else printf( "%d%s.\n", wybrany, SYSTEM_EU);
	}
}
void pobierz_dane(void)
{
	if(!wybrany)
		printf("Wprowadz przebyta odleglosc w kilometrach: ");
	else
		printf("Wprowadz przebyta odleglosc w milach: ");
	
	scanf("%d", &dystans);
	
	if(!wybrany)
		printf("Wprowadz zuzyte paliwo w litrach: ");
	else
		printf("Wprowadz zuzyte paliwo w galonach: ");
	
	scanf("%lf", &paliwo);
}
void wyswietl_dane(void)
{
	if(!wybrany)
		printf("Zyzycie paliwa wynioslo: %.2lf litrow na 100km\n", (double)paliwo/((double)dystans/100.0));
	else
		printf("Zyzycie paliwa wynioslo: %.1lf mil na galon\n", (double)dystans/paliwo);
	
	while (getchar() != '\n');
}