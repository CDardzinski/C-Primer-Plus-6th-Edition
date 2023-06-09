//lista.c -- funkcje realizujace operacje na liscie 
//listing 17.5

//lista_cw2.c -- plik zmodyfikowany pod �wiczenie 2

#include <stdio.h>
#include <stdlib.h>
#include "lista_cw2.h"

//funkcje lokalne
static void KopiujDoWezla(Pozycja pozycja, Wezel *wwezel);

//funkcje interfejsu
//inicjalizuje liste jako pusta
void InicjujListe(Lista *wlista)
{
	wlista->glowny = NULL;
	wlista->koniec = NULL;
}
//zwraca prawde, jesli lista jest pusta
bool PustaLista(const Lista *wlista)
{
	if(wlista->glowny == NULL)
		return true;
	else return false;
}
//zwraca prawde, jesli lista jest pelna
bool PelnaLista(const Lista *wlista)
{
	Wezel *wsk;
	bool full;
	wsk = (Wezel *)malloc(sizeof(Wezel));
	if(wsk == NULL)
		full = true;
	else
		full = false;
	free(wsk);
	return full;
}
//zwraca liczbe wezlow
unsigned int LiczbaPozycji(const Lista *wlista)
{
	unsigned int licznik = 0;
	Wezel *w = wlista->glowny; //ustawia na poczatku listy
	while (w != NULL)
	{
		++licznik;
		w = w->nast; //sprawia, ze w wskazuje na nastepny wezel
	}
	return licznik;
}
//tworzy wezel przechowujacy pozycje i dodaje go na koncu listy wskazywanej przez wlista (wolna implemwntacja)
bool DodajPozycje(Pozycja pozycja, Lista *wlista)
{
	Wezel *wnowy;
	Wezel *szuk;
	
	wnowy = (Wezel*) malloc(sizeof(Wezel));
	if(wnowy == NULL)
		return false; //konczy funkcje w razie niepowodzenia
	KopiujDoWezla(pozycja, wnowy);
	wnowy->nast = NULL;
	if(wlista->glowny == NULL) //lista jest pusta, wnowy nalezy
		wlista->glowny = wnowy; //wiec umiesc na jej poczatku
	else
	{
		szuk = wlista->glowny;
		while (szuk->nast != NULL)
			szuk = szuk->nast; //znajduje koniec listy
		szuk->nast = wnowy; //dodaje wnowy ma koncu		//////////////////DZIA�A!!!!!!
	}
	return true;
}
//"odwiedza" kazdy wezel i wykonuje funkcje wskazywana przez wfun
void Przejdz (const Lista *wlista, void(*wfun)(Pozycja pozycja))
{
	Wezel *wsk = wlista->glowny; //od poczatku listy
	while (wsk != NULL)
	{
		(*wfun) (wsk->pozycja); //stosuje funkcje do pozcji
		wsk = wsk->nast; //przechodzi do nastepnego wezla
	}
}
//zwalnia pamiec przydzielona przez malloc() i ustawia wskaznik na NULL
void CzyscListe(Lista *wlista)
{
	Wezel * wsk;
	while (wlista->glowny != NULL)
	{
		wsk = (wlista->glowny)->nast; //zapisuje adres wezla
		free(wlista->glowny); //zwlania wezel
		wlista->glowny = wsk; //przechodzi do nastepnego wezla
	}
}
//definicja funkcji lokalnej 
//kopiuje element do wezla
static void KopiujDoWezla(Pozycja pozycja, Wezel *wwezel)
{
	wwezel->pozycja = pozycja;
}						  