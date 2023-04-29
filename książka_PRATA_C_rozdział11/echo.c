#include <stdio.h>
//#include <cvirte.h>

int main (int argc, char *argv[])
{
	int licznik;
	
//	if (InitCVIRTE (0, argv, 0) == 0)
//		return -1;    /* out of memory */
	
	printf("Wiersz polecen zawiera %d argumentow:\n", argc - 1);
	for(licznik = 1; licznik < argc; licznik++)
		printf("%d: %s\n", licznik, argv[licznik]);
	printf("\n");
	return 0;
}