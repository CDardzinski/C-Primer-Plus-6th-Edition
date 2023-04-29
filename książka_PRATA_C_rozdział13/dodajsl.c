//dodajs1.c --- korzysta z wprintf(), fscanf() i rewind()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cvirte.h>

#define MAX 41


int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;    /* out of memory */
	
	FILE * wp;
	char slowa[MAX];
	
	if((wp = fopen("slowka", "a+")) == NULL)
	{
		fprintf(stdin, "Nie mode otworzyc pliku \"slowka\".\n");
		exit(EXIT_FAILURE);
	}
	puts("Podaj slowa, ktore maja zostac dodane do pliku;");
	puts("Aby zakonczyc, wpisz #.");
	while ((fscanf(stdin, "%40s", slowa) == 1) && (slowa[0] != '#'))
		fprintf(wp, "%s ", slowa);
	puts("Zawartosc pliku:");
	rewind(wp); //przejdz do poczatku pliku
	while (fscanf(wp, "%s", slowa) == 1)
		puts(slowa);
	puts("Gotowe!\n");
	if(fclose(wp) != 0)
		fprintf(stderr, "Blad przy zamykaniu pliku.\n");
	return 0;
}