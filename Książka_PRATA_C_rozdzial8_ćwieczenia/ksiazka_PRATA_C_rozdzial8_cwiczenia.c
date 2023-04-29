#include <cvirte.h>		
#include <userint.h>
#include <ansi_c.h>
#include "ksiazka_PRATA_C_rozdzial8_cwiczenia.h"

static int panelHandle;

void liczenie(void);
char pobierz_wybor(void);
char pobierz_pierwszy(void);
int pobierz_int(void);

int pobierz_znaki(double *pierwszaLiczbaDouble,double *drugaLiczbaDouble, int dzielenie);

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial8_cwiczenia.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 1 rodzial 8//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int counter = 0;
	char znak;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wpisz jakis tekst!\n");
			while((znak = getchar()) != '&')//EOF)
				counter++;
			
			printf("Tekst zawiera %d znakow!\n", counter);			

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 2 rodzial 8//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 3 rodzial 8//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 4 rodzial 8//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 5 rodzial 8//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int proba = 1, dalej = 0;
	char odpowiedz;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wybierz liczbe od 1 do 100. Sprobuje ja odgadnac.");
			printf("\nWpisz t, jesli moja proba jest udana lub");
			printf("\nn, jesli nie trafilem.\n");
			printf("Czy Twoja liczba miesci sie w przedziale do 50?\n");
		//	printf("Hmm.... czy Twoja liczba jest %d?\n", proba);
		
		while(((odpowiedz = getchar()) != 'n') || (odpowiedz != 't'))
		{
			
			if (odpowiedz == 'n') 
			{
				dalej = 1;
				break;
			}
			else if (odpowiedz == 't')
			{
				dalej = 2;
				break;
			}
			else
				printf("Przykro mi, rozumiem tylko t lub n .\n");
			
			while(getchar() != '\n')
				continue;
		}	
			
		if(dalej == 2)
			{
				while(getchar() != '\n')
					continue;
				
				printf("No dobrze, czy jest to %d?\n", proba);
				
				while((odpowiedz = getchar()) != 't') 
				{
					if(odpowiedz == 'n')
						printf("No dobrze, czy jest to %d?\n", ++proba);
					else
						printf("Przykro mi, rozumiem tylko t lub n .\n");
				
					while(getchar() != '\n')
						continue;
				}
			}
		
		if((dalej == 2) && (odpowiedz == 't'))
		{
				printf("Wiedzialem, ze mi sie uda!\n");	
				return 0;
		}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		if(dalej == 1)
		{
			while(getchar() != '\n')
					continue;
			
			printf("Czy Twoja liczba miescie sie w przedziele do 75?\n");
			
			while(((odpowiedz = getchar()) != 'n') || (odpowiedz != 't'))
			{
				if(odpowiedz  == 'n') 
				{
					dalej = 3;
					break;
				}
				else if (odpowiedz == 't')
				{
					dalej = 4;
					break;
				}
				else
					printf("Przykro mi, rozumiem tylko t lub n .\n");
				
				while(getchar() != '\n')
					continue;
			}
		}
		if(dalej == 4)
			{
				while(getchar() != '\n')
					continue;
				
				proba = 50;
				
				printf("No dobrze, czy jest to %d?\n", proba);
				
				while((odpowiedz = getchar()) != 't') 
				{
					if(odpowiedz == 'n')
						printf("No dobrze, czy jest to %d?\n", ++proba);
					else
						printf("Przykro mi, rozumiem tylko t lub n .\n");
				
					while(getchar() != '\n')
						continue;
				}
			}
		
		if((dalej == 4) && (odpowiedz == 't'))
		{
				printf("Wiedzialem, ze mi sie uda!\n");	
				return 0;
		}
		
		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		
		if(dalej == 3)
		{
			while(getchar() != '\n')
					continue;
			
			printf("Czy Twoja liczba miescie sie w przedziele do 100?\n");
			
			while(((odpowiedz = getchar()) != 'n') || (odpowiedz != 't'))
			{
				if (odpowiedz == 'n') 
				{
					dalej = 5;
					return 0;
				}
				else if (odpowiedz == 't')
				{
					dalej = 6;
					break;
				}
				else
					printf("Przykro mi, rozumiem tylko t lub n .\n");
				
				while(getchar() != '\n')
					continue;
			}
		}
		if(dalej == 6)
			{
				while(getchar() != '\n')
					continue;
				
				proba = 75;
				
				printf("No dobrze, czy jest to %d?\n", proba);
				
				
				while((odpowiedz = getchar()) != 't') 
				{
					if(odpowiedz == 'n')
						printf("No dobrze, czy jest to %d?\n", ++proba);
					else
						printf("Przykro mi, rozumiem tylko t lub n .\n");
				
					while(getchar() != '\n')
						continue;
				}
			}
		
		if((dalej == 6) && (odpowiedz == 't'))
		{
				printf("Wiedzialem, ze mi sie uda!\n");	
				return 0;
		}

		//printf("Wiedzialem, ze mi sie uda!\n");	

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 6 rodzial 8//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	int wybor;
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			void liczenie(void);
			
			while ((wybor = pobierz_wybor()) != 'q')
				{
				switch(wybor)
					{
					case 'a': printf("Kup po niskiej cenie, "
						   				"sprzedaj po wysokiej.\n");
						break;
					case 'b': putchar('\a');
						break;
					case 'c': liczenie();
						break;
					default: printf("Blad programu!\n");
						break;
					}
				}
			printf("Do widzenia!\n");
			

			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 7 rodzial 8//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	
	double godzinki, ExtraGodziny = 0.0, wyplataStandard, prog1 = 0.0, prog2 = 0.0, prog3 = 0.0;
	int godzinowka = 40, wKolko = 0, start = 0;
	char WybranaStawka;
	const double NADGODZINY = 1.5;
	const double PODATEK1 = 0.15;
	const double PODATEK2 = 0.20;
	const double PODATEK3 = 0.25;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			while (wKolko == 0)
				{
					printf("*******************************************************************\n");
					printf("Podaj liczbe odpowiadajaca zadanej stawce wynagrodzenia lub opcji:\n");
					printf("a) 35 zl/godz.							b) 37 zl/godz.\n");
					printf("c) 40 zl/godz.							d) 45 zl/godz.\n");
					printf("q) Wyjscie\n");
					printf("*******************************************************************\n");
					
					if(start == 1)
						while (getchar() != '\n') continue;
					
					WybranaStawka = getchar();
					start = 1;
					//scanf("%c", &WybranaStawka);
					if(WybranaStawka == 'a' || WybranaStawka == 'A' || WybranaStawka == 'b' || WybranaStawka == 'B' || WybranaStawka == 'c' || WybranaStawka == 'C' || WybranaStawka == 'd' || WybranaStawka == 'D' || WybranaStawka == 'q' || WybranaStawka == 'Q') 
						{
							switch (WybranaStawka)
								{
								case 'a':
								case 'A':	
									godzinowka = 35;
									break;
								case 'b':	
								case 'B':
									godzinowka = 37;
									break;
								case 'c':
								case 'C':	
									godzinowka = 40;
									break;
								case 'd':
								case 'D':	
									godzinowka = 45;
									break;
								case 'q':
								case 'Q':	
									wKolko = 1;
									break;
								}
						}
					else 
						{
							printf("Wybierz sposrod dostepnych opcji (A, B, C, D, Q)\n");
							printf("\n");
							continue;
						}
						
				if(wKolko == 0)
					{
						printf("Wprowadz ilosc godzin przepracowanych w tygodniu: \n");
						scanf("%lf", &godzinki);
			
						if(godzinki - 40 > 0) 
						{
							wyplataStandard = 40 * godzinowka;
							ExtraGodziny = (godzinki - 40) * godzinowka * NADGODZINY;
							printf("Przepracowales %.1lf godzin dodatkowo!\n", godzinki - 40);
						}
						else wyplataStandard = godzinki * godzinowka;
			
						if(wyplataStandard + ExtraGodziny <= 1200) prog1 = (wyplataStandard + ExtraGodziny) * PODATEK1;
						else prog1 = 1200 * PODATEK1;
			
						if((wyplataStandard + ExtraGodziny <= 1800) && (wyplataStandard + ExtraGodziny >= 1200)) 
							prog2 = ((wyplataStandard + ExtraGodziny) - 1200) * PODATEK2;
						else if(wyplataStandard + ExtraGodziny >= 1800)
							prog2 = 600 * PODATEK2;
			
						if(wyplataStandard + ExtraGodziny >= 1800) prog3 = ((wyplataStandard + ExtraGodziny) - 1800) * PODATEK3;
					
						printf("Zarobiles %.2lf brutto, to daje %.2lf netto, w podatku odprowadziles %.2lf\n", wyplataStandard+ExtraGodziny, (wyplataStandard+ExtraGodziny) - (prog1+prog2+prog3), prog1+prog2+prog3);
						printf("\n");
					}
				}
			
			printf("Koniec programu!\n");

			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 8 rodzial 8//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
		int wKolko = 0;
		char WybranaOperacja;
		double pierwszaliczba=0.0, drugaliczba=0.0;
		int dzielenie = 0;
		
	switch (event)
		{
		case EVENT_COMMIT:
			
			while (wKolko == 0)
				{
					printf("*******************************************************************\n");
					printf("Wybierz jedno z dzialan:\n");
					printf("a) dodawanie							b) odejmowanie\n");
					printf("c) mnozenie							d) dzielenie\n");
					printf("k) koniec\n");
					printf("*******************************************************************\n");
						
					WybranaOperacja = getchar();
					
					if(WybranaOperacja == 'a' || WybranaOperacja == 'A' || WybranaOperacja == 'b' || WybranaOperacja == 'B' || WybranaOperacja == 'c' || WybranaOperacja == 'C' || WybranaOperacja == 'd' || WybranaOperacja == 'D' || WybranaOperacja == 'k' || WybranaOperacja == 'K') 
						{
							switch (WybranaOperacja)
								{
								case 'a':
								case 'A':
									dzielenie = 0;
									pobierz_znaki(&pierwszaliczba , &drugaliczba, dzielenie);
									
									printf("%.2lf + %.2lf = %.2lf\n", pierwszaliczba, drugaliczba, pierwszaliczba+drugaliczba);	
									printf("\n");
									
									pierwszaliczba = 0.0;
									drugaliczba = 0.0;
									break;
								case 'b':	
								case 'B':
									dzielenie = 0;
									pobierz_znaki(&pierwszaliczba , &drugaliczba, dzielenie);
									
									printf("%.2lf - %.2lf = %.2lf\n", pierwszaliczba, drugaliczba, pierwszaliczba-drugaliczba);	
									printf("\n");
									
									pierwszaliczba = 0.0;
									drugaliczba = 0.0;
									break;
								case 'c':
								case 'C':	
									dzielenie = 0;
									pobierz_znaki(&pierwszaliczba , &drugaliczba, dzielenie);
									
									printf("%.2lf * %.2lf = %.2lf\n", pierwszaliczba, drugaliczba, pierwszaliczba*drugaliczba);	
									printf("\n");
									
									pierwszaliczba = 0.0;
									drugaliczba = 0.0;
									break;
								case 'd':
								case 'D':	
									dzielenie = 1;
									pobierz_znaki(&pierwszaliczba , &drugaliczba, dzielenie);
									
									printf("%.2lf / %.2lf = %.2lf\n", pierwszaliczba, drugaliczba, pierwszaliczba/drugaliczba);	
									printf("\n");
									
									pierwszaliczba = 0.0;
									drugaliczba = 0.0;
									break;
								case 'k':
								case 'K':	
									wKolko = 1;
									break;
								}
						}
					else 
						{
							printf("Wybierz sposrod dostepnych opcji (A, B, C, D, Q)\n");
							printf("\n");
							continue;
						}
				}
				printf("Koniec programu!\n");

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


void liczenie(void)
{
	int n, i;
	printf("Jak dlugo liczyc? Podaj liczbe calkowita:\n");
	n = pobierz_int();
	for(i = 1; i <= n; i++)
		printf("%d\n", i);
	while (getchar() != '\n')
		continue;
}


char pobierz_wybor(void)
{
	int ch;
	
	printf("Wpisz wybran litere:\n");
	printf("a. porada		b.alarm\n");
	printf("c. liczenie		q.koniec\n");
	ch = pobierz_pierwszy();
	while ((ch < 'a' || ch > 'c') && ch != 'q')
		{
			printf("Wpisz a, b, c lub q.\n");
			ch = pobierz_pierwszy();
		}
	return ch;	
}

char pobierz_pierwszy(void)
{
	int ch;
	
	ch = getchar();
	putchar(ch);
	printf("\n");
	while (getchar() != '\n')
		continue;		
	return ch;	
}			


int pobierz_int(void)
{
	int we;
	char ch;
	
	while (scanf("%d", &we) != 1)
		{
			while ((ch = getchar()) != '\n')
				putchar(ch); //pomija bledne dane wejsciowe
			printf(" nie jest liczba calkowita.\nProsze podac ");
			printf("wartosc calkowita, np 25, -178 czy 3: ");
		}
	return we;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int pobierz_znaki(double *pierwszaLiczbaDouble,double *drugaLiczbaDouble, int dzielenie)
{
	int czyZnak, znacznik = 0, znacznik2 = 0, i;
	int dlugosc, start1 = 0, start2 = 0;
	char wpisanaWartosc[100], wpisanaWartosc2[100], odpowiedz;
	double pierwszaliczba=0.0, drugaliczba=0.0;
	
	*pierwszaLiczbaDouble = 0.0;
	*drugaLiczbaDouble = 0.0;
	
	printf("Podaj pierwsza liczbe: ");
	while(getchar() != '\n')
		continue;
									
	while(start1 == 0)
		{
			znacznik = 0;
			for(i = 0; ((odpowiedz = getchar()) != '\n'); i++)
			wpisanaWartosc[i] = odpowiedz;
			wpisanaWartosc[++i] = NULL;
						
			if(dzielenie == 1)
			{
				pierwszaliczba = atof(wpisanaWartosc);
				if(pierwszaliczba == 0.0)
					{
					printf("Podaj liczbe inna niz 0: ");
					continue;
					}
			}
			
			dlugosc = strlen(wpisanaWartosc);
										
			if((czyZnak = isalpha(wpisanaWartosc[0])) != 0)
			{
				if(znacznik == 0)
				{
					printf("%s", wpisanaWartosc);
					printf(" nie jest liczba:\n");
					printf("Podaj liczbe, np. 2.5, -178E8 czy 3:");
					znacznik = 1;
				}
				continue;
			}
										
			czyZnak = isdigit(wpisanaWartosc[0]);
			znacznik = 0;
									
			if (czyZnak)
			{
				pierwszaliczba = atof(wpisanaWartosc);
				*pierwszaLiczbaDouble = pierwszaliczba;
				znacznik = 0;
				start1 = 1;
			}
		}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////									

	printf("Podaj druga liczbe: ");
								
	while(start2 == 0)
	{
		znacznik2 = 0;
		for(i = 0; ((odpowiedz = getchar()) != '\n'); i++)
			wpisanaWartosc2[i] = odpowiedz;
		wpisanaWartosc2[++i] = NULL;
										
		if(dzielenie == 1)
			{
				drugaliczba = atof(wpisanaWartosc2);
				if(drugaliczba == 0.0)
					{
					printf("Podaj liczbe inna niz 0: ");
					continue;
					}
			}
		
		dlugosc = strlen(wpisanaWartosc2);
										
		if((czyZnak = isalpha(wpisanaWartosc2[0])) != 0)
		{
			if(znacznik2 == 0)
			{
				printf("%s", wpisanaWartosc2);
				printf(" nie jest liczba:\n");
				printf("Podaj liczbe, np. 2.5, -178E8 czy 3:");
				znacznik2 = 1;
			}
			continue;
		}
										
		czyZnak = isdigit(wpisanaWartosc2[0]);
		znacznik2 = 0;
									
		if (czyZnak)
		{
			drugaliczba = atof(wpisanaWartosc2);
			*drugaLiczbaDouble = drugaliczba;
			znacznik2  = 0;
			start2 = 1;
		}
	}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////								
	printf("\n");
	return 0;
}