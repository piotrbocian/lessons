#include "stdafx.h"
#include "funkcje.h"

#include <iostream>
using namespace std;

unsigned long long fib(int n)
{
    if (n < 2)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}

unsigned long long fib_licznik(int n)
{
    licznik_globalny++;

    if (n < 2)
        return n;
    else
        return fib_licznik(n - 1) + fib_licznik(n - 2);
}

void zwieksz(int a)
{
    a = a + 100;
    cout << "argument = " << a << endl;
}


void naprawde_zwieksz(int &a)
{
    a = a + 100;
    cout << "argument = " << a << endl;

}

// przeciazenie funkcji - taka sama nazwa, ale inne parametry
void zwieksz(int t[], int liczba_elementow)
{
    for (int i = 0; i < liczba_elementow; i++)
    {
        t[i] = t[i] + 100;
    }
}

