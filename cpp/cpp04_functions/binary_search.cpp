#include "stdafx.h"

#include <iostream>
#include <ctime>

using namespace std;

// szukanie binarne
// zgadnij jak¹ liczbe od 1 do 1000 pomyslalem, masz 10 prob
class Liczba
{
private:
    int liczba;

public:

    Liczba()
    {
        std::srand(std::time(nullptr));
        liczba = (std::rand() % 1000) + 1;
        cout << "Liczba = " << liczba << endl;
    }

    int zgaduj(int n)
    {
        if (n == liczba)
            return 0;
        else if (liczba < n)
            return -1;
        else
            return 1;
    }
};


void szukaj(Liczba liczba, int poczatek, int koniec)
{
    int srodek = poczatek + (koniec - poczatek) / 2;
    int wynik = liczba.zgaduj(srodek);
    if (wynik == 0)
    {
        cout << "WYNIK = " << srodek << endl;
    }
    if (wynik > 0)
    {
        szukaj(liczba, srodek, koniec);
    }
    else if (wynik < 0)
    {
        szukaj(liczba, poczatek, srodek);
    }
}

