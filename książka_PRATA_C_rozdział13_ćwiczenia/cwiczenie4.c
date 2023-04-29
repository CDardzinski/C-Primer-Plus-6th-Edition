#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>

//do æwiczenia 4
#define ROZMIAR4096 4096
///////////////////////////////////////////////////////////////

int main (int argc, char *argv[])
{
			
			FILE *otwarty;
			int i;
			char znak;
			char plikiDoOtwarcia[argc][ROZMIAR4096];
			
			if (InitCVIRTE (0, argv, 0) == 0)
				return -1;	/* out of memory */
	
			if(argc < 2)
				exit(EXIT_FAILURE);
			else
			{
				for(i =0; i < argc; i++)
				{	
					strcpy(plikiDoOtwarcia[i], argv[i+1]);
					otwarty = fopen(plikiDoOtwarcia[i], "r");
					fseek(otwarty, 0L, SEEK_SET);
					while((znak = getc(otwarty)) != EOF)
						putchar(znak);
					printf("\n");
					fclose(otwarty);
				}
			}
	
	return 0;
}