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

void zwieksz(int a)
{
    a = a + 100;
}

void zwieksz(int t[], int liczba_elementow)
{
    for (int i = 0; i < liczba_elementow; i++)
    {
        t[i] = t[i] + 100;
    }
}

void naprawde_zwieksz(int &a)
{
    a = a + 100;
}

// n! = 1 * 2 * ... * n = (n-1)! * n
int silnia_r(int n)
{
    cout << "licze silnia(" << n << ")" << endl;

    if (n > 1)
        return silnia_r(n - 1) * n;
    else
        return 1;
}

int silnia_n(int n)
{
    int silnia = 1;
    for (int i = 2; i <= n; i++)
    {
        silnia *= i;
    }
    return silnia;
}

int counter = 0;
long long fib(long long n)
{
    counter++;
    if (n < 2)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}



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
    int wynik;
    wynik = dodaj(1, 2);    // wywołanie funkcji napisanej przez nas
    cout << wynik << endl;  // wypisze: 1 + 2 = 3

    // funkcji możemy użyć bezpośrednio w wyrażeniu:
    cout << odejmij(7, 2) << endl;  // wypisze: 7 - 2 = 5

    // a nawet funkcji w funkcji:
    cout << odejmij(dodaj(4, 5), dodaj(7, -1)) << endl; // wynik: ???

    // możemy zadeklarować funkcję o takiej samej nazwie ale z innymi parametrami (lub inną liczbą parametrów)
    cout << dodaj(1, 2, 3) << endl;

    int tablica[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << najwieksza(tablica) << endl;

    cout << najwieksza_indeks(tablica).liczba << " na pozycji " << najwieksza_indeks(tablica).indeks << endl;
    LICZBA_INDEKS liczba_indeks = najwieksza_indeks(tablica);
    cout << liczba_indeks.liczba << " na pozycji " << liczba_indeks.indeks << endl;

    int indeks;
    int max = najwieksza_indeks(tablica, indeks);

    cout << max << " na pozycji " << indeks << endl;


    cout << "silnia = " << silnia_n(5) << " " << silnia_r(5) << endl;

    cout << "fib() = " << fib(7) << endl;
    cout << "counter = " << counter << endl;

    int a = 5;
    zwieksz(a);
    cout << a << endl;

    naprawde_zwieksz(a);
    cout << a << endl;

    zwieksz(tablica, 10);
    for (auto t : tablica)
    {
        cout << t << endl;
    }

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
