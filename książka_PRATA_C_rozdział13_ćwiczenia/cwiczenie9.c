#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX 41

int main (int argc, char *argv[])
{	
	FILE * wp;
	char slowa[MAX];
	int kolejny = 1;
	char znak;
 	
	
	if((wp = fopen("slowka.txt", "a+")) == NULL)
	{
		fprintf(stdin, "Nie mode otworzyc pliku \"slowka\".\n");
		exit(EXIT_FAILURE);
	}
	
	fseek(wp, 0L, SEEK_SET);

	while ((znak = getc(wp)) != EOF)
	{
		if(isdigit(znak))
		{
			kolejny = 0;
			do
			{
				kolejny = kolejny * 10 + znak - '0';
				znak = getc(wp);
			}
			while(isdigit(znak));	
			kolejny++;
		}
	}

	puts("Podaj slowa, ktore maja zostac dodane do pliku;");
	puts("Aby zakonczyc, wpisz #.");
	while ((fscanf(stdin, "%40s", slowa) == 1) && (slowa[0] != '#'))
	{
		fprintf(wp, "%d-%s\n", kolejny, slowa);
		kolejny++;
	}
	puts("Zawartosc pliku:");
	rewind(wp); //przejdz do poczatku pliku
	while (fscanf(wp, "%s", slowa) == 1)
		puts(slowa);
	puts("Gotowe!\n");
	if(fclose(wp) != 0)
		fprintf(stderr, "Blad przy zamykaniu pliku.\n");
	return 0;
}