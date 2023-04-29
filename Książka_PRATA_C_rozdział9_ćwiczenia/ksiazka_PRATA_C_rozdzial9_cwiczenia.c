#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial9_cwiczenia.h"

static int panelHandle;

/////do æwiczenia 1
double min(double x, double y);
/////////////////////////////////////////////////////////

/////do æwiczenia 2
int rzad_zn(char ch, int i, int j);
/////////////////////////////////////////////////////////

/////do æwiczenia 3
int wiersz(char znak, int liczbaZnakow, int liczbaWierszy);
/////////////////////////////////////////////////////////

/////do æwiczenia 4
double sredniaHarmoniczna(double liczba1, double liczba2);
/////////////////////////////////////////////////////////

/////do æwiczenia 5
void wieksze_od(double *liczba1, double *liczba2);
/////////////////////////////////////////////////////////

/////do æwiczenia 6
void porzadek(double *najmniejsza, double *srodkowa, double *najwieksza);
/////////////////////////////////////////////////////////

/////do æwiczenia 7
int numerWalfabecie(char znak);
/////////////////////////////////////////////////////////

/////do æwiczenia 8
double potega(double a, int b);
/////////////////////////////////////////////////////////

/////do æwiczenia 9
double potegaRekurencja(double a, int b);
/////////////////////////////////////////////////////////

/////do æwiczenia 10
void do_podst_n(unsigned long n, unsigned int System);
/////////////////////////////////////////////////////////

/////do æwiczenia 11
unsigned long Fibonacci(unsigned n);
/////////////////////////////////////////////////////////

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial9_cwiczenia.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 1 rodzial 9//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double x, y, wynik;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj dwie liczby zmiennoprzecinkowe:\t");
			if((scanf("%lf %lf", &x, &y)) == 2)
			{
				wynik = min(x , y);
				printf("\n");
				printf("Wieksze jest %.2lf\n", wynik);
			}

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 2 rodzial 9//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char znak = 0;
	int startKolumny = 0, stopKolumny = 0;
	switch (event)
	{
		case EVENT_COMMIT:
			printf("podaj jakis znak do wypisania:\t");
		
			scanf("%c", &znak);
			
			if(znak == '\n')
				scanf("%c", &znak);
			
			printf("\n");
			printf("podaj od ktorej kolumny ma zostac wyswietlony:\t");
			scanf("%d", &startKolumny);
			printf("\n");
			printf("podaj na ktorej kolumnie ma konczyc sie wyswietlanie:\t");
			scanf("%d", &stopKolumny);
				
			printf("\n");
			rzad_zn(znak, startKolumny, stopKolumny);
			
			printf("\n");
			printf("Koniec\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 3 rodzial 9//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char znak = 0;
	int ZnakiWwierszu = 0, Wiersze = 0;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("podaj jakis znak do wypisania:\t");
			
			scanf("%c", &znak);
			
			if(znak == '\n')
				scanf("%c", &znak);
			
			printf("\n");
			printf("podaj ile ma byc znakow wyswietlonych w wierszu:\t");
			scanf("%d", &ZnakiWwierszu);
			printf("\n");
			printf("ile ma byc wyswietlonych wierszy:\t");
			scanf("%d", &Wiersze);
				
			printf("\n");
			wiersz(znak, ZnakiWwierszu, Wiersze);
			
			printf("\n");
			printf("Koniec.\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 4 rodzial 9//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double liczba1, liczba2;
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("podaj dwie liczby zmiennoprzecinkowe:\t");
			
			scanf("%lf %lf", &liczba1, &liczba2);
			printf("\n");
			
			printf("Wyliczona srednia harmoniczna: %lf", sredniaHarmoniczna(liczba1, liczba2));
			
			printf("\n");
			printf("Koniec.\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 5 rodzial 9//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double x, y;
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("podaj dwie liczby zmiennoprzecinkowe:\t");
			
			scanf("%lf %lf", &x, &y);
			printf("\n");
			
			wieksze_od(&x, &y);
			
			printf("Zmania obu na wieksza z nich: %.3lf %.3lf", x, y);
			
			printf("\n");
			printf("Koniec.\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 6 rodzial 9//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double x, y, z;
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("podaj trzy liczby zmiennoprzecinkowe:\t");
			
			scanf("%lf %lf %lf", &x, &y, &z);
			printf("\n");
			
			porzadek(&x, &y, &z);
			
			printf("Kolejno od najmniejszej do najwiekszej: %.3lf %.3lf %.3lf", x, y, z);
			
			printf("\n");
			printf("Koniec.\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 7 rodzial 9//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char znak;
	int status;
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Wpisz jakis tekst:\n");
			
			while((znak = getchar()) != '&')
				status = numerWalfabecie(znak);
				
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 8 rodzial 9//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double x, xpot;
	int n;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj liczbe oraz potege naturalna, ");
			printf("do ktorej podniesiona\nzostanie liczba. Wpisz q, ");
			printf("aby zakonczyc program.\n");
			while (scanf("%lf%d", &x, &n) == 2)
			{
				xpot = potega(x, n); //wywolanie funkcji
				printf("%.3g do potegi %d to %.5g\n", x, n, xpot);
				printf("Podaj kolejna pare liczb lub wpisz q, aby zakonczyc.\n");
			}
			printf("Zycze milego dnia!\n");			

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 9 rodzial 9//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double x, xpot;
	int n;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj liczbe oraz potege naturalna, ");
			printf("do ktorej podniesiona\nzostanie liczba. Wpisz q, ");
			printf("aby zakonczyc program.\n");
			while (scanf("%lf%d", &x, &n) == 2)
			{
				xpot = potegaRekurencja(x, n); //wywolanie funkcji
				printf("%.3g do potegi %d to %.5g\n", x, n, xpot);
				printf("Podaj kolejna pare liczb lub wpisz q, aby zakonczyc.\n");
			}
			printf("Zycze milego dnia!\n");			


			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 10 rodzial 9//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	unsigned long liczba;
	unsigned int systemLiczbowy;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj liczbe calkowita i system liczbowy (2-10) na jaki ma byæ przeliczony (q konczy program):\n");
			while (scanf("%ld %d", &liczba, &systemLiczbowy) == 2)
			{
				printf("odpowiednik w systemie: ");
				do_podst_n(liczba, systemLiczbowy);
				putchar('\n');
				printf("Podaj liczbe calkowita (q konczy program):\n");
			}
			printf("Gotowe.\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 11 rodzial 9//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	unsigned int liczba, suma;
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj ile krokow ciagu fibonnaciego ma byc wyliczonych :\n");
			while (scanf("%ld", &liczba) == 1)
			{
				suma = Fibonacci(liczba);
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

////////////////////////////funkcja do æwiczenia 1
double min(double x, double y)
{
	return (x > y ? x : y);	
}

////////////////////////////funkcja do æwiczenia 2
int rzad_zn(char ch, int i, int j)
{
	for(int a = 1; a <= j; a++)
	{
		if(a >= i) printf("%c", ch);
		else printf("%d", a);
	}	
		return 0;
}

////////////////////////////funkcja do æwiczenia 3
int wiersz(char znak, int liczbaZnakow, int liczbaWierszy)
{
	for(int nowaLinia = 1; nowaLinia <= liczbaWierszy; nowaLinia++)
	{
		for(int nowyZnak = 1; nowyZnak <= liczbaZnakow; nowyZnak++)
			printf("%c", znak);
		printf("\n");
	}
	return 0;
}

////////////////////////////funkcja do æwiczenia 4
double sredniaHarmoniczna(double liczba1, double liczba2)
{
	double wyliczonaSrednia;
	return wyliczonaSrednia = 1.0/(((1.0/liczba1) + (1.0/liczba2))/2.0);
}

////////////////////////////funkcja do æwiczenia 5
void wieksze_od(double *liczba1, double *liczba2)
{
	if(*liczba1 > *liczba2)
		*liczba2 = *liczba1;
	else
		*liczba1 = *liczba2;
}

////////////////////////////funkcja do æwiczenia 6
void porzadek(double *najmniejsza, double *srodkowa, double *najwieksza)
{
	double temp1;
	if(*najmniejsza > *najwieksza)
	{
		temp1 = *najwieksza;
		*najwieksza = *najmniejsza;
		*najmniejsza = temp1;
	}
	
	if(*srodkowa > *najwieksza)
	{
		temp1 = *najwieksza;
		*najwieksza = *srodkowa;
		*srodkowa = temp1; 
	}
	if(*najmniejsza > *srodkowa)
	{
		temp1 = *srodkowa;
		*srodkowa = *najmniejsza;
		*najmniejsza = temp1;
	}
}

////////////////////////////funkcja do æwiczenia 7
int numerWalfabecie(char znak)
{
	int status, czyLitera;
	
	if((czyLitera = isalpha(znak)) != 0)
	{
		if(islower(znak))
			status = znak - 96;
		else
			status = znak - 64;
		
		printf("%c jest litera, jej numer to %d\n", znak, status);
	}
	else
	{
		status = -1;
		printf("%c  nie jest litera, jej status to %d\n", znak, status);
	}
	return status;
}

////////////////////////////funkcja do æwiczenia 8
double potega(double a, int b)
{
	double pot = 1;
	int i;
	
	if(b > 0)
	{
		for(i = 1; i <= b; i++)
			pot *= a;
	}
	if(b < 0)
	{
		for(i = -1; i >= b; i--)
			pot *= 1.0/a;
	}
	if((a == 0.0) && (b == 0))
	{
		printf("%lf podniesiony do potegi %d nie zadzia³a, zamiast 0 uzywam 1\n", a, b);
		b = 1;	
	}
	if((a == 0.0) && (b != 0))
		pot = 0.0;
	if(b == 0)
		pot = 1.0;
	
	return pot; //zwrot wartosci pot
}

////////////////////////////funkcja do æwiczenia 9
double potegaRekurencja(double a, int b)
{
	double pot;
	
	if(b > 1)
		pot = a * potegaRekurencja(a , b-1);
	else if(b < -1)
		pot = 1.0/a * potegaRekurencja(a , b+1);	
	else if(b == -1)
		pot = 1.0/a;
	else if(b == 1)	
		pot = a;
		
	if((a == 0.0) && (b == 0))
	{
		printf("%lf podniesiony do potegi %d nie zadziala, zamiast 0 uzywam 1\n", a, b);
		b = 1;	
	}
	if((a == 0.0) && (b != 0))
		pot = 0.0;
	if(b == 0)
		pot = 1.0;
	
	return pot; //zwrot wartosci pot
}

////////////////////////////funkcja  do æwiczenia 10
void do_podst_n(unsigned long n, unsigned int System)
{
	int r;
	r = n % System;
	if(n >= System)
		do_podst_n(n/System, System);
	printf("%d", r);
	return;
}

////////////////////////////funkcja  do æwiczenia 10
unsigned long Fibonacci(unsigned n)
{
	unsigned long sum = 1, sum1 = 0;
	for(int i = 0; i <= n; i++)
	{
		sum1 = sum + sum1;
		sum = sum1 - sum;		
		printf("%ld\t", sum);
	}
	printf("\n");
	return sum;
}