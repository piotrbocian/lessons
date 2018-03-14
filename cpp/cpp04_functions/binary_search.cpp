// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "stdafx.h"

#include <iostream>
#include <ctime>

using namespace std;

// szukanie binarne przy pomocy klasy
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


// przy pomocy tablicy ---------------------------

#include <algorithm>

void szukaj(int tablica[], int poszukiwanaLiczba, int poczatek, int koniec)
{
    static int licznik = 0;

    int srodek = poczatek + (koniec - poczatek) / 2;
    int liczbaZTablicy = tablica[srodek];
    licznik++;

    if (liczbaZTablicy == poszukiwanaLiczba)
    {
        cout << "Liczba " << poszukiwanaLiczba << " jest pod indeksem " << srodek << endl;
        cout << "Znaleziona po " << licznik << " probach" << endl;
    }
    if (poszukiwanaLiczba > liczbaZTablicy)
    {
        szukaj(tablica, poszukiwanaLiczba, srodek, koniec);
    }
    else if (poszukiwanaLiczba < liczbaZTablicy)
    {
        szukaj(tablica, poszukiwanaLiczba, poczatek, srodek);
    }
}

void bisekcja()
{
    // zadeklaruj i wypelnij tablice 1000-elementowa za pomoca generatora liczba losowych
    // (bylo na Zajeciach nr 2)
    int tablica[1000];
    std::generate(std::begin(tablica), std::end(tablica), std::rand);
    
    // wylosuj indeks tablicy (uzyj funkcji random)
    int indeks = std::rand() % 1000;

    // przypisz do zmiennej poszukiwanaLiczba wartosc spod wylosowanego indeksu
    // int poszukiwanaLiczba = tablica[indeks];
    int poszukiwanaLiczba = tablica[indeks];

    // posortuj tablice (bylo na zajeciach nr 2)
    std::sort(std::begin(tablica), std::end(tablica));

    // Wywolaj funkcje szukaj(...) z argumentami:
    //   tablica
    //   poszukiwanaLiczba
    //   pozostale argumenty potrzebne przez funkcje...
    // ktora odszuka poszukiwanaLiczbe w tablicy i wypisze pod ktorym jest teraz indeksem.
    // Ponadto funkcja ma wypisac po ilu probach udalo sie liczbe odnaleŸæ - zliczamy ka¿de odwolanie do tablicy.
    // Ile maksymalnie prob jest potrzebnych? Jaka jest zlozonosc takiego przeszukiwania?
    szukaj(tablica, poszukiwanaLiczba, 0, 1000);
}

