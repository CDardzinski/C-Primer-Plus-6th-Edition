#include <stdio.h>
#include <stdlib.h>

#include <cvirte.h>

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;    /* out of memory */
	
	if(argc > 1)
		for(int i = argc; i > 0; i--)
			printf("%s\n", argv[i]);	
	
	getchar();
	getchar();
	
	return 0;
}