//drzewo.c -- funkcje do obslugi drzewa
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "drzewo.h"

//lokalny typ danych
typedef struct para {
	Wezel_Drzewo *rodzic;
	Wezel_Drzewo *dziecko;
}Para;

//prototyp funkcji lokalnych
static Wezel_Drzewo *UtworzWezel(const Pozycja_Drzewo *wp);
static bool NaLewo(const Pozycja_Drzewo *p1, const Pozycja_Drzewo *p2);
static bool NaPrawo(const Pozycja_Drzewo *p1, const Pozycja_Drzewo *p2);
static void DodajWezel(Wezel_Drzewo *nowy, Wezel_Drzewo *korzen);
static void PoKolei(const Wezel_Drzewo *korzen, void (*wfun)(Pozycja_Drzewo pozycja));
static Para SzukajPozycji(const Pozycja_Drzewo *wp, const Drzewo *wdrzewo);
static void UsunWezel(Wezel_Drzewo **wsk);
static void UsunWszystkieWezly(Wezel_Drzewo *wsk);

//definicje funkcji
void InicjujDrzewo(Drzewo *wdrzewo)
{
	wdrzewo->korzen = NULL;
	wdrzewo->rozmiar = 0;
}
bool PusteDrzewo(const Drzewo *wdrzewo)
{
	if(wdrzewo->korzen ==NULL)
		return true;
	else
		return false;
}
bool PelneDrzewo(const Drzewo *wdrzewo)
{
	if(wdrzewo->rozmiar == MAXPOZYCJI)
		return true;
	else
		return false;
}
int LiczbaPozycjiDrzewo(const Drzewo *wdrzewo)
{
	return wdrzewo->rozmiar;
}
bool DodajPozycjeDrzewo(const Pozycja_Drzewo *wp, Drzewo *wdrzewo)
{
	Wezel_Drzewo *nowy;
	if(PelneDrzewo(wdrzewo))
	{
		fprintf(stderr, "Drzewo jest pelne\n");
		return false;	//wczesny powrot
	}
	if(SzukajPozycji(wp, wdrzewo).dziecko != NULL)
	{
		fprintf(stderr, "Proba dodania istniejacej pozycji\n");
		return false;	//wczesny powrot
	}
	nowy = UtworzWezel(wp);	//nowy wskazuje na nowy wezel
	if(nowy == NULL)
	{
		fprintf(stderr, "Nie mozna utworzyc wezla\n");
		return false;	//wczesny powrot
	}
	//utworznie nowego wezla sie powiodlo
	wdrzewo->rozmiar++;
	if(wdrzewo->korzen == NULL)//przypadek 1: drzewo jest puste
		wdrzewo->korzen = nowy;	//nowy wezel jest korzeniem drzewa
	else		//przypadek 2: drzewo nie jest puste
		DodajWezel(nowy, wdrzewo->korzen); //dodaje nowy wezel do drzewa
	return true;		
}
bool WDrzewie(const Pozycja_Drzewo *wp, const Drzewo *wdrzewo)
{
	return (SzukajPozycji(wp, wdrzewo).dziecko == NULL) ? false : true;
}
bool UsunPozycjeDrzewo(const Pozycja_Drzewo *wp, Drzewo *wdrzewo)
{
	Para szuk;
	szuk = SzukajPozycji(wp, wdrzewo);
	if(szuk.dziecko == NULL)
		return false;
	if(szuk.rodzic == NULL) //usuwa pozycje w korzeniu
		UsunWezel(&wdrzewo->korzen);
	else if(szuk.rodzic->lewy == szuk.dziecko)
		UsunWezel(&szuk.rodzic->lewy);
	else
		UsunWezel(&szuk.rodzic->prawy);
	wdrzewo->rozmiar--;
	return true;
}
void PrzejdzDrzewo(const Drzewo *wdrzewo, void (*wfun)(Pozycja_Drzewo pozycja))
{
	if(wdrzewo != NULL)
		PoKolei(wdrzewo->korzen, wfun);
}
void UsunWszystkoDrzewo(Drzewo *wdrzewo)
{
	if(wdrzewo != NULL)
		UsunWszystkieWezly(wdrzewo->korzen);
	wdrzewo->korzen = NULL;
	wdrzewo->rozmiar = 0;
}

//funkcje lokalne
static Wezel_Drzewo *UtworzWezel(const Pozycja_Drzewo *wp)
{
	Wezel_Drzewo *nowy;
	nowy = (Wezel_Drzewo *)malloc(sizeof(Wezel_Drzewo));
	if(nowy != NULL)
	{
		nowy->pozycjaDrzewo = *wp;
		nowy->lewy = NULL;
		nowy->prawy = NULL;
	}
	return nowy;
}
static bool NaLewo(const Pozycja_Drzewo *p1, const Pozycja_Drzewo *p2)
{
	int porown1;
	if((porown1 = strcmp(p1->imie, p2->imie)) < 0)
		return true;
	else if(porown1 == 0 && strcmp(p1->gatunek, p2->gatunek) < 0)
		return true;
	else
		return false;
}
static bool NaPrawo(const Pozycja_Drzewo *p1, const Pozycja_Drzewo *p2)
{
	int porown1;
	if((porown1 = strcmp(p1->imie, p2->imie)) > 0)
		return true;
	else if(porown1 == 0 && strcmp(p1->gatunek, p2->gatunek) > 0)
		return true;
	else
		return false;
}
static void DodajWezel(Wezel_Drzewo *nowy, Wezel_Drzewo *korzen)
{
	if(NaLewo(&nowy->pozycjaDrzewo, &korzen->pozycjaDrzewo))
	{
		if(korzen->lewy == NULL) //puste poddrzewo
			korzen->lewy = nowy; //wiec ustawiam tu wezel
		else
			DodajWezel(nowy, korzen->lewy);//w przeciwnym wypadku
	}										//szukamy szczescia w poddrzewie
	else if(NaPrawo(&nowy->pozycjaDrzewo, &korzen->pozycjaDrzewo))
	{
		if(korzen->prawy == NULL)
			korzen->prawy = nowy;
		else
			DodajWezel(nowy, korzen->prawy);
	}
	else//nie powinno byc dwoch identycznych pozycji
	{
		fprintf(stderr, "Blad funkcji DodajWezel()\n");
		exit(1);
	}
}
static void PoKolei(const Wezel_Drzewo *korzen, void (*wfun)(Pozycja_Drzewo pozycja))
{
	if(korzen != NULL)
	{
		PoKolei(korzen->lewy, wfun);
		(*wfun)(korzen->pozycjaDrzewo);
		PoKolei(korzen->prawy, wfun);
	}
}
static Para SzukajPozycji(const Pozycja_Drzewo *wp, const Drzewo *wdrzewo)
{
	Para szuk;
	szuk.rodzic = NULL;
	szuk.dziecko = wdrzewo->korzen;
	if(szuk.dziecko == NULL)
		return szuk; //wczesny powrot
	while (szuk.dziecko != NULL)
	{
		if(NaLewo(wp, &(szuk.dziecko->pozycjaDrzewo)))
		{
			szuk.rodzic = szuk.dziecko;
			szuk.dziecko = szuk.dziecko->lewy;
		}
		else if(NaPrawo(wp, &(szuk.dziecko->pozycjaDrzewo)))
		{
			szuk.rodzic = szuk.dziecko;
			szuk.dziecko = szuk.dziecko->prawy;
		}
		else //jesli szukana pozycja nie znajduje sie ani po lewej ani po prawej stronie pozycjiDrzewo szuk.dziecko->pozycjaDrzewo, pozycje sa identyczne; szuk.dziecko jest adresem wezla przechowujacego szukana pozycje
			break;
	}
	return szuk;
}
static void UsunWezel(Wezel_Drzewo **wsk)
{//wsk jest adresm skladnika rodzica, ktory wskazuje na usuwany wezel
	Wezel_Drzewo *tymcz;
	if( (*wsk)->lewy == NULL)
	{
		tymcz = *wsk;
		*wsk = (*wsk)->prawy;
		free(tymcz);
	}
	else if( (*wsk)->prawy == NULL)
	{
		tymcz = *wsk;
		*wsk = (*wsk)->lewy;
		free(tymcz);
	}
	else //usuwany wezel ma dwoje dzieci
	{
		//szukamy miejsca dolaczenia prawego poddrzewa
		for(tymcz = (*wsk)->lewy; tymcz->prawy != NULL; tymcz = tymcz->prawy)
			continue;
		tymcz->prawy = (*wsk)->prawy;
		tymcz = *wsk;
		*wsk = (*wsk)->lewy;
		free(tymcz);
	}
}
static void UsunWszystkieWezly(Wezel_Drzewo *wsk)
{
	Wezel_Drzewo *wprawy;
	if(wsk != NULL)
	{
		wprawy = wsk->prawy;
		UsunWszystkieWezly(wsk->lewy);
		free(wsk);
		UsunWszystkieWezly(wprawy);
	}
}