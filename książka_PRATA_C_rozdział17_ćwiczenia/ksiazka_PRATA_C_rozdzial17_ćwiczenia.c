#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial17_æwiczenia.h"

//#include "lista_cw2.h" // do æwiczenia 2 (przyk³ad wziêty z listingu 17.4 (musi byæ w tym miejscu, gdy¿ awieraz def ROZT)

#include "lista_cw3.h" // do æwiczenia 3 (przyk³ad wziêty z listingu 17.4 (musi byæ w tym miejscu, gdy¿ awieraz def ROZT)

static int panelHandle;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//æwiczenie 1 (modyfikacja listingu 17.2)
//#define ROZT 45

struct film2 {
	char tytul[ROZT];
	int ocena;
	struct film2 *nast; //wskazuje na nastêpn¹ strukture w liscie
	struct film2 *poprzeni; //wskazuje na poprzednia strukture na liscie //modyfikacja do æwiczenia 1 listingu 17.2
};

char *wczytaj(char *z, int ile); //uzyty w lisingu 17.2
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//æwiczenie 2 ( modyfikacja listingu 17.4)
void pokazfilm(Pozycja pozycja);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial17_æwiczenia.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
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
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 1 rozdzia³ 17//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
			//add posibility to show list in add order and reverse order (w orginale, wiadomo o co chodzi w t³umaczeniu polskim nie koniecznie)
			//modyfkikacja listingu 17.2 to æwiczenia 1
		case EVENT_COMMIT:
			
			struct film2 *glowny = NULL;
			struct film2 *poprz, *biezacy, *nastepny;
			char wejscie[ROZT];
			
			//pobieranie i zapisywanie informacji
			puts("Podaj pierwszy tytul filmu:");
			while(wczytaj(wejscie, ROZT) != NULL && wejscie[0] != '\0')
			{
				biezacy = (struct film2 *)malloc(sizeof(struct film2));
				
				if(glowny == NULL) //pierwsza struktura
				{
					biezacy->poprzeni = NULL; //brak struktury nad glowna
					glowny = biezacy;
				}	
				else
				{
					poprz->nast = biezacy; //kolejne struktury
					biezacy->poprzeni = poprz; //do biezacego wezla jest wpisywany adres wczeœniejszego
				}
				
				biezacy->nast = NULL;
				
				strcpy(biezacy->tytul, wejscie);
				puts("Podaj Twoja ocene <0-10>:");
				scanf("%d", &biezacy->ocena);
				while (getchar() != '\n')
					continue;
				puts("Podaj nastepny tytul filmu (pusty wiersz konczy program):");
				poprz = biezacy;
				nastepny = biezacy;
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
			//w odwróconej kolejnosci
			biezacy = nastepny->poprzeni;
			printf("W odwroconej kolejnosci\n");
			printf("Film: %s Ocena: %d\n", nastepny->tytul, nastepny->ocena);
			while(biezacy != NULL)
			{
				printf("Film: %s Ocena: %d\n", biezacy->tytul, biezacy->ocena);
				biezacy = biezacy->poprzeni;
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
//////////////////////////Æwiczenie 2 rozdzia³ 17//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
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
//////////////////////////Æwiczenie 3 rozdzia³ 17//////////////////////////////////////////////////////
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
