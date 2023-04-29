#include <utility.h>
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "Ksiazka_PRATA_C_cwiczenia.h"
#include <limits.h>
#include <float.h>
#include <string.h>

#define GESTOSC 62.4
#define POCHWALA "Ach, jakie wspaniale imie!"
#define PI 3.14159
#define STRONY 336
#define SLOWA 65618


//Pytania sprawdzaj¹ce
#define Q "\"Jego Hamlet byl zabawny, nie bedac przy tym wulgarnym.\""
#define KSIAZKA "Wojna i pokoj"

static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "Ksiazka_PRATA_C_cwiczenia.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);	
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Przyk³ad  z listingu 4.1////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	float waga, objetosc;
	int rozmiar, litery;
	char nazwa[40];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Witam! Podaj swoje imie.\n");
			scanf("%s", nazwa);
			printf("%s, ile funtowwazysz?\n", nazwa);
			scanf("%f", &waga);
			rozmiar = sizeof nazwa;
			litery = strlen(nazwa);
			objetosc = waga / GESTOSC;
			printf("Zatem, %s, twoaja objetosc wynosi %2.2f stopy szescienne.\n", nazwa, objetosc);
			printf("Ponadto Twoje imie zawiera %d liter(y),\n", litery);
			printf("a na jego przechowanie przeznaczylismy %d bajtow.\n", rozmiar);
			printf("------------------------------------------------------------------------------------------------------------------\n");
			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Przyk³ad  z listingu 4.2////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char imie[40];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Jak masz na imie?\n");
			scanf("%s", imie);
			printf("Witaj, %s. %s\n", imie, POCHWALA);
			printf("------------------------------------------------------------------------------------------------------------------\n");
			
			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Przyk³ad  z listingu 4.3////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char imie[40];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Jak masz na imie?\n");
			scanf("%s", imie);
			printf("Witaj, %s. %s\n", imie, POCHWALA);
			printf("Twoje imie, skladajace sie z %zd liter, zajmuje %zd komorek pamieci\n", strlen(imie), sizeof imie);
			printf("Pochwala sklada sie z %zd liter ", strlen(POCHWALA));
			printf("i zajmuje %zd komorek pamieci.\n", sizeof POCHWALA);
			printf("------------------------------------------------------------------------------------------------------------------\n");

			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Przyk³ad  z listingu 4.4////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	float powierzchnia, obwod, promien;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Ile wynosi promien Twojej pizzy?\n");
			scanf("%f", &promien);
			powierzchnia = PI * promien * promien;
			obwod = 2.0 * PI * promien;
			printf("Podstawowe parametry Twojej pizzy to:\n");
			printf("obwod = %1.2f, powierzchnia = %1.2f\n", obwod, powierzchnia);
			printf("------------------------------------------------------------------------------------------------------------------\n");

			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Przyk³ad  z listingu 4.5////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			printf("Niektore granice liczbowe dla tego systemu:\n");
			printf("Najwiekszy int: %d\n", INT_MAX);
			printf("Najmniejszy long long: %lld\n", LLONG_MIN);
			printf("Jeden bajt = %d bitow(w tym systemie).\n", CHAR_BIT);
			printf("Najwiêkszy double: %e\n", DBL_MAX);
			printf("Najmniejszy normalny float: %e\n", FLT_MIN);
			printf("float precyzja =  %d cyfr\n", FLT_DIG);
			printf("float epsilon =  %e cyfr\n", FLT_EPSILON);
			printf("------------------------------------------------------------------------------------------------------------------\n");
	
			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Przyk³ad  z listingu 4.11////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	short num = STRONY;
	short mnum = -STRONY;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("num jako short i unsigned short: %hd %hu\n", num, num);
			printf("-num jako short i unsigned short: %hd %hu\n", mnum, mnum);
			printf("num jako int i char: %d %c\n", num, num);
			printf("SLOWA jako int, short i char: %d %hd\n", SLOWA, SLOWA, SLOWA);
			printf("------------------------------------------------------------------------------------------------------------------\n");
			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Przyk³ad  z listingu 4.12////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad12ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	float n1 = 3.0;
	double n2 = 3.0;
	long n3 = 2000000000;
	long n4 = 1234567890;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			//DisableBreakOnLibraryErrors();
			printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
			printf("%ld %ld\n", n3, n4);
			printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
			printf("------------------------------------------------------------------------------------------------------------------\n");
			//EnableBreakOnLibraryErrors();

			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Przyk³ad  z listingu 4.13////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad13ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int n =100;
	int wz;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			wz = printf("Woda wrze w temperaturze %d C.\n", n);
			printf("Funkcja printf() wyswietla %d znaki.\n", wz);
			printf("------------------------------------------------------------------------------------------------------------------\n");

			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Przyk³ad  z listingu 4.14////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad14ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Oto jeden ze sposobow wyswietlania ");
			printf("dlugiego lancucha.\n");
			printf("Oto inny sposob wyswietlania \
dlugiego lancucha.\n");
			printf("Oto najnowszy sposob wyswietlania "
				   "dlugiego lancucha.\n");		//ANSI C //
	printf("------------------------------------------------------------------------------------------------------------------\n");
			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Przyk³ad  z listingu 4.15////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad15ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int wiek; 					//zmienna
	float majatek;			//zmienna
	char zwierzatko[30];	//³añcuch
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj swoj wiek, majatek i ulubione zwierzatko.\n");
			scanf("%d %f", &wiek, &majatek); //tu uzywamy znaku &
			scanf("%s", zwierzatko);					//przy tablicy znakowej nie ma &
			printf("%d, %.0f zl, %s\n", wiek, majatek, zwierzatko);
printf("------------------------------------------------------------------------------------------------------------------\n");
			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Przyk³ad  z listingu 4.16////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad16ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	unsigned szerokosc, dokladnosc;
	int liczba = 256;
	double waga = 242.5;
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			printf("Jaka szerokosc pola?\n");
			scanf("%d", &szerokosc);
			printf("Liczba jest rowna :%*d:\n", szerokosc, liczba);
			printf("Teraz podaj szerokosc i dokladnosc:\n");
			scanf("%d %d", &szerokosc, &dokladnosc);
			printf("Waga = %*.*f\n", szerokosc, dokladnosc, waga);
			printf("Gotowe!\n");
			printf("------------------------------------------------------------------------------------------------------------------\n");

			break;
		}
	return 0;
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Przyk³ad  z listingu 4.17////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad17ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	int n;
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			printf("Poadaj prosze, trzy liczby calkowite!\n");
			scanf("%*d %*d %d", &n);
			printf("Ostatnia podana liczba byla %d\n", n);
			printf("------------------------------------------------------------------------------------------------------------------\n");
			break;
		}
	return 0;
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Pytania sprawdzajace//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad18ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	
	float cena = 41.99;
	float procent = 80.0;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("On sprzedal obraz za %2.2f zlotych\n", 2.345e2);
			
			printf("%c%c%c\n", 'H', 105, '\041');
			
			printf("%s\nSklada sie z %d znakow.\n", Q, strlen(Q));
			
			printf("Czy %2.2e jest tym samym co %2.2f\n", 1201.0, 1201.0); 
			
			printf("Cena hurtowa tego egzemplarza ksiazki \"%s\" wynosi %.2f zl.\n"
				   "Jest to %.1f%% ceny hurtowej.\n", KSIAZKA, cena, procent);
			
			
			printf("------------------------------------------------------------------------------------------------------------------\n");

			break;
	}
	return 0;
}



int CVICALLBACK QuitCallback (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}
