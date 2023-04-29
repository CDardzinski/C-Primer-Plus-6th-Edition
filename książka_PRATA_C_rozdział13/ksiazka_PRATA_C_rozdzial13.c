#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial13.h"

//do listingu 13.4
#define CNTL_Z '\032' //znczanik EOF w plikach tekstowych DOS/
#define DLNA 81
///////////////////////////////////////////////////////////////////////////

//do listingu 13.5
#define ROZMIAR_BUF 4096
#define DLAN 50

void dopisz(FILE *zrodlo, FILE *cel);
char *wczytaj(char *z, int ile);
/////////////////////////////////////////////////////////////////////////

//do listingu 13.6
#define DL_TAB 1000
////////////////////////////////////////////////////////////////////////

static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial13.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 13.4 rodzial 13///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			char plik[DLNA];
			char ch;
			FILE *wp;
			long licznik, koniec;
			
			puts("Podaj nazwe pliku:");
			scanf("%80s",plik);
			if((wp = fopen(plik, "rb")) == NULL)
			{ //tryb tylko do odczytu
				printf("Nie moge otworzyc %s\n", plik);
				exit(EXIT_FAILURE);
			}
			fseek(wp, 0L, SEEK_END); // przejdz do konca pliku
			koniec = ftell(wp);
			
			for(licznik = 1L; licznik <= koniec; licznik++)
			{
				fseek(wp, -licznik, SEEK_END); //idz do tylu
				ch = getc(wp);
				if(ch != CNTL_Z && ch != '\r')//pliki ms-dos
					putchar(ch);
			}
			putchar('\n');
			fclose(wp);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 13.5 rodzial 13///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			FILE *pd, *pz; //pz - plik dopisywany,  pd- plik docelowy
			int pliki = 0; //liczba dopisywanych plikow
			char plik_doc[DLAN]; //nazwa pliku dopisywanego
			char plik_zro[DLAN]; //nazwa pliku zrodlowego
			int ch;
			
			puts("Podaj nazwe pliku docelowego:");
			wczytaj(plik_doc, DLAN);
			if((pd = fopen(plik_doc, "a")) == NULL)
			{
				fprintf(stderr, "Blad otwarcia %s\n", plik_doc);
				exit(EXIT_FAILURE);
			}
			if(setvbuf(pd, NULL, _IOFBF, ROZMIAR_BUF) != 0)
			{
				fputs("nie mozna utworzyc bufora wyjsciowego\n", stderr);
				exit(EXIT_FAILURE);
			}
			puts("Podaj nazwe pierwszego pliku zrodlowego (pusty wiersz konczy program):");
			
			while (wczytaj(plik_zro, DLAN) && plik_zro[0] != '\0')
			{
				if(strcmp(plik_zro, plik_doc) == 0)
					fputs("Nie mozna dopisac pliku do siebie\n", stderr);
				else if((pz = fopen(plik_zro, "r")) == NULL)
					fprintf(stderr, "Blad otwarcia pliku %s\n", plik_zro);
				else
				{
					if(setvbuf(pz, NULL, _IOFBF, ROZMIAR_BUF) != 0)
					{
						fputs("Nie mozna utworzyc bufora wejsciowego\n", stderr);
						continue;
					}
					dopisz(pz, pd);
					if(ferror(pz) != 0)
						fprintf(stderr, "Blad odczytu pliku %s\n", plik_zro);
					if(ferror(pd) != 0)
						fprintf(stderr, "Blad zapisu pliku %s\n", plik_doc);
					fclose(pz);
					pliki++;
					printf("Plik %s dopisany .\n", plik_zro);
					puts("Kolejny plik (pusty wiersz konczy program):");
				}
			}
			printf("Koniec. Dopisano %d pilow.\n", pliki);
			rewind(pd);
			printf("%s zawiera:\n", plik_doc);
			while ((ch = getc(pd)) != EOF)
				putchar(ch);
			puts("Koniec.");
			fclose(pd);
			
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Przyk³ad listing 13.6 rodzial 13///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			double liczby[DL_TAB];
			double wartosc;
			const char *plik = "liczby.dat";
			int i;
			long poz;
			FILE *plikwewy;
			
			//tworzy zestaw wartosci typu double
			for(i = 0; i < DL_TAB; i++)
				liczby[i] = 100.0 * i + 1.0 / (i + 1);
			//probuje otworzyc plik
			if((plikwewy = fopen(plik, "wb")) == NULL)
			{
				fprintf(stderr, "Blad otwarcia pliku %s do zapisu.\n", plik);
				exit(EXIT_FAILURE);
			}
			//zapisuje tablice do pliku w formacie binarnym
			fwrite(liczby, sizeof(double), DL_TAB, plikwewy);
			fclose(plikwewy);
			if((plikwewy = fopen(plik, "rb")) == NULL)
			{
				fprintf(stderr, "Blad otawrcia pliku %s do dostepu swobodnego.\n", plik);
				exit(EXIT_FAILURE);
			}
			//odczytuje z pliku wybrane pozycje
			printf("Podaj indeks z przedzialu 0-%d.\n", DL_TAB-1);
			while (scanf("%d", &i) == 1 && i >= 0 && i < DL_TAB)
			{
				poz = (long)i * sizeof(double); //oblicza offset
				fseek(plikwewy, poz, SEEK_SET); //przechodzi w odpowiednie miejsce
				fread(&wartosc, sizeof(double), 1, plikwewy);
				printf("Wartosc pod tym indeksem to %f.\n", wartosc);
				printf("Kolejny indeks (wyjscie poza przedzial konczy program):\n");
			}
			//sprzatanie
			fclose(plikwewy);
			puts("Na razie!");
			

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
//podprogramu do listingu 13.5
void dopisz(FILE *zrodlo, FILE *cel)
{
	size_t bajty;
	static char temp[ROZMIAR_BUF]; //jednorazowy przydzial bufora
	while ((bajty = fread(temp, sizeof(char), ROZMIAR_BUF, zrodlo)) > 0)
		fwrite(temp, sizeof(char), bajty, cel);		
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
			*tutaj = '\0'; //zmieniamy znak nowego wiersza na znak pusty
		else
			while (getchar() != '\0')
				continue;
	}
	return wynik;		
}