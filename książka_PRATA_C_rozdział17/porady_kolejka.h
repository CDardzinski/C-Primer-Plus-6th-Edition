//porady_kolejka.h -- plik naglowkowy potrzebny do listingu 17.9

#ifndef _PORADY_KOLEJKA_H_
#define _PORADY_KOLEJKA_H_

typedef struct pozycja_porady //na potrzeby listingu 17.9 porady.c
{
	long przybycie; //czaswejscia klienata do kolejki
	int czaskons; //liczba zadanych minut konsultacji
}Pozycja_porady; 

#endif
