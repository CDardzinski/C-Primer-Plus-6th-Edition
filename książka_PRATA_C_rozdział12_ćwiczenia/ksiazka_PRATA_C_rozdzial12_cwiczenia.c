#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial12_cwiczenia.h"
#include "pe12-2a.h"
#include "pe12-3.h"
//#include <rzutkosc.h>
#include "rzutkosc_cwiczenia.h"

static int panelHandle;

//do przyk³adu æwiczenia 1
int krytyka(int jednostka);
//////////////////////////////////////////////////////

//do przyk³adu æwiczenia 4
int auto_wywolanie(void);
//////////////////////////////////////////////////////

//do przyk³adu æwiczenia 8
int *stworz_tablice(int , int);
void pokaz_tablice(const int [], int);
//////////////////////////////////////////////////////


//do æwiczenia 9
#define LIMIT 400

char ** pobierz_slowa(int n);
static void znajdz_slowo(char **start, char **end);
//////////////////////////////////////////////////////


int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial12_cwiczenia.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 1 rodzial 12//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int jednostki; 
			
			printf("Ile funtow masla miesci sie w barylce?\n");
			scanf("%d", &jednostki);
			while (jednostki != 56)
				jednostki = krytyka(jednostki);
			printf("Musiales podejrzec!\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 2 rodzial 12//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			int tryb; 
			
			printf("Wybierz: 0 - system metryczny, 1 - system US: ");
			scanf("%d", &tryb);
			while(tryb >= 0)
			{
				wybierz_tryb(tryb);
				pobierz_dane();
				wyswietl_dane();
				printf("WYbierz: 0 - system metryczny, 1 - system US");
				printf("(-1 aby zakonczyc): ");
				scanf("%d", &tryb);
			}
			printf("Koniec.\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 3 rodzial 12//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int tryb, wybor = 0; 
			double paliwo;
			int dystans;
			
			printf("Wybierz: 0 - system metryczny, 1 - system US: ");
			scanf("%d", &tryb);
			while(tryb >= 0)
			{
				wybor = wybierz_tryb_auto(wybor, tryb);
				pobierz_dane_auto(&dystans, &paliwo, wybor);
				wyswietl_dane_auto(dystans, paliwo, wybor);
				printf("WYbierz: 0 - system metryczny, 1 - system US");
				printf("(-1 aby zakonczyc): ");
				scanf("%d", &tryb);
			}
			printf("Koniec.\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 4 rodzial 12//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			int sprawdzenie, wywolanie;
			
			printf("Ile razy mam wywolac funkcje?\n");
			scanf("%d", &wywolanie);
			
			for(int i = 0; i < wywolanie; i++)
			{
				sprawdzenie = auto_wywolanie();
				printf("%d\n", sprawdzenie);
			}			
			printf("Funkcja zostala wywolana %d razy.\n", sprawdzenie);

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 5 rodzial 12//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			int n = 10;
			int lista[n];
			int liczba,x;
			
			srand(time(0));
			
			puts("Lista nieposorotwana");
			for(int i = 0; i < n; i++)
			{
				liczba = rand() % 10;
				lista[i] = liczba;
				printf("Losowe liczby nieposortowane %d\t\t: %d\n", i+1, lista[i]);
			}
			
			puts("Lista posorotwana");
	
  // sortowanie b¹belkowe

  			for(int i = 1; i < n; i++) // wykonuje siê n - 1 razy
    			for(int j = 0; j < n - i; j++)
      				if(lista[j] < lista[j + 1]) // sprawdzamy kolejnoœæ
      				{
        				x = lista[j]; // jeœli z³a, elementy zamieniamy
        				lista[j] = lista[j + 1];
        				lista[j + 1] = x;
     				}

  			for(int i = 0; i < n; i++) printf("Losowe posortowane malejaco %d\t\t: %d\n", i+1, lista[i]);
  
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 6 rodzial 12//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int n = 1000;
			int lista[n];
			int zero = 0, jeden = 0, dwa = 0, trzy = 0, cztery = 0, piec = 0, szesc = 0, siedem = 0, osiem = 0, dziewiec = 0;
			
		//	srand(time(0));
	
			for(int i = 0; i < n; i++)
			{
				if(!(i % 100)) srand(time(0));
				
				lista[i] = rand() % 10;
			}
			
			for(int z = 0; z < n; z++)
			{
				if(lista[z] == 0) zero++;
				if(lista[z] == 1) jeden++;
				if(lista[z] == 2) dwa++;
				if(lista[z] == 3) trzy++;
				if(lista[z] == 4) cztery++;
				if(lista[z] == 5) piec++;
				if(lista[z] == 6) szesc++;
				if(lista[z] == 7) siedem++;
				if(lista[z] == 8) osiem++;
				if(lista[z] == 9) dziewiec++;
			}
			
			
			printf("Liczba 0 pojawila sie %d razy\n", zero);
			printf("Liczba 1 pojawila sie %d razy\n", jeden);
			printf("Liczba 2 pojawila sie %d razy\n", dwa);
			printf("Liczba 3 pojawila sie %d razy\n", trzy);
			printf("Liczba 4 pojawila sie %d razy\n", cztery);
			printf("Liczba 5 pojawila sie %d razy\n", piec);
			printf("Liczba 6 pojawila sie %d razy\n", szesc);
			printf("Liczba 7 pojawila sie %d razy\n", siedem);
			printf("Liczba 8 pojawila sie %d razy\n", osiem);
			printf("Liczba 9 pojawila sie %d razy\n", dziewiec);
			printf("\n");	

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 7 rodzial 12//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int sciany, kosci, status, liczba_kolejek, wynik;
			char kolejki[10];
			char znak;
			
			srand((unsigned int) time(0)); //losowe ziarno
			printf("Wprowadz liczbe kolejek; wybierz q, aby zakonczyc.\n");
			while ((scanf("%s", kolejki)) == 1 && (kolejki[0] != 0))
			{
				sciany = 0;
				kosci = 0;
				
				if(kolejki[0] == 'q') exit(EXIT_SUCCESS);
				
				liczba_kolejek = atoi(kolejki);
				
				printf("Ile scian i ile kosci?\n");
				if((status = scanf("%d %d", &sciany, &kosci)) != 1)
				{
					if((sciany == 0) || (kosci == 0))
					{
						printf("Nalezy podac liczby calkowite.");
						printf("Sprobujmy jeszcze raz.\n");
						while ((znak = getchar()) != '\n')
						{
							if(znak == 'q') exit(EXIT_SUCCESS); //wyjscie
							continue; //odrzucenie niepoprawnego wejscia
						}
						printf("Ile kolejek? q oznacza koniec.\n");
						continue; //nowy przebieg petli
					}
				}
				
				printf("Oto %d kolejek rzutow %d %d-sciennymi kostkami:\n", liczba_kolejek, kosci, sciany);
				for(int i = 0; i < liczba_kolejek; i++)
				{
					wynik = rzucaj(sciany*kosci);
					printf("%d ", wynik);
				}
				printf("\n");
				printf("Wprowadz liczbe kolejek; wybierz q, aby zakonczyc.\n");
			}

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 8 rodzial 12//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			int *wt;
			int rozmiar, wartosc;
			 
			printf("Podaj liczbe elementow: ");
			while(scanf("%d", &rozmiar) == 1 && rozmiar > 0)
			{
				printf("Podaj wartosc poczatkowa: ");
				scanf("%d", &wartosc);
				wt = stworz_tablice(rozmiar, wartosc);
				if(wt)
				{
					pokaz_tablice(wt, rozmiar);
					free(wt);
				}
				printf("Podaj liczbe elementow (< 1 - koniec): ");	
			}
			
			printf("Koniec.\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 9 rodzial 12//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
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

			break;
	}
	return 0;
}

//////////////Wyjœcie
int CVICALLBACK QuitCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}
//do æwiczenia 1
int krytyka(int jednostka)
{	
	printf("Nie masz szczescia, sprobuj ponownie.\n");
	scanf("%d", &jednostka);
	return jednostka;
}
//do æwiczenia 4
int auto_wywolanie(void)
{
	static int wywolanie;
	return ++wywolanie;
}	
//do æwiczenia 8
int *stworz_tablice(int elem, int wart)
{
	int *wsk;
	
	wsk = (int *) malloc(elem * sizeof(int));
	
	for(int i = 0; i < elem; i++)
		*(wsk + i) = wart;
	
	return wsk;
	
}
void pokaz_tablice(const int tab[], int n)
{
	for(int i = 0, z = 1; i < n; i++, z++)
		{
			printf("%d ", *(tab+i));
			if(!(z % 8)) printf("\n");
		}
	printf("\n");	
}
//do æwiczenia 9
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
		//znajdz pocz¹tek i koniec nastêpnego s³owa
		znajdz_slowo(&pierwsze_slowo, &ostatnie_slowo);
		
		// je¿eli pierwsze_slowo to znak null, oznacza to ,¿e dalej nie ma s³ow, wychodze z petli
		if (*pierwsze_slowo == '\0')
			break;

		// allocate memory for new word and copy from tymczasowa
		dlugosc_slowa = ostatnie_slowo - pierwsze_slowo;
		tablica_slow[i] = (char *) malloc((dlugosc_slowa + 1) * sizeof(char));
		if (tablica_slow[i] != NULL)
		{
			strncpy(tablica_slow[i], pierwsze_slowo, dlugosc_slowa);
			tablica_slow[i][dlugosc_slowa] = '\0';
		}
		
		pierwsze_slowo = ostatnie_slowo;
	}

	// if less than n words found, set remaining elements of
	// tablica_slow to null string
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
	// takes two pointers to pointers to char
	// sets *start to point to first character of first
	// word occuring after **start and sets *end to point
	// to the character immediately after the word
	
	// pobieram dwa wskazniki do wskaznika typu char
 	// ustawiam wksaznik *start na adres pierwszego znaku pierwszego slowa wyspêtuj¹ce po wskazniku **start i ustawiam wskaznik *end na
	// punkt wystêpuj¹cy od razu po tym s³owie

	while (isspace(**start))
		(*start)++;

	*end = *start;

	while (!isspace(**end) && **end != '\0')
		(*end)++;
}