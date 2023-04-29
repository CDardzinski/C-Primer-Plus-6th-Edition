#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <ansi_c.h>

#define LenghtString 255

int main (int argc, char *argv[])
{	
	char textSearch[LenghtString];
	FILE* openToSearch;
	char* status;
	
	if(argc != 3)
		exit(EXIT_FAILURE);
	
	
	if((openToSearch = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stdin, "Nie mode otworzyc pliku %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	fseek(openToSearch, 0L, SEEK_SET);
	
	do
	{
		status = 0;
		for(int i = 0; i < LenghtString; i++)
			textSearch[i] = 0;
			
		fgets(textSearch, LenghtString, openToSearch);
		status = strstr(textSearch, argv[1]);
		
		if(status)
			puts(textSearch);
	}while(textSearch[0] != 0);
	
	fclose(openToSearch);
	puts("Zakonczono przeszukiwanie pliku!");
	
	return 0;
}