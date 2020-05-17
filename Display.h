#pragma once
#include <iostream>
#include <Windows.h>

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


class Display
{
	int x, y;																			// Pozycja okienka
	int wartosc;																		// wskazywana wartosc
	static unsigned int counter;														// licznik obiektow
	std::string nazwa;																	// nazwa okienka

public:

	const int r = 234;

	Display(int xx, int yy, std::string name = "bez nazwy", int value = 0);				// Konstruktor okienka; ostatni argument domniemany, wiec mozna go pominac w konstruktorze
	Display(void);																		// Konstruktor domniemany
	~Display();																			// Destruktor

	void draw();																		// Funkcja rysujaca okienko
	void wpisz_wartosc(int val);														// dopisanie wartosci do tabelki

	int wysokosc();																		// Funkcja zwracajaca wysokosc utworzonego displaya
	int szerokosc();																	// Funkcja zwracajaca szerokosc utworzonego displaya
	friend int counter(Display);
};






int unsigned Display::counter;

Display::Display(int x, int y, std::string name, int value) : x(x), y(y), nazwa(name), wartosc(value)
{
	counter++;

//	this -> x = x;										//
//	this -> y = y;										//	Zamiast nadawania wartosci w ten sposob, uzyta zostala lista incjalizacyjna powyzej
//			nazwa = name;									//
//			wartosc = value;								//

	draw();
}

Display::Display()
{
	counter++;

	nazwa = "bez nazwy";
	x = 10;
	y = 20;
	wartosc = 0;

	draw();
}

Display::~Display()
{
	counter--;
}

void Display::draw()
{
	std::string wypelnienie(nazwa.size(), ' ');
	std::string ramka(nazwa.size(), '_');

	gotoxy(x, y);
	std::cout << ".== " << nazwa << " ==.";
	gotoxy(x, y + 1);
	std::cout << "|    " << wypelnienie << "  |";
	gotoxy(x, y + 2);
	std::cout << "|    " << wypelnienie << "  |";
	gotoxy(x, y + 3);
	std::cout << "|___" << ramka << "___|";

	wpisz_wartosc(wartosc);
}

void Display::wpisz_wartosc(int val)
{
	wartosc = val;
	gotoxy(x + 2 + nazwa.size() / 2, y + 2);
	std::cout << "V: " << wartosc;
}


int Display::wysokosc()
{
	return 4;
}

int Display::szerokosc()
{
	return nazwa.size();
}