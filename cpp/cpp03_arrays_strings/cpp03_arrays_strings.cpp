// cpp03_arrays_strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <string>

#include <algorithm>

#include <array>
#include <vector>

using namespace std;

int fib(int n)
{
    cout << "licze fib(" << n << ")";
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}



int main()
{

	// arrays -------------------------------------
	int tab1[10];
	cout << "sizeof = " << sizeof(tab1) << endl;    // 40



	int tab[10] = { 1, 2, 3 };	// = {1, 2, 3, 0, 0, 0, 0, 0, 0, 0}

    for (int i = 0; i < 10; i++)
    {
        cout << tab[i] << endl;
    }


	// dostęp do elemenetów przez inteks
	// indeksowanie od 0 do (n-1) !!!
    cout << tab[0] << endl;
    cout << tab[1] << endl;
    cout << tab[9] << endl;
	//cout << tab[10] << endl;	// błąd, C++ nie sprawdza zakresu!


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


    // tablice wielowymiarowe
    int tab_2d[][5] = { 
        {1, 2, 3, 0, 0},
        {4, 5, 6, 7, 8} 
    };


    // tabliczka mnozenia
    // zdefiniuj tablice[20][20]
    // wypelnij tablice 20x20 wartosciami tabliczki mnozenia
    {
        int tab[20][20];
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                tab[i][j] = i*j;
            }
        }
    }

	// std::array - C++ array
	std::array<int, 10> arr = { 1, 2 };
	arr[3] = 7;
	//arr[10] = 77;	// poza zakresem!

    std::fill(arr.begin(), arr.end(), 7);

	// wypelnij losowymi elementami
	std::generate(arr.begin(), arr.end(), std::rand);
	
	// operator for each
	for (int i : arr)
	{
		cout << i << endl;
	}

    cout << "posortowana tablica" << endl;
	// sortowanie tablicy
	std::sort(arr.begin(), arr.end());
	for (int i : arr)
	{
		cout << i << endl;
	}

	// C++11
	// std::begin/std::end for C arrays
	{
		int tab[10];
		std::generate(std::begin(tab), std::end(tab), std::rand);
        for (int i = 0; i < 10; i++)
        {
            cout << i << ": " << tab[i] << endl;
        }

		// C++11
		std::sort(begin(tab), end(tab));

		for (int i = 0; i < 10; i++)
		{
			cout << i << ": " << tab[i] << endl;
		}
	}


	// std::vector
	std::vector<int> v = { 1, 2, 3 };
	v[0] = 6;
	//v[4] = 7;	// poza zakresem!
	v.resize(10);
	v[4] = 7;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.pop_back();


	// zadanie
	// https://www.hackerrank.com/challenges/vector-sort/problem

	// drugie zadanie
	// https://www.hackerrank.com/challenges/vector-erase/problem


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


	// zadanie
	// https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem


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
	

    return 0;
}

