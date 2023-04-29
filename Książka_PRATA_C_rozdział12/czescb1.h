///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk�ad listing 12.6 rodzial 12///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
//#include <ansi_c.h>
//#include "czescb.h"

void sumuj(int k);

extern int liczba; //deklaracja nawiazujaca, ��cznos� zewn�trzn�
static int suma = 0; //definicja static, �aczno�� wewn�trzna

void sumuj(int k) // k ma zasieg blokowy i brak laczno�ci
{
	static int podsuma = 0; // statyczna, brak laczno�ci
	
	if(k <= 0)
	{
		printf("Cykl petli: %d\n", liczba);
		printf("Podsuma: %d; Suma: %d\n", podsuma, suma);
		podsuma = 0;
	}
	else
	{
		podsuma += k;
		suma += k;
	}
}
