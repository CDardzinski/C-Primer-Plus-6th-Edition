//lista.h -- plik naglowkowy dla typu "prosta lista"
//listing 17.3

//lista_cw2.h--plik zmodyfikowany pod æwiczenie 2
#ifndef  _LISTACW2_H_
#define _LISTACW2_H_

#include <stdbool.h>

//deklaracje szegolowe programu
#define ROZT 45
struct film3
{
	char tytul[ROZT];
	int ocena;
};
//ogolne definiecje typow

typedef struct film3 Pozycja;

typedef struct wezel
{
	Pozycja pozycja;
	struct wezel *nast;	
}Wezel;

//typedef Wezel *Lista;//orginalana definicja listy z listingu 17.2

typedef struct Lista //definicja listy z æwiczenia 2
{
	Wezel *glowny;//wskazuje na pocz¹tek listy
	Wezel *koniec;//wskazuje na koniec listy
} Lista; 
	

//prototypy funkcji
//dzialanie: inicjalizuje liste
//warunki wstepne: wlisata wskazuje na liste
//warunki koncowe: lista zostaje zainicjalizowana jako pusta
void InicjujListe(Lista * wlista);
//dzialanie: okresla czy lista jest pusta
//warunki wstepne: wlisata wskazuje na zainicjalizowana liste
//warunki koncowe: funkcja zwraca true, jesli lista jest pusta, a w przeciwnym wypadku false
bool PustaLista(const Lista *wlista);
//dzialanie: okresla czy lista jest pelna
//warunki wstepne: wlisata wskazuje na zainicjalizowana liste
//warunki koncowe: funkcja zwraca true, jesli lista jest pelna, a w przeciwnym wypadku false
bool PelnaLista(const Lista *wlista);
//dzialanie: okresla liczbe pozycji na liscie
//warunki wstepne: wlisata wskazuje na zainicjalizowana liste
//warunki koncowe: funkcja zwraca liczbe pozycji na liscie
unsigned int LiczbaPozycji(const Lista *wlista);
//dzialanie: dodaje pozycje na koncu listy
//warunki wstepne: pozycja jest pozycja do dodania, wlista wskazuje na zainicjalizowana liste
//warunki koncowe: jesli jest to mozliwe, funkcja dodaje pozycje na koncu listy i zwraca true, w przeciwnym wypadku funkcja zwraca false
bool DodajPozycje(Pozycja pozycja, Lista *wlista);
//dzialanie: stosuje funkcje  do kazdej pozycji na liscie
//warunki wstepne: wlista wskazuje na zainicjalizowana liste, wfun wskazuje na funkcje, ktora pobiera argument typu Pozycja i nie ma wartosci zwracanej
//warunki koncowe: funkcja wskazywana przez wfun jest uruchamiana jeden raz dla kazdej pozycji w liscie
void Przejdz (const Lista *wlista, void(*wfun)(Pozycja pozycja));
//dzialanie: zwalnia pamiec zajmowana przez liste
//warunki wstepne: wlista wskazuje na zainicjalizowana liste
//warunki koncowe: pamiec zostaje zwolniona, wlista ma wartosc NULL
void CzyscListe(Lista *wlista);

#endif