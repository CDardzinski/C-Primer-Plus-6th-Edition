// drzewo.h -- drzewo binarne
// drzewo nie moze zawierac dwoch jednakowych pozycji
#ifndef _DRZEWO_H_
#define _DRZEWO_H_

#include <stdbool.h>

//typ Pozycja_Drzewo nalezy zdefiniowac w zaleznosci od okolicznosc
typedef struct Pozycja
{
	char imie[20];
	char gatunek[20];
} Pozycja_Drzewo;

#define MAXPOZYCJI 10

typedef struct wezel_drz
{
	Pozycja_Drzewo pozycjaDrzewo;
	struct wezel_drz *lewy; //wskaznik do prawej galezi
	struct wezel_drz *prawy; //wskaznik do lewej galezi
}Wezel_Drzewo;

typedef struct drzewo
{
	Wezel_Drzewo *korzen; //wskaznik do korzenia drzewa
	int rozmiar;	//liczba pozycji w drzewie
}Drzewo;

//prototyp funkcji
//dzialania: Inicjalizuje drzewo jako puste
//warunki wstepne: wdrzewo wskazuje na drzewo
//warunki koncowe: drzewo zostalo zainicjalizowane
void InicjujDrzewo(Drzewo *wdrzewo);
//dzialania: okresla, czy drzewo jest puste
//warunki wstepne: wdrzewo wskazuje na drzewo
//warunki koncowe: funkcja zwraca true, jesli drzewo jest puste, a w przeciwnym wypadku - false
bool PusteDrzewo(const Drzewo *wdrzewo);
//dzialania: okresla, czy drzewo jest pelne
//warunki wstepne: wdrzewo wskazuje na drzewo
//warunki koncowe: funkcja zwraca true, jesli drzewo jest pelne, a w przeciwnym wypadku - false
bool PelneDrzewo(const Drzewo *wdrzewo);
//dzialania: okresla liczbe pozycji w drzewie
//warunki wstepne: wdrzewo wskazuje na drzewo
//warunki koncowe: funkcja zwraca liczbe pozycji w drzewie
int LiczbaPozycjiDrzewo(const Drzewo *wdrzewo);
//dzialania: dodaje pozycje do drzewa
//warunki wstepne: wp jest adresem dodawanej pozycji wdrzewo wskazuje na zainicjalizowanie drzewo
//warunki koncowe: jesli jest to mozliwe, funkcja dodaje pozycje do drzewa i zwraca true, w przeciwnym wypadku funkcja zwraca false
bool DodajPozycjeDrzewo(const Pozycja_Drzewo *wp, Drzewo *wdrzewo);
//dzialania: znajduje pozycje w drzewie
//warunki wstepne: wp wskazuje na pozycje wdrzewo wskazuje zinicjalizowane drzewo
//warunki koncowe: funkcja zwraca true, jesli pozycja znajduje sie w drzewie, a w przeciwnym wypadku - false
bool WDrzewie(const Pozycja_Drzewo *wp, const Drzewo *wdrzewo);
//dzialania: usuwa pozycje z drzewa
//warunki wstepne: wp jest adresem usuwanej pozycji wdrzewo wskazuje zinicjalizowane drzewo
//warunki koncowe: jesli jest to mozliwe, funkcja usuwa pozycje z drzewa i zwraca true, w przeciwnym wypadku funkcja zwraca false
bool UsunPozycjeDrzewo(const Pozycja_Drzewo *wp, Drzewo *wdrzewo);
//dzialania: stosuje funkcje do kazdej pozycji w drzewie
//warunki wstepne: wdrzewo wskazuje na drzewo, wfun wskazuje na funkcje, ktora przyjmuje argument typu Pozycja_Drzewo i nie posiada wartosci zwracanej
//warunki koncowe: funkcja wskazywana przez wfun zostaje zastosowana jeden raz dla kazdej pozycji w drzewie
void PrzejdzDrzewo(const Drzewo *wdrzewo, void (*wfun)(Pozycja_Drzewo pozycja));
//dzialania: usuwa cale drzewo
//warunki wstepne: wdrzewo wskazuje zinicjalizowane drzewo
//warunki koncowe: drzewo jest puste
void UsunWszystkoDrzewo(Drzewo *wdrzewo);
#endif 