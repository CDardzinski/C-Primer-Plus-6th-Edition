#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 400

char ** pobierz_slowa(int n);
static void znajdz_slowo(char **start, char **end);

int main(void)
{
			int n;
			char **slowa;

			printf("Podaj liczbe slow do wprowadzenia\n");
			if (scanf("%d", &n) == 1 && n > 0)
			{
				while (getchar() != '\n')
					continue;
				slowa = pobierz_slowa(n);

				printf("Oto wprowadzone slowa:\n");
				for (int i = 0; i < n; i++)
					printf("%s\n", slowa[i]);
			}
return 0;
}

char ** pobierz_slowa(int n)
{
	char tymczasowa[LIMIT];
	int i;
	char * pierwsze_slowo;
	char * ostatnie_slowo;
	int dlugosc_slowa;

	char ** tablica_slow = (char **) malloc(n * sizeof(char *));

	printf("Wprowadz %d slow:\n", n); 
	pierwsze_slowo = fgets(tymczasowa, LIMIT, stdin);

	for (i = 0; i < n; i++)
	{
	
		znajdz_slowo(&pierwsze_slowo, &ostatnie_slowo);
		

		if (*pierwsze_slowo == '\0')
			break;

		dlugosc_slowa = ostatnie_slowo - pierwsze_slowo;
		tablica_slow[i] = (char *) malloc((dlugosc_slowa + 1) * sizeof(char));
		if (tablica_slow[i] != NULL)
		{
			strncpy(tablica_slow[i], pierwsze_slowo, dlugosc_slowa);
			tablica_slow[i][dlugosc_slowa] = '\0';
		}
		
		pierwsze_slowo = ostatnie_slowo;
	}


	if (i < n)
		for (; i < n; i++)
		{	
			tablica_slow[i] = (char *) malloc(sizeof(char));
			*tablica_slow[i] = '\0';
		}

	return tablica_slow;
}

static void znajdz_slowo(char **start, char **end)
{

	while (isspace(**start))
		(*start)++;

	*end = *start;

	while (!isspace(**end) && **end != '\0')
		(*end)++;
}