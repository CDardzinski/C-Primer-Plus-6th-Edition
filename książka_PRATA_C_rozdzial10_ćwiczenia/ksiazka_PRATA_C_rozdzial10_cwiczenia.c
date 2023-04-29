#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial10_cwiczenia.h"

/////do cwiczenia 1
#define LATA 5
#define MIESIACE 12
///////////////////////////

////////do æwiczenia 2
void kopiuj_tab(double zrodlo[], double cel[], int wielkosc);
void kopiuj_wsk(double zrodlo[], double cel[], int wielkosc);
void kopiuj_wsk2(double zrodlo[], double cel[], int wielkosc);
/////////////////////////////////////////////////////////////////

///////do æwieczenia 3
double MaxValue(double zrodlo[], int wielkosc);
/////////////////////////////////////////////////////////////////

///////do æwieczenia 4
int IndexMaxValue(double zrodlo[], int wielkosc);
/////////////////////////////////////////////////////////////////

///////do æwieczenia 5
double DiffrenceBetwenMaxMin(double zrodlo[], int wielkosc);
/////////////////////////////////////////////////////////////////

///////do æwieczenia 6
#define WIELKOSC 10
void TurnOver(double zrodlo[], double cel[], int wielkosc);
/////////////////////////////////////////////////////////////////

///////do æwieczenia 7
#define WIERSZE 3
/////////////////////////////////////////////////////////////////

///////do æwieczenia 9
#define WERSY 3
#define KOLUMNY 5
void CopyTable(int n, int m, double source[n][m], double target[*][*]);
void ShowTable(int n, int m, double array[n][m]);
/////////////////////////////////////////////////////////////////

///////do æwieczenia 10
#define ELEMENTY 4
void SumujDwieTablice(int k, int tablica1[k], int tablica2[k], int sumaTablica1i2[k]);
/////////////////////////////////////////////////////////////////

///////do æwieczenia 11
void ShowIntTable(int n, int m, int array[n][m]);
void DoublingIntArray(int t, int r, int source[t][r], int target[t][r]);
/////////////////////////////////////////////////////////////////

///////do æwieczenia 12
float SumujMiesiace(int rok, int miesiac, float tabela[rok][miesiac]);
float SumujRoczneOpady(int rok, int miesiac, float tabela[rok][miesiac]);
/////////////////////////////////////////////////////////////////

///////do æwieczenia 13
void SaveToArray(int z, int x, double Array[z][x]);
double AvangeOne(double Array[], int size);
double AllArrayAve(int z, int x, double Array[z][x]);
double MaxArrayValue(int z, int x, double array[z][x]);

double AllArrayAvenAllTable(double Array[3][5]);
double MaxArrayValueAllTable(double Array[3][5]);
/////////////////////////////////////////////////////////////////

static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial10_cwiczenia.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 1 rodzial 10//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	//inicjalizacja danych o opadach z lat 2010 - 2014
	const float deszcz[LATA][MIESIACE] = 
		{
			{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
			{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
			{9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
			{7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
			{7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2},
		};
	int rok, miesiac;
	float podsuma, suma;
	float *wsk;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf(" ROK		OPADY (w calach)\n");
			
			wsk = deszcz;
			
			for(rok = 0, suma = 0; rok < LATA; rok++)
			{	//dla ka¿dego roku sumuj opady dla kazdego miesiaca
				for(miesiac = 0, podsuma = 0; miesiac < MIESIACE; miesiac++)
					podsuma += *wsk++;
					//podsuma += deszcz[rok][miesiac];
				printf("%5d %12.1f\n", 2010+rok, podsuma);
				suma += podsuma; //suma dla wszystkich lat
			}
			printf("\nRoczna srednia wynosi %.1f cale\n\n", suma/LATA);
			printf("SREDNIE MIESIECZNE:\n\n");
			printf(" Sty	Lut	Mar	Kwi	Maj	Cze	Lip	Sie	Wrz	Paz	Lis	Gru\n");
			
			for(miesiac = 0; miesiac < MIESIACE; miesiac++)
			{	//dla kazdego miesiaca, sumuj opady w ciagu lat
				for(rok = 0, podsuma = 0; rok < LATA; rok++)
					podsuma += *(*(deszcz + rok) + miesiac);
					//podsuma += deszcz[rok][miesiac];
				printf("%4.1f	",podsuma/LATA);
			}
			printf("\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 2 rodzial 10//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double zrodlo[5] = { 1.1, 2.2, 3.3, 4.4, 5.5};
	double cel1[5];
	double cel2[5];
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Tablica poczatkowa:\t");
			for(int i = 0; i < 5; i++)
				printf("%.2lf\t", zrodlo[i]);
			printf("\n");
			
			kopiuj_tab(zrodlo, cel1, 5);
			printf("Tablica Cel1:\t\t");
			for(int i = 0; i < 5; i++)
				printf("%.2lf\t", cel1[i]);
			printf("\n");
			
			kopiuj_wsk(zrodlo, cel2, 5);
			printf("Tablica Cel2:\t\t");
			for(int i = 0; i < 5; i++)
				printf("%.2lf\t", cel2[i]);
			printf("\n");		

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 3 rodzial 10//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const double tabela[5] = {2.4, 1.1, 8.5, 1.9, 5.7};
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Tablica poczatkowa:\t");
			for(int i = 0; i < 5; i++)
				printf("%.2lf\t", tabela[i]);
			printf("\n");

			printf("Najwyzsza wartosc w tabeli to %.1lf\n", MaxValue(tabela, 5));
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 4 rodzial 10//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const double tabela[5] = {2.4, 1.1, 8.5, 1.9, 5.7};
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Tablica poczatkowa:\t");
			for(int i = 0; i < 5; i++)
				printf("%.2lf\t", tabela[i]);
			printf("\n");
			
			printf("Index najwyzszej wartosc w tabeli to %d\n", IndexMaxValue(tabela, 5));

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 5 rodzial 10//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const double tabela[5] = {2.4, 1.1, 8.5, 1.9, 5.7};
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Tablica poczatkowa:\t");
			for(int i = 0; i < 5; i++)
				printf("%.2lf\t", tabela[i]);
			printf("\n");
			
			printf("Roznica pomiedzy najwieksza a najmniejsza wartosc w tabeli to %.2lf\n", DiffrenceBetwenMaxMin(tabela, 5));

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 6 rodzial 10//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	//const double tabela[5] = {2.4, 1.1, 8.5, 1.9, 5.7};
	const double tabela[WIELKOSC] = {2.4, 1.1, 8.5, 1.9, 5.7, 5.8, 9.1, 2.8, 3.7, 4.4};
	double tabela2[WIELKOSC];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Tablica poczatkowa:\t");
			for(int i = 0; i < WIELKOSC; i++)
				printf("%.2lf\t", tabela[i]);
			printf("\n");
			
			TurnOver(tabela, tabela2, WIELKOSC);
			
			printf("Tablica po odwroceniu:\t");
			for(int i = 0; i < WIELKOSC; i++)
				printf("%.2lf\t", tabela2[i]);
			printf("\n");
			

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 7 rodzial 10//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const double tabela[WIERSZE][WIELKOSC] = {{2.4, 1.1, 8.5, 1.9, 5.7, 5.8, 9.1, 2.8, 3.7, 4.4},
																		{1.2, 5.8, 8.9, 7.6, 6.2, 3.7, 2.4, 2.5, 7.9, 5.5},
																		{3.7, 8.7, 9.9, 1.1, 1.6, 6.7, 8.9, 4.7, 6.1, 3.9}};
	double tabela2[WIERSZE][WIELKOSC];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Tablica poczatkowa:\t");
			for(int n = 0; n < WIERSZE; n++)
			{
				for(int i = 0; i < WIELKOSC; i++)
					printf("%.2lf\t", tabela[n][i]);
				printf("\n");
				printf("\t\t\t");
			}
			printf("\n");
			
			kopiuj_tab(tabela[0], tabela2[0], WIELKOSC);
			kopiuj_tab(tabela[1], tabela2[1], WIELKOSC);
			kopiuj_tab(tabela[2], tabela2[2], WIELKOSC);
			
			printf("Tablica skopiowana:\t");
			for(int n = 0; n < WIERSZE; n++)
			{
				for(int i = 0; i < WIELKOSC; i++)
					printf("%.2lf\t", tabela2[n][i]);
				printf("\n");
				printf("\t\t\t");
			}
			printf("\n");
			
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 8 rodzial 10//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad8ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const double tab1[7] = { 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
	double tab2[3];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Tablica poczatkowa:\t");
			for(int i = 0; i < 7; i++)
				printf("%.2lf\t", tab1[i]);
			printf("\n");
			
			kopiuj_tab(tab1+2, tab2, 3);
			
			printf("Tablica skopiowana:\t");
			for(int i = 0; i < 3; i++)
				printf("%.2lf\t", tab2[i]);
			printf("\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 9 rodzial 10//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad9ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	const double zaz1[WERSY][KOLUMNY] = {	{1.0, 2.0, 3.0, 4.0, 5.0},
											{6.0, 7.0, 8.0, 9.0, 10.0},
											{11.0, 12.0, 13.0, 14.0, 15.0}};
	int n = 3;
	int m = 5;
	double zaz2[n][m];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Tablica poczatkowa:\t");
			
			ShowTable( n, m, zaz1);
			printf("\n");
			
			CopyTable(n, m, zaz1, zaz2);
			
			printf("Tablica skopiowana:\t");
			
			ShowTable( n, m, zaz2);
			
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 10 rodzial 10//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad10ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int n = ELEMENTY;
	
	const int tab1[ELEMENTY] = {2, 4, 5, 8};
	const int tab2[ELEMENTY] = {1, 0, 4, 6};
	int sumaTab1Tab2[ELEMENTY];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Tablica 1:\t");
			for(int z = 0; z < n; z++)
				printf("%d\t", tab1[z]);
			printf("\n");
			
			printf("Tablica 2:\t");
			for(int z = 0; z < n; z++)
				printf("%d\t", tab2[z]);
			printf("\n");
			
			SumujDwieTablice(n, tab1, tab2, sumaTab1Tab2);
			
			printf("Suma tablic:\t");
			for(int z = 0; z < n; z++)
				printf("%d\t", sumaTab1Tab2[z]);
			printf("\n");

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 11 rodzial 10//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad11ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int array[WERSY][KOLUMNY];
	int a = WERSY;
	int b = KOLUMNY;
	int targetArray[WERSY][KOLUMNY];
		
	switch (event)
	{
		case EVENT_COMMIT:
			
			for(int j = 0; j < WERSY; j++)
				for(int y = 0; y < KOLUMNY; y++)
					array[j][y] = rand();
			
			printf("Tabela poczatkowa:\t");
			ShowIntTable(a, b, array);
			
			DoublingIntArray(a, b, array, targetArray);
			
			printf("\nTabela podwojona:\t");
			ShowIntTable(a, b, targetArray);
			

			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 12 rodzial 10//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad12ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	//inicjalizacja danych o opadach z lat 2010 - 2014
	const float deszcz[LATA][MIESIACE] = 
		{
			{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
			{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
			{9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
			{7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
			{7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2},
		};
	int rok = LATA;
 	int miesiac = MIESIACE;
	float suma;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf(" ROK		OPADY (w calach)\n");
			
			suma = SumujMiesiace(rok, miesiac, deszcz);
			
			printf("\nRoczna srednia wynosi %.1f cale\n\n", suma/LATA);
			printf("SREDNIE MIESIECZNE:\n\n");
			printf(" Sty	Lut	Mar	Kwi	Maj	Cze	Lip	Sie	Wrz	Paz	Lis	Gru\n");
			
			SumujRoczneOpady(rok, miesiac, deszcz);
			
			printf("\n");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 13 rodzial 10//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad13ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	double FirstTab[3][5];
	int z = 3;
	int x = 5;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			SaveToArray(z, x, FirstTab);
			
			for(int s = 0; s < z; s++)
				printf("Srednia dla wiersza %d wynosi %.2lf\n", s, AvangeOne(FirstTab[s], x));
			
			printf("Srednia dla wrzystkich wartosci wynosi %.2lf\n", AllArrayAve(z, x, FirstTab));
			
			printf("Srednia dla wrzystkich wartosci wynosi %.2lf\n", AllArrayAvenAllTable(FirstTab));//do æwiczenia 14
			
			printf("Najwieksza wartosc sposrod wszystkich wartosci to %.2lf\n", MaxArrayValue(z, x, FirstTab));		  
			
			printf("Najwieksza wartosc sposrod wszystkich wartosci to %.2lf\n", MaxArrayValueAllTable(FirstTab));//do æwiczenia 14

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

////////funkcje do æwiczenia 2
void kopiuj_tab(double zrodlo[], double cel[], int wielkosc)
{
	for(int i = 0; i < wielkosc; i++)
		cel[i] = zrodlo[i];
}
void kopiuj_wsk(double zrodlo[], double cel[], int wielkosc)
{
	for(int i = 0; i < wielkosc; i++)
		*cel++ = *zrodlo++;
}

////////funkcje do æwiczenia 3
double MaxValue(double zrodlo[], int wielkosc)
{
	double FoundedMax = 0.0;
	
	for(int i = 0; i < wielkosc; i++)
		if(FoundedMax < zrodlo[i])
				FoundedMax = zrodlo[i];
				
	return FoundedMax;
}
////////funkcje do æwiczenia 4
int IndexMaxValue(double zrodlo[], int wielkosc)
{
	int Index = 0;
	double FoundedMax = 0.0;
	
	for(int i = 0; i < wielkosc; i++)
		if(FoundedMax < zrodlo[i])
		{
			FoundedMax = zrodlo[i];
			Index = i;	
		}
	
	return Index;
}
////////funkcje do æwiczenia 5
double DiffrenceBetwenMaxMin(double zrodlo[], int wielkosc)
{
	double FoundedMax = zrodlo[0];
 	double FoundedMin = zrodlo[0];
	
	for(int i = 0; i < wielkosc; i++)
	{
		if(FoundedMax < zrodlo[i])
				FoundedMax = zrodlo[i];
		if(FoundedMin > zrodlo[i])
				FoundedMin = zrodlo[i];
	}
	return FoundedMax - FoundedMin;
}
////////funkcje do æwiczenia 6
void TurnOver(double zrodlo[], double cel[], int wielkosc)
{
	for(int i = 0; i < wielkosc; i++)
		cel[(wielkosc-1) - i] = zrodlo[i];
}
////////funkcje do æwiczenia 9
void CopyTable(int n, int m, double source[n][m], double target[n][m])
{
	for(int z = 0; z < n; z++)
		for(int i = 0; i < m; i++)
			target[z][i] = source[z][i];	
}
void ShowTable(int n, int m, double array[n][m])
{
	for(int i = 0; i < n; i++)
		{
			for(int h = 0; h < m; h++)
				printf("%.2lf\t", array[i][h]);
			printf("\n");
			printf("\t\t\t");
		}
}
////////funkcje do æwiczenia 10
void SumujDwieTablice(int k, int tablica1[k], int tablica2[k], int sumaTablica1i2[k])
{
	for(int l = 0; l < k; l++)
		sumaTablica1i2[l] = tablica1[l] + tablica2[l];
}
////////funkcje do æwiczenia 11
void ShowIntTable(int n, int m, int array[n][m])
{
	for(int i = 0; i < n; i++)
		{
			for(int h = 0; h < m; h++)
				printf("%d\t", array[i][h]);
			printf("\n");
			printf("\t\t\t");
		}
}
void DoublingIntArray(int t, int r, int source[t][r], int target[t][r])
{
	for(int i = 0; i < t; i++)
		{
			for(int h = 0; h < r; h++)
				target[i][h] = 2*source[i][h];
		}
}
////////funkcje do æwiczenia 12
float SumujMiesiace(int rok, int miesiac, float tabela[rok][miesiac])
{
	float podsuma, suma;
	
	for(rok = 0, suma = 0; rok < LATA; rok++)
			{	//dla ka¿dego roku sumuj opady dla kazdego miesiaca
				for(miesiac = 0, podsuma = 0; miesiac < MIESIACE; miesiac++)
					podsuma += tabela[rok][miesiac];
				printf("%5d %12.1f\n", 2010+rok, podsuma);
				suma += podsuma; //suma dla wszystkich lat
			}
	return suma;
}
float SumujRoczneOpady(int rok, int miesiac, float tabela[rok][miesiac])
{
	float podsuma;
	
	for(miesiac = 0; miesiac < MIESIACE; miesiac++)
			{	//dla kazdego miesiaca, sumuj opady w ciagu lat
				for(rok = 0, podsuma = 0; rok < LATA; rok++)
					podsuma += tabela[rok][miesiac];
				printf("%4.1f	",podsuma/LATA);
			}
	return podsuma;		
}
////////funkcje do æwiczenia 13
void SaveToArray(int z, int x, double Array[z][x])
{
	printf("Prosze podac trzy zbiory po piec liczb zmiennoprzecinkowych:\t");
			for(int h = 0; h < z; h++)
				for(int u = 0; u < x; u++)
					scanf("%lf", &Array[h][u]);
}
double AvangeOne(double Array[], int size)
{
	double sum = 0.0;
	for(int j = 0; j < size; j++)
		sum += Array[j];
	return (sum/size);
}
double AllArrayAve(int z, int x, double Array[z][x])
{
	double Aveg = 0.0 ;
	int counter = 0;
	for(int h = 0; h < z; h++)
		for(int u = 0; u < x; u++)
		{
			Aveg += Array[h][u];
			counter++;
		}
	return Aveg/counter;
}
double MaxArrayValue(int z, int x, double array[z][x])
{
	double MaxVal = 0.0 ;

	for(int h = 0; h < z; h++)
		for(int u = 0; u < x; u++)
			if(MaxVal < array[h][u])
				MaxVal = array[h][u];
		
	return MaxVal;
}

double AllArrayAvenAllTable(double Array[3][5])
{
	double Aveg = 0.0 ;
	int counter = 0;
	for(int h = 0; h < 3; h++)
		for(int u = 0; u < 5; u++)
		{
			Aveg += Array[h][u];
			counter++;
		}
	return Aveg/counter;
}
double MaxArrayValueAllTable(double Array[3][5])
{
	double MaxVal = 0.0 ;

	for(int h = 0; h < 3; h++)
		for(int u = 0; u < 5; u++)
			if(MaxVal < Array[h][u])
				MaxVal = Array[h][u];
		
	return MaxVal;
}