//kolejka.h -- plik naglowkowy interfejs dla kolejki
//listing 17.6
#ifndef _KOLEJKA_H_
#define _KOLEJKA_H_

#include <stdbool.h>

//TUTAJ WSTAW DEFINICJE TYPU POZYCJA_KOLEJKI
//NA PRZYK£AD

/*
typedef int Pozycja_Kolejki; //na potrzeby programu uzyj_k.c
//lub typedef struct pozycja {int slon; int zyrafa;} Pozycja_kolejki;
*/
typedef struct pozycja_porady //na potrzeby listingu 17.9 porady.c
{
	long przybycie; //czaswejscia klienata do kolejki
	int czaskons; //liczba zadanych minut konsultacji
}Pozycja_Kolejki; 

#define MAXKOLEJKA 10

typedef struct wezel_kolejka
{
	Pozycja_Kolejki Pozycja_Wezla_kolejki;
	struct wezel_kolejka *nast;
} Wezel_kolejka;

typedef struct kolejka
{
	Wezel_kolejka *przod; //wskaznik do przodu kolejki
	Wezel_kolejka *tyl;//wskaznik do tylu kolejki
	int Pozycje_W_kolejce; //liczba pozycji w kolejce
} Kolejka;

//dzialanie: inicjalizuje kolejke
//warunek wstepny: wk wskazuje na kolejke
//warunek koncowy: kolejka zostaje zainicjalizowana jako pusta
void InicjujKolejke(Kolejka *wk);
//dzialanie: sprawdza, czy kolejka jest pelna
//warunek wstepny: wk wskazuje na wczesniej zainicjalizowana kolejke
//warunek koncowy: zwraca true, jesli kolejka jest pelna, w przeciwnym wypadku - false
bool PelnaKolejka(const Kolejka *wk);
//dzialanie: sprawdza, czy kolejka jest pusta
//warunek wstepny: wk wskazuje na wczesniej zainicjalizowana kolejke
//warunek koncowy: zwraca true, jesli kolejka jest pusta, w przeciwnym wypadku - false
bool PustaKolejka(const Kolejka *wk);
//dzialanie: okresla liczbe pozycji w kolejce
//warunek wstepny: wk wskazuje na wczesniej zainicjalizowana kolejke
//warunek koncowy:zwraca liczbe pozycji w kolejce
int LiczbaPozycjiKolejki(const Kolejka *wk);
//dzialanie: ustawia pozycje z tylu kolejki
//warunek wstepny: wk wskazuje na wczesniej zainicjalizowana kolejke
//warunek koncowy: jesli kolejka nie jest pusta, pozycja zostaje wmieszczona z tylu kolejki a funkcja zwraca true; w przeciwnym wypadku pozostaje niezmieniona, a funkcja zwraca false			
bool Ustaw(Pozycja_Kolejki pozycja, Kolejka *wk);
//dzialanie: odlacza pozycje z przodu kolejki a
//warunek wstepny: wk wskazuje na wczesniej zainicjalizowana kolejke
//warunek koncowy: jesli kolejka nie jest pusta, pozycja z przodu kolejki zastaje skopiowana do *wpozycja i usunieta z kolejki, a funkcja zwraca true. Jesli usunieto ostatnio pozycje, kolejka jest zerowana (inicjalizowana). Jesli kolejka by³a pusta wczesniej, pozostaje ona bez zmian, a funkcja zwraca false;
bool Odlacz(Pozycja_Kolejki *wpozycja, Kolejka *wk);
//dzialanie: oproznia kolejke
//warunek wstepny: wk wskazuje na wczesniej zainicjalizowana kolejke
//warunek koncowy: kolejka jest pusta
void WyczyscKolejke(Kolejka *wk);
#endif
