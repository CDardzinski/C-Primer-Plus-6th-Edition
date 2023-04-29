#include <cvirte.h>		
#include <userint.h>
#include <ansi_c.h>
#include "Ksiazka_PRATA_C_rodzial6.h"

#define RZEDY 6
#define ZNAKI 10

#define ROZMIAR 10
#define PAR 72

double potega(double a, int b);

static int panelHandle;

int main (int argc, char *argv[])
	{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "Ksiazka_PRATA_C_rodzial6.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.1 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	long num;
	long suma = 0L; //przypisanie zmiennej suma wartoœci pocz¹tkowej
	int stan;
	
	switch (event)
		{
		case EVENT_COMMIT:
			printf("Podaj liczbe calkowita do zsumowania");
			printf("(albo 1, aby zakonczyc program):\n");
			stan = scanf("%ld", &num); //jak podam liczbe, to scanf zwróci 1, jak coœ innego to nie da jedynki
			
			while (stan == 1)//== oznacza "jest równy"
				{
					suma = suma + num;
					printf("Podaj nastepna liczbe" );
					printf("(albo q, aby zakonczyc program):\n");
					stan = scanf("%ld", &num);
				}
			printf("Suma podanych liczb wynosi %ld.\n", suma);			
			printf("------------------------------------------------------------------------------------\n");
			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.2 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	int n = 5;

	switch (event)
		{
		case EVENT_COMMIT:
			
			while(n < 7)
				{
				printf("n = %d\n", n);
				n++;
				printf("Teraz n = %d\n", n);
				}
			printf("Petla zakonczona\n");
			printf("------------------------------------------------------------------------------------\n");
			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.3 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	int n = 0;
	switch (event)
		{
		case EVENT_COMMIT:
			
			while(n < 3)
				printf("n jest rowne %d\n", n);
			n++;
			printf("Na tym konczymy nasz program.\n");
			printf("------------------------------------------------------------------------------------\n");		
			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.4 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	int n = 0;
	switch (event)
		{
		case EVENT_COMMIT:
			while(n++ < 3);
				printf("n jest rowne %d\n", n);
			printf("Na tym konczymy nasz program.\n");
			printf("------------------------------------------------------------------------------------\n");
			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.5 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const double ODPOWIEDZ = 3.14159;
	double odp;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Jaka jest wartosc liczby PI?\n");
			scanf("%lf", &odp);
			while (fabs(odp - ODPOWIEDZ) > 0.0001)
			{
				printf("Sprobuj ponownie!\n");
				scanf("%lf", &odp);
			}
			printf("Wystarczajaco blisko!\n");
			printf("------------------------------------------------------------------------------------\n");
	
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.6 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int prawda, falsz;
	
	switch (event)
	{
		case EVENT_COMMIT:
			prawda = (10 > 2); //wartosc relacji prawdziwej
			falsz = (10 == 2); //wartosc realcji falszywej
			printf("prawda = %d; falsz = %d\n", prawda, falsz);
			printf("------------------------------------------------------------------------------------\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.7 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int n = 3;
	switch (event)
	{
		case EVENT_COMMIT:
			while (n)
				printf("%d to prawda\n", n--);
			printf("%d to falsz\n", n);
			n = -3;
			while (n)
					printf("%2d to prawda\n", n++);
			printf("%d to falsz\n", n);	
			printf("------------------------------------------------------------------------------------\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.8 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	long num;
	long suma = 0L;
	int stan;
	
	switch (event)
		{
		case EVENT_COMMIT:
			printf("Podaj liczbe calkowita do zsumowania ");
			printf("(albo q, aby zakonczyc program):\n");
			stan = scanf("&ld", &num);
			while(stan = 1)
				{
				suma = suma + num;
				printf("Podaj nastepna liczbe calkowita ");
				printf("(albo q, aby zakonczyc program):\n");
				stan = scanf("&ld", &num);
				}
			printf("Suma podanych liczb wynosi %ld.\n", suma);
			printf("------------------------------------------------------------------------------------\n");
			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.9 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	long num;
	long suma = 0L;
	BOOL wej_jest_ok;
	
	switch (event)
		{
		case EVENT_COMMIT:
			printf("Podaj liczbe calkowita do zsumowania ");
			printf("(k - koniec): ");
			wej_jest_ok = (scanf("&ld", &num) == 1);
			while(wej_jest_ok)
				{
				suma = suma + num;
				printf("Podaj nastepna liczbe calkowita (k - koniec):  ");
				wej_jest_ok = (scanf("&ld", &num) == 1);
				}
			printf("Suma podanych liczb wynosi %ld.\n", suma);
			printf("------------------------------------------------------------------------------------\n");

			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.10 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const int LICZBA = 22;
	int licznik = 1;
	
	switch (event)
	{
		case EVENT_COMMIT:
			while (licznik <= LICZBA)
			{
				printf("Wesolych Swiat!\n");
				licznik++;
			}
			printf("------------------------------------------------------------------------------------\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.11 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	const int LICZBA = 22;
	int licznik;
	
	switch (event)
	{
		case EVENT_COMMIT:
			for(licznik = 1; licznik <= LICZBA; licznik++) printf("Wesolych Swiat!\n");
			printf("------------------------------------------------------------------------------------\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.12 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad12ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int num;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf(" n n do szescianu\n");
			for(num = 1; num <= 6; num++) printf(" %5d %5d\n", num, num*num*num);
			printf("------------------------------------------------------------------------------------\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.13 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad13ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const float PIERWSZE = 0.70;
	const float NASTEPNE = 0.30;
	const int G = 25;
	
	int gramy;
	float cena;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf(" waga  cena\n");
			for(gramy = G, cena = PIERWSZE; gramy <= 400; gramy += G, cena += NASTEPNE)
				printf("%5d %7.2f\n", gramy, cena);
			printf("------------------------------------------------------------------------------------\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.14 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad14ButtonCallback (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	int licznik;
	double czas, potega_2;
	int granica;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Ile wyrazow chcesz zsumowac?\n");
			scanf("%d", &granica);
			
			for(czas = 0, potega_2 = 1, licznik = 1; licznik <= granica; licznik++, potega_2 *=2.0)
			{
				czas += 1.0/potega_2;
				printf("czas = %f, gdzy licznik = %d.\n", czas, licznik);
			}
			printf("------------------------------------------------------------------------------------\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.15 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad15ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const int tajny_kod = 13;
	int wprowadzony_kod;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			do
			{
				printf("Aby wejsc do klubu terapeutycznego agorafobii,\n");
				printf("wprowadz wlasciwy kod: ");
				scanf("%d", &wprowadzony_kod);
			}while (wprowadzony_kod != tajny_kod);
			printf("Gratulacje! Jestes wyleczony!\n");
			printf("------------------------------------------------------------------------------------\n");	
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.16 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad16ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const int tajny_kod = 13;
	int wprowadzony_kod;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Aby wejsc do klubu terapeutycznego agorafobii,\n");
			printf("wprowadz wlasciwy kod: ");
			scanf("%d", &wprowadzony_kod);
			while (wprowadzony_kod != tajny_kod)
				{
				printf("Aby wejsc do klubu terapeutycznego agorafobii,\n");
				printf("wprowadz wlasciwy kod: ");
				scanf("%d", &wprowadzony_kod);
				}
			printf("Gratulacje! Jestes wyleczony!\n");
			printf("------------------------------------------------------------------------------------\n");	
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.17 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad17ButtonCallback (int panel, int control, int event,	void *callbackData, int eventData1, int eventData2)
{
	int rzad;
	char ch;
	
	switch (event)
	{
		case EVENT_COMMIT:
			for(rzad = 0; rzad < RZEDY; rzad++)
			{
				for(ch = 'A'; ch < ('A' + ZNAKI); ch++)
					printf("%c", ch);
				printf("\n");
			}
			printf("------------------------------------------------------------------------------------\n");	
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.18 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad18ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const int RZEDY_2 = 6;
	const int ZNAKI_2 = 6;
	int rzad;
	char ch;
	
	switch (event)
	{
		case EVENT_COMMIT:
			for(rzad = 0; rzad < RZEDY_2; rzad++)
			{
				for(ch = ('A' + rzad); ch < ('A' + ZNAKI_2); ch++)
					printf("%c", ch);
				printf("\n");
			}
			printf("------------------------------------------------------------------------------------\n");	
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.19 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad19ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int index, wynik[ROZMIAR];
	int suma = 0;
	float srednia;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj %d wynikow gry w golfa:\n", ROZMIAR);
			for(index = 0; index < ROZMIAR; index++)
				scanf("%d", &wynik[index]); //wczytanie dziesieciu wynikow
			printf("Odczytane wyniki to: \n");
			for(index = 0; index < ROZMIAR; index++)
				printf("%5d", wynik[index]); // wyswietlenie wpisanych danych
			printf("\n");
			for(index = 0; index < ROZMIAR; index++)
				suma += wynik[index]; //sumowanie danych
			srednia = (float)suma/ROZMIAR; //dobrze znana metoda liczenia sredniej
			printf("Suma wynikow = %d, srednia = %.2f\n", suma, srednia);
			printf("Oznacza to handicap w wysokosci %.0f.\n", srednia - PAR);
			printf("------------------------------------------------------------------------------------\n");	
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 6.20 rodzial 6///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad20ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double x, xpot;
	int n;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj liczbe oraz potege naturalna, ");
			printf("do ktorej podniesiona\nzostanie liczba. Wpisz q, ");
			printf("aby zakonczyc program.\n");
			while (scanf("%lf%d", &x, &n) == 2)
			{
				xpot = potega(x, n); //wywolanie funkcji
				printf("%.3g do potegi %d to %.5g\n", x, n, xpot);
				printf("Podaj kolejna pare liczb lub wpisz q, aby zakonczyc.\n");
			}
			printf("Zycze milego dnia!\n");			
			printf("------------------------------------------------------------------------------------\n");	
			break;
	}
	return 0;
}

//////////////Wyjœcie
int CVICALLBACK QuitCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	switch (event)
		{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
		}
	return 0;
	}


double potega(double a, int b)
{
	double pot = 1;
	int i;
	
	for(i = 1; i <=b; i++)
		pot *= a;
	
	return pot; //zwrot wartosci pot
}