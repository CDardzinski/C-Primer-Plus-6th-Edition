//przyk³ad 16.10 z rozdzia³u 16
//zastosowanie dyrektywy #ifndef
#ifndef DANEOS1_H_
#define DANEOS1_H_
//stale
#define DL_LAN 32
//deklaracje struktur
struct daneos_st
{
	char imie[DL_LAN];
	char nazw[DL_LAN];
};
//typedef
typedef struct daneos_st daneos;
//prototyp funkcji
void wprowadz (daneos *);
void wyswietl(const daneos *);
void *wczytaj(char *z, int ile);
#endif