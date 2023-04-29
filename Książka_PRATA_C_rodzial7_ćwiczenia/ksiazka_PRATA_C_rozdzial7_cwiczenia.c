#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include <ctype.h>
#include <stdbool.h>
#include "ksiazka_PRATA_C_rozdzial7_cwiczenia.h"

static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial7_cwiczenia.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 1 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	
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
			printf("Wprowadz tekst do analizy (znak # przerywa prace programu):\n");
			poprz = '\n'; //uzyty do rozpoznania konca linii
			while ((c = getchar()) != '#')
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
//////////////////////////Æwiczenie 2 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char c; //biezacy znak
	int i = 0; //licznik
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wprowadz tekst do analizy (znak # przerywa prace programu):\n");
			while ((c = getchar()) != '#')
			{
				printf("Znak %c = kod ASCII %d\t", c, c);
				i++;
				if(i % 8 == 0) printf("\n");
			}
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 3 rodzial 7///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char liczba;
	int iloscParzysta= 0 , iloscNieparzysta = 0, liczbyParzyste = 0, liczbyNieparzyste = 0, cyfra; 
	double sredniaParzyste = 0.0, sredniaNieparzyste = 0.0;
	switch (event)
	{
		case EVENT_COMMIT: //Ÿle i dobrze zarazem zrobi³em te zadania, teraz przerabiam tak jak autor mia³ na myœli
			printf("Wprowadz ciag liczby (0 przerywa prace programu):\n");
			while((liczba = getchar()) != '0')
			{
				cyfra = liczba - 48;
				if(!cyfra) break;
				if(cyfra % 2 == 0) 
				{
					iloscParzysta++;
					liczbyParzyste += cyfra;
				}
				else
				{
					iloscNieparzysta++;
					liczbyNieparzyste += cyfra;
				}	
			}
			sredniaNieparzyste = liczbyNieparzyste / iloscNieparzysta;
			sredniaParzyste = liczbyParzyste / iloscParzysta;
			printf("Ilosc parzystych: 		%d, srednia %lf\n", iloscParzysta, sredniaParzyste);
			printf("Ilosc nieparzystych:	 	%d, srednia %lf\n", iloscNieparzysta, sredniaNieparzyste);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 3 rodzial 7 - wariant poprawny//////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3_1ButtonCallback (int panel, int control, int event, 	void *callbackData, int eventData1, int eventData2)
{
	int iloscParzysta= 0 , iloscNieparzysta = 0, liczbyParzyste = 0, liczbyNieparzyste = 0, liczba;
	int sredniaParzyste = 0, sredniaNieparzyste = 0;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wprowadz ciag liczby (0 przerywa prace programu):\n");
			while(scanf("%d", &liczba) == 1)
			{
				if(!liczba) break;
				if(liczba % 2 == 0) 
				{
					iloscParzysta++;
					liczbyParzyste += liczba;
				}
				else
				{
					iloscNieparzysta++;
					liczbyNieparzyste += liczba;
				}	
			}
			sredniaNieparzyste = liczbyNieparzyste / iloscNieparzysta;
			sredniaParzyste = liczbyParzyste / iloscParzysta;
			printf("Ilosc parzystych: 		%d, srednia %d\n", iloscParzysta, sredniaParzyste);
			printf("Ilosc nieparzystych:	 	%d, srednia %d\n", iloscNieparzysta, sredniaNieparzyste);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 4 rodzial 7 ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char znaki;
	int zmiana = 0;
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wprowadz ciag znakow (# przerywa prace programu):\n");
			while((znaki = getchar()) != '#')
			{
				if(znaki == '!') 
				{
					putchar(znaki);
					putchar(znaki);
					zmiana++;
					continue;
				}
				else if(znaki == '.') 
				{
					znaki = '!';
					putchar(znaki);
					zmiana++;
					continue;
				}
			putchar(znaki);
			}
			printf("\n");
			printf("Program wykonal %d zmian!\n", zmiana);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 5 rodzial 7 ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char znaki;
	int zmiana = 0;
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wprowadz ciag znakow (# przerywa prace programu):\n");
			while((znaki = getchar()) != '#')
			{
				switch (znaki)
				{
					case '!':
							putchar(znaki);
							putchar(znaki);
							zmiana++;
							break;
					case '.':
							znaki = '!';
							putchar(znaki);
							zmiana++;
						break;
					default:
						putchar(znaki);
						break;
				}
			}
			printf("\n");
			printf("Program wykonal %d zmian!\n", zmiana);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 6 rodzial 7 ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char znaki;
	char znak2;
	int zmiana = 0;
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wprowadz ciag znakow (# przerywa prace programu):\n");
			while((znaki = getchar()) != '#')
			{
				if(znaki == 'o') znak2 = znaki;
				//else znak2 = ' ';
				
				if(znaki == 't' && znak2 == 'o')
				{
					zmiana++;
					znak2 = ' ';
				}
			}
			printf("\n");
			printf("Program znalazl %d powtorzen!\n", zmiana);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 7 rodzial 7 ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double godzinki, ExtraGodziny = 0.0, wyplataStandard, prog1 = 0.0, prog2 = 0.0, prog3 = 0.0;
	const int GODZINOWKA = 40;
	const double NADGODZINY = 1.5;
	const double PODATEK1 = 0.15;
	const double PODATEK2 = 0.20;
	const double PODATEK3 = 0.25;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wprowadz ilosc godzin przepracowanych w tygodniu: \n");
			scanf("%lf", &godzinki);
			
			if(godzinki - 40 > 0) 
			{
				wyplataStandard = 40 * GODZINOWKA;
				ExtraGodziny = (godzinki - 40) * GODZINOWKA * NADGODZINY;
				printf("Przepracowales %.1lf godzin dodatkowo!\n", godzinki - 40);
			}
			else wyplataStandard = godzinki * GODZINOWKA;
			
			if(wyplataStandard + ExtraGodziny <= 1200) prog1 = (wyplataStandard + ExtraGodziny) * PODATEK1;
			else prog1 = 1200 * PODATEK1;
			
			if((wyplataStandard + ExtraGodziny <= 1800) && (wyplataStandard + ExtraGodziny >= 1200)) 
				prog2 = ((wyplataStandard + ExtraGodziny) - 1200) * PODATEK2;
			else if(wyplataStandard + ExtraGodziny >= 1800)
				prog2 = 600 * PODATEK2;
			
			if(wyplataStandard + ExtraGodziny >= 1800) prog3 = ((wyplataStandard + ExtraGodziny) - 1800) * PODATEK3;
					
			printf("Zarobiles %.2lf brutto, to daje %.2lf netto, w podatku odprowadziles %.2lf\n", wyplataStandard+ExtraGodziny, (wyplataStandard+ExtraGodziny) - (prog1+prog2+prog3), prog1+prog2+prog3);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 8 rodzial 7 ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double godzinki, ExtraGodziny = 0.0, wyplataStandard, prog1 = 0.0, prog2 = 0.0, prog3 = 0.0;
	int godzinowka = 40, WybranaStawka, wKolko = 0;
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
					printf("1) 35 zl/godz.							2) 37 zl/godz.\n");
					printf("3) 40 zl/godz.							4) 45 zl/godz.\n");
					printf("5) Wyjscie\n");
					printf("*******************************************************************\n");
	
					scanf("%d", &WybranaStawka);
					if(WybranaStawka > 0 && WybranaStawka < 6)
						{
							switch (WybranaStawka)
								{
								case 1:
									godzinowka = 35;
									break;
								case 2:
									godzinowka = 37;
									break;
								case 3:
									godzinowka = 40;
									break;
								case 4:
									godzinowka = 45;
									break;
								case 5:
									wKolko = 1;
									break;
								}
						}
					else 
						{
							printf("Wybierz sposrod dostepnych opcji (1 ÷ 5)\n");
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
//////////////////////////Æwiczenie 9 rodzial 7 ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	long long int liczbaPobrana, z, reszta, i;
	switch (event)
		{
		case EVENT_COMMIT:
			printf("Podaj dowolna liczbe calkowita\n");
			scanf("%lld", &liczbaPobrana);
			
			printf("Liczby pierwsze ze zbioru %lld\n", liczbaPobrana);
			
			
			for(i = 1; i <= liczbaPobrana; i++)
				{
				reszta = 1;
				if(i < 2) continue; 
				do{
					for(z = 2; z <= i; z++)
						{
							reszta = i % z;
							if(reszta == 0) break;
						}
					if((z == i) && (reszta == 0)) 
						{
						printf("%lld\t", i);
						break;
						}
					else break;
					}
				while(reszta != 0);			
				}

			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 10 rodzial 7 ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	int zapetlenie = 0, status, dochod;
	const double PODATEK1 = 0.15;
	const double PODATEK2 = 0.28;\
	double rozliczenie = 0.0;
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			while (zapetlenie == 0)
				{		
					printf("Podaj swoj status:\n");
					printf("1) Stan wolny					2) Glowa rodziny\n");
					printf("3) Malzenstwo, rozliczanie wspolne		4)Malzenstwo, rozliczene osobno\n");
					printf("5) Wyjscie\n");
					
					scanf("%d", &status);
					
					if(status == 5) 
						{
						zapetlenie = 1;
						break;
						}
					if(status < 1 || status > 5)
						{
						printf("Podaj wartosc z przedzialu 1 do 5!\n");
						continue;
						}
					else 
						printf("Podaj dochod: ");
				
					scanf("%d", &dochod);
					
					if(status == 1)
						{
						if(dochod < 17850) 
							rozliczenie = dochod * PODATEK1;
						else
							rozliczenie = (17850 * PODATEK1) + ((dochod - 17850) * PODATEK2);
						}
					if(status == 2)
						{
						if(dochod < 23900) 
							rozliczenie = dochod * PODATEK1;
						else
							rozliczenie = (23900 * PODATEK1) + ((dochod - 23900) * PODATEK2);
						}
					if(status == 3)
						{
						if(dochod < 29750) 
							rozliczenie = dochod * PODATEK1;
						else
							rozliczenie = (29750 * PODATEK1) + ((dochod - 29750) * PODATEK2);
						}
					if(status == 4)
						{
						if(dochod < 14875) 
							rozliczenie = dochod * PODATEK1;
						else
							rozliczenie = (14875 * PODATEK1) + ((dochod - 14875) * PODATEK2);
						}
					
					if(status > 0 && status < 5) printf("Masz do zaplacenia %.2lf podatku\n", rozliczenie);
					printf("\n");
				}
				printf("Koniec programu!\n");

			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 11 rodzial 7 ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double const ArbuzyZaKg = 1.25;
	double const BurakiZaKg = 0.65;
	double const CebulaZaKg = 0.89;
	double const KosztWysylkido5kg = 3.50;
	double const KosztWysylkiod5kgdo20kg = 10.0;
	double const KosztWysylkiPowyzej20kg = 8.0;
	double const cenaZaKgPowyzej20kg = 0.10;
	
	int konczenieZamawiania = 0, pobierzTyp = 0;
	char wyborTowaru = -1;
	double waga, wagaCalkowitaArbuzow = 0.0, wagaCalkowitaBurakow = 0.0 , wagaCalkowitaCebuli = 0.0;
	double cenaZaArbuzy = 0.0, cenaZaBuraki = 0.0, cenaZaCebule = 0.0, kosztyWarzyw, wagaWarzyw;
	double kosztyOgolneWysylki, kosztyWarzywPorabacie, rabat = 0.0;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			while(konczenieZamawiania == 0)
			{
				printf("Wybierz opcje:\n");
				printf("A) Arbuzy\n");
				printf("B) Buraki\n");
				printf("C) Cebula\n");
				printf("K) Koniec zamowienia\n");
				printf("W) Wyjscie z programu!\n");
			
				while ((wyborTowaru = getchar()) != '\n')
					continue;
					
				scanf("%c", &wyborTowaru);
				
				printf("\n");
				
				if(wyborTowaru == 'k' || wyborTowaru == 'K' || wyborTowaru == 'W' || wyborTowaru == 'w')
					printf("\n");
				else
					{
					printf("Podaj wage w kg:\n");
					scanf("%lf", &waga);
					}
			
				switch(wyborTowaru)
				{
					case 'a':
					case 'A':
						wagaCalkowitaArbuzow += waga;
						cenaZaArbuzy = wagaCalkowitaArbuzow * ArbuzyZaKg;
						break; 
					case 'b':
					case 'B':
						wagaCalkowitaBurakow += waga;
						cenaZaBuraki = wagaCalkowitaBurakow * BurakiZaKg;
						break; 
					case 'c':
					case 'C':
						wagaCalkowitaCebuli += waga;
						cenaZaCebule = wagaCalkowitaCebuli * CebulaZaKg;
						break; 
					case 'k':
					case 'K':
						konczenieZamawiania = 1;
						break; 
					case 'W':
					case 'w':	
						konczenieZamawiania = 2;
						break; 
				}
			
			if(konczenieZamawiania == 1)
				{
				kosztyWarzyw = cenaZaArbuzy + cenaZaBuraki + cenaZaCebule;
				wagaWarzyw = wagaCalkowitaArbuzow + wagaCalkowitaBurakow + wagaCalkowitaCebuli;
					if(kosztyWarzyw > 100.0)
					{
						rabat = kosztyWarzyw * 0.05;
						kosztyWarzyw = kosztyWarzyw * 0.95;
					}
					else rabat = 0.0;
					
					if(wagaWarzyw < 5.0) 	kosztyOgolneWysylki = KosztWysylkido5kg;
					else if(wagaWarzyw > 5.0 && wagaWarzyw < 20.0) kosztyOgolneWysylki = KosztWysylkiod5kgdo20kg;
					else kosztyOgolneWysylki = KosztWysylkiPowyzej20kg + ((wagaWarzyw - 20.0) * cenaZaKgPowyzej20kg);
					
				printf("Twoje zamowione towary kosztuja %.2lf\n", kosztyWarzyw);
				printf("Twoj rabat to %.2lf\n", rabat);
				printf("Twoje zamowienie razem z przesylko wynosi %.2lf\n", kosztyWarzyw + kosztyOgolneWysylki);
				printf("\n");
				konczenieZamawiania = 0;
				}
				if(konczenieZamawiania == 2)
				{
					printf("Wyjscie z programu!\n");
					break;
				}
			}
			

			break;
	}
	return 0;
}

//////////////Wyjœcie
int CVICALLBACK QuitCallback (int panel, int control, int event,  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}