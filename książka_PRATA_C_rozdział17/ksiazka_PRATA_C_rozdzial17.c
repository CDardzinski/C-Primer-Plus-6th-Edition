#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial17.h"

#include "lista.h" // do przyk³adu 17.4 (musi byæ w tym miejscu, gdy¿ awieraz def ROZT

#include "kolejka.h"//do przyk³adu 17.8 i 17.9

//#include "porady_kolejka.h" //do przyk³adu 17.9

#include "drzewo.h"//do przyk³adu 17.12

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//do listingu 17.1
#define ROZT 45 //rozmiar tablicy przechowujacej tytul //zdefiniowane w pliku lista.h
#define FMAX 5 //maksymalna liczba filmow

struct film {
	char tytul[ROZT];
	int ocena;
};

char *wczytaj(char *z, int ile); //uzyty w lisingu 17.2, listingu 17.4, listingu 17.12
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//do listingu 17.2
struct film2 {
	char tytul[ROZT];
	int ocena;
	struct film2 *nast; //wskazuje na nastêpn¹ strukture w liscie
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//do listingu 17.4
void pokazfilm(Pozycja pozycja);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//do listingu 17.9
#define MIN_W_GODZ 60.0
bool nowyklient(double x); //czy jest nowy klient?
Pozycja_Kolejki czasklienta(long kiedy); //ustawia parametry klienta
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//do listingu 17.12
#define MAXROZ 20
char menu(void);
void dodajzw(Drzewo *wd);
void usunzw(Drzewo *wd);
void pokazzw(const Drzewo *wd);
void szukajzw(const Drzewo *wd);
void wyswpoz(Pozycja_Drzewo pozycja);
void duzelit(char *lan);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
static int panelHandle;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial17.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 17.1 rozdzial 17//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct film filmy[FMAX];
			int i = 0;
			int j;
			
			puts("Podaj pierwszy tytul filmu:");
			while (i < FMAX && wczytaj(filmy[i].tytul, ROZT) != NULL && filmy[i].tytul[0] != '\0')
			{
				puts("Podaj Twoja ocene <0-10>:");
				scanf("%d", &filmy[i++].ocena);
				while (getchar() != '\n')
					continue;
				puts("Podaj nastepny tytul filmu (pusty wiersz konczy program):");
			}
			if(i == 0)
				printf("Nie wpisano zadnych danych. ");
			else 
				printf("Oto lista filmow:\n");
			
			for(j = 0; j < i; j++)
				printf("Film: %s Ocena: %d\n", filmy[j].tytul, filmy[j].ocena);
			
			printf("Do widzenia!\n");
					
			break;
	}
	return 0;
}
char *wczytaj(char *z, int ile)
{
	char *wynik;
	char *tutaj;
	
	wynik = fgets(z, ile, stdin);
	if(wynik)
	{
		tutaj = strchr(z, '\n'); //szukamy nowego wiersza
		if(tutaj) //jesli adres jest rozny od NULL
			*tutaj = '\0'; //zmieniamy znak nowego wiersza na pusty
		else
			while (getchar() != '\n')
				continue;			
	}
	return wynik;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 17.2 rozdzial 17//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct film2 *glowny = NULL;
			struct film2 *poprz, *biezacy;
			char wejscie[ROZT];
			
			//pobieranie i zapisywanie informacji
			puts("Podaj pierwszy tytul filmu:");
			while(wczytaj(wejscie, ROZT) != NULL && wejscie[0] != '\0')
			{
				biezacy = (struct film2 *)malloc(sizeof(struct film2));
				
				if(glowny == NULL) //pierwsza struktura
					glowny = biezacy;
				else
					poprz->nast = biezacy; //kolejne struktury
				
				biezacy->nast = NULL;
				
				strcpy(biezacy->tytul, wejscie);
				puts("Podaj Twoja ocene <0-10>:");
				scanf("%d", &biezacy->ocena);
				while (getchar() != '\n')
					continue;
				puts("Podaj nastepny tytul filmu (pusty wiersz konczy program):");
				poprz = biezacy;				
			}
			//wypisanie listy filmow
			if(glowny == NULL)
				printf("Nie wpisano zadnych danych. ");
			else
				printf("Oto lista filmow:\n");
			
			biezacy = glowny;
			while(biezacy != NULL)
			{
				printf("Film: %s Ocena: %d\n", biezacy->tytul, biezacy->ocena);
				biezacy = biezacy->nast;
			}
			//Przebieg programu zakonczony, zwalniamy przydzielona pamiec
			biezacy = glowny;
			while (biezacy != NULL)
			{
				poprz = biezacy;
				biezacy = poprz->nast;
				free(poprz);
			}
			
			printf("Do widzenia!\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 17.4 rozdzial 17//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			Lista filmy;
			Pozycja tymcz;
			
			//inicjalizacja
			InicjujListe(&filmy);
			if(PelnaLista(&filmy))
			{
				fprintf(stderr, "Brak pamieci!, Do widzenia!\n");
				exit(1);
			}
			//wczytanie i zapis danych
			puts("Podaj pierwszy tytul filmu:");
			while (wczytaj(tymcz.tytul, ROZT) != NULL && tymcz.tytul[0] != '\0')
			{
				puts("Podaj Twoja ocene <0-10>:");
				scanf("%d", &tymcz.ocena);
				while (getchar() != '\n')
					continue;
				if(DodajPozycje(tymcz, &filmy) == false)
				{
					fprintf(stderr, "Blad alokacji pamieci\n");
					break;
				}
				if(PelnaLista(&filmy))
				{
					puts("Lista jest juz pelna.");
					break;
				}
				puts("Podaj nastepny tytul filmu (pusty wiersz konczy wpisywanie):");
			}
			//wpisywanie zawartosci listy
			if(PustaLista(&filmy))
				printf("Nie wpisano zadnych danych. ");
			else
			{
				printf("Oto lista filmow:\n");
				Przejdz(&filmy, pokazfilm);
			}
			printf("Wpisales %d filmow.\n", LiczbaPozycji(&filmy));
				   
			//porzadki
			CzyscListe(&filmy);
			printf("Do widzenia!\n");

			break;
	}
	return 0;
}
void pokazfilm(Pozycja pozycja)
{
	printf("FIlm: %s Ocena: %d\n", pozycja.tytul, pozycja.ocena);	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 17.8 rozdzial 17//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			Kolejka kol;
			Pozycja_Kolejki tymcz;
			char ch;
			
			InicjujKolejke(&kol);
			puts("Test interfejsu Kolejka. Wpisz d, aby dodac wartosc,");
			puts("u, aby usunac wartosc, lub q, aby zakonczyc.");
			while ((ch = getchar()) != 'q')
			{
				if(ch != 'd' && ch != 'u') //pomija inne dane wejsciowe
					continue;
				if(ch == 'd')
				{
					printf("Liczba do dodania: ");
					scanf("%d", &tymcz);
					if(!PelnaKolejka(&kol))
					{
						printf("Wstawiam %d do kolejki\n", tymcz);
						Ustaw(tymcz, &kol);
					}
					else
						puts("Kolejka jest pelna!");
				}
				else
				{
					if(PustaKolejka(&kol))
						puts("Nie ma czego usunac!");
					else
					{
						Odlacz(&tymcz, &kol);
						printf("Usuwam %d z kolejki\n", tymcz);
					}
				}
				printf("%d pozycji w kolejce\n", LiczbaPozycjiKolejki(&kol));
				puts("Wpisz d, aby dodac, u, aby usunac, q, aby zakonczyc:");
			}
			WyczyscKolejke(&kol);
			puts("Do widzenia!");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 17.9 rozdzial 17//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
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
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 17.12 rozdzial 17//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			Drzewo zwierz;
			char wybor;
			InicjujDrzewo(&zwierz);
			
			while ((wybor = menu()) != 'q')
			{
				switch(wybor)
				{
					case 'd': dodajzw(&zwierz);
						break;
					case 'w': pokazzw(&zwierz);
						break;
					case 's': szukajzw(&zwierz);
						break;
					case 'l': printf("%d zwierzat w klubie.\n", LiczbaPozycjiDrzewo(&zwierz));
						break;
					case 'u': usunzw(&zwierz);
						break;
					default: puts("Blad w instrukcji switch");
				}
			}
			UsunWszystkoDrzewo(&zwierz);
			puts("Do widzenia.");
			break;
	}
	return 0;
}
char menu(void)
{
	int ch;
	puts("Klub Zwierzat Domowych - baza danych czlonkow");
	puts("Podaj litere odpowiadajaca wybranej opcji:");
	puts("d) dodaj zwierze		w)wyswietl liste zwierzat");
	puts("l) liczba zwierzat		s)szukaj zwierzecia");
	puts("u) usun zwierze		q)koniec");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')//porzuca reszte wiersza
			continue;
		ch = tolower(ch);
		if(strchr("dwlsuq", ch) == NULL)
			puts("Wpisz d, w, l, s, u lub q:");
		else
			break;		
	}
	if(ch == EOF) //sprawia, ze EOF konczy program
		ch = 'q';
	
	return ch;
}
void dodajzw(Drzewo *wd)
{
	Pozycja_Drzewo tymcz;
	if(PelneDrzewo(wd))
		puts("Brak wolnych miejsc w klubie!");
	else
	{
		puts("Podaj imie zwierzecia:");
		wczytaj(tymcz.imie, MAXROZ);
		puts("Podaj gatunek zwierzecia:");
		wczytaj(tymcz.gatunek, MAXROZ);
		duzelit(tymcz.imie);
		duzelit(tymcz.gatunek);
		DodajPozycjeDrzewo(&tymcz, wd);
	}
}
void usunzw(Drzewo *wd)
{
	Pozycja_Drzewo tymcz;
	
	if(PusteDrzewo(wd))
	{
		puts("Brak pozycji!");
		return; //wychodzi z funkcji, jesli drzewo jest puste
	}
	puts("Podaj imie zwierzecia, ktore chcesz usunac:");
	wczytaj(tymcz.imie, MAXROZ);
	puts("Podaj gatunek zwierzecia:");
	wczytaj(tymcz.gatunek, MAXROZ);
	duzelit(tymcz.imie);
	duzelit(tymcz.gatunek);
	printf("%s, %s", tymcz.imie, tymcz.gatunek);
	if(UsunPozycjeDrzewo(&tymcz, wd))
		printf("zostal(a) usuniety/a z klubu.\n");
	else
		printf("nie jest czlonkiem klubu.\n");
}
void pokazzw(const Drzewo *wd)
{
	if(PusteDrzewo(wd))
		puts("Brak pozycji!");
	else
		PrzejdzDrzewo(wd, wyswpoz);
}
void szukajzw(const Drzewo *wd)
{
	Pozycja_Drzewo tymcz;
	if(PusteDrzewo(wd))
	{
		puts("Brak pozycji!");
		return; //wychodzi z funkcji, jesli drzewo jest puste
	}
	puts("Podaj imie zwierzecia, ktore chcesz znalezc:");
	wczytaj(tymcz.imie, MAXROZ);
	puts("Podaj gatunek zwierzecia:");
	wczytaj(tymcz.gatunek, MAXROZ);
	duzelit(tymcz.imie);
	duzelit(tymcz.gatunek);
	printf("%s, %s", tymcz.imie, tymcz.gatunek);
	if(WDrzewie(&tymcz, wd))
		printf("jest czlonkiem klubu.\n");
	else
		printf("nie jest czlonkiem klubu.\n");
}
void wyswpoz(Pozycja_Drzewo pozycja)
{
	printf("Zwierze: %-19s Gatunek:%-19s\n", pozycja.imie, pozycja.gatunek);
}
void duzelit(char *lan)
{
	while (*lan != '\0')
	{
		*lan = toupper(*lan);
		lan++;
	}
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