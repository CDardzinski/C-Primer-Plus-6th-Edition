#include "toolbox.h"
#include <formatio.h>
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial13_cwiczenia.h"
#include <cvidef.h>

static int panelHandle;

//do æwiczenia 2
#define ROZMIAR4096 4096
///////////////////////////////////////////////////////////////

//do æwiczenia 6
#define DL 40
///////////////////////////////////////////////////////////////

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial13_cwiczenia.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 1 rodzial 13//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		
			int ch; // przechowuje kolejne odczytane znaki
			FILE *wp; //wskaznik plikowy
			char nazwa_pliku[100];
			unsigned long licznik = 0;
	
			printf("Podaj nazwe pliku do odczytania: \n");
			scanf("%s", nazwa_pliku);
			if(nazwa_pliku[0] == '\0')
			{
				printf("Brak pliku do otwarcia.\n");
				exit(EXIT_FAILURE);
			}
			if((wp = fopen(nazwa_pliku, "r")) == NULL)
			{
				printf("Nie mozna otworzyc %s\n", nazwa_pliku);
				exit(EXIT_FAILURE);
			}
			while((ch = getc(wp)) != EOF)
			{
				putc(ch, stdout);
				licznik++;
			}
			fclose(wp);
			printf("Plik %s zawiera %lu znakow\n", nazwa_pliku, licznik);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 2 rodzial 13//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			size_t bajty;
			int ch; // przechowuje kolejne odczytane znaki
			FILE *zrodlo; //wskaznik pliku Zrodlowego
			FILE *docelowy;
			char nazwa_plikuZrodlowego[ROZMIAR4096], nazwa_plikuDocelowego[ROZMIAR4096];
			char tymczasowa[ROZMIAR4096];
			unsigned long licznik = 0;
			
			printf("Podaj nazwe pliku do skopiowania: \n");
			scanf("%s", nazwa_plikuZrodlowego);
			
			printf("\n");
			printf("Podaj nazwe pliku kopii: \n");
			scanf("%s", nazwa_plikuDocelowego);
			
			if((zrodlo = fopen(nazwa_plikuZrodlowego, "rb")) == NULL)
			{
				printf("Nie mozna otworzyc %s\n", nazwa_plikuZrodlowego);
				exit(EXIT_FAILURE);
			}
			
			if((docelowy = fopen(nazwa_plikuDocelowego, "wb")) == NULL)
			{
				printf("Nie mozna otworzyc %s\n", nazwa_plikuZrodlowego);
				exit(EXIT_FAILURE);
			}
			
			fseek(zrodlo, 0, SEEK_SET);
			fseek(docelowy, 0, SEEK_SET);
			
			if(setvbuf(zrodlo, NULL, _IOFBF, ROZMIAR4096) != 0) //bufor wejsciowy
			{
				fputs("Nie mozna utworzyc bufora wejsciowego\n", stderr);
				exit(EXIT_FAILURE);
			}
			
			if(setvbuf(docelowy, NULL, _IOFBF, ROZMIAR4096) != 0) //bufor wyjsciowy
			{
				fputs("Nie mozna utworzyc bufora wyjsciowego\n", stderr);
				exit(EXIT_FAILURE);
			}
			
			while((bajty = fread(tymczasowa, sizeof(char), ROZMIAR4096, zrodlo)) > 0)
				fwrite(tymczasowa, sizeof(char), bajty, docelowy);
			
			fclose(zrodlo);
			fclose(docelowy);
			

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 3 rodzial 13//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			//size_t bajty;
			//int ch; // przechowuje kolejne odczytane znaki
			FILE *zrodlo; //wskaznik pliku Zrodlowego
			FILE *docelowy;
			char nazwa_plikuZrodlowego[ROZMIAR4096], nazwa_plikuDocelowego[ROZMIAR4096];
			//char tymczasowa[ROZMIAR4096];
			//unsigned long licznik = 0;
			char znak;
			
			printf("Podaj nazwe pliku zrodlowego: \n");
			scanf("%s", nazwa_plikuZrodlowego);
			
			printf("\n");
			printf("Podaj nazwe pliku wyjsciowego: \n");
			scanf("%s", nazwa_plikuDocelowego);
			
			if((zrodlo = fopen(nazwa_plikuZrodlowego, "r")) == NULL)
			{
				printf("Nie mozna otworzyc %s\n", nazwa_plikuZrodlowego);
				exit(EXIT_FAILURE);
			}
			
			if((docelowy = fopen(nazwa_plikuDocelowego, "w")) == NULL)
			{
				printf("Nie mozna otworzyc %s\n", nazwa_plikuZrodlowego);
				exit(EXIT_FAILURE);
			}
			
			fseek(zrodlo, 0L, SEEK_SET);
			fseek(docelowy, 0L, SEEK_SET);
			
			while((znak = getc(zrodlo)) != EOF)
			{
				if(islower(znak))
				{
					znak = toupper(znak);
					putc(znak, docelowy);			
				}
				else putc(znak, docelowy);				
				
				putchar(znak);
			}
			
			fclose(zrodlo);
			fclose(docelowy);
			
			//exit(EXIT_SUCCESS);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 6 rodzial 13//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			FILE *we, *wy; //deklaracja 2 wskaznikow plikowych
			int ch;
			char nazwa[DL]; //miejsce na nazwy pliku wyjsciowego
			int licznik = 0;
			char plik_zrodlowy[DL], plik_wynikowy[DL];
			
			printf("Podaj nazwe pliku zrodlowego: \n");
			scanf("%s", plik_zrodlowy);
			
			printf("\n");
			printf("Podaj nazwe pliku wyjsciowego: \n");
			scanf("%s", plik_wynikowy);

			//plik wejsciowy
			if((we = fopen(plik_zrodlowy, "r")) == NULL)
			{
				fprintf(stderr, "Nie moglem tworzyc pliku\"%s\".\n", plik_zrodlowy);
				exit(EXIT_FAILURE);
			}
	
			//przygotowanie pliku wynikowego
			strncpy(nazwa, plik_wynikowy, DL-5); //kopiuje nazwe pliku do tablicy
			nazwa[DL-5] = '\0';
			strcat(nazwa, ".cdx"); //dodaje.red do nazwy
	
			if((wy = fopen(nazwa, "w'")) == NULL) //otwiera plik do zapisu
			{
				fprintf(stderr, "Nie mozna utworzyc pliku wyjsciowego.\n");
				exit(EXIT_FAILURE);
			}
			//kopioweanie danych
			while ((ch = getc(we)) != EOF)
				if(licznik++ % 3 == 0)
					putc(ch, wy); //wyswietla co trzeci znak
			//sprzatanie
			if(fclose(we) != 0 || fclose(wy) != 0)
				fprintf(stderr, "Blad przy zamykaniu plikow.\n");
			
				exit(EXIT_SUCCESS);	
				
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 10 rodzial 13//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			char plikDoOtwarcia[DL];
			char polozenie, wyswietl;
			int miejsce = 0, koniecPetli = 0;
			FILE* plik = NULL;
			
			printf("Podaj nazwe pliku do otwarcia: \n");
			scanf("%s", plikDoOtwarcia);
			
			while((polozenie = getchar()) != '\n');
			
			do
			{		
				puts("\nPodaj miejsce w pliku od ktorego maja zostac wyswietlone dane: ");
				
				polozenie = getchar();
					
				if(isdigit(polozenie))
				{
					miejsce = 0;
					do
					{
						miejsce = miejsce * 10 + polozenie - '0';
						polozenie = getchar();
					}
					while(isdigit(polozenie));	
				}
				else if(isalpha(polozenie))
				{
					if(plik != NULL)
						fclose(plik);
					exit(EXIT_SUCCESS);
				}
				else if(polozenie == '-')
				{
					if(plik != NULL)
						fclose(plik);
					exit(EXIT_SUCCESS);
				}
			
				if((plik = fopen(plikDoOtwarcia, "r")) == NULL)
					{
						fprintf(stdin, "Nie mode otworzyc pliku %s.\n", plikDoOtwarcia);
						exit(EXIT_FAILURE);
					}
				fseek(plik, miejsce, SEEK_SET);
				
				while((wyswietl = getc(plik)) != '\n')
				{
					printf("%c", wyswietl);
				}
			}
			while(!koniecPetli);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 12 rodzial 13//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad12ButtonCallback (int panel, int control, int event,  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int tabPicture[20][30];
			char tabFinal[20][31];
			FILE* plikWejsciowy, * plikWynikowy;
			char znak;
			int t = 0, z = 0, wypisz;
			
			if((plikWejsciowy = fopen("obraz.txt", "r")) == NULL)
			{
				fprintf(stdin, "Nie mode otworzyc pliku obraz.txt.\n");
				exit(EXIT_FAILURE);
			}
			
			fseek(plikWejsciowy, 0L, SEEK_SET);
			
			while((znak = getc(plikWejsciowy)) != EOF)
			{
				if(isdigit(znak))
				{
					tabPicture[t][z] = znak -'0';
					z++;
					if(z == 30)
					{
						t++;
						z = 0;
					}
					if(t == 20) break;
				}
			}
			
			fclose(plikWejsciowy);
			
			if((plikWynikowy = fopen("obraz2.txt", "w")) == NULL)
			{
				fprintf(stdin, "Nie mode otworzyc pliku obraz2.txt.\n");
				exit(EXIT_FAILURE);
			}
			
			fseek(plikWynikowy, 0L, SEEK_SET);
			
			for(int h = 0; h < 20; h++)
			{
				for(int j = 0; j < 30; j++)
				{
					wypisz = tabPicture[h][j];
					switch (wypisz)
					{
						case 0:
							tabFinal[h][j] = ' ';
							break;	
						case 1:
							tabFinal[h][j] = '.';
							break;
						case 2:
							tabFinal[h][j] = '\'';
							break;
						case 3:
							tabFinal[h][j] = ':';
							break;
						case 4:
							tabFinal[h][j] = '~';
							break;
						case 5:
							tabFinal[h][j] = '*';							
							break;
						case 6:
							tabFinal[h][j] = '=';
							break;
						case 7:
							tabFinal[h][j] = '+';
							break;
						case 8:
							tabFinal[h][j] = '%';
							break;
						case 9:
							tabFinal[h][j] = '#';
							break;	
					}
				}
				tabFinal[h][30] = '\0';
			}
			
			for(int s = 0; s < 20; s++)
			{
				fputs(tabFinal[s], plikWynikowy);
				putc('\n', plikWynikowy);
				fputs(tabFinal[s], stdout);
				printf("\n");
			}
			
			fclose(plikWynikowy);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 13 rodzial 13//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad13ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			
			//int tabPicture[20][30];
			//char tabFinal[20][31];
			FILE* plikWejsciowy, * plikWynikowy;
			char znak;
			int t = 0, z = 0, wypisz, licznik = 0, a = 0, b = 0;
			
			if((plikWejsciowy = fopen("obraz3.txt", "r")) == NULL)
			{
				fprintf(stdin, "Nie mode otworzyc pliku obraz.txt.\n");
				exit(EXIT_FAILURE);
			}
			
			fseek(plikWejsciowy, 0L, SEEK_SET);
			
			while((znak = getc(plikWejsciowy)) != EOF)
			{
				if(isdigit(znak))
				{
					t++;
					if(licznik < t)
						licznik = t;
				}
				if(znak == '\n')
				{
					z++;
					t = 0;
				}
			}
			
			int tabPicture[z+1][t];
			char tabFinal[z+1][t+1]; 
			
			fseek(plikWejsciowy, 0L, SEEK_SET);
			
			while((znak = getc(plikWejsciowy)) != EOF)
			{
				if(isdigit(znak))
				{
					tabPicture[a][b] = znak -'0';
					b++;
					if(b == t)
					{
						a++;
						b = 0;
					}
					if(a == z + 1) break;
				}
			}
			
			fclose(plikWejsciowy);
			
			if((plikWynikowy = fopen("obraz4.txt", "w")) == NULL)
			{
				fprintf(stdin, "Nie mode otworzyc pliku obraz2.txt.\n");
				exit(EXIT_FAILURE);
			}
			
			fseek(plikWynikowy, 0L, SEEK_SET);
			
			for(int h = 0; h < z+1; h++)
			{
				for(int j = 0; j < t; j++)
				{
					wypisz = tabPicture[h][j];
					switch (wypisz)
					{
						case 0:
							tabFinal[h][j] = ' ';
							break;	
						case 1:
							tabFinal[h][j] = '.';
							break;
						case 2:
							tabFinal[h][j] = '\'';
							break;
						case 3:
							tabFinal[h][j] = ':';
							break;
						case 4:
							tabFinal[h][j] = '~';
							break;
						case 5:
							tabFinal[h][j] = '*';							
							break;
						case 6:
							tabFinal[h][j] = '=';
							break;
						case 7:
							tabFinal[h][j] = '+';
							break;
						case 8:
							tabFinal[h][j] = '%';
							break;
						case 9:
							tabFinal[h][j] = '#';
							break;	
					}
				}
				tabFinal[h][t] = '\0';
			}
			
			for(int s = 0; s < z+1; s++)
			{
				fputs(tabFinal[s], plikWynikowy);
				putc('\n', plikWynikowy);
				fputs(tabFinal[s], stdout);
				printf("\n");
			}
			
			fclose(plikWynikowy);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 14 rodzial 13//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad14ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int tabPicture[20][30], tabAvgPic[20][30];
			char tabFinal[20][31];
			FILE* plikWejsciowy, * plikWynikowy;
			char znak;
			int t = 0, z = 0, wypisz;
			
			if((plikWejsciowy = fopen("obraz.txt", "r")) == NULL)
			{
				fprintf(stdin, "Nie mode otworzyc pliku obraz.txt.\n");
				exit(EXIT_FAILURE);
			}
			
			fseek(plikWejsciowy, 0L, SEEK_SET);
			
			while((znak = getc(plikWejsciowy)) != EOF)
			{
				if(isdigit(znak))
				{
					tabPicture[t][z] = znak -'0';
					z++;
					if(z == 30)
					{
						t++;
						z = 0;
					}
					if(t == 20) break;
				}
			}
			
			fclose(plikWejsciowy);
			
			//usrednianie komórek na podstawie komorek s¹siednich
			
			for(int y = 0; y < 20; y++)
			{
				for(int u = 0; u < 30; u++)
				{
					if(y == 0 && u == 29) //skrajne punkty
					{
						if(abs(tabPicture[y][u] - tabPicture[y][u-1]) > 1 || abs(tabPicture[y][u] - tabPicture[y+1][u]) > 1)
							tabAvgPic[y][u] = (tabPicture[y][u] + tabPicture[y][u-1] + tabPicture[y+1][u]) / 3;
						else
							tabAvgPic[y][u] = tabPicture[y][u];
					}
					else if(y == 19 && u == 29)
					{
						if(abs(tabPicture[y][u] - tabPicture[y][u-1]) > 1 || abs(tabPicture[y][u] - tabPicture[y-1][u]) > 1)
							tabAvgPic[y][u] = (tabPicture[y][u] + tabPicture[y][u-1] + tabPicture[y-1][u]) / 3;
						else
							tabAvgPic[y][u] = tabPicture[y][u];
					}
					else if(y == 19 && u == 0)
					{
						if(abs(tabPicture[y][u] - tabPicture[y][u+1]) > 1 || abs(tabPicture[y][u] - tabPicture[y-1][u]) > 1)
							tabAvgPic[y][u] = (tabPicture[y][u] + tabPicture[y][u+1] + tabPicture[y-1][u]) / 3;	
						else
							tabAvgPic[y][u] = tabPicture[y][u];
					}
					else if(y == 0 && u == 0)
					{
						if(abs(tabPicture[y][u] - tabPicture[y][u+1]) > 1 || abs(tabPicture[y][u] - tabPicture[y+1][u]) > 1)
							tabAvgPic[y][u] = (tabPicture[y][u] + tabPicture[y][u+1] + tabPicture[y+1][u]) / 3;
						else
							tabAvgPic[y][u] = tabPicture[y][u];
					}
					else if(y == 0 && u < 29 && u > 0) //boki
					{
						if(abs(tabPicture[y][u] - tabPicture[y][u-1]) > 1 || abs(tabPicture[y][u] - tabPicture[y][u+1]) > 1 || abs(tabPicture[y][u] - tabPicture[y+1][u]) > 1)
							tabAvgPic[y][u] = (tabPicture[y][u] + tabPicture[y][u-1] + tabPicture[y][u+1] + tabPicture[y+1][u]) / 4;
						else
							tabAvgPic[y][u] = tabPicture[y][u];
					}
					else if(y == 19 && u < 29 && u > 0)
					{
						if(abs(tabPicture[y][u] - tabPicture[y][u-1]) > 1 || abs(tabPicture[y][u] - tabPicture[y][u+1]) > 1 || abs(tabPicture[y][u] - tabPicture[y-1][u]) > 1)
							tabAvgPic[y][u] = (tabPicture[y][u] + tabPicture[y][u-1] + tabPicture[y][u+1] + tabPicture[y-1][u]) / 4;
						else
							tabAvgPic[y][u] = tabPicture[y][u];
					}
					else if(y > 0 && y < 19 && u == 0)
					{
						if(abs(tabPicture[y][u] - tabPicture[y][u+1]) > 1 || abs(tabPicture[y][u] - tabPicture[y-1][u]) > 1 || abs(tabPicture[y][u] - tabPicture[y+1][u]) > 1)
							tabAvgPic[y][u] = (tabPicture[y][u] + tabPicture[y][u+1] + tabPicture[y-1][u] + tabPicture[y+1][u]) / 4;
						else
							tabAvgPic[y][u] = tabPicture[y][u];
					}
					else if(y > 0 && y < 19 && u == 29)
					{
						if(abs(tabPicture[y][u] - tabPicture[y][u-1]) > 1 || abs(tabPicture[y][u] - tabPicture[y-1][u]) > 1 || abs(tabPicture[y][u] - tabPicture[y+1][u]) > 1)
							tabAvgPic[y][u] = (tabPicture[y][u] + tabPicture[y][u-1] + tabPicture[y-1][u] + tabPicture[y+1][u]) / 4;
						else
							tabAvgPic[y][u] = tabPicture[y][u];
					}
					else
					{
						if(abs(tabPicture[y][u] - tabPicture[y][u+1]) > 1 || abs(tabPicture[y][u] - tabPicture[y][u-1]) > 1 || abs(tabPicture[y][u] - tabPicture[y+1][u]) > 1 || abs(tabPicture[y][u] - tabPicture[y-1][u]) > 1)
							tabAvgPic[y][u] = (tabPicture[y][u] + tabPicture[y][u+1] + tabPicture[y][u-1] + tabPicture[y+1][u] + tabPicture[y-1][u]) / 5;
						else
							tabAvgPic[y][u] = tabPicture[y][u];
					}
				}
			}
	
			if((plikWynikowy = fopen("obraz6.txt", "w")) == NULL)
			{
				fprintf(stdin, "Nie mode otworzyc pliku obraz2.txt.\n");
				exit(EXIT_FAILURE);
			}
			
			fseek(plikWynikowy, 0L, SEEK_SET);
			
			for(int h = 0; h < 20; h++)
			{
				for(int j = 0; j < 30; j++)
				{
					wypisz = tabAvgPic[h][j];
					switch (wypisz)
					{
						case 0:
							tabFinal[h][j] = ' ';
							break;	
						case 1:
							tabFinal[h][j] = '.';
							break;
						case 2:
							tabFinal[h][j] = '\'';
							break;
						case 3:
							tabFinal[h][j] = ':';
							break;
						case 4:
							tabFinal[h][j] = '~';
							break;
						case 5:
							tabFinal[h][j] = '*';							
							break;
						case 6:
							tabFinal[h][j] = '=';
							break;
						case 7:
							tabFinal[h][j] = '+';
							break;
						case 8:
							tabFinal[h][j] = '%';
							break;
						case 9:
							tabFinal[h][j] = '#';
							break;	
					}
				}
				tabFinal[h][30] = '\0';
			}
			
			for(int s = 0; s < 20; s++)
			{
				fputs(tabFinal[s], plikWynikowy);
				putc('\n', plikWynikowy);
				fputs(tabFinal[s], stdout);
				printf("\n");
			}
			
			fclose(plikWynikowy);

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
///////////////////////////////////////////////////////////////////////////////////////////////
////////////////Otiwranie metryczki dopisywanie i zamykanie metryczki/////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK MashaCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
	/*		
			FILE* plikDopisywnia;
			
			if((plikDopisywnia = fopen("metr104wzks.doc", "a")) == NULL)
			{
				fprintf(stdin, "Nie mode otworzyc pliku obraz2.txt.\n");
				exit(EXIT_FAILURE);
			}
			
			fseek(plikDopisywnia, 133, SEEK_SET);
			
			fputs("Masza to z³y miœ", plikDopisywnia);
			
			fclose(plikDopisywnia);
			
			printf("Zrobione!");
	*/		
	
		int WriteFileHandle, status;
		char buf[10000];
		ssize_t posistionFromStart;
	
		WriteFileHandle = OpenFile("masza.doc", VAL_READ_WRITE, VAL_TRUNCATE, VAL_ASCII);
		
		
		Fmt(buf, "%s<%s", "MASZA jest glodna... mam zly dzien\n dlugopis pisze na niebiesko\t smieci\n");
		status = WriteFile(WriteFileHandle, buf, StringLength(buf));
		
		
		CloseFile(WriteFileHandle);
		
		
		//File pointer set
		//posistionFromStart =  SetFilePtr(WriteFileHandle, 0, 0);
		
		//printf("%d\n", posistionFromStart);
		
		WriteFileHandle = OpenFile("masza.doc", VAL_READ_WRITE, VAL_OPEN_AS_IS, VAL_ASCII);
		
		do
		{
		FillBytes(buf, 0, 9999, 0);
		status = ReadFile(WriteFileHandle, buf, 10000);
		puts(buf);
		}while (buf[0] == 0);
		
		
		
		CloseFile(WriteFileHandle);
		
		printf("Zrobione!");
		
		OpenDocumentInDefaultViewer("masza.doc", 0);

			break;
	}
	return 0;
}
