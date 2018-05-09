// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#pragma once


#include <iostream>
using namespace std;

class Kantor
{
public:
    Kantor(float usd_pln, float eur_pln)
    {
        USD_PLN = usd_pln;
        EUR_PLN = eur_pln;
        SPREAD = 0.1;
    }
    float kupUsd(float pln)
    {
        // pierwsza forma obliczen
        float kursWymiany = USD_PLN * (1 + SPREAD / 2);
        zysk += pln - pln / (1 + SPREAD / 2);
        return pln / kursWymiany;
    }

    float kupEur(float pln)
    {
        // druga forma obliczen
        float kursWymiany = 1 / (EUR_PLN * (1 + SPREAD / 2));
        zysk += pln * (1 / EUR_PLN - kursWymiany) * EUR_PLN;    // zysk w EUR * kurs EUR
        return pln * kursWymiany;
    }

    float sprzedajUsd(float usd)
    {
        float kursWymiany = (USD_PLN * (1 - SPREAD / 2));
        zysk += usd * (USD_PLN - kursWymiany);
        return usd * kursWymiany;
    }

    float sprzedajEur(float eur)
    {
        float kursWymiany = (EUR_PLN * (1 - SPREAD / 2));
        zysk += eur * (EUR_PLN - kursWymiany);
        return eur * kursWymiany;
    }

private:
    float USD_PLN;
    float EUR_PLN;
    float SPREAD;
    float zysk = 0;
};

void kantor_test()
{
    Kantor k(3.40, 4.30);
    float pln = 100;
    float usd = k.kupUsd(pln);
    pln = k.sprzedajUsd(usd);

    float eur = k.kupEur(pln);
    pln = k.sprzedajEur(eur);

    float zarobek = 100 - pln;

    cout << "Zarobek " << zarobek << endl;
}