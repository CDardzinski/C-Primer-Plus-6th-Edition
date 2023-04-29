#include <stdbool.h>
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ksiazka_PRATA_C_rozdzial15_cwiczenia.h"

static int panelHandle;

//do æwiczenia 1 i æwiczenia 2
int pokazLiczbeBINtoDEC(char *);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//do æwiczenia 1 i æwiczenia 2
void przerzucDECnaBIN(int wsad, char *daneWyjsciowe);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//do æwiczenia 3
int SprIleBitowJestWlaczonych (int);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//do æwiczenia 4
int SprKtoryBitJestWlaczonych (int wsad, int numerBitu);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//do æwiczenia 5
int obroc_l(int wsad, int ileRazy);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//do æwiczenia 6
struct czcionka{
	unsigned int	typ_czcionki		:8; 
	unsigned int	rozmiar_czcionki	:8;
	unsigned int	wyrownanie			:2;
	bool			wytluszczenie		:1; 
	bool			kursywa				:1;
	bool			podkreslenia 		:1;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//do æwiczenia 7
unsigned long czcionka2 = 0xFFFFFFFF;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ksiazka_PRATA_C_rozdzial15_cwiczenia.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
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
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 1 rodzial 15//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad1ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char lancuchBinarny[9];
	char *wbin;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj 8-bitowa liczbe w kodzie binarnym: ");
			scanf("%s", lancuchBinarny);
			
			wbin = lancuchBinarny;
			
			printf("Wynik w DEC: %i\n", (pokazLiczbeBINtoDEC(wbin)));

			break;
	}
	return 0;
}
int pokazLiczbeBINtoDEC(char *pobranyLancuch)
{
	int wynik;
	
	wynik = (((int)pobranyLancuch[0] - 48) * 128) + (((int)pobranyLancuch[1] - 48) * 64) + (((int)pobranyLancuch[2] - 48) * 32) + (((int)pobranyLancuch[3] - 48) * 16) + (((int)pobranyLancuch[4] - 48) * 8) + (((int)pobranyLancuch[5] - 48) * 4) + (((int)pobranyLancuch[6] - 48) * 2) + (((int)pobranyLancuch[7] - 48) * 1);
	
	return wynik;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 2 rodzial 15//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad2ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	char lancuchBinarny1[9], lancuchBinarny2[9];
	int wynik1, wynik2, negacja1, negacja2, koniunkcja, alternatywa, alternatywaWylaczajaca;
	char wynikDzialanBinarny[9];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj PIERWSZA 8-bitowa liczbe w kodzie binarnym: ");
			scanf("\t%s", lancuchBinarny1);
			
			printf("Podaj DRUGA 8-bitowa liczbe w kodzie binarnym: ");
			scanf("\t%s", lancuchBinarny2);
			
			wynik1 = pokazLiczbeBINtoDEC(lancuchBinarny1);
			wynik2 = pokazLiczbeBINtoDEC(lancuchBinarny2);
			
			negacja1 = ~wynik1;
			negacja2 = ~wynik2;
			
			koniunkcja = wynik1 & wynik2;//iloraz logiczny
			
			alternatywa = wynik1 | wynik2;//suma logiczna
			
			alternatywaWylaczajaca = wynik1 ^ wynik2;//alternatywa wy³aczajaca
			
			przerzucDECnaBIN(wynik1, wynikDzialanBinarny);
			printf("Wynik1 w systemie binarnym to \t\t\t\t\t%s\n", wynikDzialanBinarny);
			przerzucDECnaBIN(wynik2, wynikDzialanBinarny);
			printf("Wynik2 w systemie binarnym to \t\t\t\t\t%s\n", wynikDzialanBinarny);
			
			przerzucDECnaBIN(negacja1, wynikDzialanBinarny);
			printf("Zanegowany Wynik1 w systemie binarnym to \t\t\t%s\n", wynikDzialanBinarny);
			
			przerzucDECnaBIN(negacja2, wynikDzialanBinarny);
			printf("Zanegowany Wynik2 w systemie binarnym to \t\t\t%s\n", wynikDzialanBinarny);
			
			przerzucDECnaBIN(koniunkcja, wynikDzialanBinarny);
			printf("Koniunkcja Wynik1 & Wynik2 w systemie binarnym to \t\t%s\n", wynikDzialanBinarny);
			
			przerzucDECnaBIN(alternatywa, wynikDzialanBinarny);
			printf("Alternatywa Wynik1 | Wynik2 w systemie binarnym to \t\t%s\n", wynikDzialanBinarny);
			
			przerzucDECnaBIN(alternatywaWylaczajaca, wynikDzialanBinarny);
			printf("Alternatywa wylaczajaca Wynik1 ^ Wynik2 w systemie binarnym to \t%s\n", wynikDzialanBinarny);
			
			break;
	}
	return 0;
}
void przerzucDECnaBIN(int wsad, char *daneWyjsciowe)
{
	int liczba = 8*sizeof(char);
	
	for(int i = liczba - 1; i >= 0; i--, wsad>>=1)
		daneWyjsciowe[i] = (0x01 & wsad) +'0'; //zakladamy kodowanie ASCII
	
	daneWyjsciowe[liczba] = '\0';
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 3 rodzial 15//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad3ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int wartoscPobrana, wlaczoneBity;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			printf("Podaj liczbe w zakresie od 0 do 255: ");
			scanf("%d", &wartoscPobrana);
			
			printf("Liczba wlaczonych bitow: %d\n", SprIleBitowJestWlaczonych(wartoscPobrana));

			break;
	}
	return 0;
}
int SprIleBitowJestWlaczonych (int wsad)
{
	int wynik =0;
	char daneZeroJeden[9];
	int liczba = 8*sizeof(char);
	
	for(int i = liczba - 1; i >= 0; i--, wsad>>=1)
	{
		daneZeroJeden[i] = (0x01 & wsad) +'0'; //zakladamy kodowanie ASCII
		if(daneZeroJeden[i] == '1') wynik += 1;
	}

	return wynik;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 4 rodzial 15//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad4ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int wartosc = 0, numerBitu = 0;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj liczbe w zakresie od 0 do 255: ");
			scanf("%d", &wartosc);
			printf("Podaj numer bitu do sprawdzenia (od 0 (MSB) do 7(LSB)): ");
			scanf("%d", &numerBitu);
			printf("Bit numer %d liczby %d ma wartosc %d\n", numerBitu, wartosc, SprKtoryBitJestWlaczonych(wartosc, numerBitu));
			break;
	}
	return 0;
}
int SprKtoryBitJestWlaczonych (int wsad, int numerBitu)
{
	char daneZeroJeden[9];
	int liczba = 8*sizeof(char);
	
	for(int i = liczba - 1; i >= 0; i--, wsad>>=1)
		daneZeroJeden[i] = (0x01 & wsad) +'0'; //zakladamy kodowanie ASCII

	return daneZeroJeden[numerBitu]  == '1' ? 1 : 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 5 rodzial 15//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad5ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int wartosc, ileMiejscPrzesunac;
	
	switch (event)
	{
		case EVENT_COMMIT:
			printf("Podaj liczbe w zakresie od 0 do 255: ");
			scanf("%d", &wartosc);
			printf("Podaj o ile miejsc przesunac bity w lewo strone: ");
			scanf("%d", &ileMiejscPrzesunac);
			
			printf("Po obrocie bitow w lewo o %d otrzymam: %d\n", ileMiejscPrzesunac, obroc_l(wartosc,ileMiejscPrzesunac)); 
			
			break;
	}
	return 0;
}
int obroc_l(int wsad, int ileRazy) //dzia³a!!!!!!!!!!!!!!!
{
	char daneZeroJeden[ileRazy];
	int wynik = 0;
	
	for(int i = 0; i < ileRazy; i++, wsad<<=1)
		daneZeroJeden[ileRazy-i-1] = (0x80 & wsad) + 48; //zakladam ¿e wszytko jest w kodzie ASCII
	
	for(int j = ileRazy-1; j >= 0; j--)
	{
		if(daneZeroJeden[j] != '0') daneZeroJeden[j] = '1';
		wynik = (((int)daneZeroJeden[j] - 48) * (int)pow(2,j)) + wynik;
	}
	
	wsad &= 0xFF;//sprowadzanie wartoœci wsad do 8-bitowej formy
	
	return wynik+wsad;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 6 rodzial 15//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad6ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	struct czcionka ParametryCzcionki = { 1, 12, 0, false, false, false};
	char wyrowanieOpis[7], kursywaOpis[4], wytluszczenieOpis[4], podkreslenieOpis[4];
	int exit = 0, znak, temp;
	char wybor, opcje;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			do{	
				switch (ParametryCzcionki.wyrownanie)
				{
					case 0:
						strcpy(wyrowanieOpis, "lewo");
						break;
					case 1:
						strcpy(wyrowanieOpis, "srodek");
						break;
					case 2:
						strcpy(wyrowanieOpis, "prawo");
						break;
				}
				
				switch (ParametryCzcionki.wytluszczenie)
				{
					case false:
						strcpy(wytluszczenieOpis, "wyl");
						break;
					case true:
						strcpy(wytluszczenieOpis, "wl");
						break;
				}
				
				switch (ParametryCzcionki.kursywa)
				{
					case false:
						strcpy(kursywaOpis, "wyl");
						break;
					case true:
						strcpy(kursywaOpis, "wl");
						break;
				}
				
				switch (ParametryCzcionki.podkreslenia)
				{
					case false:
						strcpy(podkreslenieOpis, "wyl");
						break;
					case true:
						strcpy(podkreslenieOpis, "wl");
						break;
					default:
						break;
				}
				
				
				
				printf("Typ		Rozmiar		Wyrownanie		Wytl.		Kurs.		Podkr.\n");
				printf("%d		%d		%s			%s		%s		%s\n",
					   ParametryCzcionki.typ_czcionki, ParametryCzcionki.rozmiar_czcionki, wyrowanieOpis, wytluszczenieOpis, kursywaOpis, podkreslenieOpis); 
				
				puts("t)zmiana czcianki		r)zmiana rozmiaru	w)zmiana wyrownania");
				puts("b)przelacz wytluszczenie	i)przelacz kuryswe	u)przelacz podkreslenie");
				puts("k)wyjscie");
				
				wybor = getchar();
				
				while ((znak = getchar()) != '\n') continue;
				
				
				switch (wybor)
				{
					case 'T':
					case 't':
						printf("Wybierz typ czcionki (0-255):");
						scanf("%d", &temp);
						ParametryCzcionki.typ_czcionki = temp;
						ParametryCzcionki.typ_czcionki &= 0xFF;
						puts("");
						exit = 0;
						while ((znak = getchar()) != '\n') continue;
						break;
					case 'r':
					case 'R':
						printf("Podaj rozmiar czcionki (0-127):");
						scanf("%d", &temp);
						ParametryCzcionki.rozmiar_czcionki = temp;
						ParametryCzcionki.rozmiar_czcionki &= 0xFF;
						puts("");
						exit = 0;
						while ((znak = getchar()) != '\n') continue;
						break;
					case 'w':
					case 'W':
						puts("Wybierz wyrownanie");
						puts("l)w lewo		s)na srodek		p)w prawo");
						scanf("%c", &opcje);
						if(opcje == 'l' || opcje == 'L') ParametryCzcionki.wyrownanie = 0;
						else if(opcje == 's' || opcje == 'S') ParametryCzcionki.wyrownanie = 1;
						else if(opcje == 'p' || opcje == 'P') ParametryCzcionki.wyrownanie = 2;
						ParametryCzcionki.wyrownanie &= 0x3;
						puts("");
						exit = 0;
						while ((znak = getchar()) != '\n') continue;
						break;
					case 'b':
					case 'B':
						if(ParametryCzcionki.wytluszczenie == false) ParametryCzcionki.wytluszczenie = true;
						else ParametryCzcionki.wytluszczenie = false;
						ParametryCzcionki.wytluszczenie &= 0x1;
						exit = 0;
						break;
					case 'i':	
					case 'I':
						if(ParametryCzcionki.kursywa == false) ParametryCzcionki.kursywa = true;
						else ParametryCzcionki.kursywa = false;
						ParametryCzcionki.kursywa &= 0x1;
						exit = 0;
						break;
					case 'u':
					case 'U':
						if(ParametryCzcionki.podkreslenia == false) ParametryCzcionki.podkreslenia = true;
						else ParametryCzcionki.podkreslenia = false;
						ParametryCzcionki.podkreslenia &= 0x1;
						exit = 0;
						break;	
					case 'k':
					case 'K':
						exit = 1;
						break;
				}		
			}while (exit != 1);
			puts("Koniec programu!");
			break;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Æwiczenie 7 rodzial 15//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int CVICALLBACK Przyklad7ButtonCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	//czcionka2 = FF - typ czcionki FF - romiar czcionki F - wyrowannie (0,1,2) F- wytluszczenie(0,1) F- kursywa(0,1) F- podkreslenie(0,1)
	czcionka2 = 0x010C0000;
	
	char wyrowanieOpis[7], kursywaOpis[4], wytluszczenieOpis[4], podkreslenieOpis[4];
	int typCzcionki, rozmiarCzcionki;
	int exit = 0, znak, temp;
	char wybor, opcje;
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			do{	
				if(czcionka2 & 0x00001000) strcpy(wyrowanieOpis, "srodek");	//wyrownanie + maska do niego
				else if(czcionka2 & 0x00002000) strcpy(wyrowanieOpis, "prawo");
				else strcpy(wyrowanieOpis, "lewo");
				
				if(czcionka2 & 0x00000100) strcpy(wytluszczenieOpis, "wl"); //wytluszczenie
				else strcpy(wytluszczenieOpis, "wyl");
				
				if(czcionka2 & 0x00000010) strcpy(kursywaOpis, "wl"); //kursywa
				else strcpy(kursywaOpis, "wyl");
				
				if(czcionka2 & 0x00000001) strcpy(podkreslenieOpis, "wl");
				else strcpy(podkreslenieOpis, "wyl");
				
				typCzcionki = czcionka2 >> 24;
				typCzcionki &= 0xFF;
				
				rozmiarCzcionki = czcionka2 >> 16;
				rozmiarCzcionki &= 0XFF;
							
				
				printf("Typ		Rozmiar		Wyrownanie		Wytl.		Kurs.		Podkr.\n");
				printf("%d		%d		%s			%s		%s		%s\n",
					   typCzcionki, rozmiarCzcionki, wyrowanieOpis, wytluszczenieOpis, kursywaOpis, podkreslenieOpis); 
				
				puts("t)zmiana czcianki		r)zmiana rozmiaru	w)zmiana wyrownania");
				puts("b)przelacz wytluszczenie	i)przelacz kuryswe	u)przelacz podkreslenie");
				puts("k)wyjscie");
				
				wybor = getchar();
				
				while ((znak = getchar()) != '\n') continue;
				
				
				switch (wybor)
				{
					case 'T':
					case 't':
						printf("Wybierz typ czcionki (0-255):");
						scanf("%d", &temp);
						temp <<= 24;
						czcionka2 &= ~0xFF000000;//czyszczenie bitow typu czcionki
						czcionka2 |=temp;
						puts("");
						exit = 0;
						while ((znak = getchar()) != '\n') continue;
						break;
					case 'r':
					case 'R':
						printf("Podaj rozmiar czcionki (0-127):");
						scanf("%d", &temp);
						temp <<= 16;
						czcionka2 &= ~0x00FF0000;//czyszczenie bitow rozmiaru czcionki
						czcionka2 |=temp;
						puts("");
						exit = 0;
						while ((znak = getchar()) != '\n') continue;
						break;
					case 'w':
					case 'W':
						puts("Wybierz wyrownanie");
						puts("l)w lewo		s)na srodek		p)w prawo");
						scanf("%c", &opcje);
						czcionka2 &= ~0x0000F000; //czyœci bity wyrownanie
						if(opcje == 'l' || opcje == 'L') czcionka2 |= 0x00000000;
						else if(opcje == 's' || opcje == 'S') czcionka2 |= 0x00001000;
						else if(opcje == 'p' || opcje == 'P') czcionka2 |= 0x00002000;
						puts("");
						exit = 0;
						while ((znak = getchar()) != '\n') continue;
						break;
					case 'b':
					case 'B':
						if(czcionka2 & 0x00000100) czcionka2 &= ~0x0000F00; //czyœci bity wytluszczenie				
						else czcionka2 |= 0x00000100;
						exit = 0;
						break;
					case 'i':	
					case 'I':
						if(czcionka2 & 0x00000010) czcionka2 &= ~0x000000F0; //czyœci bity kursywy				
						else czcionka2 |= 0x00000010;
						exit = 0;
						break;
					case 'u':
					case 'U':
						if(czcionka2 & 0x00000001) czcionka2 &= ~0x000000F; //czyœci bity podkreslenia
						else czcionka2 |= 0x0000001;
						exit = 0;
						break;	
					case 'k':
					case 'K':
						exit = 1;
						break;
				}		
			}while (exit != 1);
			puts("Koniec programu!");
			
			break;
	}
	return 0;
}
