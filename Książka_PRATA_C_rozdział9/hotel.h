//Plik nag³ówkowy hotel.h listing 9.11 z rozdzia³u 9
#define KONIEC 5
#define HOTEL1 80.00
#define HOTEL2 125.00
#define HOTEL3 155.00
#define HOTEL4 200.00
#define RABAT 0.95
#define GWIAZDKI "**********************************"
//pokazuje liste wyborow
int menu(void);
//zwraca zadna liczbe nocy
int pobierz_noce(void);
//oblicza cene na podstawie stawki i liczby noclegow i wyswietla wynik
void pokaz_cene(double hotel, int noce);