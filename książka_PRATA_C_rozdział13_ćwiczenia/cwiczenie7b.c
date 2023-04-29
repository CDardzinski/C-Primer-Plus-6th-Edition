#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>

//do æwiczenia 7b
#define DLAN 50
char odczytWypisz(FILE* plik);
///////////////////////////////////////////////////////////////

int main (int argc, char *argv[])
{

			FILE *plik1doOdczytu, *plik2doOdczytu; 
			char ch1, ch2;
			int koniec = 0;
			int licznik1 = 0, licznik2 = 0;
			
			
			if(argc != 3)
				exit(EXIT_FAILURE);
			else
			{
				if((plik1doOdczytu = fopen(argv[1], "r")) == NULL)
				{
					fprintf(stderr, "Blad otwarcia %s\n", plik1doOdczytu);
					exit(EXIT_FAILURE);
				}
				if((plik2doOdczytu = fopen(argv[2], "r")) == NULL)
				{
					fprintf(stderr, "Blad otwarcia %s\n", plik2doOdczytu);
					exit(EXIT_FAILURE);
				}
			}
			
			while(koniec != 1)
			{
				if(ch1 != EOF)
				{
					ch1 = odczytWypisz(plik1doOdczytu);
					if(ch1) licznik1++;
				}
				if(ch2 != EOF)
				{
					ch2 = odczytWypisz(plik2doOdczytu);
					if(ch2) licznik2++;
				}
				
				if(licznik1 == licznik2)
					putchar('\n');
				else
					putchar('\n');
				
				
				if(ch1 == EOF && ch2 == EOF)
				{
					koniec = 1;
					break;
				}
			}
			
			fclose(plik1doOdczytu);
			fclose(plik2doOdczytu);
			
			exit(EXIT_SUCCESS);
				
	return 0;		
}
char odczytWypisz(FILE* plik)
{
	char znak = 0;
	
	while((znak = getc(plik)) != '\n')
		putchar(znak);
	
//	if(znak == '\n')
//		putchar(znak);
	
	if(!(znak = getc(plik)))
		znak = EOF;
	else ungetc(znak, plik);
	
	return znak;
}