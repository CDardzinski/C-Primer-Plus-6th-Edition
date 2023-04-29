#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include <stdbool.h>
#include "ksiazka_PRATA_C_rozdzial14.h"

static int panelHandle;

//do listingu 14.1 i listingu 14.11
char *wczytaj(char *z, int ile); //u¿yta w listingu 14.8 i lisingu 14.9 i listingu 14.10 i listingu 14.14 i listingu 14.15 i listingu 14.16

#define MAXTYT 41 //maksymalna dlugosc tytulu + 1
#define MAXAUT 31 //makszymalna dlugosc nazwiska autora +1

struct ksiazka{ //szablon struktury o nazwie ksiazka
	char tytul[MAXTYT];
	char autor[MAXAUT];
	float wartosc;
}; // koniec szablonu struktury

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do listingu 14.2
//char *wczytaj(char *z, int ile); // to samo co we wczeœniejszym przykladzie
#define MAXTYT1 40
#define MAXAUT1 40
#define MAXKS 100 //maksymalna liczba ksiazek

struct ksiazka1{  //definiuje szablon ksiazka
	char tytul1[MAXTYT1];
	char autor1[MAXTYT1];
	float wartosc1;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do listingu 14.3 i listingu 14.4 i
#define DL 20

struct daneos{	//pierwszy szablon
	char imie[DL];
	char nazw[DL];//
};
			
struct facet { //drugi szablon
	struct daneos person; //struktura zagniezdzona
	char ulub_jedz[DL]; 
	char zawod[DL];
	float dochody;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do listingu 14.5 i listingu 14.6 i listingu 14.7
#define FUNDDL 50

struct fundusze {
	char bank[FUNDDL];
	double bankfund;
	char oszcz[FUNDDL];
	double oszczfund;
};
double suma(double, double); //prototyp funkcji do lisingu 14.5

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do listingu 14.6
double suma1(const struct fundusze *);//prototyp funkcji do listingu 14.6 //argument jest wskaŸnikiem

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do listingu 14.7
double suma2(struct fundusze mamona); //prototyp funkcji do listingu 14.7 //argument jest struktura

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do listingu 14.8 i listingu 14.9
#define DL1 30

struct daneos1{	
	char imie[DL1];
	char nazw[DL1];
	int litery;
};

void pobierz(struct daneos1 *);//argument jest wskaŸnikiem
void oblicz(struct daneos1 *);//argument jest wskaŸnikiem
void pokaz(const struct daneos1 *);//argument jest wskaŸnikiem

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do listingu 14.9
struct daneos1 pobierz1(void);
struct daneos1 oblicz1(struct daneos1);
void pokaz1(struct daneos1);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do listingu 14.10
#define DL2 81

struct daneos2 {
	char *imie; //uzycie wskaznikow
	char *nazwisko;
	int litery;
};
void pobierz2(struct daneos2 *); //alokuje pamiec
void oblicz2(struct daneos2 *); 
void pokaz2(const struct daneos2 *);
void wyczysc2(struct daneos2 *); //zwlania pamiec

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do listingu 14.12
struct elast {
	size_t licznik;
	double srednia;
	double wynik[]; //elastyczny skladnik tablicowy
};
void pokazElast(const struct elast *p);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do listingu 14.13
#define FUNDDL13 50
#define N13 2

struct fundusze13 {
	char bank[FUNDDL13];
	double bankfund;
	char oszcz[FUNDDL13];
	double oszczfund;
};
double suma13(const struct fundusze13 pieniadze[], int n);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do listingu 14.14
#define MAXTYT14 40
#define MAXAUT14 40
#define MAXKS14 10	//maksymalna liczba ksiazek

struct ksiazka14 {//utworzenie szablonu ksiazka
	char tytul[MAXTYT14];
	char autor[MAXAUT14];
	float wartosc;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do listingu 14.15
enum widmo{czerwony, pomaranczowy, zolty, zielony, niebieski, fioletowy};
const char *kolory[] = {"czerwony", "pomaranczowy", "zolty", "zielony", "niebieski", "fioletowy"};

#define DLUGOSC15 30

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do listingu 14.16
#define DLUGOSC16 81

char pokazmenu(void);
void usunwiersz(void); //usuwa dane do konca wiersza
void pokaz16(void (*fp) (char*), char*str);
void DuzeLit(char *);//przetwarza male litery na duze
void MaleLit(char *); //przetwarza duze litery na male
void Odwroc(char *); // zamienia duze litery na male i odwrotnie
void Atrapa(char *); //pozostawia lancuch bez zmian

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial14.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.1 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct ksiazka bibl; //deklaracja bibl jako zmiennej typu strukturalnego ksiazka
			printf("Podaj tytul ksiazki.\n");
			wczytaj(bibl.tytul, MAXTYT);
			printf("Teraz podaj autora.\n");
			wczytaj(bibl.autor, MAXAUT);
			printf("Teraz podaj wartosc.\n");
			scanf("%f", &bibl.wartosc);
			printf("%s, autor: %s, cena: %.2f zl\n", bibl.tytul, bibl.autor, bibl.wartosc);
			printf("%s: \"%s\" (%.2f zl)\n", bibl.autor, bibl.tytul, bibl.wartosc);
			printf("Gotowe.\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.2 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct ksiazka1 bibl[MAXKS]; //tablica struktur typu ksiazka
			int licznik = 0;
			int index;
			
			printf("Podaj tytul ksiazki.\n");
			printf("Aby zakonczyc, nacisnij [enter] na poczatku wiersza.\n");
			while (licznik < MAXKS && wczytaj(bibl[licznik].tytul1, MAXTYT1) != NULL && bibl[licznik].tytul1[0] != '\0')
			{
				printf("Teraz podaj autora.\n");
				wczytaj(bibl[licznik].autor1, MAXTYT1);
				printf("Teraz podaj wartosc.\n");
				scanf("%f", &bibl[licznik++].wartosc1);
				while (getchar() != '\n')
					continue; //czysci wiersz wejsciowy
				if(licznik < MAXKS)
					printf("Podaj kolejny tytul.\n");
			}
			if(licznik > 0)
			{
				printf("Oto lista Twoich ksiazek:\n");
				for(index = 0; index < licznik; index++)
					printf("%s, autor: %s, cena: %.2f zl\n", bibl[index].tytul1, bibl[index].autor1, bibl[index]. wartosc1);
			}
			else
				printf("Zadnych ksiazek? Szkoda\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.3 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			const char *teksty[5] = {
				"	Dziekuje za cudowny wieczor, ",
				"Nie przypuszczalam, ze ",
				"moze byc tak wspanialym facetem. Musimy umowic sie",
				"na pyszny ",
				" i spedzic ze soba kilka milych chwil"
			};
			
			
			struct facet gosc = { //inicjalizacja zmennej
				{ "Chip", "HYperlink" },
				"talerz chipsow",
				"trener osobisty",
				36827.00
			};
			
			printf("%s - moj drogi, \n\n", gosc.person.imie);
			printf("%s%s. \n", teksty[0], gosc.person.imie);
			printf("%s%s\n", teksty[1], gosc.zawod);
			printf("%s\n", teksty[2]);
			printf("%s%s%s", teksty[3], gosc.ulub_jedz, teksty[4]);
			if(gosc.dochody > 150000.0)
				puts("!!");
			else if(gosc.dochody > 75000.0)
				puts("!");
			else
				puts(".");
			printf("\n%40s%s\n", " ", "Do zaobaczenia wkrotce,");
			printf("%40s%s\n", " ", "Szalala");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.4 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct facet gosc[2] = {
				{{ "Chip", "Hyperlink"},
					"talerz chipsow",
					"trener osobisty",
					36827.00
				},
				{{"Norbert", "Brzuchacz"},
					"mus lososiowy",
					"redaktor brukowca",
					148500.00
				}
			};
			
			struct facet *on; //oto wskaznik do struktury
			printf("adres #1: %p #2: %p\n", &gosc[0], &gosc[1]);
			on = &gosc[0]; // ustawia wskaznik
			printf("wskaznik #1:  %p #2: %p\n", on, on+1);
			printf("on->dochody ma wartosc %.2f $: (*on).dochody ma wartosc %.2f $\n", on->dochody, (*on).dochody);
			on++; 
			printf("on->ulub_jedz ma wartosc %s: on->person.nazw ma wartosc %s\n", on->ulub_jedz, on->person.nazw);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.5 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct fundusze edek = {
				"Bank Czosnkowo-Melonowy",
				2024.72,
				"Kasa Oszczednosciowo-Pozyczkowa\"Debet\"",
				8237.11
			};
			printf("Edek posiada w sumie %.2f zl.\n", suma(edek.bankfund, edek.oszczfund));

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.6 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct fundusze edek = {
				"Bank Czosnkowo-Melonowy",
				2024.72,
				"Kasa Oszczednosciowo-Pozyczkowa \"Debet\"",
				8237.11
			};
			
			printf("Edek posiada w sumie %.2f zl.\n", suma1(&edek));

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.7 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct fundusze edek = {
				"Bank Czosnkowo-Melonowy",
				2024.72,
				"Kasa Oszczednosciowo-Pozyczkowa \"Debet\"",
				8237.11
			};
			
			printf("Edek posiada w sumie %.2f zl.\n", suma2(edek));

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.8 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct daneos1 osoba;
			pobierz(&osoba);
			oblicz(&osoba);
			pokaz(&osoba);
			
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.9 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct daneos1 osoba;
			osoba = pobierz1();
			osoba = oblicz1(osoba);
			pokaz1(osoba);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.10 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct daneos2 osoba;
			pobierz2(&osoba);
			oblicz2(&osoba);
			pokaz2(&osoba);
			wyczysc2(&osoba);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.11 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct ksiazka polecana;
			int wynik;
			
			printf("Wprowadz wynik testu: ");
			scanf("%d", &wynik);
			
			if(wynik >= 84)
				polecana = (struct ksiazka) {"Zbrodnia i kara",
											"Fiodor Dostojewski",
											9.99};
			else
				polecana = (struct ksiazka) {"Kubus Puchatek",
											"A.A. Milne",
											5.99};
			printf("Wlasniwa dla Ciebie lektura to:\n");
			printf("%s autorstwa %s: $%.2f\n", polecana.tytul, polecana.autor, polecana.wartosc);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.12 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad12ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct elast *wsk1, *wsk2;
			int n = 5;
			int i;
			int suma = 0;
			
			//przydzielenie pamieci dla struktury + tablicy
			wsk1 = malloc(sizeof(struct elast) + n * sizeof(double));
			wsk1->licznik = n;
			for(i = 0; i < n; i++)
			{
				wsk1->wynik[i] = 20.0 - i;
				suma += wsk1->wynik[i];
			}
			wsk1->srednia = suma/n;
			pokazElast(wsk1);
			
			n = 9;
			suma = 0;
			wsk2 = malloc(sizeof(struct elast) + n * sizeof(double));
			wsk2->licznik = n;
			for(i = 0; i < n; i++)
			{
				wsk2->wynik[i] = 20.0 - i/2.0;
				suma += wsk2->wynik[i];
			}
			wsk2->srednia = suma/n;
			pokazElast(wsk2);
			free(wsk1);
			free(wsk2);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.13 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad13ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct fundusze13 kowalski[N13] =
			{
				{
					"Bank Czosnkowo - Melonowy",
					2024.72,
					"Kasa Oszczednosciwo - Pozyczkowa \"Debet\"",
					8237.11
				},
				{
					"Bank \"Uczciwy Jan\"",
					1834.28,
					"Kasa oszczednosciowa \"Chomik\"",
					2903.89
				}
			};
			
			printf("Kowalscy posiadaja w sumie %.2f zl.\n", suma13(kowalski, N13));
			

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.14 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad14ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct ksiazka14 bibl[MAXKS14]; //tablica struktur
			int licznik = 0;
			int index, licznikp;
			FILE *pksiazki;
			int rozmiar = sizeof(struct ksiazka14);
			
			if((pksiazki = fopen("ksiazki.dat", "a+b")) == NULL)
			{
				fputs("Nie moge otworzyc pliku ksiazki.dat\n", stderr);
				exit(1);
			}
			rewind(pksiazki); // przejscie na poczatek pliku
			
			while (licznik < MAXKS14 && fread(&bibl[licznik], rozmiar, 1, pksiazki) == 1)
			{
				if(licznik == 0)
					puts("Biezaca zawartosc pliku ksiazki.dat:");
				printf("%s by %s: %.2f zl\n", bibl[licznik].tytul, bibl[licznik].autor, bibl[licznik].wartosc);
				licznik++;
			}
			
			licznikp = licznik;
			
			if(licznik == MAXKS14)
			{
				fputs("Plik ksiazki.dat jest pelny.", stderr);
				exit(2);
			}
			
			puts("Podaj nowe tytuly ksiazek.");
			puts("Aby zkaonczyc, nacisnij [enter] na poczatku wiersza.");
			while (licznik <MAXKS14 && wczytaj(bibl[licznik].tytul, MAXTYT14) != NULL && bibl[licznik].tytul[0] != '\0')
			{
				puts("Teraz podaj autora.");
				wczytaj(bibl[licznik].autor, MAXAUT14);
				puts("Teraz podaj wartosc.");
				scanf("%f", &bibl[licznik++].wartosc);
				while (getchar() != '\n')
					continue; //czysci wiersz wejsciowy
				if(licznik < MAXKS14)
					puts("Podaj nastepny tytul.");				
			}
			if(licznik > 0)
			{
				puts("Oto lista Twoich ksiazek:\n");
				for(index = 0; index < licznik; index++)
					printf("%s, autor: %s, cena: %.2f zl\n", bibl[index].tytul, bibl[index].autor, bibl[index].wartosc);
				fwrite(&bibl[licznikp], rozmiar, licznik - licznikp, pksiazki);
			}
			else
				puts("Zadnych ksiazek? Szkoda\n");
			puts("Koniec\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.15 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad15ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			char wybor[DLUGOSC15];
			enum widmo kolor;
			bool kolor_znaleziony = false;
			puts("Podaj kolor (pusta linia - koniec):");
			while(wczytaj(wybor, DLUGOSC15) != NULL && wybor[0] != '\0')
			{
				for(kolor = czerwony; kolor <= fioletowy; kolor++)
				{
					if(strcmp(wybor, kolory[kolor]) == 0)
					{
						kolor_znaleziony = true;
						break;
					}
				}
				if(kolor_znaleziony)
					switch (kolor)
					{
						case czerwony: puts("Roze sa czerwone.");							
							break;
						case pomaranczowy: puts("Maki sa pomaranczowe.");
							break;
						case zolty: puts("Sloneczniki sa zolte.");
							break;
						case zielony: puts("Traw jest zielona.");
							break;
						case niebieski: puts("Dzwonki sa niebieskie.");
							break;
						case fioletowy: puts("Fiolki sa fioletowe.");
							break;
					}
				else
					printf("Nie wiem nic o kolorze %s.\n", wybor);
				kolor_znaleziony = false;
				puts("Podaj nastepny kolor, prosze (pusta linia - koniec):");
			}
			puts("Do widzenia!");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 14.16 rodzial 14///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad16ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			char wiersz[DLUGOSC16];
			char kopia[DLUGOSC16];
			char wybor;
			void (*wfun)(char* ); //wskazuje na funkcje przyjmujaca argument typu char* i nie zwracajaca wartosci
			puts("Podaj lancuch (pusty wiersz konczy program):");
			while (wczytaj(wiersz, DLUGOSC16) != NULL && wiersz[0] != '\0')
			{
				while ((wybor = pokazmenu()) != 'n')
				{
					switch (wybor)//switch decyduje o wskazniku
					{
						case 'd': wfun = DuzeLit; 		
							break;
						case 'm': wfun = MaleLit;
							break;
						case 'o': wfun = Odwroc;
							break;
						case 'b': wfun = Atrapa;	
					}
					strcpy(kopia, wiersz); //tworzy kopie dla funkcji pokaz()
					pokaz16(wfun, kopia); //korzysta z wybranej funkcji
				}
				puts("Podaj lancuch (pusty wiersz konczy program):");
			}
			puts("Czesc!");
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
//definicja funkcji do przykladu 14.1 i przyk³adu 14.2
char *wczytaj(char *z, int ile)
{
	char *wynik;
	char *tutaj;
	wynik = fgets(z, ile, stdin);
	if(wynik)
	{
		tutaj = strchr(z, '\n'); //szukamy nowego wiersza
		if(tutaj) // jesli adres jest rozny od NULL
			*tutaj = '\0'; //zmieniamy znak nowego wiersza na pusty
		else
			while(getchar() != '\n')
				continue;
	}
	return wynik;
}
//definicja funkcji do przykladu 14.5
double suma(double x, double y)
{
	return (x + y);
}
//definicja funkcji do przykladu 14.6
double suma1(const struct fundusze *pieniedze)
{
	return (pieniedze->bankfund + pieniedze->oszczfund);
}
//definicja funckji do przyk³adu 14.7
double suma2(struct fundusze mamona)
{
	return(mamona.bankfund + mamona.oszczfund);
}
//definicje funkcji do przykladu 14.8
void pobierz(struct daneos1 *wst)
{
	printf("Podaj swoje imie.\n");
	wczytaj(wst->imie, DL1);
	printf("Podaj swoje nazwisko.\n");
	wczytaj(wst->nazw, DL1);
}
void oblicz(struct daneos1 *wst)
{
	wst->litery = strlen(wst->imie) + strlen(wst->nazw);
}
void pokaz(const struct daneos1 *wst)
{
	printf("%s %s, Twoje imie i nazwisko skladaja sie z %d liter.\n", wst->imie, wst->nazw, wst->litery);
}
//definicje funkcji do przyk³adu 14.9
struct daneos1 pobierz1(void)
{
	struct daneos1 temp;
	printf("Podaj swoje imie.\n");
	wczytaj(temp.imie, DL1);
	printf("Podaj swoje nazwisko.\n");
	wczytaj(temp.nazw, DL1);
	return temp;
}
struct daneos1 oblicz1(struct daneos1 info)
{
	info.litery = strlen(info.imie) + strlen(info.nazw);
	return info;
}
void pokaz1(struct daneos1 info)
{
	printf("%s %s, Twoje imie i nazwisko skladaja sie z %d liter.\n", info.imie, info.nazw, info.litery);
}
//definicje funkcji do przyk³adu 14.10
void pobierz2(struct daneos2 *wsk) //alokuje pamiec
{
	char temp[DL2];
	printf("Podaj swoje imie.\n");
	wczytaj(temp, DL2);
	//alokuje pamiec dla lancucha
	wsk->imie = (char *) malloc(strlen(temp) + 1);
	//kopiuje lanuch do zaalokownej pamieci
	strcpy(wsk->imie, temp);
	printf("Podaj swoje nazwisko.\n");
	wczytaj(temp, DL2);
	wsk->nazwisko = (char *) malloc(strlen(temp) + 1);
	strcpy(wsk->nazwisko, temp);
}
void oblicz2(struct daneos2 *wsk)
{
	wsk->litery = strlen(wsk->imie) + strlen(wsk->nazwisko);
}
void pokaz2(const struct daneos2 *wsk)
{
	printf("%s %s, Twoje imie i nazwisko skladaja sie z %d liter.\n", wsk->imie, wsk->nazwisko, wsk->litery);	
}
void wyczysc2(struct daneos2 *wsk) //zwlania pamiec
{
	free(wsk->imie);
	free(wsk->nazwisko);
}
//definicja funkcji do przyk³adu 14.12
void pokazElast(const struct elast *p)
{
	int i;
	printf("Wynik : ");
	for(i = 0; i < p->licznik; i++)
		printf("%g ", p->wynik[i]);
	printf("\nSrednia: %g\n", p->srednia);
}
//definicja funkcji do przyk³adu 14.13
double suma13(const struct fundusze13 pieniadze[], int n)
{
	double kwota;
	int i;
	for(i = 0, kwota = 0; i < n; i++)
		kwota += pieniadze[i].bankfund + pieniadze[i].oszczfund;
	return(kwota);
}
//definicje funkcji przyk³adu 14.16
char pokazmenu(void)
{
	char odp;
	puts("Wybierz jedna opcje:");
	puts("d) duze litery				m) male litery");
	puts("o) odwrocenie liter		b) bez zmian");
	puts("n) nastepny lancuch");
	odp = getchar(); //pobiera odpowiedz
	odp = tolower(odp); //przetwarza odp. na mala litere
	usunwiersz(); //pozbywa sie reszty wiersza
	while (strchr("dmobn", odp) == NULL)
	{
		puts("Wpisz d, m, o, b lub n:");
		odp = tolower(getchar());
		usunwiersz();
	}
	return odp;
}
void usunwiersz(void) //usuwa dane do konca wiersza
{
	while (getchar() != '\n')
		continue;
}
void pokaz16(void (*fw) (char*), char*lan)
{
	(*fw)(lan); //stosuje wybarna funkcje do lan
	puts(lan);//wyswietla wynik	
}
void DuzeLit(char *lan)//przetwarza male litery na duze
{
	while (*lan != '\0')
	{
		*lan = toupper(*lan);
		lan++;
	}
}
void MaleLit(char *lan) //przetwarza duze litery na male
{
	while (*lan != '\0')
	{
		*lan = tolower(*lan);
		lan++;
	}
}
void Odwroc(char *lan) // zamienia duze litery na male i odwrotnie
{
	while (*lan != '\0')
	{
		if(islower(*lan))
			*lan = toupper(*lan);
		else if(isupper(*lan))
			*lan = tolower(*lan);
		lan++;
	}
}
void Atrapa(char *lan) //pozostawia lancuch bez zmian
{
	//pozostawia lancuch bez zmian
}