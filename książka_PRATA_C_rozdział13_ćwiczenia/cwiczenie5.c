#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>

//do æwiczenia 5
#define ROZMIAR4096 4096

#define ROZMIAR_BUF 4096
#define DLAN 50
///////////////////////////////////////////////////////////////

void dopisz(FILE *zrodlo, FILE *cel);
char *wczytaj(char *z, int ile);

int main (int argc, char *argv[])
{

			FILE *pd, *pz; //pz - plik dopisywany,  pd- plik docelowy
			//int pliki = 0; //liczba dopisywanych plikow
			char plik_do_dopisania[argc][DLAN]; //nazwy plików dopisywanych
			char plik_do_ktorego_dopisuje[DLAN]; //nazwa pliku docelowego
			int ch;
			
			if(argc < 3)
				exit(EXIT_FAILURE);
			else
			{
				strcpy(plik_do_ktorego_dopisuje, argv[1]);
				pz = fopen(plik_do_ktorego_dopisuje, "a");
				setvbuf(pz, NULL, _IOFBF, ROZMIAR_BUF);
				
				for(int i = 0; i < argc-2; i++)
				{
					strcpy(plik_do_dopisania[i], argv[i+2]);
					pd = fopen(plik_do_dopisania[i], "r");
					setvbuf(pd, NULL, _IOFBF, ROZMIAR_BUF);
					dopisz(pd, pz);
					fclose(pd);
				}
				
				fclose(pz);
				
			}
			
	/*		
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
*/
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