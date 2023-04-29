//przyk³ad 16.7 do rozdzia³u 16
//tworzenie pliku do³¹czanego c
#include <stdio.h>
#include "daneos.h" //dolacz plik naglowkowy
//definicja funkcji
void wprowadz(daneos *wskn) 
{
	int i;
	
	printf("Prosze podac imie: ");
	wczytaj(wskn->imie, DL_LAN);
	printf("Prosze podac nazwisko: ");
	wczytaj(wskn->nazw, DL_LAN);
}
void wyswietl(const daneos *wskn)
{
	printf("%s %s", wskn->imie, wskn->nazw);
}
char *wczytaj(char *z, int ile)
{
	char *wynik;
	char *tutaj;
	
	wynik = fgets(z, ile, stdin);
	
	if(wynik)
	{
		tutaj = strchr(z, '\n'); //szukamy nowego wiersza
		if(tutaj)	//jesli adres jest rozny od NULL
			*tutaj = '\0'; //zmieniamy znak nowego wiersza na pusty
		else
			while(getchar() != '\n')
				continue;
	}
	return wynik;
}