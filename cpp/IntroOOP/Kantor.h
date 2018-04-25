// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#pragma once


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
        return pln / (USD_PLN + SPREAD / 2);
    }

    float kupEur(float pln)
    {
        return pln / (EUR_PLN + SPREAD / 2);
    }

    float sprzedajUsd(float usd)
    {
        return usd * (USD_PLN - SPREAD / 2);
    }

    float sprzedajEur(float eur)
    {
        return eur * (EUR_PLN - SPREAD / 2);
    }

private:
    float USD_PLN;
    float EUR_PLN;
    float SPREAD;
};

void main()
{
    Kantor kantor(3, 4);
    float pln = 100;
    float usd, eur;
    usd = kantor.kupUsd(pln);
    pln = kantor.sprzedajUsd(usd);
    eur = kantor.kupEur(pln);
    pln = kantor.sprzedajEur(eur);

    cout << "zysk kantoru = " << 100 - pln << endl;
}
