#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial17_porady.h"

//#include "porady_kolejka.h" //do przyk³adu 17.9
#include "kolejka.h"

static int panelHandle;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//do listingu 17.9
#define MIN_W_GODZ 60.0
bool nowyklient(double x); //czy jest nowy klient?
Pozycja_Kolejki czasklienta(long kiedy); //ustawia parametry klienta
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial17_porady.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 17.9 rozdzial 17//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			Kolejka kol;
			Pozycja_Kolejki tymcz; //dane o nowym kliencie
			int godz; //liczba godzin symulacji
			int nagodz; //srednia liczba nowyhc klientow na godzine
			long cykl, gran_cyklu; //licznik petli, granica
			long odeslani = 0; //klienci odeslani z braku miejsca
			long klienci = 0; //klienci, ktorzy weszli do kolejki
			long obsluzeni = 0; //obsluzeni w czasie symulacji
			long suma_kol = 0; //kumulatywan dlugosc kolejki
			int czas_czek = 0; //czas do obsluzenia nastepnego klienta
			double min_na_kl; //sredni czas miedzy przeybylymi klienatami
			long kol_czek = 0; //kumulowany czas stania w kolejce
			
			InicjujKolejke(&kol);
			srand((unsigned int)time(0)); //losowa inicjalizacja funkcji rand()
			puts("Studium przypadkow: Punkt porad Zygmunata Prywaciarza");
			puts("Podaj liczbe godzin symulacji:");
			scanf("%d", &godz);
			gran_cyklu = MIN_W_GODZ * godz;
			puts("Podaj srednia liczbe klientow w ciagu godziny:");
			scanf("%d", &nagodz);			
			min_na_kl = MIN_W_GODZ/nagodz;			
			for(cykl = 0; cykl < gran_cyklu; cykl++)
			{
				if(nowyklient(min_na_kl))
				{
					if(PelnaKolejka(&kol))
						odeslani++;
					else
					{
						klienci++;
						tymcz = czasklienta(cykl);
						Ustaw(tymcz, &kol);
					}
				}
				if(czas_czek <= 0 && !PustaKolejka(&kol))
				{
					Odlacz(&tymcz, &kol);
					czas_czek = tymcz.czaskons;
					kol_czek += cykl - tymcz.przybycie;
					obsluzeni++;
				}
				if(czas_czek > 0)
					czas_czek--;
				suma_kol  += LiczbaPozycjiKolejki(&kol);
			}
			if(klienci > 0)
			{
				printf("klienci przyjeci do kolejki: %ld\n", klienci);
				printf("klienci obsluzeni: %ld\n", obsluzeni);
				printf("klienci odeslani: %ld\n", odeslani);
				printf("srednia dlugosc kolejki: %.2f\n", (double) suma_kol/gran_cyklu);
				printf("srednia czas oczekiwania: %.2f minut\n", (double) kol_czek/obsluzeni);
			}
			else
				puts("Brak klientow!");
				
			WyczyscKolejke(&kol);
			puts("Do widzenia.");

			break;
	}
	return 0;
}
// x = sredni czas w minutach miedzy wejsciem kloejnych klientow
// wartosc zwraca jest true, jesli w tej minucie pojawil sie klient
bool nowyklient(double x) //czy jest nowy klient?
{
	if(rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}
//kiedy jest czasem wejscie klienta do kolejki
//funkcja zwraca strukture typu Pozycja_Kolejki z czasem przybycia
//ustawionym na kiedy i czasem konsultacji ustawionym na
//wartosc losowa z przedzialu 1-3
Pozycja_Kolejki czasklienta(long kiedy) //ustawia parametry klienta
{
	Pozycja_Kolejki klient;
	klient.czaskons = rand() % 3 + 1;
	klient.przybycie = kiedy;
	return klient;
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