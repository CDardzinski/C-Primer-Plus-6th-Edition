///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 12.11 rodzial 12///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////U¿yty do rozwiazania æwiczenia 7 rozdzial 12 (lekko przerobiony)//////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "rzutkosc_cwiczenia.h"
#include <stdio.h>
#include <stdlib.h> //potrzebujemy funkcji rand()

int liczba_rzutow = 0; //lacznosc zewnetrzna

int rzucaj(int scianki) //prywatne w ramach pliku
{ 
	int oczka;
	oczka = rand() % scianki + 1;
	++liczba_rzutow; //zlicza wywolania funkcji
	
	return oczka;
}
int rzucaj_n_razy(int rzuty, int scianki)
{
	int k;
	int suma = 0;
	
	if(scianki < 2)
	{
		printf("wymagane sa co najmniej 2 scianki.\n");
		return -2;
	}
	if(rzuty < 1)
	{
		printf("Wymagany co najmniej 1 rzut.\n");
		return -1;
	}
	
	for(k = 0; k < rzuty; k++)
		suma += rzucaj(scianki);
	
	return suma;
}