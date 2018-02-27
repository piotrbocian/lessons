// cpp03_arrays_strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <string>

#include <algorithm>

#include <array>
#include <vector>

using namespace std;

void print(int tab[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << i << ": " << tab[i] << endl;
	}
}


int main()
{

	// arrays -------------------------------------
	int tab1[10];
	cout << "sizeof = " << sizeof(tab1) << endl;


	int tab[10] = { 1, 2, 3 };	// = {1, 2, 3, 0, 0, 0, 0, 0, 0, 0}


	// dostęp do elemenetów przez inteks
	// indeksowanie od 0 do (n-1) !!!
	cout << tab[0];
	cout << tab[1];
	cout << tab[9];
	//cout << tab[10];	// błąd, C++ nie sprawdza zakresu!

	// Zadanie1
	// ciąg Fibonacciego
	// F[0] = 0,
	// F[1] = 1,
	// F[n] = F[n-1] + F[n-2]
	unsigned long long F[50] = { 0, 1 };
	for (int i = 2; i < 50; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
		cout << "F[" << i << "] = " << F[i] << endl;
	}

	// sortowanie tablicy
	// tablica 10 elementow int
	// wypelnij losowymi elementami
	{
		int tab[10];
		// C++11
		std::generate(begin(tab), end(tab), std::rand);
		print(tab, 10);

		// C++11
		std::sort(begin(tab), end(tab));
		print(tab, 10);

	}

	// string -------------------------------------
	cout << "Podaj swoje imie: ";
	string imie;
	cin >> imie;
	cout << imie << endl;

	// C-strings
	char c_tekst[] = "tekst w C";
	cout << c_tekst << ", sizeof = " << sizeof(c_tekst) << ", length = " << strlen(c_tekst) << endl;
	char c_tekst2[] = { 't', 'e', 'k', 's', 't', ' ', 'w', ' ', 'C', 0 }; // NULL terminator!
	
	/*
	char input1[10];
	char input2[] = " jest super!";
	cin >> input1;
	cout << input1 << input2 << endl;
	*/

	// using pointer operator
	const char *p_tekst = "inny tekst w C";

	{
		char imie_nazwisko[100];
		char imie[] = "Piotr";
		char nazwisko[] = "Bocian";

		//strcat(imie_nazwisko, imie);
		//strcat(imie_nazwisko, nazwisko);

		//strcmp()
		//strlen()
		//strcpy()
	}

	{
		// std::strings
		std::string tekst = "tekst w C++";
		std::wstring w_tekst = L"tekst w C++";
		cout << tekst << endl;
		wcout << w_tekst << endl;

		cout << tekst << ", sizeof = " << sizeof(tekst) << ", length = " << tekst.length() << endl;

		// binary operators
		if (tekst == "tekst w C++")
		{
			cout << "takie same" << endl;
		}

		string nowy_tekst = tekst + ", ale troche inny";
		
		cout << tekst << endl << nowy_tekst << endl;
	}


	// zadanie2
	// napisz program ktory policzy litery w slowie
	// C++11
	string s = "konstantynopolitanczykowianeczka";
	int znaki[128] = { 0 };
	for (char c : s)
	{
		znaki[c]++;
	}
	for (char i=32; i<127; i++)	// !! uwaga na przekroczenie zakresu
	{
		if (znaki[i] > 0)
		{
			cout << i << ": " << znaki[i] << endl;
		}
	}

	// std::array
	// std::vector
	std::array<int, 10> arr = { 1, 2 };
	//std::generate(arr.begin(), arr.end(), rand());


	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.pop_back();

    return 0;
}

