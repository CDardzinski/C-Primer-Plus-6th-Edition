//przykład 16.6 z rozdziału 16
//tworzenie pliku nagłówkowego

#include <string.h>
#define DL_LAN 32
//deklaracje struktur
struct daneos_st
{
	char imie[DL_LAN];
	char nazw[DL_LAN];
};
//typedef
typedef struct daneos_st daneos;
//prototypy funkcji
void wprowadz(daneos *);
void wyswietl(const daneos *);
char *wczytaj(char *z, int ile);