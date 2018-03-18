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
    }

    float kupEur(float pln)
    {
    }

    float sprzedajUsd(float pln)
    {
    }

    float sprzedajEur(float pln)
    {
    }

private:
    float USD_PLN;
    float EUR_PLN;
    float SPREAD;
};
