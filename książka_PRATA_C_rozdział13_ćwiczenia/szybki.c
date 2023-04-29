#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>

//do æwiczenia 2
#define ROZMIAR4096 4096
///////////////////////////////////////////////////////////////

int main (int argc, char *argv[])
{
			size_t bajty;
			FILE *zrodlo; //wskaznik pliku Zrodlowego
			FILE *docelowy;
			char nazwa_plikuZrodlowego[ROZMIAR4096], nazwa_plikuDocelowego[ROZMIAR4096];
			char tymczasowa[ROZMIAR4096];
			//, tempZrod[ROZMIAR4096], tempDoce[ROZMIAR4096];
			//int LenghtSource, LenghtTarget;
			
			
			if (InitCVIRTE (0, argv, 0) == 0)
				return -1;	/* out of memory */
	
			if(argc != 3)
				exit(EXIT_FAILURE);
			
			if(argc == 3)
			{
				strcpy(nazwa_plikuZrodlowego, argv[1]);
				strcpy(nazwa_plikuDocelowego, argv[2]);
			}
			else
			{
				printf("Podano b³êdne parametry");
				exit(EXIT_FAILURE);
			}
			
			
	//		LenghtSource = strlen(nazwa_plikuZrodlowego);
	//		LenghtTarget  = strlen(nazwa_plikuDocelowego);	
			
	/*		if(LenghtSource)
			{
				strncpy(tempZrod, nazwa_plikuZrodlowego, LenghtSource-1);
				for(int i = 0; i < ROZMIAR4096; i++)
					nazwa_plikuZrodlowego[i] = 0;
				strcpy(nazwa_plikuZrodlowego, tempZrod);
			}
			
			if(LenghtTarget)
			{
				strncpy(tempDoce, nazwa_plikuDocelowego, LenghtSource-1);
				for(int i = 0; i < ROZMIAR4096; i++)
					nazwa_plikuDocelowego[i] = 0;
				strcpy(nazwa_plikuDocelowego, tempDoce);
			}
				
*/			if((zrodlo = fopen(nazwa_plikuZrodlowego, "r")) == NULL)
			{
				printf("Nie mozna otworzyc %s\n", nazwa_plikuZrodlowego);
				exit(EXIT_FAILURE);
			}
			
			docelowy = fopen(nazwa_plikuDocelowego, "w");
	/*		if((docelowy = fopen(nazwa_plikuDocelowego, "w")) == NULL)
			{
				printf("Nie mozna otworzyc %s\n", nazwa_plikuDocelowego);
				exit(EXIT_FAILURE);
			}
	*/		
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
	
	return 0;
}