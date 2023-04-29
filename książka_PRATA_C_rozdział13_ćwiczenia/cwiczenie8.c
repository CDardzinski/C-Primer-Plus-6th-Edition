#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>

//do æwiczenia 8
#define ROZMIAR 50
#define ROZMIAR100000 100000

int EntryStandardIO(char);

int main (int argc, char *argv[])
{
	int status;
	char znakSzukany, znak, argument;
	char tablica[argc][1024];
	FILE *plik;
			
	if(argc < 2)
		exit(EXIT_FAILURE);
			
	strcpy(&znakSzukany, &argv[1][0]);
	
	if(argc == 2) argument = '0';
	if(argc >= 3) 
	{
		for (int i = 0; i < argc-2; i++)
			strcpy(tablica[i], argv[i+2]);
	
	argument = tablica[0][0];
	}
	/////////////
	printf("argc = %d\n", argc);
	for(int z=0; z < argc; z++)
	{
		printf("tablica [%d] = %c\n", z, tablica[z][0]);
	}
	printf("argument = %c\n", argument);
	/////////////////////
	if(argument == '0')
	{
		status = EntryStandardIO(znakSzukany);//tutaj przejscie na tryb u¿ycia klawiatury i ekranu
		if(!status) 
		{
			printf("Nacisnij ENTER aby zakonczyc!");
			while (znak != '\n')
				znak = getchar();
			exit(EXIT_SUCCESS);
		}
	}
	else 
	{
		int licznik = 0;
		
		for(int t = 0; t < argc-2; t++)
		{
			strcpy(tablica[t], argv[t+2]);
			
			if((plik = fopen(tablica[t], "r")) == NULL)
			{
				fprintf(stderr, "Nie mozna otworzyc %s\n", tablica[t]);
				printf("%c\n", plik);
				continue;
			}
			
			fseek(plik, 0L, SEEK_SET);
			while((znak = getc(plik)) != EOF)
			{
				if(znak == znakSzukany) licznik++;
			}
			printf("W pliku: %s\t znaleziono znak %c\t %d razy\n", tablica[t], znakSzukany, licznik);
			fclose(plik);
		}
	}
	
	puts("Nacisnij ENTER aby zakonczyc!");
	while (znak != '\n')
		znak = getchar();
	exit(EXIT_SUCCESS);

	return 0;		
}

int EntryStandardIO(char znakSzukany)
{
	int i = 0, licznik = 0;
	char znak;
	char tab[ROZMIAR100000];
	
	printf("Prosze wpisac dane: ");
	
	while((znak = getchar()) != '\n')
	{
		tab[i] = znak;
		i++;
	}
	
	for(int n = 0; n < i; n++)
	{
		if(znakSzukany == tab[n])
			licznik++;
	}
	
	printf("Znak %c wystepuje %d razy we wprowadzonych danych.", znakSzukany, licznik);
		
	return 0;
}