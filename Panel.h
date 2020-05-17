#pragma once
#include <iostream>
#include <Windows.h>
#include <cmath>
#include "Display.h"


class Panel
{
	std::string nazwa;																	// Nazwa panelu
	int x = 0, y = 0;																	// wspolrzedne
	int width;																			// szerokosc panelu

public:

	static unsigned int panel_no;

	Panel(int x = 3, int y = 3, std::string name = "bez nazwy");						// Konstruktor
	Panel(const Panel& obiekt, std::string nazwa);										// Konstruktor kopiujacy

	void ramka(int x, int y, int width);												// Funkcja rysujaca ramke
};


unsigned int Panel::panel_no = 0;

Panel::Panel(int x, int y, std::string name) : x(x), y(x), nazwa(name)
{
	panel_no++;

	Display okienko1(x + 2, y + 2, "Okno 1", 30); 
	Display okienko2(x + 2, y + 7, "Okno 2", 45);

	if (okienko1.szerokosc() > okienko2.szerokosc()) width = okienko1.szerokosc();
	else width = okienko2.szerokosc();

	ramka(x, y, width);
}

Panel::Panel(const Panel& obiekt, std::string nazwa) 
{
	this -> nazwa = nazwa;

	ramka(obiekt.x, obiekt.y, obiekt.width);
}

void Panel::ramka(int x, int y, int width)
{
	int diff = 0;
	if (width > nazwa.size())	diff = abs(width - (int)nazwa.size());
	
	gotoxy(x, y);
	std::cout << ".==== " << nazwa << " ==" << std::string(diff, '=') << "==.";
	for (int i = 1; i < 12; i++)
	{
		gotoxy(x, y + i);							std::cout << '|';
		gotoxy(x + nazwa.size() + diff + 11, y + i);	std::cout << '|';
	}
	gotoxy(x, y + 12);
	std::cout << "|_____" << std::string(nazwa.size() + diff, '_') << "_____|";
}