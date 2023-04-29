//kolejka.c -- impelementacja typu "kolejka"
//listing 17.7
#include <stdio.h>
#include <stdlib.h>
#include "kolejka.h"

//funkcje lokalne
static void KopiujDoWezla(Pozycja_Kolejki pozycja, Wezel_kolejka *ww);
static void KopiujDoPozycji(Wezel_kolejka *ww, Pozycja_Kolejki *wp);

void InicjujKolejke(Kolejka *wk)
{
	wk->przod = wk->tyl = NULL;
	wk->Pozycje_W_kolejce = 0;
}
bool PelnaKolejka(const Kolejka *wk)
{
	return wk->Pozycje_W_kolejce == MAXKOLEJKA;
}
bool PustaKolejka(const Kolejka *wk)
{
	return wk->Pozycje_W_kolejce == 0;
}
int LiczbaPozycjiKolejki(const Kolejka *wk)
{
	return wk->Pozycje_W_kolejce;
}	
bool Ustaw(Pozycja_Kolejki pozycja, Kolejka *wk)
{
	Wezel_kolejka *wnowy;
	if(PelnaKolejka(wk))
		return false;
	wnowy = (Wezel_kolejka *) malloc(sizeof(Wezel_kolejka));
	if(wnowy == NULL)
	{
		fprintf(stderr, "Blad alokacji pamieci!\n");
		exit(1);
	}
	KopiujDoWezla(pozycja, wnowy);
	wnowy->nast = NULL;
	
	if(PustaKolejka(wk))
		wk->przod = wnowy;
	else
		wk->tyl->nast = wnowy;
	wk->tyl = wnowy;
	wk->Pozycje_W_kolejce++;
	return true;
}
bool Odlacz(Pozycja_Kolejki *wpozycja, Kolejka *wk)
{
	Wezel_kolejka *wsk;
	if(PustaKolejka(wk))
		return false;
	KopiujDoPozycji(wk->przod, wpozycja);
	wsk = wk->przod;
	wk->przod = wk->przod->nast;
	free(wsk);
	wk->Pozycje_W_kolejce--;
	if(wk->Pozycje_W_kolejce == 0)
		wk->tyl = NULL;
	return true;
}
//oproznianie kolejki
void WyczyscKolejke(Kolejka *kol)
{
	Pozycja_Kolejki fikcyjny;
	while (!PustaKolejka(kol))
		Odlacz(&fikcyjny, kol);
}
//funkcje lokalne
static void KopiujDoWezla(Pozycja_Kolejki pozycja, Wezel_kolejka *ww)
{
	ww->Pozycja_Wezla_kolejki = pozycja;
}
static void KopiujDoPozycji(Wezel_kolejka *ww, Pozycja_Kolejki *wp)
{
	*wp = ww->Pozycja_Wezla_kolejki;
}