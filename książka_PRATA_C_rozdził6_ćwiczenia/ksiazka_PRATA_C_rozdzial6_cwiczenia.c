#include <cvirte.h>		
#include <userint.h>
#include <ansi_c.h>
#include "ksiazka_PRATA_C_rozdzial6_cwiczenia.h"

///////////////////////////////////////////////////////////////
/////////funkcja pomocnicza do cwiczenia 9//////////////////////
//////////////////////////////////////////////////////////////
float doIRightNow(float liczba1, float liczba2);



static int panelHandle;

int main (int argc, char *argv[])
	{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial6_cwiczenia.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 1 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	char tab[26];
	char i = 'a';
	
	switch (event)
		{
		case EVENT_COMMIT:
			for(int x = 0 ; x < 26; x++)
				tab[x] = i++;
			printf("%s", tab);
			
			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 2 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	switch (event)
		{
		case EVENT_COMMIT:
			for(int i = 0; i < 5; i++)
				{
					for (int x = 0; x <= i; x++)
						printf("$");
				printf("\n");	
				}

			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 3 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
	{
	switch (event)
		{
		case EVENT_COMMIT:
			for(int i = 0; i < 6; i++)
				{
					for(char y = 'F', x = 0; x <= i ; x++)
						printf("%c", y--);		
				printf("\n");	
				}
			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 4 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char y = 'A';
	
	switch (event)
	{
		case EVENT_COMMIT:
			for(int i = 0; i < 6; i++)
				{
					for(int x = 0; x <= i ; x++)
						printf("%c", y++);		
				printf("\n");	
				}

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 5 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char znak;
	int x,y,z;// = 4;
	char abc;
	
	switch (event)
	{
		case EVENT_COMMIT:
				
				printf("Wprowadz znak: ");
				scanf("%c", &znak);
			
				for(int i = 5; i > 0; i--)
				{
					for(x = i - 2; x >= 0 ; x--)
						printf(" ");
					for(abc = 4, z = 0; z < 9 - 4 - i; z++, abc--)
						printf("%c", znak - abc);
					for(abc, y = 0; y < 9 - 3 - i; y++, abc++)
						printf("%c", znak - abc);
				printf("\n");
				}
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 6 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	int dol, gora;
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wprowadz dolna granice:  ");
			scanf("%d", &dol);
			printf("\n");
			printf("Wprowadz gorna granice:  ");
			scanf("%d", &gora);
			printf("\n");
			printf("Liczba calkowita | \tKwadrat | \tSzescian|\n");
			for(int a = dol; a <= gora; a++) printf("\t\t%d|\t\t%d|\t%d| \n", a, a*a, a*a*a);
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 7 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char slowo[20];
	int znakOstatni;
	
	switch (event)
		{
		case EVENT_COMMIT:
			printf("Wprowadz slowo: ");
			scanf("%s", slowo);
			printf("\n");
			for(znakOstatni = strlen(slowo); znakOstatni >= 0; znakOstatni--)
				printf("%c",slowo[znakOstatni]);

			break;
		}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 8 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	float liczba1, liczba2, roznica = 0.0;
	int status = 1;
	switch (event)
		{
		case EVENT_COMMIT:
			do
				{
				printf("Wpisz liczbe zmiennaprzecinkowa: (Wyjscie wpisz znak)\n");
				status = scanf("%f", &liczba1);
				printf("Wpisz druga liczbe zmiennoprzecinkowa: (Wyjscie wpisz znak)\n");
				status = scanf("%f", &liczba2);
				roznica = (liczba1 - liczba2)/(liczba1 * liczba2);
				printf("%f\n", roznica);
				}
			while(status == 1);
			printf("Wyjscie\n");

			break;
		}
	return 0;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 9 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	float liczba1, liczba2, roznica = 0.0;
	int status = 1;
	
	switch (event)
		{
		case EVENT_COMMIT:
			do
				{
				printf("Wpisz liczbe zmiennaprzecinkowa: (Wyjscie wpisz znak)\n");
				status = scanf("%f", &liczba1);
				printf("Wpisz druga liczbe zmiennoprzecinkowa: (Wyjscie wpisz znak)\n");
				status = scanf("%f", &liczba2);
				roznica =  doIRightNow(liczba1, liczba2);
				printf("%f\n", roznica);
				}
			while(status == 1);
			printf("Wyjscie\n");
			

			break;
		}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 10 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	int liczba1, liczba2;
	int poczatek, suma = 0;
	switch (event)
		{
		case EVENT_COMMIT:
			printf("Podaj dolna i gorna granice przedialu liczb calkowitych: ");
			scanf("%d %d", &liczba1, &liczba2);
			do
				{
				for(poczatek = liczba1, suma = 0; liczba1 <= liczba2; liczba1++)
					suma += liczba1*liczba1;
				printf("Suma kwadratow od %d do %d wynosi %d\n", poczatek*poczatek, liczba2*liczba2, suma);
				printf("Podaj nastepny przedzial: ");
				scanf("%d %d", &liczba1, &liczba2);
				}
			while(liczba2 > liczba1);
			printf("Koniec\n");

			break;
		}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 11 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	int liczba;
	long liczbyJakies[8];
	
	switch (event)
		{
		case EVENT_COMMIT:
			for(liczba = 0; liczba < 8; liczba++)
				{
				liczbyJakies[liczba] = rand();
				printf("%d ", liczbyJakies[liczba]);
				}
			printf("\n");
			for(liczba = 7; liczba >= 0; liczba--)
				printf("%d ", liczbyJakies[liczba]);
			printf("\n");

			break;
		}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 12 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad12ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int licznik, granica;
	double dzielnik, suma, suma1, dzielna = 1.0, dzielna1;
	switch (event)
		{
		case EVENT_COMMIT:
			printf("Ile wyrazow ciagu chcesz zsumowac?");
			scanf("%d", &granica);
			
			while (granica > 0)
				{
				for(suma = 0.0, suma1 = 0.0, licznik = 0, dzielnik = 2.0, dzielna1 = -1.0; licznik <= granica; licznik++, dzielnik += 1.0, dzielna1 *= -1.0)
					{
					suma += dzielna/dzielnik;
					suma1 += dzielna1/dzielnik;
					printf("Krok %d: suma = %f| suma1 = %f\n", licznik, suma, suma1);
					}
				printf("podaj kolejna granice (0 lub wartosc ujemna -> wyjscie)");
				scanf("%d", &granica);
				}
			printf("Koniec");

			break;
		}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 13 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad13ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int tablica[8], i, potega = 2;
	switch (event)
		{
		case EVENT_COMMIT:
			printf("Kolejne osiem poteg liczby 2\n");
		//	tablica[0] = potega;
		//	tablica[1] = potega*potega;
		//	tablica[2] = potega*potega*potega;
		//	tablica[3] = potega*potega*potega*potega;
		//	tablica[4] = potega*potega*potega*potega*potega;
		//	tablica[5] = potega*potega*potega*potega*potega*potega;
		//	tablica[6] = potega*potega*potega*potega*potega*potega*potega;
		//	tablica[7] = potega*potega*potega*potega*potega*potega*potega*potega;
			for(i = 0; i < 8; i++)
				tablica[i] = pow(potega, i); 				
			i = 0;
			do
				{
				printf("2^%d = %d\n", i, tablica[i]);
				i++;
				}
			while (i < 8);

			break;
		}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 14 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad14ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double tablica1[8];
	double tablica2[8];
	double suma = 0.0; 
	
	switch (event)
		{
		case EVENT_COMMIT:
			printf("wprowadz 8 cyfr zmiennoprzecinowych: ");
			for(int i=0; i < 7;i++)
				scanf("%lf", &tablica1[i]);
			
			for(int z=0; z < 7; z++)
				{
				suma += tablica1[z];
				tablica2[z] = suma;
				}
			for(int y = 0; y < 7; y++)
				printf("%lf\t", tablica1[y]);
			printf("\n");
			for(int a = 0; a < 7; a++)
				printf("%lf\t", tablica2[a]);
			printf("\n");
			break;
		}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 15 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad15ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char linia[255];
	int a = 0, i = 0;
	char s = ' ';
	switch (event)
		{
		case EVENT_COMMIT:
			for(int z = 0; z < 254; z++)
				linia[z] = 0;
			
			printf("wpisz jakis tekst\n");
			while(s != '\n') 
				{
					scanf("%c", &linia[i]);
					s = linia[i++];
				}
			for(a = strlen(linia); a >= 0; a--)
				printf("%c",linia[a]);
				
			break;
		}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 16 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad16ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double Ewa = 100.0, Ewa1 = 100.0, Ewa2 = 100.0;
	double Kasia = 100.0, Kasia1 = 100.0;
	int lata = 0;
	
	switch (event)
		{
		case EVENT_COMMIT:
			while (Kasia1 <= Ewa2)
				{
				Ewa1 = (Ewa * 1.1) - Ewa;
				Ewa2 += Ewa1;
				Kasia = (Kasia1 * 1.05) - Kasia1;
				Kasia1 += Kasia; 
				lata++;
				}
			printf("Kasia zarobi wiecej od Ewy po %d lat\n", lata);
			printf("Kasia bedzie miala %lf PLN\n", Kasia1);
			printf("Ewa bedzi miala %lf PLN\n", Ewa2);

			break;
		}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 17 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad17ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double Jim = 0.0, Jim1 = 1000000.0;
	int lata = 0;
	switch (event)
		{
		case EVENT_COMMIT:
			while (Jim1 >= 0.0)
				{
					Jim = (Jim1 * 1.08) - Jim1;
					Jim1 += Jim;
					printf("Przed wyplata po roku oprocenotowanie 8%% - > %lf\n", Jim1);
					Jim1 = Jim1 - 100000.0;
					lata++;
					printf("Po wyplacie 100000 $ - > %lf\n", Jim1);
				}
			printf("Jim wyczysci swoje konto po %d lat\n", lata);

			break;
		}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////æwiczenie 18 rodzial 6/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad18ButtonCallback (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	int liczbaDunbara = 150;
	int ProfPop = 5;
	int tygodnie = 0;
	
	switch (event)
		{
		case EVENT_COMMIT:
			
			while (ProfPop < liczbaDunbara)
				{
					ProfPop -= ++tygodnie;
					ProfPop = ProfPop * 2;
					printf("W tygodniu %d Profesor popularny mial %d znajomych.\n", tygodnie, ProfPop);
				}
			printf("W tygodniu %d liczba znajomych przekoroczyla liczbe Dunbara i wynosi %d!\n", tygodnie, ProfPop);

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
///////////////////////////////////////////////////////////////
/////////funkcja pomocnicza do cwiczenia 9//////////////////////
//////////////////////////////////////////////////////////////
float doIRightNow(float liczba1, float liczba2)
{
	float roznica;
	roznica = (liczba1 - liczba2)/(liczba1 * liczba2);
	return roznica;
}
