#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include <ctype.h>
#include <stdbool.h>
#include "ksiazka_PRATA_C_rozdzial7.h"

#define ODSTEP ' ' //apostrof - spacja - apostrof

static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial7.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 7.1 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	const int MROZ = 0;
	float temperatura;
	int mrozne_dni = 0;
	int wszystkie_dni = 0;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj liste najnizszych temperatur dnia.\n");
			printf("Uzyj skali Celsjusza. Aby zakonczyc wpisz q.\n");
			while(scanf("%f", &temperatura) == 1)
			{
				wszystkie_dni++;
				if(temperatura < MROZ)
					mrozne_dni++;
			}
			if(wszystkie_dni != 0)
				printf("Calkowita liczba dni: %d, z czego %.1f%% bylo mrozne.\n",
					   	wszystkie_dni, 100.0 * (float)mrozne_dni/wszystkie_dni);
			else
				printf("Nie wpisano danych!\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 7.2 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char ch;
	switch (event)
	{
		case EVENT_COMMIT:
			ch = getchar(); //odczytanie znaku
			while ((ch = getchar()) != '\n')	//dopóki nie ma koñca wiersza
			{
				if(ch == ODSTEP)	//pozostaw znak spacji
					putchar(ch);
				else
					putchar(ch + 1); //zmien posostale znaki
				//ch = getchar(); //wczytaj kolejny znak
			}
			putchar(ch); //wyœwietl znak nowej linii
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 7.3 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char ch;
	
	switch (event)
	{
		case EVENT_COMMIT:
			while ((ch = getchar()) != '\n')
			{
				if(isalpha(ch)) //jeœli znak jest litera
					putchar(ch +1); //wyswietla nastepna litere
				else putchar(ch);	//jeœli nie, wyswietla go bez zmian
			}
			putchar(ch); //wyswietla znak nowej linii
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 7.4 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
#define STAWKA1 0.2401	//stawka dla pierwszych 360kWh
#define STAWKA2 0.2881	//stawka dla nastepnych 108kWh
#define STAWKA3 0.3457	//stawka dla nastepnych 252kWh
#define STAWKA4 0.3877	//stawka powyzej 720kWh
#define PROG1 360.0			//pierwszy próg
#define PROG2 468.0			//drugi próg
#define PROG3 720.0			//trzeci próg
#define PODSTAWA1 (STAWKA1 * PROG1)		//cena pierwszych 360kWh
#define PODSTAWA2 (PODSTAWA1 +(STAWKA2 * (PROG2 - PROG1)))	//cena pierwszych 468kWh
#define PODSTAWA3 (PODSTAWA1 + PODSTAWA2 + (STAWKA3 * (PROG3 - PROG2))) //cena pierwszych 720kWh	

	double kwh;				//liczba zuzytych kilowatogodzin
	double oplata; 			//ich cena
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj liczbe zuzytych kWh.\n");
			scanf("%lf", &kwh);								//%lf - typ double
			if(kwh <= PROG1) 
				oplata = STAWKA1 * kwh;
			else if (kwh <= PROG2) //pomiedzy 360 a 468 kWh
				oplata = PODSTAWA1 + (STAWKA2 * (kwh - PROG1));
			else if(kwh <= PROG3) //pomiedzy 468 a 720 kWh
				oplata = PODSTAWA2 + (STAWKA3 * (kwh - PROG2));
			else							//oplata powyzej 720kWh
				oplata = PODSTAWA3 + (STAWKA4 * (kwh - PROG3));
			printf("Oplata za %.1f kWh wynosi %1.2fzl.\n", kwh, oplata);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 7.5 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	unsigned long num; //liczba do sprawdzenia
	unsigned long dziel; //potencjalne dzielnik
	bool pierwsza; //flaga
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj dodatnia liczbe calkowite do zanalizowania; ");
			printf("Wpisz q, aby zakonczyc.\n");
			while (scanf("%ld", &num) == 1)
			{
				for(dziel = 2, pierwsza = true; (dziel * dziel) <= num; dziel++)
				{
					if(num % dziel == 0)
					{
						if((dziel * dziel) != num)
							printf("%ld dzieli sie przez %ld i %ld.\n", num, dziel, num/dziel);
						else printf("%ld dzieli sie przez %ld.\n", num, dziel);
					pierwsza = false; //liczba nie jest liczba pierwsza
					}
				}
				if(pierwsza) printf("%ld jest liczba pierwsza.\n", num);
				printf("Podaj nastepna liczbe do zanalizowania; ");
				printf("Wpisz q, aby zakonczyc.\n");
			}
			printf("Gotowe.\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 7.6 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
#define KROPKA '.'

	char ch;
	int licznik = 0;
	
	switch (event)
	{
		case EVENT_COMMIT:
			while ((ch = getchar()) != KROPKA)
			{
				if(ch != '"' && ch != '\'')
					licznik++;
			}
			printf("W zdaniu jest %d znakow niebedocych cudzyslowami lub apostrofami.\n", licznik);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 7.7 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
#define STOP '|'
	
	char c; //biezacy znak
	char poprz; //poprzedni znak
	long ile_znakow = 0L; //liczba znakow
	int ile_wierszy = 0; //liczba linii
	int ile_slow = 0; // liczba slow
	int ile_np_wierszy = 0; //liczba niepelnych wierszy
	bool w_slowie = false; // ==true, jesli c znajduje sie w slowie
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wprowadz tekst do analizy (znak | przerywa prace programu):\n");
			poprz = '\n'; //uzyty do rozpoznania konca linii
			while ((c = getchar()) != STOP)
			{
				ile_znakow++; //liczy znaki
				if(c == '\n') ile_wierszy ++; //liczy wiersze
				if(!isspace(c) && !w_slowie)
				{
					w_slowie = true; //zaczelo sie nowe slowo
					ile_slow++;
				}
				if(isspace(c) && w_slowie) w_slowie = false; //znajduje koniec slowa
				poprz = c;					
			}
			
			if(poprz != '\n') ile_np_wierszy = 1;
			printf("znakow = %ld, slow = %d, wierszy = %d, ", ile_znakow, ile_slow, ile_wierszy);
			printf("niepelnych wierszy = %d\n", ile_np_wierszy);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 7.8 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
#define POKRYCIE 18 //liczba metrow kw. pokrywana przez jedna puszke
	int m_kw;
	int puszki;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj liczbe metrow kwadratowych do pomalowania:\n");
			while (scanf("%d", &m_kw) == 1)
			{
				puszki = m_kw/POKRYCIE;
				puszki += ((m_kw % POKRYCIE == 0)) ? 0 : 1;
				printf("Potrzeba %d %s farby.\n", puszki, puszki == 1 ? "puszki" : "puszek");
				printf("Podaj kolejna wartosc (q konczy program): \n");
			}

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 7.9 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const float MIN = 0.0f;
	const float MAX = 100.0f;
	
	float wynik;
	float suma = 0.0f;
	int n = 0;
	float min = MAX;
	float max = MIN;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj pierwszy wynik (albo q zeby zakonczyc): \n");
			while (scanf("%f", &wynik) == 1)
			{
				if(wynik < MIN || wynik > MAX)
				{
					printf("%0.1f jest nieprawidlowa wartoscia. \n", wynik);
					continue; //skok do testu warunku wykonania petli
				}
				printf("Przyjeto %0.1f:\n", wynik);
				min = (wynik < min) ? wynik : min;
				max = (wynik > max) ? wynik : max;
				suma += wynik;
				n++;
				printf("podaj kolejny wynik (albo q zeby zakonczyc): \n");
			}
			if(n>0)
			{
				printf("Srednia z %d wynikow wynosi %0.1f.\n", n, suma/n);
				printf("Najnizszy = %0.1f, najwyzszy = %0.1f\n", min, max);
			}
			else printf("NIe podano zadnych prawidlowych wynikow.\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 7.10 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	float dlugosc, szerokosc;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj dlugosc prostokata:\n");
			while (scanf("%f", &dlugosc) == 1)
			{
				printf("Dlugosc = %0.2f:\n", dlugosc);
				printf("Podaj szerokosc prostokata:\n");
				if(scanf("%f", &szerokosc) != 1) break;
				printf("Szerokosc = %0.2f:\n", szerokosc);
				printf("Pole = %0.2f:\n", dlugosc * szerokosc);
				printf("Podaj dlugosc prostokata:\n");
				printf("Gotowe.\n");
			}
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 7.11 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char ch;
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj mi litere, a ja podam Ci ");
			printf("nazwe zwierzecia\nna te litere.\n");
			printf("Wpisz mala litere; #konczy zabawe.\n");
			while ((ch = getchar()) != '#')
			{
				if('\n' == ch) continue;
				if(islower(ch)) //tylko male litery
					switch (ch)
					{
						case 'a':
							printf("aguti, roslinozeny gryzon z Ameryki Lacinskiej\n");	
							break;
						case 'b':
							printf("babirusa, dzika swinia indonezyjska\n");	
							break;
						case 'c':
							printf("cierlik, nieduzy ptak srodziemnomorski\n");	
							break;
						case 'd':
							printf("desman, wodny ssak podobny do kreta\n");	
							break;
						case 'e':
							printf("edredon, arktyczny ptak morski z rodziny kaczek\n");	
							break;
						case 'f':
							printf("fretka, udomowiona odmiana tchorza pospolitego\n");	
							break;
						default:
							printf("To za trudne!\n");
							break;
					} //koniec switch
			else printf("Rozpoznaje tylko male litery.\n");
			while (getchar() != '\n') continue; //pomija reszte wiersza wejsciowego
			printf("Podaj kolejna litere lub znak #.\n"); 
			}//koniec petli while				
			printf("Do widzenia!\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 7.12 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad12ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char ch;
	int a_licz, e_licz, i_licz, o_licz, u_licz, y_licz;
	switch (event)
	{
		case EVENT_COMMIT:
			a_licz = e_licz = i_licz = o_licz = u_licz = y_licz = 0;
			printf("Wpisz jakis tekst; # konczy program\n");
			while ((ch = getchar()) != '#')
			{
				switch (ch)
				{
					case 'a':
					case 'A': 
						a_licz++;
						break;
					case 'e':
					case 'E':
						e_licz++;
						break;
					case 'i':
					case 'I':
						i_licz++;
						break;
					case 'o':
					case 'O':
						o_licz++;
						break;
					case 'u':
					case 'U':
						u_licz++;
						break;
					case 'y':
					case 'Y':
						y_licz++;
						break;
					default:
						break;
				} //koniec switcha
			} //koniec petli while
			printf("liczba samoglosek:	A 	E 	I 	O 	U 	Y\n");
			printf(" 			%4d	%4d	%4d	%4d	%4d %4d\n", a_licz, e_licz, i_licz, o_licz, u_licz, y_licz);
			break;
	}
	return 0;
}

//////////////Wyjœcie
int CVICALLBACK QuitCallback (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}
