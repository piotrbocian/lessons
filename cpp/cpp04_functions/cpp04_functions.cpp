// cpp04_functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

// deklaracja
int dodaj(int a, int b)
{
	cout << a << " + " << b << " = ";
	return a + b;
}

int dodaj(int a, int b, int c)
{

	cout << a << " + " << b << " + " << c << " = ";
	return a + b + c;
}

// definicja
int odejmij(int a, int b);


struct LICZBA_INDEKS
{
	int liczba;
	int indeks;
};

int najwieksza(int tablica[10]);
LICZBA_INDEKS najwieksza_indeks(int tablica[10]);
int najwieksza_indeks(int tablica[10], int &indeks);


int main()
{
	cout << dodaj(1, 2) << endl;
	cout << odejmij(7, 2) << endl;
	cout << dodaj(1, 2, 3) << endl;

	int tablica[10] = { 123, 42, 52, 5325, 535, 351, 35, 35, 13, 12 };
	cout << najwieksza(tablica) << endl;

	cout << najwieksza_indeks(tablica).liczba << " na pozycji " << najwieksza_indeks(tablica).indeks << endl;
	LICZBA_INDEKS liczba_indeks = najwieksza_indeks(tablica);
	cout << liczba_indeks.liczba << " na pozycji " << liczba_indeks.indeks << endl;

	int indeks;
	int max = najwieksza_indeks(tablica, indeks);

	cout << max << " na pozycji " << indeks << endl;


	//cin.get();
	return 0;
}

int odejmij(int a, int b)
{
	cout << a << " - " << b << " = ";
	return a - b;
}

// przekazywanie parametrow

// !!! pierwsza grupa nie miala znajdowania maxa
// !!! obie grupy nie miały tablics
int najwieksza(int tablica[10])
{
	int max = tablica[0];
	for (int i = 1; i < 10; i++)
	{
		if (tablica[i] > max)
		{
			max = tablica[i];
		}
	}
	return max;
}


int najwieksza_indeks(int tablica[10], int &indeks)
{
	indeks = 0;
	int max = tablica[indeks];
	for (int i = 1; i < 10; i++)
	{
		if (tablica[i] > max)
		{
			max = tablica[i];
			indeks = i;
		}
	}
	return max;
}


LICZBA_INDEKS najwieksza_indeks(int tablica[10])
{
	int indeks = 0;
	int max = tablica[indeks];
	for (int i = 1; i < 10; i++)
	{
		if (tablica[i] > max)
		{
			max = tablica[i];
			indeks = i;
		}
	}
	return LICZBA_INDEKS{ max, indeks };
}
