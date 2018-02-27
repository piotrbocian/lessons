// cpp03_arrays_strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <string>

using namespace std;

int main()
{

	// arrays -------------------------------------

	int tab[10] = { 1, 2, 3 };  // na początek nie zainicjowane
								// indexowane od 0 do (n-1) !!! // bardzo częsty błąd
	for (int i = 1; i <= 10; i++)
	{
		cout << tab[i] << endl;
	}


	// fibbonaci na tablicach
	int fib[10] = { 1, 1 };
	for (int i = 2; i < 10; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		cout << fib[i] << endl;
	}


	//string tekst = "WSB";
	//cout << tekst[0] << endl;
	//cout << tekst[1] << endl;
	//cout << tekst
	//cout << tekst.length();

	char tekst[] = "WSB";



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
	}

	{
		// std::strings
		std::string tekst = "tekst w C++";
		std::wstring w_tekst = L"tekst w C++";
		cout << tekst << endl;
		wcout << w_tekst << endl;

		cout << tekst << ", sizeof = " << sizeof(tekst) << ", length = " << tekst.length() << endl;
	}




    return 0;
}

