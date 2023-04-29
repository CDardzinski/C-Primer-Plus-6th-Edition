#include <ansi_c.h>
#include <stdio.h>
#include <stdlib.h>
#include <cvirte.h>
#define WIELKIELITERY "-u"
#define MALELITAERY "-l"
#define BEZZMIAN "-p"

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;    /* out of memory */
	
	int ch, status = 1, status1 = 1, status2 = 1;

	if(argc > 1)
	{
		status = strcmp(argv[1], WIELKIELITERY);
		status1= strcmp(argv[1], MALELITAERY);
		status2= strcmp(argv[1], BEZZMIAN);
	}
	
	for(int i = 0; i < argc; i++)
		printf("%d\t%s\tstatus %d\tstatus1 %d\tstatus2 %d\n", i, argv[i],status, status1, status2);
		
	if(!status)
	{
		while ((ch = getchar()) != EOF)
		{
			if(islower(ch))
				putchar(ch-32);
			else
				putchar(ch);
				
		}
	}
	else if(!status1)
	{
		while ((ch = getchar()) != EOF)
		{
			if(isupper(ch))
				putchar(ch+32);
			else
				putchar(ch);
				
		}
	}
	else if(!status2)
	{
		while ((ch = getchar()) != EOF)
					putchar(ch);
	}
	else if(argc == 1)
	{
		while ((ch = getchar()) != EOF)
					putchar(ch);
	}
		
	
	return 0;
}