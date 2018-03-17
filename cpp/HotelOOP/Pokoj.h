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
    float cena;
    bool zajety;
    string nazwiskoGoscia;

    Pokoj()
    {
        zajety = false;
        nazwiskoGoscia = "";
    }

    Pokoj(int standard, int lozka, float cena)
    {
        this->standard = standard;
        this->lozka = lozka;
        this->cena = cena;
        this->zajety = false;
        this->nazwiskoGoscia = "";
    }

    void wypisz()
    {
        cout << setw(5) << standard << setw(5) << lozka << setw(10) << cena;
        cout << setw(20) << nazwiskoGoscia << endl;
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
};

