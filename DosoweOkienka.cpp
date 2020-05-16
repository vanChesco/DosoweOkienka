#include <iostream>
#include <Windows.h>

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


class Okienko
{
	int x, y;													// Pozycja okienka
	std::string nazwa;											// nazwa okienka
	int wartosc;												// wskazywana wartosc
	static unsigned int counter;								// licznik obiektow

public:

	const int r = 234;

	Okienko(int xx, int yy, std::string name, int value = 0);	// Konstruktor okienka; ostatni argument domniemany, wiec mozna go pominac w konstruktorze
	Okienko();													// Konstruktor domniemany
	~Okienko();													// Destruktor

	void draw();												// Funkcja rysujaca okienko
	void wpisz_wartosc(int val);								// dopisanie wartosci do tabelki

	friend int funkcja(Okienko);
	friend int counter(Okienko);
};

int unsigned Okienko::counter;

Okienko::Okienko(int x, int y, std::string name, int value )
{
	counter++;

	this -> x = x;
	this -> y = y;
			nazwa = name;
			wartosc = value;

	draw();
}

Okienko::Okienko()
{
	counter++;

	nazwa = "bez nazwy";
	x = 10;
	y = 20;
	wartosc = 0;

	draw();
}

Okienko::~Okienko()
{
	counter--;
}

void Okienko::draw()
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

void Okienko::wpisz_wartosc(int val)
{
	wartosc = val;
	gotoxy(x + 2 + nazwa.size() / 2, y + 2);
	std::cout << "V: " << wartosc;
}

int funkcja(Okienko okno)
{
	return okno.x;
}

int counter(Okienko okno)
{
	return okno.counter;
}

int main()
{
	//	Okienko(2, 3, "g", 4);									// Utworzenie obiektu bez nazwy (jawne wywolanie konstruktora)
	
	Okienko win1 = Okienko(10, 5, "wartosc przyblizona", 4);	// Utworzenie obiektu za pomoca jawnego wywolania konstruktora
	Okienko win2(10, 10, "wskazanie");							// Utworzenie obiektu bez ostatniej wartosci, ktora zostala zdefiniowana w konstruktorze, dlatego domyslnie jest 0
	Okienko win3(40, 5, "inne", 4);
	
	Okienko win4;
	
	Okienko win5;

	
//	win1.wpisz_wartosc(5);
//	win2.wpisz_wartosc(45);

	for (int i=0; i < 10000; i++)	win2.wpisz_wartosc(i);

	gotoxy(1, 25);

	std::cout << counter(win3) << " " << win2.r;

	return 0;
}
