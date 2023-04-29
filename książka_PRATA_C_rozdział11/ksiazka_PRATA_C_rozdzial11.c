#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial11.h"

/////do przykladu 11.1
#define NAPIS "To jest stala lancuchowa."
#define MAXDL 81
///////////////////////////

/////do przykladu 11.3
#define LANCUCH "Jestem wyjatkowy."
///////////////////////////

/////do przykladu 11.4
#define DLUGOSC 40
#define MAX 5
///////////////////////////

/////do przykladu 11.6
#define DLUGOSC1 81
///////////////////////////

/////do przykladu 11.7
#define DLUGOSC2 14
///////////////////////////

/////do przykladu 11.8
#define DLUGOSC3 10
///////////////////////////

/////do przykladu 11.10 i 11.20 i 11.21 i 11.23 i 11.25 i 11.27 i 11.28 i 11.29 i 11.33
char *wczytaj(char *z, int ile);
///////////////////////////

/////do przykladu 11.12
#define DEF "Jestem zdefiniowanym lancuchem"
///////////////////////////

/////do przykladu 11.14
void wysw1(const char *lancuch); //lancuch nie ulega zmianie
///////////////////////////

/////do przykladu 11.15
int wysw2(const char *lancuch);
///////////////////////////

/////do przykladu 11.17
void skroc(char *, unsigned int);
///////////////////////////

/////do przykladu 11.18
#define ROZMIAR 80
///////////////////////////

/////do przykladu 11.19
#define ROZMIAR1 30
#define ROZMIAR_OWADY 17
///////////////////////////

/////do przykladu 11.20
#define ODPOWIEDZ "Grant" //i 11.21 
#define ROZMIAR2 40
///////////////////////////

/////do przykladu 11.20
#define MAX2 40
///////////////////////////

/////do przykladu 11.23
#define ROZMIAR3 81
#define GRAN 100
#define STOP "koniec"
///////////////////////////

/////do przykladu 11.24
#define ROZMIARLISTY 5
///////////////////////////

/////do przykladu 11.25
#define ROZMIAR4 40
#define GRAN1 5
///////////////////////////

/////do przykladu 11.26
#define ROZMIAR5 40
#define SLOWO "cukier"
///////////////////////////

/////do przykladu 11.27
#define ROZMIAR6 40
#define ROZMIAR_CELU 7
#define GRAN2 5
///////////////////////////

/////do przykladu 11.28
#define MAX3 20
///////////////////////////

/////do przykladu 11.29
#define ROZMIAR7  81 	//granica dlugosci lancucha, wlacznie z \0
#define GRAN3 20		//maksymalna liczba wierszy 
void srtlan(char *lancuch[], int num); //funkcja sortujaca lancuchy
///////////////////////////

/////do przykladu 11.30
#define GRANICA 80
void DuzeLit(char *);
int LiczInter(const char *);
///////////////////////////

/////do przykladu 11.33
#define LIMIT 30
///////////////////////////


static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial11.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.1 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char slowa[MAXDL] = "To jest lancuch w tablicy.";
	const char *wsk1 = "Cos mnie wskazuje.";
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts("Oto kilka lancuchow:");
			puts(NAPIS);
			puts(slowa);
			puts(wsk1);
			slowa[1] = 'u';
			puts(slowa);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.2 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			printf("%s, %p, %c\n", "Nie", "jestesmy", *"kosmicznymi wedrowcami");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.3 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char tab[] = LANCUCH;
	const char *wsk  = LANCUCH;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("adres \"Jestem wyjatkowy\": %p \n", "Jestem wyjatkowy");
			printf(" adres tab: %p\n", tab);
			printf(" adres wsk: %p\n", wsk);
			printf(" adres  LANCUCH-a: %p\n", LANCUCH);
			printf("adres \"Jestem wyjatkowy\": %p \n", "Jestem wyjatkowy");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.4 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const char *wymagania[MAX] = {
		"Dodawanie w pamieci", 
		"Bezbledne mnozenie",
		"Szybkie zapamietywanie",
		"Doslowne wykonywanie polecen",
		"Programowanie w C"
	};
	
	char umiejetnosc[MAX][DLUGOSC] = {
		"Chodzenie wzdluz linii",
		"Spanie", "Ogladanie telewizji",
		"Wysylanie poczty", "Czytanie e-maili"
	};
	
	int i;
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts("Porownajmy:");
			printf("%-36s %-25s\n", "Wymagania", "Umiejetnosci");
			for(i = 0; i < MAX; i++)
				printf("%-36s %-25s\n", wymagania[i], umiejetnosc[i]);
			printf("\nsizeof wymagania: %zd, sizeof umiejetnosc: %zd\n", sizeof(wymagania), sizeof(umiejetnosc));
			

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.5 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char *tekst = "Nie badz glupi!";
	char *kopia;
	
	switch (event)
	{
		case EVENT_COMMIT:
			kopia = tekst;
			printf("%s\n", kopia);
			printf("tekst = %s; &tekst = %p; wartosc = %p\n", tekst, &tekst, tekst);
			printf("kopia = %s; &kopia = %p; wartosc = %p\n", kopia, &kopia, kopia);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.6 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char slowa[DLUGOSC1];
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts("Prosze wprowadzic lancuch.");
			gets(slowa);
			printf("Wprowadzony lancuch (dwa razy):\n");
			printf("%s\n", slowa);
			puts(slowa);
			puts("Gotowe.");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.7 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char slowa[DLUGOSC2];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			puts("Prosze wprowadzic lancuch.");
			fgets(slowa, DLUGOSC2, stdin);
			printf("Wprowadzony lancuch (dwa razy: z puts() i fputs()):\n");
			puts(slowa);
			fputs(slowa, stdout);
			puts("Prosze wprowadzic kolejny lancuch.");
			fgets(slowa, DLUGOSC2, stdin);
			printf("Wprowadzony lancuch (dwa razy: z puts() i fputs()):\n");
			puts(slowa);
			fputs(slowa, stdout);
			puts("Gotowe.");		

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.8 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char slowa[DLUGOSC3];
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts("Wprowadz lancuchy (Pusty wiersz zakonczy program):");
			while (fgets(slowa, DLUGOSC3, stdin) != NULL && slowa[0] != '\n')
				fputs(slowa, stdout);
			puts("Gotowe.");				
			

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.9 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char slowa[DLUGOSC3];
	int i;
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts("Wprowadz lancuchy (pusty wiersz zakonczy program):");
			while(fgets(slowa, DLUGOSC3, stdin) != NULL && slowa[0] != '\n')
			{
				i = 0;
				while (slowa[i] != '\n' && slowa[i]  != '\0')
					i++;
				if(slowa[i] == '\n')
					slowa[i] = '\0';
				else //slowa[i] juz wynosi '\0'
					while (getchar() != '\n')
						continue;						
				puts(slowa);				
			}
			puts("Gotowe");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.11 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char imie1[11], imie2[12];
	int licznik;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj dwa imiona.\n");
			licznik = scanf("%5s %10s", imie1, imie2);
			printf("Odczytalem %d imiona: %s i %s.\n", licznik, imie1, imie2);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.12 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad12ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char lan1[180] = "Przypisano mnie tablicy.";
	char *lan2 = "Przypisano mnie wskaznikowi.";
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts("Jestem argumentem funkcji puts().");
			puts(DEF);
			puts(lan1);
			puts(lan2);
			puts(&lan1[5]);
			puts(lan2+4);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.13 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad13ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char przed[] = "Przed";
	char nie[] = {'N', 'I', 'E', '!'};
	char za[] = "Za";
	switch (event)
	{
		case EVENT_COMMIT:
			puts(nie); //nie nie jest ³añcuchem

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.16 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad16ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			wysw1("Gdybym mial fure kasy,");
			wysw2("zrobilbym zapasy\n");
			printf("Naliczylem %d znakow.\n", wysw2("Albo pojechalbym na wczasy."));

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.17 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad17ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char tekst[] = "Wyjasnienia powinny byc tak proste jak to mozliwe, ale nie prostsze.";
	switch (event)
	{
		case EVENT_COMMIT:
			puts(tekst);
			skroc(tekst, 49);
			puts(tekst);
			puts("Spojrzmy na reszte lancucha.");
			puts(tekst + 50);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.18 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad18ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char kwiat[ROZMIAR];
	char dodatek[] = " smierdza jak stare buty.";
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts("Jakie kwiaty lubisz najbardziej?");
			if(wczytaj(kwiat, ROZMIAR))
			{
				strcat(kwiat, dodatek);
				puts(kwiat);
				puts(dodatek);
			}
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.19 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad19ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char kwiaty[ROZMIAR1];
	char dodatek[] = " smierdza jak stare buty.";
	char owady[ROZMIAR_OWADY];
	int wolne;
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts("Jakie kwiaty lubisz najbardziej?");
			wczytaj(kwiaty, ROZMIAR1);
			if((strlen(dodatek) + strlen(kwiaty) +1) <= ROZMIAR1)
				strcat(kwiaty, dodatek);
			puts(kwiaty);
			puts("Jakie owady lubisz najbardziej?");
			wczytaj(owady, ROZMIAR_OWADY);
			wolne = ROZMIAR_OWADY - strlen(owady) - 1;
			strncat(owady, dodatek, wolne);
			puts(owady);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.20 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad20ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char proba[ROZMIAR2];
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts("Kto jest pochowany w grobowcu Granta?");
			wczytaj(proba, ROZMIAR2);
			while (proba != ODPOWIEDZ)
			{
				puts("Niestety to nie jest dobra odpowiedz. Sprobuj jeszcze raz.");
				wczytaj(proba, ROZMIAR2);
			}
			puts("Tak jest!");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.21 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad21ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char proba[MAX2];
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts("Kto jest pochowany w grobowcu Granta?");
			wczytaj(proba, MAX2);
			while (strcmp(proba, ODPOWIEDZ) !=  0)
			{
				puts("Niestety to nie jest dobra odpowiedz. Sprobuj jeszcze raz.");
				wczytaj(proba, ROZMIAR2);
			}
			puts("Tak jest!");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.22 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad22ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			printf("strcmp(\"A\", \"A\") = ");
			printf("%d\n", strcmp("A", "A"));
			
			printf("strcmp(\"A\", \"B\") = ");
			printf("%d\n", strcmp("A", "B"));
			
			printf("strcmp(\"B\", \"A\") = ");
			printf("%d\n", strcmp("B", "A"));
			
			printf("strcmp(\"C\", \"A\") = ");
			printf("%d\n", strcmp("C", "A"));
			
			printf("strcmp(\"Z\", \"a\") = ");
			printf("%d\n", strcmp("Z", "a"));
			
			printf("strcmp(\"koty\", \"kot\") = ");
			printf("%d\n", strcmp("koty", "kot"));

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.23 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad23ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char wejscie[GRAN][ROZMIAR3];
	int licz = 0;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wpisz maksymalnie %d wierszy (wpisz koniec, aby zakonczyc): \n", GRAN);
			while (licz < GRAN && wczytaj(wejscie[licz], ROZMIAR3) != NULL && strcmp(wejscie[licz], STOP) != 0)
			{
				licz++;
			}
			printf("Podano %d lancuchow\n", licz);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.24 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad24ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const char *lista[ROZMIARLISTY]  = {
							"astronomia", "asteroida",
							"astrofizyka", "ostroga",
							"asteryzm" };
	int licznik = 0;
	int i;
	
	switch (event)
	{
		case EVENT_COMMIT:
			for(i = 0; i < ROZMIARLISTY; i++)
				if(strncmp(lista[i], "astro", 5) == 0)
				{
					printf("Znaleziono: %s\n", lista[i]);
					licznik++;
				}
			printf("Lista zawiera %d slowa zaczynajace sie na astro.\n", licznik);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.25 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad25ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char vslowa[GRAN1][ROZMIAR4];
	char temp[ROZMIAR4];
	int i = 0;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj %d slow zaczynajacych sie na v:\n", GRAN1);
			while (i < GRAN1 && wczytaj(temp, ROZMIAR4))
			{
				if(temp[0] != 'v')
					printf("%s nie zaczyna sie na v!\n", temp);
				else
				{
					strcpy(vslowa[i], temp);
					i++;
				}
			}
			puts("Oto przyjete slowa: ");
			for(i = 0; i < GRAN1; i++)
				puts(vslowa[i]);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.26 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad26ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const char *zrodlo = SLOWO;
	char kopia[ROZMIAR5] = "Podaj mnie do sadu.";
	char *wl;
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts(zrodlo);
			puts(kopia);
			wl = strcpy(kopia + 6, zrodlo);
			puts(kopia);
			puts(wl);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.27 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad27ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char vslowa[GRAN2][ROZMIAR5];
	char temp[ROZMIAR5];
	int i = 0;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj %d slow zaczynajacych sie na v:\n", GRAN2);
			while (i < GRAN2 && wczytaj(temp, ROZMIAR5))
			{
				if(temp[0] != 'v')
					printf("%s nie zaczyna sie na v!\n", temp);
				else
				{
					strncpy(vslowa[i], temp, ROZMIAR_CELU - 1);
					vslowa[i][ROZMIAR_CELU - 1] = '\0';
					i++;
				}
			}
			puts("Oto przyjete slowa: ");
			for(i = 0; i < GRAN2; i++)
				puts(vslowa[i]);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.28 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad28ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char imie[MAX3];
	char nazwisko[MAX3];
	char formal[2*MAX3 + 101];
	double wygrana;
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts("Podaj swoje imie:");
			wczytaj(imie, MAX3);
			puts("Podaj swoje nazwisko:");
			wczytaj(nazwisko, MAX3);
			puts("Podaj wygrana sume pieniedzy:");
			scanf("%lf", &wygrana);
			sprintf(formal, "%s, %-19s: %6.2f zl\n", nazwisko, imie, wygrana);
			puts(formal);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.29 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad29ButtonCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char dane[GRAN3][ROZMIAR7]; //tablica przechowujaca dane wejsciowe
	char *wsklan[GRAN3]; //tablica zmiennych wskaznikowych
	int licz = 0;
	int k;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj maksymalnie %d wierszy, a ja je uporzadkuje.\n", GRAN3);
			printf("Aby zakonczyc, wcisnij Enter na poczatku wiersza.\n");
			while(licz < GRAN3 && wczytaj(dane[licz], ROZMIAR7) != NULL && dane[licz][0] != '\0')
			{
				wsklan[licz] = dane[licz]; //ustaw wskazniki na lancuchy
				licz++;
			}
			srtlan(wsklan, licz);
			puts("\nOto uporzadkowa lista:\n");
			for(k = 0; k < licz; k++)
				puts(wsklan[k]); //posortowane wskazniki
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.30 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad30ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char wiersz[GRANICA];
	char *tutaj;
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts("Podaj wiersz tekstu:");
			fgets(wiersz, GRANICA, stdin);
			tutaj = strchr(wiersz, '\n'); //szukamy znaku nowego wiersz
			if(tutaj)	//jesli adres jest rozny od NULL
				*tutaj = '\0';	//zmieniamy na znak pusty

			DuzeLit(wiersz);
			puts(wiersz);
			printf("Wpisany wiersz zawiera %d znakow interpunkcyjnych.\n", LiczInter(wiersz));
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.33 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad33ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char liczba[LIMIT];
	char *koniec;
	long wartosc;
	
	switch (event)
	{
		case EVENT_COMMIT:
			puts("Podaj liczbe (wpisz pusty wiersz, aby zakonczyc):");
			while (wczytaj(liczba, LIMIT) && liczba[0] != '\0')
			{
				wartosc = strtol(liczba, &koniec, 10);
				printf("wartosc: %ld, poprzedza %s (%d)\n", wartosc, koniec, *koniec);
				wartosc = strtol(liczba, &koniec, 16);
				printf("wartosc: %ld, poprzedza %s (%d)\n", wartosc, koniec, *koniec);
				puts("Nastepna liczba:");
			}
			puts("Do widzenia!\n");

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
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.10 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///Podprogram z listingu 11.10
///////////////////////////////////////////////////////////////////////////////////
char *wczytaj(char *z, int ile)
{
	char *wynik;
	int i = 0;
	
	wynik = fgets(z, ile, stdin);
	if(wynik)//wynik roczny od NULL
	{
		while (z[i] != '\n' && z[i] != '\0')
			i++;
		if(z[i] == '\n')
			z[i] = '\0'; //znak nowego wiersza -> znak pusty
		else //z[i] == '\0'
			while(getchar() != '\n')
				continue;
	}
	return wynik;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.14 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///Podprogram z listingu 11.14
///////////////////////////////////////////////////////////////////////////////////
void wysw1(const char *lancuch) //lancuch nie ulega zmianie
{
	while(*lancuch != '\0')
		putchar(*lancuch++);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 11.15 rodzial 11///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///Podprogram z listingu 11.15
///////////////////////////////////////////////////////////////////////////////////
int wysw2(const char *lancuch)
{
	int licznik = 0;
	while (*lancuch)
	{
		putchar(*lancuch++);
		licznik++;
	}
	putchar('\n');	//znak nowej linii nie jest liczony
	return(licznik);
}
////Do programu 11.17
void skroc(char *lancuch, unsigned int rozmiar)
{
	if(strlen(lancuch) > rozmiar)
		*(lancuch + rozmiar) = '\0';
}

////Do programu 11.29
void srtlan(char *lancuch[], int num) //funkcja sortujaca lancuchy
{
	char *temp;
	int dol, szuk;
	
	for(dol = 0; dol < num-1; dol++)
		for(szuk = dol + 1; szuk < num; szuk++)
			if(strcmp(lancuch[dol], lancuch[szuk]) > 0)
			{
				temp = lancuch[dol];
				lancuch[dol] = lancuch[szuk];
				lancuch[szuk] = temp;
			}
}

////Do programu 11.30
void DuzeLit(char *lan)
{
	while (*lan)
	{
		*lan = toupper(*lan);
		lan++;
	}
}
int LiczInter(const char *lan)
{
	int licz = 0;
	while (*lan)
	{
		if(ispunct(*lan))
			licz++;
		lan++;
	}
	return licz;
}