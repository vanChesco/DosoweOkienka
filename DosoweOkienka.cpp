#include <iostream>
#include "Panel.h"
#include "Display.h"
#include <Windows.h>


int counter(Display okno)
{
	return okno.counter;
}

int main()
{
	Panel pan(6, 5, "Panel okien");
	Panel pna2(36, 5, "Ok");

	Panel kopia(pna2, "kopia");




//	Okienko(2, 3, "g", 4);									// Utworzenie obiektu bez nazwy (jawne wywolanie konstruktora)
	
//	Okienko win1 = Okienko(10, 5, "wartosc przyblizona", 4);		// Utworzenie obiektu za pomoca jawnego wywolania konstruktora
//	Okienko win2(10, 10, "wskazanie");							// Utworzenie obiektu bez ostatniej wartosci, ktora zostala zdefiniowana w konstruktorze, dlatego domyslnie jest 0
//	Okienko win3(40, 5, "inne", 4);
//	
//	Okienko win4;
//	
//	Okienko win5;
//
//	
////	win1.wpisz_wartosc(5);
////	win2.wpisz_wartosc(45);
//
//	for (int i=0; i < 10000; i++)	win2.wpisz_wartosc(i);
//
	gotoxy(1, 25);

	std::cout << &kopia  << " " << &pna2;

	return 0;
}
