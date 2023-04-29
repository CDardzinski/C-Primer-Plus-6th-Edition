#include <stdlib.h>
#include <stdio.h>

//int #include <cvirte.h>

int main (int argc, char *argv[])
{
//	if (InitCVIRTE (0, argv, 0) == 0)
//		return -1;    /* out of memory */

	int i, razy;
	
	if(argc < 2 || (razy = atoi(argv[1])) < 1)
		printf("Sposob uzycia: %s liczba-dodatnia\n", argv[0]);
	else
		for(i = 0; i < razy; i++)
			puts("Witaj, przystojniaku!");	
	
	getchar();
	return 0;
}