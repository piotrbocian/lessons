// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#pragma once
#include <iostream>
#include <string>

#include <iomanip>

using namespace std;

class Pokoj
{
public:
    // 1 - standard "ekonomiczny"
    // 2 - standard "apartament"
    // 3 - standard "prezydencki"
    int standard;

    // 1 - pojedyncze
    // 11- 2 x pojedyncze
    // 2 - podwojne
    // 22- 2 x podwojne
    // 21- podwojne + pojedyncze
    int lozka;

    // cena pokoju za noc
    double cena;

    // true - pok�j jest zajety
    // false - pok�j jest wolny
    bool zajety;

    // nazwisko go�cia zameldowanego w pokoju
    string nazwiskoGoscia;

    Pokoj(int standard, int lozka, double cena)
    {
        this->standard = standard;
        this->lozka = lozka;
        this->cena = cena;
        this->zajety = false;
        this->nazwiskoGoscia = "";
    }

    // Szczeg� kt�rym nie zaprz�tajmy sobie na razie glowy.
    //   *Poniewa� jest zdefiniowany nie-domy�lny konstruktor
    //   *to musimy doda� jeszcze konstruktor domy�lny aby program si� skompilowa�.
    // O konstruktorach b�dziemy jeszcze m�wi� wi�cej.

    Pokoj()
    {
    }

    // lub od C++11
    //Pokoj() = default;

    // wypisz informacje o pokoju
    void wypisz()
    {
        cout << setw(5) << standard
             << setw(5) << lozka
             << setw(10) << cena
             << setw(20) << nazwiskoGoscia << endl;
    }

    void zamelduj(string nazwisko)
    {
        if (zajety)
        {
            cout << "Pokoj jest juz zajety przez " << nazwiskoGoscia << endl;
        }
        else
        {
            zajety = true;
            nazwiskoGoscia = nazwisko;
        }
    }

    void wymelduj()
    {
        if (zajety)
        {
            zajety = false;
            nazwiskoGoscia = "";
        }
        else
        {
            cout << "W pokoju nikt nie jest zameldowany!" << endl;
        }
    }

};  // pami�tajmy o �redniku na ko�cu deklaracji klasy
