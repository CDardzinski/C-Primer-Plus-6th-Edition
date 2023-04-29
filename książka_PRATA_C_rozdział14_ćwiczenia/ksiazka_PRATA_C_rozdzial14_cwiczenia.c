#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include <math.h>
#include "ksiazka_PRATA_C_rozdzial14_cwiczenia.h"

static int panelHandle;

// do æwiczenia 1
struct miesiac {
	char nazwa[15];
	char skrot[4];
	int dni;
	int numer;
};
struct miesiac miesiace[12] = 
{
	{"Styczen", "sty", 31, 1},
	{"Luty", "lut", 28, 2},
	{"Marzec", "mar", 31, 3},
 	{"Kwiecien", "kwi", 30, 4},
	{"Maj", "maj", 31, 5},
	{"Czerwiec", "cze", 30, 6},
	{"Lipiec", "lip", 31, 7},
	{"Sierpien", "sie", 31, 8},
	{"Wrzesien", "wrz", 30, 9},
	{"Pazdziernik", "paz", 31, 10},
	{"Listopad", "lis", 30, 11},
	{"Grudzien", "gru", 31, 12}
};
	
int obliczDniDoTegoMiesiaca(char*);
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// do æwiczenia 2
int SprawdzMiesiac(char *miesiac);
int obliczIleDni(int, int, int);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do æwiczenia 3
char *wczytaj(char *z, int ile); // to samo co we wczeœniejszym przykladzie
#define MAXTYT 40
#define MAXAUT 40
#define MAXKS 100 //maksymalna liczba ksiazek

struct ksiazka{  //definiuje szablon ksiazka
	char tytul[MAXTYT];
	char autor[MAXTYT];
	float wartosc;
};

int SegregujKsiazki(int licznik, const struct ksiazka []);
double WartoscBilioteki(int licznik,const struct ksiazka lista[]);

////////////////////////////////////////////////////////////////////////////////////////////////////////////2

//do æwiczenia 4
struct danePersnalne{
	char imie[MAXTYT];
	char drugieImie[MAXTYT];
	char nazwisko[MAXTYT];
};

struct danePelne{
	int pesel;
	struct danePersnalne Osoba;
};

void WyswietlDaneWStrukturze(struct danePelne *wsk);
void WyswietlDaneWStrukturzeStruktura(struct danePelne strukturaPrzekzana[]);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do æwiczenia 5
#define ROZMIAR 4

struct daneos{
	char imie[MAXTYT];
	char nazwisko[MAXTYT];
};

struct student{
	struct daneos daneStudenta;
	double oceny[MAXTYT];
	double srednia;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do æwiczenia 6
struct gracz{
	int numerGracza;
	char imie[MAXTYT];
	char nazwisko[MAXTYT];
	int liczbaRzutowOddanychZaDwaPunkty;
	int liczbaTrafienZaDwaPunkty;
	int liczbaAsyst;
	int LiczbaFauli;
	double skutecznosc;
};

int SprCzySiePowtarza(struct gracz *wsk, char numer[], char infoDoPrzetworzenia[]);
////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do æwiczenia 7
//char *wczytaj(char *z, int ile);

#define MAXTYT14 40
#define MAXAUT14 40
#define MAXKS14 10	//maksymalna liczba ksiazek

struct ksiazka14 {//utworzenie szablonu ksiazka
	char tytul[MAXTYT14];
	char autor[MAXAUT14];
	float wartosc;
};

void edytujWczytanyRekord(struct ksiazka14 *);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do æwiczenia 8
#define MIEJSCAwSAMOLOCIE 12

struct Colssus1 {
	int IDnumber;
	int FreeOrNot;
	char name[20];
	char surname[20];
};

struct Colssus1 AirPlane1[MIEJSCAwSAMOLOCIE];

void FreeSpaceSizeInPlane(FILE *, int sizeOfFile);
void FreeSpaceList(FILE *, int sizeOfFile);
void ShowList(FILE *, int sizeOfFile);
void BookPlaceInPlane(FILE *, int sizeOfFile);
void CanceldBookedPlace(FILE *, int sizeOfFile);


////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do æwiczenia 9

struct Colssus2 {
	int IDnumber;
	int FreeOrNot;
	int Reserved;
	char name[20];
	char surname[20];
};

struct Colssus2 AirPlane2[MIEJSCAwSAMOLOCIE];

int MainManu(char FlightNumber[6]);
void FreeSpaceSizeInPlaneExersie9(FILE *, int sizeOfFile, char FlightNumber[6]);
void FreeSpaceListExersie9(FILE *, int sizeOfFile, char FlightNumber[6]);
void ShowListExersie9(FILE *, int sizeOfFile, char FlightNumber[6]);
void BookPlaceInPlaneExersie9(FILE *, int sizeOfFile, char FlightNumber[6], char FlightFileName[20]);
void CanceldBookedPlaceExersie9(FILE *, int sizeOfFile, char FlightNumber[6], char FlightFileName[20]);
void BookedAgrementExersie9(FILE *, int sizeOfFile, char FlightNumber[6], char FlightFileName[20]);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do æwiczenia 10

int WypiszLitery(void);
int WypiszCyfry(void);
int WyjdzZProgramu(void);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

//do æwiczenia 11

int przeksztalc(double *, double *, int, double (*)(double));
double potega (double);
double sumowanie (double);

////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial14_cwiczenia.uir", PANEL)) < 0)
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
//////////////////////////Æwiczenie 1 rodzial 14//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char miesiac[20];
	int liczbaDni;
	
	switch (event)
	{
		case EVENT_COMMIT:

				puts("Podaj nazwe miesiaca:");
				scanf("%s", miesiac);
			
				liczbaDni = obliczDniDoTegoMiesiaca(miesiac);
				if(liczbaDni < 0) puts("Blednie podana nazwa miesiaca");
				else printf("Do konca %s jest %d dni.\n", miesiac, liczbaDni);

			break;
	}
	return 0;
}

//do æwiczenia 1
int obliczDniDoTegoMiesiaca(char *WybranyMiesiac)
{
	int iloscDni = 0, CzyToTen = 0, i, n;
	
	for(i = 0; i < 12; i++)
	{
		CzyToTen = strcmp(miesiace[i].nazwa, WybranyMiesiac);
		if(!CzyToTen) break;
	}
	
	if(CzyToTen) iloscDni = -1;
	else for(n = 0; n <= i; n++) iloscDni += miesiace[n].dni;
		
	return iloscDni;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 2 rodzial 14//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int dzien, rok, dobryMiesiac, sumaDni;
	char WpisanyMiesiac[15];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			puts("Prosze podac dzien miesiaca");
			scanf("%d", &dzien);
			while(getchar() != '\n')
				continue;
			puts("Prosze podac miesiac");
			scanf("%s", WpisanyMiesiac);
			dobryMiesiac = SprawdzMiesiac(WpisanyMiesiac);
			if(dobryMiesiac < 0) 
			{
				puts("Blednie wpisany miesiac");
				return 0;
			}
			puts("Prosze podac rok");
			scanf("%d", &rok);
			while(getchar() != '\n')
				continue;
			
			sumaDni = obliczIleDni(dzien, dobryMiesiac, rok);
			
			printf("Od poczatku roku %d, minelo %d dni\n", rok, sumaDni);

			break;
	}
	return 0;
}
//do æwiczenia 2
int SprawdzMiesiac(char *miesiac)
{
	int JakiMiesiacZostalWybrany;
	int pierwszyZnak;
	int sprawdzMiesiace = 0;
	
	if(miesiac[0] != '\0')
	{
		pierwszyZnak = isdigit(miesiac[0]);
		if(pierwszyZnak) 
		{
			JakiMiesiacZostalWybrany =  atoi(miesiac);
			return JakiMiesiacZostalWybrany;
		}
		else
		{
			for(int i = 0; i < 12; i++)
			{
				sprawdzMiesiace = strcmp(miesiace[i].nazwa, miesiac);
				if(!sprawdzMiesiace) return i+1;					
			}
			if(sprawdzMiesiace)
			{
				for(int h = 0; h < 12; h++)
				{
					sprawdzMiesiace = strcmp(miesiace[h].skrot, miesiac);
					if(!sprawdzMiesiace) return h+1;					
				}
			}
		}
	}
	return -1;
}
int obliczIleDni(int dni, int miesi, int rok)
{
	int suma = 0; 
	int SprCzyPrzestepny = 0;
	
	if((SprCzyPrzestepny = rok % 4) == 0) 
	{
		if(miesi > 2) suma = suma + 1;
	}
	
	for(int i = 0; i < miesi-1; i++) suma += miesiace[i].dni;
	
	if(suma > 1) suma += dni;
	
	return suma;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 3 rodzial 14//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct ksiazka bibl[MAXKS]; //tablica struktur typu ksiazka
			int licznik = 0;
			
			printf("Podaj tytul ksiazki.\n");
			printf("Aby zakonczyc, nacisnij [enter] na poczatku wiersza.\n");
			while (licznik < MAXKS && wczytaj(bibl[licznik].tytul, MAXTYT) != NULL && bibl[licznik].tytul[0] != '\0')
			{
				printf("Teraz podaj autora.\n");
				wczytaj(bibl[licznik].autor, MAXTYT);
				printf("Teraz podaj wartosc.\n");
				scanf("%f", &bibl[licznik++].wartosc);
				while (getchar() != '\n')
					continue; //czysci wiersz wejsciowy
				if(licznik < MAXKS)
					printf("Podaj kolejny tytul.\n");
			}
			if(licznik > 0)
			{
				printf("Oto lista Twoich ksiazek:\n");
				SegregujKsiazki(licznik, bibl);
				printf("Wartosc ksiazek wynosi : %.2f zl", WartoscBilioteki(licznik, bibl));
			}
			else
				printf("Zadnych ksiazek? Szkoda\n");

			break;
	}
	return 0;
}
//definicja funkcji do æwiczenia 3
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
int SegregujKsiazki(int licznik,const struct ksiazka lista[])
{
	struct ksiazka segreguj[MAXKS] = { 'wpis', 'wpsi', 1} ;
	struct ksiazka tymczasowa[MAXKS] = { 'wpis', 'wpsi', 1} ;
	
	for(int przepisz = 0; przepisz < licznik; przepisz++)	
	{
		segreguj[przepisz] = lista[przepisz];
		tymczasowa[przepisz] = lista[przepisz];
	}
	
	for(int i = 0; i < licznik; i++)//sortowanie babelkowe
	{		
		for(int n = 0; n < licznik; n++)
		{
			if(segreguj[n+1].tytul[0] == '\0') 
			{
					segreguj[i] = segreguj[i];
			}
			else if(segreguj[n].tytul[0] > segreguj[n+1].tytul[0])
			{
					tymczasowa[0] = segreguj[n];
					segreguj[n] = segreguj[n+1];
					segreguj[n+1] = tymczasowa[0];
			}
			else if(segreguj[n].tytul[0] == segreguj[n+1].tytul[0])
			{
				for(int x = 0; x < strlen(segreguj[n].tytul); x++)
				{
					if(segreguj[n].tytul[x] > segreguj[n+1].tytul[x])
					{
						tymczasowa[0] = segreguj[n];
						segreguj[n] = segreguj[n+1];
						segreguj[n+1] = tymczasowa[0];
						break;
					}
				}
			}
		}
	}

	for(int x = 0; x < licznik; x++)
		printf("%s, autor: %s, cena: %.2f zl\n", segreguj[x].tytul, segreguj[x].autor, segreguj[x].wartosc);
	
	return 0;
}
double WartoscBilioteki(int licznik,const struct ksiazka lista[])
{
	double suma = 0.0;
	
	for(int i = 0; i < licznik; i++)
		suma += lista[i].wartosc;
	
	return suma;	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 4 rodzial 14//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	struct danePelne *wskaznik;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct danePelne zbiorOsob[3] = {
				{	989898121212,
					{"Michal", "Artur", "Strukturalny"},
			},
				{	999999232323,
					{"Bartek", " ", "Pojedynczy"},
			},
				{	777777656565,
					{"Stary", "Parchaty", "Dziad"},
			}};
				
			wskaznik = &zbiorOsob[0];
			
			WyswietlDaneWStrukturze(wskaznik);
			
			printf("\n\n");
			
			WyswietlDaneWStrukturzeStruktura(zbiorOsob);
			
			break;
	}
	return 0;
}
void WyswietlDaneWStrukturze(struct danePelne *wsk)
{
	for(int i = 0; i < 3; i++)	
	{
		if(isspace(wsk[i].Osoba.drugieImie[0]))
			printf("%s, %s     -- %d\n", wsk[i].Osoba.nazwisko, wsk[i].Osoba.imie, wsk[i].pesel);
		else
			printf("%s, %s %c. -- %d\n", wsk[i].Osoba.nazwisko, wsk[i].Osoba.imie, wsk[i].Osoba.drugieImie[0], wsk[i].pesel);
	}
}
void WyswietlDaneWStrukturzeStruktura(struct danePelne strukturaPrzekzana[])
{
	for(int i = 0; i < 3; i++)	
	{
		if(isspace(strukturaPrzekzana[i].Osoba.drugieImie[0]))
			printf("%s, %s     -- %d\n", strukturaPrzekzana[i].Osoba.nazwisko, strukturaPrzekzana[i].Osoba.imie, strukturaPrzekzana[i].pesel);
		else
			printf("%s, %s %c. -- %d\n", strukturaPrzekzana[i].Osoba.nazwisko, strukturaPrzekzana[i].Osoba.imie, strukturaPrzekzana[i].Osoba.drugieImie[0], strukturaPrzekzana[i].pesel);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 5 rodzial 14//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int i = 0, z = 0;
			int znak = 0;
			int nastepny;

			struct student zespol[ROZMIAR] =
			{
				{   {"Benek", "Nierob"},
					
				},
				{   {"Ludwik", "Obibok"},
					
				},
				{   {"Grzmot", "Kedzierzawy"},
					
				},
				{   {"Maly", "Borubar"},
					
				}
			};
			
						
			do
			{
				z = 0;
				nastepny = 0;
				
				printf("Podaj oceny studenta %s %s\n", zespol[i].daneStudenta.imie, zespol[i].daneStudenta.nazwisko);
				printf("Podawaj kolejne w jednej linii\n");
				
				do
				{
					znak = scanf("%lf", &zespol[i].oceny[z]);	
					z++;
					
				}
				while((nastepny = getchar()) != '\n');

				i++;		
			}
			while(i != 4);
			  
			for(int n = 0; n < i; n++)
			{
				double SumaOdczytanychOcen = 0.0;
				int x = 0;
				
				do
				{
					SumaOdczytanychOcen += zespol[n].oceny[x];
					x++;
				}
				while (zespol[n].oceny[x] != '\0');
				
				zespol[n].srednia = SumaOdczytanychOcen/x;
			}
			
			for(i = 0; i < ROZMIAR; i++)
			{
				printf("Uczen %s %s z ocen ", zespol[i].daneStudenta.imie, zespol[i].daneStudenta.nazwisko);
				
				int x = 0;
				do
				{
					printf("%.2f ", zespol[i].oceny[x]);
					x++;
				}
				while (zespol[i].oceny[x] != '\0');
			
				printf("otrzymal srednia %.2f\n", zespol[i].srednia);
			}
			
			printf("Srednia ocen wszystkich studentow w grupie ");
			
			double SredniaOcen = 0.0;
			for(i = 0; i < ROZMIAR; i++)
				SredniaOcen += zespol[i].srednia;
			
			printf("%.2f", SredniaOcen/ROZMIAR);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 6 rodzial 14//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct gracz koszyk[19];
			FILE *plikZawodnicy;
			char tekstPobrany[100], sprawdzenie[100];
			char buffer[20];
			int i = 0, n = 0, dlugoscBuffora, nastepny = 0, status;
			struct gracz *wskaznikKoszyk;
			
			wskaznikKoszyk = &koszyk[0];
			
			if((plikZawodnicy = fopen("zawodnicy.txt", "r")) == NULL)
			{
				fprintf(stdin, "Nie mode otworzyc pliku zawodnicy.txt.\n");
				exit(EXIT_FAILURE);
			}
			
			fseek(plikZawodnicy, 0L, SEEK_SET);
			
			fgets(tekstPobrany, 99, plikZawodnicy);
			
			for(int z = 0; z < 19; z++)
			{
				koszyk[z].numerGracza = 0;
				koszyk[z].imie[0] = 'Y';
				koszyk[z].nazwisko[0] = 'Y';
				koszyk[z].liczbaRzutowOddanychZaDwaPunkty = 0;
				koszyk[z].liczbaTrafienZaDwaPunkty = 0;
				koszyk[z].liczbaAsyst = 0;
				koszyk[z].LiczbaFauli =0;
				koszyk[z].skutecznosc = 0.0;
			}
			
			do
			{
				for(int z = 0; z < 100; z++) sprawdzenie[z] = 0;
				for(int z = 0; z <strlen(tekstPobrany); z++) sprawdzenie[z] = tekstPobrany[z];
				dlugoscBuffora = strlen(tekstPobrany);
				tekstPobrany[dlugoscBuffora+1] = ' ';
				tekstPobrany[dlugoscBuffora+2] = '\n';
				
				while(tekstPobrany[i] != '\n')
				{
					buffer[n] = tekstPobrany[i];
					n++;	
					i++;
				
					if(koszyk[nastepny].numerGracza == 0)
					{
						if(isspace(tekstPobrany[i]))
						{
							if(isdigit(buffer[0]))
							{
								
								status = SprCzySiePowtarza(wskaznikKoszyk, buffer, tekstPobrany);
								if(status == 1)
								{
									nastepny--;
									break;
								}
								koszyk[nastepny].numerGracza = atoi(buffer);
								for(int o = 0; o < 20; o++) buffer[o] = 0;
							}
							n = 0;
							i++;
						}
					}
					else if(koszyk[nastepny].imie[0] == 'Y')
					{
						if(isspace(tekstPobrany[i]))
						{
							if(isalpha(buffer[0]))
							{
								strcpy(koszyk[nastepny].imie, buffer);	
								for(int o = 0; o < 20; o++) buffer[o] = 0;
							}
							n = 0;
							i++;
						}
					}
					else if(koszyk[nastepny].nazwisko[0] == 'Y')
					{
						if(isspace(tekstPobrany[i]))
						{
							if(isalpha(buffer[0])) 
							{
								strcpy(koszyk[nastepny].nazwisko, buffer);
								for(int o = 0; o < 20; o++) buffer[o] = 0;
							}
							n = 0;
							i++;
						}
					}
					else if(koszyk[nastepny].liczbaRzutowOddanychZaDwaPunkty == 0)
					{
						if(isspace(tekstPobrany[i]))
						{
							if(isdigit(buffer[0]))
							{
								koszyk[nastepny].liczbaRzutowOddanychZaDwaPunkty = atoi(buffer);
								for(int o = 0; o < 20; o++) buffer[o] = 0;
							}
							n = 0;
							i++;
						}
					}
					else if(koszyk[nastepny].liczbaTrafienZaDwaPunkty == 0)
					{
						if(isspace(tekstPobrany[i]))
						{
							if(isdigit(buffer[0]))
							{
								koszyk[nastepny].liczbaTrafienZaDwaPunkty = atoi(buffer);
								for(int o = 0; o < 20; o++) buffer[o] = 0;
							}
							n = 0;
							i++;
						}
					}
					else if(koszyk[nastepny].liczbaAsyst == 0)
					{
						if(isspace(tekstPobrany[i]))
						{
							if(isdigit(buffer[0]))
							{
								koszyk[nastepny].liczbaAsyst = atoi(buffer);
								for(int o = 0; o < 20; o++) buffer[o] = 0;
							}
							n = 0;
							i++;
						}
					}
					else if(koszyk[nastepny].LiczbaFauli == 0)
					{
						if(isspace(tekstPobrany[i]))
						{
							if(isdigit(buffer[0]))
							{
								koszyk[nastepny].LiczbaFauli = atoi(buffer);
								for(int o = 0; o < 20; o++) buffer[o] = 0;
							}
							n = 0;
							i++;
						}
					}
				}
				fgets(tekstPobrany, 99, plikZawodnicy);
				i = 0;
				nastepny++;
				n = 0;
				status = strcmp(tekstPobrany, sprawdzenie);
			}while(status != 0);
			
			for(int t = 0; t < nastepny; t++) koszyk[t].skutecznosc = (double)koszyk[t].liczbaTrafienZaDwaPunkty/(double)koszyk[t].liczbaRzutowOddanychZaDwaPunkty;
			
			for(int y = 0; y < nastepny; y++)
			{
				printf("Zawodnik %s %s z numerem %d oddal %d rzutow, trafil %d razy, jego skutecznosc wynosi %.2lf, mial %d asyst i %d fauli\n", koszyk[y].imie, koszyk[y].nazwisko, koszyk[y].numerGracza, koszyk[y].liczbaRzutowOddanychZaDwaPunkty, koszyk[y].liczbaTrafienZaDwaPunkty, koszyk[y].skutecznosc, koszyk[y].liczbaAsyst, koszyk[y].LiczbaFauli);
			}
			
			
			int rzutyZespolu = 0, trafienieZespolu = 0, liczbaAsystZespolu = 0, liczbaFauliZespolu = 0;
			double skutecznoscZespolu = 0.0;
							   
			printf("Sklad zespolu:\n");
			for(int g = 0; g < nastepny; g++)
			{
				printf("\t- %s %s z numerem %d\n", koszyk[g].imie, koszyk[g].nazwisko, koszyk[g].numerGracza);
				rzutyZespolu += koszyk[g].liczbaRzutowOddanychZaDwaPunkty;
				trafienieZespolu += koszyk[g].liczbaTrafienZaDwaPunkty;
				liczbaAsystZespolu += koszyk[g].liczbaAsyst;
				liczbaFauliZespolu += koszyk[g].LiczbaFauli;
			}
			skutecznoscZespolu = (double)trafienieZespolu/(double)rzutyZespolu;
			
			printf("Zespol mial lacznie %d rzutow, %d trafien, skutecznosc na poziomie %.2lf, liczba asyst %d, liczba fauli %d", rzutyZespolu, trafienieZespolu, skutecznoscZespolu, liczbaAsystZespolu, liczbaFauliZespolu);
			
			break;
	}
	return 0;
}
SprCzySiePowtarza(struct gracz *wsk, char numer[], char infoDoPrzetworzenia[])
{
	int numerGracza, znalezionyGracz = 0, status = 0, i = 0, n = 0, next = 0;
	char buff[20];
	char ImieZnalezionego[20], NazwiskoZnalezionego[20];
	int liczbaRzutowOddanychDotychczas = 0, liczbaTrafienDotychczas = 0, liczbaAsystDotychczas = 0, liczbaFauliDotychczas = 0;
	
	ImieZnalezionego[0] = 'Y';
	NazwiskoZnalezionego[0] = 'Y';
	
	numerGracza = atoi(numer);
	
	for(i = 0; i < 19; i++)
	{
		if(wsk[i].numerGracza == numerGracza)
		{
			znalezionyGracz = numerGracza;
			status = 1;
			break;
		}
		else 
			status = 0;
	}
	
	if(status == 0) return 0;
	
	if(status == 1)
	{
		while(infoDoPrzetworzenia[next] != '\n')
		{
			buff[n] = infoDoPrzetworzenia[next];
			n++;	
			next++;
			
			if(wsk[i].numerGracza == znalezionyGracz)
			{
				if(isspace(infoDoPrzetworzenia[next]))
				{
					if(isdigit(buff[0]))
					{
						strcpy(ImieZnalezionego, wsk[i].imie);
						for(int o = 0; o < 20; o++) buff[o] = 0;
						znalezionyGracz = 0;
					}
					n = 0;
					next++;
				}
			}
			else if(wsk[i].imie[0] == ImieZnalezionego[0])
			{
				if(isspace(infoDoPrzetworzenia[next]))
				{
					if(isalpha(buff[0]))
					{
						strcpy(NazwiskoZnalezionego, wsk[i].nazwisko);
						for(int o = 0; o < 20; o++) buff[o] = 0;
						ImieZnalezionego[0] = 'Y';
					}
					n = 0;
					next++;
				}
			}
			else if(wsk[i].nazwisko[0] == NazwiskoZnalezionego[0])
			{
				if(isspace(infoDoPrzetworzenia[next]))
				{
					if(isalpha(buff[0])) 
					{
						liczbaRzutowOddanychDotychczas = wsk[i].liczbaRzutowOddanychZaDwaPunkty;
						for(int o = 0; o < 20; o++) buff[o] = 0;
						NazwiskoZnalezionego[0] = 'Y';
					}
					n = 0;
					next++;
				}
			}
			else if(wsk[i].liczbaRzutowOddanychZaDwaPunkty == liczbaRzutowOddanychDotychczas)
			{
				if(isspace(infoDoPrzetworzenia[next]))
				{
					if(isdigit(buff[0]))
					{
						int tymczasowy = 0;
						tymczasowy = atoi(buff);
						wsk[i].liczbaRzutowOddanychZaDwaPunkty += tymczasowy;
						liczbaTrafienDotychczas = wsk[i].liczbaTrafienZaDwaPunkty;
						for(int o = 0; o < 20; o++) buff[o] = 0;
						liczbaRzutowOddanychDotychczas = 0;
					}
					n = 0;
					next++;
				}
			}
			else if(wsk[i].liczbaTrafienZaDwaPunkty == liczbaTrafienDotychczas)
			{
				if(isspace(infoDoPrzetworzenia[next]))
				{
					if(isdigit(buff[0]))
					{
						int tymczasowy = 0;
						tymczasowy = atoi(buff);
						wsk[i].liczbaTrafienZaDwaPunkty += tymczasowy;
						liczbaAsystDotychczas = wsk[i].liczbaAsyst;
						for(int o = 0; o < 20; o++) buff[o] = 0;
						liczbaTrafienDotychczas = 0;
					}
					n = 0;
					next++;
				}
			}
			else if(wsk[i].liczbaAsyst == liczbaAsystDotychczas)
			{
				if(isspace(infoDoPrzetworzenia[next]))
				{
					if(isdigit(buff[0]))
					{
						int tymczasowy = 0;
						tymczasowy = atoi(buff);
						wsk[i].liczbaAsyst += tymczasowy;
						liczbaFauliDotychczas = wsk[i].LiczbaFauli;
						for(int o = 0; o < 20; o++) buff[o] = 0;
						liczbaAsystDotychczas = 0;
					}
					n = 0;
					next++;
				}
			}
			else if(wsk[i].LiczbaFauli == liczbaFauliDotychczas)
			{
				if(isspace(infoDoPrzetworzenia[next]))
				{
					if(isdigit(buff[0]))
					{
						int tymczasowy = 0;
						tymczasowy = atoi(buff);
						wsk[i].LiczbaFauli += tymczasowy;
						for(int o = 0; o < 20; o++) buff[o] = 0;
						liczbaFauliDotychczas = 0;
					}
					n = 0;
					next++;
				}
			}
		}
		return 1;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 7 rodzial 14//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			struct ksiazka14 bibl[MAXKS14]; //tablica struktur
			int licznik = 0;
			int index, licznikp, ch;
			FILE *pksiazki;
			int rozmiar = sizeof(struct ksiazka14);
			
			if((pksiazki = fopen("ksiazki.dat", "r+b")) == NULL)
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
				
				printf("Wybierz co wykonac z:\n"
			   "[n] nastepny record [u] usun wczytany record "
			   "[m] zmodyfikuj wczytany record.\n");
				ch = getchar();
				while (getchar() != '\n') continue;
					switch (ch)
						{
							case ('n'):
							case ('N'):
									break;
							case ('m'):
							case('M'):
								edytujWczytanyRekord(&bibl[licznik]);
								break;
							case('u'):
							case('U'):
								licznik--;
							break;
						}			
				licznik++;
			}
			
			licznikp = licznik;
			
			if(licznik == MAXKS14)
			{
				fputs("Plik ksiazki.dat jest pelny.", stderr);
				exit(2);
			}
			
			puts("Podaj nowe tytuly ksiazek.");
			puts("Aby zakonczyc, nacisnij [enter] na poczatku wiersza.");
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
			fclose(pksiazki);
			puts("Koniec\n");

			break;
	}
	return 0;
}
void edytujWczytanyRekord(struct ksiazka14 *nowaKsiazka)
{
	puts("Wprowadz nowy tytul:");
	wczytaj(nowaKsiazka->tytul, MAXTYT14);
	puts("Wprowadz nowego autora:");
	wczytaj(nowaKsiazka->autor, MAXAUT14);
	puts("Wprowadz nowa wartosc:");
	scanf("%f", &nowaKsiazka->wartosc);

	while (getchar() != '\n') continue;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 8 rodzial 14//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char wybor = '\0';
	int exit = 0, znak, i;
	FILE *AirplaneFile;
	int rozmiar = sizeof(struct Colssus1);
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			if((AirplaneFile = fopen("samolot.txt", "r+b")) == NULL)
			{
				fputs("Nie moge otworzyc pliku samolot.txt\n", stderr);
				fputs("Wypelniam plik wartosciami pustymi\n", stdout);
				
				AirplaneFile = fopen("samolot.txt", "w+b");
				
				for(i = 0; i < MIEJSCAwSAMOLOCIE; i++)
				{
					AirPlane1[i].IDnumber = i;
					AirPlane1[i].FreeOrNot = 0;
					AirPlane1[i].name[0] = '\0';
					AirPlane1[i].surname[0] = '\0';
				}
				 
				fwrite(&AirPlane1, rozmiar, MIEJSCAwSAMOLOCIE, AirplaneFile);
						
				fputs("Zapisano wartosci domyslne w pliku samolot.txt\n", stdout);
			}			
			
			do
			{
				printf("Aby wybrac opcje, wpisz jej oznaczenie literowe:\n");
				printf("a) Pokaz liczbe pustych miejsc\n");
				printf("b) Pokaz liste pustych miejsc\n");
				printf("c) Pokaz alfabetycznie liste miejsc\n");
				printf("d) Zarezerwuj miejsce dla klienta\n");
				printf("e) Usun rezerwacje miejsca\n");
				printf("f) koniec\n");
				
				wybor = getchar();
				
				while((znak = getchar()) != '\n')
					continue;
				
				switch (wybor)
				{
					case 'A':
					case 'a':
						FreeSpaceSizeInPlane(AirplaneFile, rozmiar);
						exit = 0;
						wybor = '\0';
						break;
					case 'B':
					case 'b':
						FreeSpaceList(AirplaneFile, rozmiar);
						exit = 0;
						wybor = '\0';
						break;
					case 'C':
					case 'c':	
						ShowList(AirplaneFile, rozmiar);
						exit = 0;
						wybor = '\0';
						break;
					case 'D':
					case 'd':
						BookPlaceInPlane(AirplaneFile, rozmiar);
						exit = 0;
						wybor = '\0';
						while((znak = getchar()) != '\n') continue;
						break;
					case 'E':
					case 'e':
						CanceldBookedPlace(AirplaneFile, rozmiar);
						exit = 0;
						wybor = '\0';
						while((znak = getchar()) != '\n') continue;
						break;
					case 'F':
					case 'f':
						exit = 1;
						wybor = '\0';
						break;
				}
				
			}while (exit == 0);
			fclose(AirplaneFile);
			printf("\nKoniec programu!\n");

			break;
	}
	return 0;
}
void FreeSpaceSizeInPlane(FILE *ActuallyOpenFile, int rozmiarPliku)
{
	struct Colssus1 Temp1[MIEJSCAwSAMOLOCIE];
	int counter = 0;
	
	rewind(ActuallyOpenFile);
	
	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)
	{
		fread(&Temp1[i], rozmiarPliku, MIEJSCAwSAMOLOCIE - i, ActuallyOpenFile);
		if(Temp1[i].FreeOrNot == 0)
			counter++;
	}
	printf("W samolocie jest %i pustych miejsc.\n\n", counter);
}
void FreeSpaceList(FILE *ActuallyOpenFile, int rozmiarPliku)
{
	struct Colssus1 Temp1[MIEJSCAwSAMOLOCIE];
	
	rewind(ActuallyOpenFile);
	
	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)
	{
		fread(&Temp1[i], rozmiarPliku, MIEJSCAwSAMOLOCIE - i, ActuallyOpenFile);
		if(Temp1[i].FreeOrNot == 0) printf("Miejsce nr %i jest puste.\n", i+1);
	}
	printf("\n\n");
}
void ShowList(FILE *ActuallyOpenFile, int rozmiarPliku)
{
	struct Colssus1 Temp1[MIEJSCAwSAMOLOCIE];
	struct Colssus1 tymczasowa[MIEJSCAwSAMOLOCIE];
	struct Colssus1 Temp2[MIEJSCAwSAMOLOCIE];
	int zapisane = 0;
	
	rewind(ActuallyOpenFile);
	
	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)
	{
		fread(&Temp1[i], rozmiarPliku, MIEJSCAwSAMOLOCIE - i, ActuallyOpenFile);
		if(islower(Temp1[i].surname[0])) Temp1[i].surname[0] = toupper(Temp1[i].surname[0]);
		
		if(Temp1[i].FreeOrNot == 1) printf("Miejsce %i, jest zajete przez %s %s.\n", Temp1[i].IDnumber+1, Temp1[i].name, Temp1[i].surname);
		else printf("Miejsce %i jest wolne.\n", Temp1[i].IDnumber+1);		
	}
	
	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)
	{
		if(Temp1[i].surname[0] != '\0') 
		{
			Temp2[zapisane] = Temp1[i];
			zapisane++;
		}
	}	
	
	Temp2[zapisane].IDnumber = zapisane;
	Temp2[zapisane].FreeOrNot = 0;
	Temp2[zapisane].name[0] = '\0';
	Temp2[zapisane].surname[0] = '\0';

	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)//sortowanie babelkowe
	{		
		for(int n = 0; n < zapisane-1; n++)
		{
			if(Temp2[n+1].surname[0] == '\0') 
			{
				Temp2[i] = Temp2[i];
			}
			else if(Temp2[n].surname[0] > Temp2[n+1].surname[0])
			{
				tymczasowa[0] = Temp2[n];
				Temp2[n] = Temp2[n+1];
				Temp2[n+1] = tymczasowa[0];
			}
			else if(Temp2[n].surname[0] == Temp2[n+1].surname[0])
			{
				for(int x = 1; x < strlen(Temp2[n].surname); x++)
				{
					if(Temp2[n].surname[x] > Temp2[n+1].surname[x])
					{
						tymczasowa[0] = Temp2[n];
						Temp2[n] = Temp2[n+1];
						Temp2[n+1] = tymczasowa[0];
						break;
					}
					else if(Temp2[n].surname[x] < Temp2[n+1].surname[x])
						break;
				}
			}
		}
	}
	
	printf("\n\n");
	
	for(int i = 0; i < zapisane; i++)
	{
		if(Temp2[i].surname[0] != '\0') printf("%s %s zarezerwowal miejsce %i w samolocie.\n", Temp2[i].surname, Temp2[i].name, Temp2[i].IDnumber+1);	
	}
	
	printf("\n\n");
}
void BookPlaceInPlane(FILE *ActuallyOpenFile, int rozmiarPliku)
{
	struct Colssus1 Temp1[MIEJSCAwSAMOLOCIE];
	int rubbish, znak;
	char accept[10];
	
	rewind(ActuallyOpenFile);
	
	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)
		fread(&Temp1[i], rozmiarPliku, MIEJSCAwSAMOLOCIE - i, ActuallyOpenFile);
	
	fclose(ActuallyOpenFile);
	
	ActuallyOpenFile = fopen("samolot.txt", "w+b");
	
	printf("Podaj miejsce rezerwacji: ");
	scanf("%i", &znak);
	
	znak = znak - 1;
	
	while((rubbish = getchar()) != '\n')
			continue;
	
	if(znak < 12 && znak > -1)
	{
		if(Temp1[znak].FreeOrNot == 1) printf("To miejsce jest zajête.");
		else
		{
			printf("\nPodaj imie podroznego: ");
			scanf("%s", Temp1[znak].name);
			printf("\nPodaj nazwisko podroznego: ");
			scanf("%s", Temp1[znak].surname);
			
			printf("\nCzy zatwierdzic wprowadzone dane? Wpisz 'Tak' lub 'Nie'.");
			scanf("%s", accept);
			if(accept[0] == 't' || accept[0] == 'T')
			{
				Temp1[znak].FreeOrNot = 1;
			
				fwrite(&Temp1, rozmiarPliku, MIEJSCAwSAMOLOCIE, ActuallyOpenFile);
			}
		}
	}
	else printf("\nBrak takiego miejsca w samolocie.\n");
	
	fclose(ActuallyOpenFile);
	
	ActuallyOpenFile = fopen("samolot.txt", "r+b");
}
void CanceldBookedPlace(FILE *ActuallyOpenFile, int rozmiarPliku)
{
	struct Colssus1 Temp1[MIEJSCAwSAMOLOCIE];
	int rubbish, znak;
	char accept[10];
	
	rewind(ActuallyOpenFile);
	
	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)
		fread(&Temp1[i], rozmiarPliku, MIEJSCAwSAMOLOCIE - i, ActuallyOpenFile);
	
	fclose(ActuallyOpenFile);
	
	ActuallyOpenFile = fopen("samolot.txt", "w+b");
	
	printf("Podaj miejsce rezerwacji do usuniecia: ");
	scanf("%i", &znak);
	
	znak = znak - 1;
	
	while((rubbish = getchar()) != '\n')
			continue;
	
	if(znak < 12 && znak > -1)
	{
		printf("\nCzy na pewno usunac to rezerwacje? Wpisz 'Tak' lub 'Nie'.");
		scanf("%s", accept);
		if(accept[0] == 't' || accept[0] == 'T')
			{
				Temp1[znak].FreeOrNot = 0;
				Temp1[znak].IDnumber = znak;
				Temp1[znak].name[0] = '\0';
				Temp1[znak].surname[0] = '\0';
			
				fwrite(&Temp1, rozmiarPliku, MIEJSCAwSAMOLOCIE, ActuallyOpenFile);
			}
	}
	else printf("\nBrak takiego miejsca w samolocie.\n");
	
	fclose(ActuallyOpenFile);
	
	ActuallyOpenFile = fopen("samolot.txt", "r+b");	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 9 rodzial 14//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char wybor = '\0';
	int exit = 0, znak;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			do
			{
				puts("Wybierz rejs z ponizszych:");
				puts("a) Rejs 102");
				puts("b) Rejs 311");
				puts("c) Rejs 444");
				puts("d) Rejs 519");
				puts("e) Wyjscie z programu.");
				
				wybor = getchar();
				
				while((znak = getchar()) != '\n')
					continue;
				
				switch (wybor)
				{
					case 'A':
					case 'a':
						MainManu("102");
						exit = 0;
						wybor = '\0';
						break;
					case 'B':
					case 'b':
						MainManu("311");
						exit = 0;
						wybor = '\0';
						break;
					case 'C':
					case 'c':	
						MainManu("444");
						exit = 0;
						wybor = '\0';
						break;
					case 'D':
					case 'd':
						MainManu("519");
						exit = 0;
						wybor = '\0';
						while((znak = getchar()) != '\n') continue;
						break;
					case 'E':
					case 'e':
						exit = 1;
						wybor = '\0';
						break;
				}
				
			}while (exit == 0);

			printf("\nKoniec programu!\n");

			break;
	}
	return 0;
}
int MainManu(char FlightNumber[6])
{
	char wybor = '\0';
	int exit = 0, znak, i;
	FILE *AirplaneFile;
	int rozmiar = sizeof(struct Colssus2);
	char FileName[20] = "samolot";

	strcat(FileName, FlightNumber);
	strcat(FileName, ".txt");

	if((AirplaneFile = fopen(FileName, "r+b")) == NULL)
	{
		printf("Nie moge otworzyc pliku %s\n", FileName);
		fputs("Wypelniam plik wartosciami pustymi\n", stdout);

		AirplaneFile = fopen(FileName, "w+b");

		for(i = 0; i < MIEJSCAwSAMOLOCIE; i++)
		{
			AirPlane2[i].IDnumber = i;
			AirPlane2[i].FreeOrNot = 0;
			AirPlane2[i].Reserved = 0;
			AirPlane2[i].name[0] = '\0';
			AirPlane2[i].surname[0] = '\0';
		}

		fwrite(&AirPlane2, rozmiar, MIEJSCAwSAMOLOCIE, AirplaneFile);

		printf("Zapisano wartosci domyslne w pliku %s\n", FileName);
	}

	do
	{
		printf("Aby wybrac opcje, wpisz jej oznaczenie literowe: (Wybrany lot -> %s)\n", FlightNumber);
		printf("a) Pokaz liczbe pustych miejsc\n");
		printf("b) Pokaz liste pustych miejsc\n");
		printf("c) Pokaz alfabetycznie liste miejsc\n");
		printf("d) Zarezerwuj miejsce dla klienta\n");
		printf("e) Usun rezerwacje miejsca\n");
		printf("f) Potwierdzenie rezerwacji\n");
		printf("g) Powrot do glownego menu\n");

		wybor = getchar();

		while((znak = getchar()) != '\n')
			continue;

		switch (wybor)
		{
			case 'A':
			case 'a':
				FreeSpaceSizeInPlaneExersie9(AirplaneFile, rozmiar, FlightNumber);
				exit = 0;
				wybor = '\0';
				break;
			case 'B':
			case 'b':
				FreeSpaceListExersie9(AirplaneFile, rozmiar, FlightNumber);
				exit = 0;
				wybor = '\0';
				break;
			case 'C':
			case 'c':
				ShowListExersie9(AirplaneFile, rozmiar, FlightNumber);
				exit = 0;
				wybor = '\0';
				break;
			case 'D':
			case 'd':
				BookPlaceInPlaneExersie9(AirplaneFile, rozmiar, FlightNumber, FileName);
				exit = 0;
				wybor = '\0';
				while((znak = getchar()) != '\n') continue;
				break;
			case 'E':
			case 'e':
				CanceldBookedPlaceExersie9(AirplaneFile, rozmiar, FlightNumber, FileName);
				exit = 0;
				wybor = '\0';
				while((znak = getchar()) != '\n') continue;
				break;
			case 'F':
			case 'f':
				BookedAgrementExersie9(AirplaneFile, rozmiar, FlightNumber, FileName);
				exit = 0;
				wybor = '\0';
				while((znak = getchar()) != '\n') continue;
				break;
			case 'G':
			case 'g':
				exit = 1;
				wybor = '\0';
				break;
		}
	}
	while (exit == 0);
	fclose(AirplaneFile);
	return 0;
}
void FreeSpaceSizeInPlaneExersie9(FILE *ActuallyOpenFile, int rozmiarPliku, char FlightNumber[6])
{
	struct Colssus2 Temp1[MIEJSCAwSAMOLOCIE];
	int counter = 0;
	
	rewind(ActuallyOpenFile);
	
	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)
	{
		fread(&Temp1[i], rozmiarPliku, MIEJSCAwSAMOLOCIE - i, ActuallyOpenFile);
		if(Temp1[i].FreeOrNot == 0)
			counter++;
	}
	printf("W samolocie o numerze rejsu %s jest %i pustych miejsc.\n\n",FlightNumber, counter);
}
void FreeSpaceListExersie9(FILE *ActuallyOpenFile, int rozmiarPliku, char FlightNumber[6])
{
	struct Colssus2 Temp1[MIEJSCAwSAMOLOCIE];
	
	rewind(ActuallyOpenFile);
	
	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)
	{
		fread(&Temp1[i], rozmiarPliku, MIEJSCAwSAMOLOCIE - i, ActuallyOpenFile);
		if(Temp1[i].FreeOrNot == 0) printf("Miejsce nr %i w rejsie %s jest puste.\n", i+1, FlightNumber);
	}
	printf("\n\n");
}
void ShowListExersie9(FILE *ActuallyOpenFile, int rozmiarPliku, char FlightNumber[6])
{
	struct Colssus2 Temp1[MIEJSCAwSAMOLOCIE];
	struct Colssus2 tymczasowa[MIEJSCAwSAMOLOCIE];
	struct Colssus2 Temp2[MIEJSCAwSAMOLOCIE];
	int zapisane = 0;
	
	rewind(ActuallyOpenFile);
	
	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)
	{
		fread(&Temp1[i], rozmiarPliku, MIEJSCAwSAMOLOCIE - i, ActuallyOpenFile);
		if(islower(Temp1[i].surname[0])) Temp1[i].surname[0] = toupper(Temp1[i].surname[0]);
		
		if(Temp1[i].FreeOrNot == 1) printf("Miejsce %i, w rejsie nr %s jest zajete przez %s %s.", Temp1[i].IDnumber+1, FlightNumber, Temp1[i].name, Temp1[i].surname);
		else printf("Miejsce %i w rejsie nr %s jest wolne.", Temp1[i].IDnumber+1, FlightNumber);
		
		if(Temp1[i].Reserved == 1) printf(" Rezerwacja potwierdzona.\n");
		else printf("\n");
				
	}
	
	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)
	{
		if(Temp1[i].surname[0] != '\0') 
		{
			Temp2[zapisane] = Temp1[i];
			zapisane++;
		}
	}	
	
	Temp2[zapisane].IDnumber = zapisane;
	Temp2[zapisane].FreeOrNot = 0;
	Temp2[zapisane].Reserved = 0;
	Temp2[zapisane].name[0] = '\0';
	Temp2[zapisane].surname[0] = '\0';

	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)//sortowanie babelkowe
	{		
		for(int n = 0; n < zapisane-1; n++)
		{
			if(Temp2[n+1].surname[0] == '\0') 
			{
				Temp2[i] = Temp2[i];
			}
			else if(Temp2[n].surname[0] > Temp2[n+1].surname[0])
			{
				tymczasowa[0] = Temp2[n];
				Temp2[n] = Temp2[n+1];
				Temp2[n+1] = tymczasowa[0];
			}
			else if(Temp2[n].surname[0] == Temp2[n+1].surname[0])
			{
				for(int x = 1; x < strlen(Temp2[n].surname); x++)
				{
					if(Temp2[n].surname[x] > Temp2[n+1].surname[x])
					{
						tymczasowa[0] = Temp2[n];
						Temp2[n] = Temp2[n+1];
						Temp2[n+1] = tymczasowa[0];
						break;
					}
					else if(Temp2[n].surname[x] < Temp2[n+1].surname[x])
						break;
				}
			}
		}
	}
	
	printf("\n\n");
	
	for(int i = 0; i < zapisane; i++)
	{
		if(Temp2[i].surname[0] != '\0') printf("%s %s zarezerwowal miejsce %i w rejsie %s.", Temp2[i].surname, Temp2[i].name, Temp2[i].IDnumber+1, FlightNumber);	
		
		if(Temp2[i].Reserved == 1) printf(" Rezerwacja potwierdzona.\n");
		else printf(" Oczekuje na potwierdzenie rezerwacji.\n");
	}
	
	printf("\n\n");
}
void BookPlaceInPlaneExersie9(FILE *ActuallyOpenFile, int rozmiarPliku, char FlightNumber[6], char FlightFileName[20])
{
	struct Colssus2 Temp1[MIEJSCAwSAMOLOCIE];
	int rubbish, znak;
	char accept[10];
	
	rewind(ActuallyOpenFile);
	
	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)
		fread(&Temp1[i], rozmiarPliku, MIEJSCAwSAMOLOCIE - i, ActuallyOpenFile);
	
	fclose(ActuallyOpenFile);
	
	ActuallyOpenFile = fopen(FlightFileName, "w+b");
	
	printf("Podaj miejsce rezerwacji dla rejsu %s: ", FlightNumber);
	scanf("%i", &znak);
	
	znak = znak - 1;
	
	while((rubbish = getchar()) != '\n')
			continue;
	
	if(znak < 12 && znak > -1)
	{
		if(Temp1[znak].FreeOrNot == 1) printf("To miejsce jest zajête.");
		else
		{
			printf("\nPodaj imie podroznego: ");
			scanf("%s", Temp1[znak].name);
			printf("\nPodaj nazwisko podroznego: ");
			scanf("%s", Temp1[znak].surname);
			
			printf("\nCzy zatwierdzic wprowadzone dane? Wpisz 'Tak' lub 'Nie'.");
			scanf("%s", accept);
			if(accept[0] == 't' || accept[0] == 'T')
			{
				Temp1[znak].FreeOrNot = 1;
			
				fwrite(&Temp1, rozmiarPliku, MIEJSCAwSAMOLOCIE, ActuallyOpenFile);
			}
		}
	}
	else printf("\nBrak takiego miejsca w samolocie.\n");
	
	fclose(ActuallyOpenFile);
	
	ActuallyOpenFile = fopen(FlightFileName, "r+b");
}
void CanceldBookedPlaceExersie9(FILE *ActuallyOpenFile, int rozmiarPliku, char FlightNumber[6], char FlightFileName[20])
{
	struct Colssus2 Temp1[MIEJSCAwSAMOLOCIE];
	int rubbish, znak;
	char accept[10];
	
	rewind(ActuallyOpenFile);
	
	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)
		fread(&Temp1[i], rozmiarPliku, MIEJSCAwSAMOLOCIE - i, ActuallyOpenFile);
	
	fclose(ActuallyOpenFile);
	
	ActuallyOpenFile = fopen(FlightFileName, "w+b");
	
	printf("Podaj miejsce rezerwacji do usuniecia w rejsie %s: ", FlightNumber);
	scanf("%i", &znak);
	
	znak = znak - 1;
	
	while((rubbish = getchar()) != '\n')
			continue;
	
	if(znak < 12 && znak > -1)
	{
		printf("\nCzy na pewno usunac to rezerwacje? Wpisz 'Tak' lub 'Nie'.");
		scanf("%s", accept);
		if(accept[0] == 't' || accept[0] == 'T')
			{
				Temp1[znak].FreeOrNot = 0;
				Temp1[znak].IDnumber = znak;
				Temp1[znak].Reserved = 0;
				Temp1[znak].name[0] = '\0';
				Temp1[znak].surname[0] = '\0';
			
				fwrite(&Temp1, rozmiarPliku, MIEJSCAwSAMOLOCIE, ActuallyOpenFile);
			}
	}
	else printf("\nBrak takiego miejsca w rejsie %s.\n", FlightNumber);
	
	fclose(ActuallyOpenFile);
	
	ActuallyOpenFile = fopen(FlightFileName, "r+b");	
}
void BookedAgrementExersie9(FILE *ActuallyOpenFile, int rozmiarPliku, char FlightNumber[6], char FlightFileName[20])
{
	struct Colssus2 Temp1[MIEJSCAwSAMOLOCIE];
	int rubbish, znak;
	char accept[10];
	
	rewind(ActuallyOpenFile);
	
	for(int i = 0; i < MIEJSCAwSAMOLOCIE; i++)
		fread(&Temp1[i], rozmiarPliku, MIEJSCAwSAMOLOCIE - i, ActuallyOpenFile);
	
	fclose(ActuallyOpenFile);
	
	ActuallyOpenFile = fopen(FlightFileName, "w+b");
	
	printf("Podaj miejsce rezerwacji, ktore chcesz potwierdzic w rejsie %s: ", FlightNumber);
	scanf("%i", &znak);
	
	znak = znak - 1;
	
	while((rubbish = getchar()) != '\n')
			continue;
	
	if(znak < 12 && znak > -1)
	{
		printf("\nCzy na pewno chcesz potwierdzic ta rezerwacje? Wpisz 'Tak' lub 'Nie'.");
		scanf("%s", accept);
		if(accept[0] == 't' || accept[0] == 'T')
			{
				Temp1[znak].Reserved = 1;
			
				fwrite(&Temp1, rozmiarPliku, MIEJSCAwSAMOLOCIE, ActuallyOpenFile);
			}
	}
	else printf("\nBrak takiego miejsca w rejsie %s.\n", FlightNumber);
	
	fclose(ActuallyOpenFile);
	
	ActuallyOpenFile = fopen(FlightFileName, "r+b");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 10 rodzial 14//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int (*wskaznik[4])(void);//tablica wskaŸników poszczególnych funkcji.
	int exit = 0;
	int wybor, znak;
	
	wskaznik[0] = WypiszLitery;
	wskaznik[1] = WypiszCyfry;
	wskaznik[2] = WyjdzZProgramu;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			do{
				puts("Wybierz jedna z opcji:");
				puts("a) Wypisz Litery");
				puts("b) Wypisz Cyfry");
				puts("c) Wyjscie z programu");
				
				wybor = getchar();
				while((znak = getchar()) != '\n') continue;
				
				switch (wybor)
				{
					case 'A':
					case 'a':
						exit = wskaznik[0]();
						break;
					case 'B':
					case 'b':
						exit = wskaznik[1]();
						break;
					case 'C':
					case 'c':
						exit = wskaznik[2]();
						break;
				}
			}while (exit == 0);

			break;
	}
	return 0;
}
int WypiszLitery(void)
{
	printf("abcdefghijklmonprsuwyz\n\n");
	return 0;
}
int WypiszCyfry(void)
{
	printf("0 1 2 3 4 5 6 7 8 9\n\n");
	return 0;
}
int WyjdzZProgramu(void)
{
	printf("Wychodze z programu!");
	return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 11 rodzial 14//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int exit = 0;
	int wybor, znak;
	double source[10], target[10];
	int elementy = 0;
	
	double (*wskzanikFunkcji)(double); //deklaracja wskaŸnika do funkcji
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			for(int i = 0; i < 10; i++)
			{
				source[i] = i;
				elementy++;
			}
			
			do{
				puts("Wybierz jedna z opcji:");
				puts("a) sinus z bilb math");
				puts("b) pierwiastek kwadratowy z bibl math");
				puts("c) potega funkcja stworzona");
				puts("d) sumowanie funkcja stworzona");
				puts("e) Wyjscie");
				
				wybor = getchar();
				while((znak = getchar()) != '\n') continue;
				
				switch (wybor)
				{
					case 'A':
					case 'a':
						wskzanikFunkcji = sin;	//przypisanie wskaŸnikowi konkretnej funkcji
						przeksztalc(source, target, elementy, wskzanikFunkcji);
						exit = 0;
						break;
					case 'B':
					case 'b':
						wskzanikFunkcji = sqrt;	//przypisanie wskaŸnikowi konkretnej funkcji
						przeksztalc(source, target, elementy, wskzanikFunkcji);
						exit = 0;
						break;
					case 'C':
					case 'c':
						wskzanikFunkcji = potega;	//przypisanie wskaŸnikowi konkretnej funkcji
						przeksztalc(source, target, elementy, wskzanikFunkcji);
						exit = 0;
						break;
					case 'D':
					case 'd':
						wskzanikFunkcji = sumowanie;	//przypisanie wskaŸnikowi konkretnej funkcji
						przeksztalc(source, target, elementy, wskzanikFunkcji);
						exit = 0;
						break;
					case 'E':
					case 'e':
						exit = 1;
						break;
				}
			}while (exit == 0);

			break;
	}
	return 0;
}
int przeksztalc(double *zrodlo, double *cel, int elementy, double (*funkcja)(double))
{
	for(int i = 0; i < elementy; i++)
	{
		cel[i] = funkcja(zrodlo[i]);
		printf("zrodlo = %.2lf, cel = %.2lf\n", zrodlo[i], cel[i]);
	}
				 
	return 0;
}
double potega (double x)
{
	return (x*x);
}
double sumowanie (double x)
{
	return (x+x);
}