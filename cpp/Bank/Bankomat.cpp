// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "stdafx.h"
#include "Bankomat.h"

#include <iostream>

Bankomat::Bankomat()
{
}


Bankomat::~Bankomat()
{
}

void Bankomat::wczytajKarte(string karta)
{
    // sprawdz czy karta jest obslugiwana
    if (karta == "1234-4321-0987-7890")
    {
        karta_rozpoznana = true;
    }
}

void Bankomat::wyplac(float pln)
{
    if (karta_rozpoznana)
    {
        int pin;
        cout << "Podaj PIN: ";
        cin >> pin;

        if (pin == 5556)
        {

        }
        else
        {
            cout << "NIEPRAWIDLOWY PIN, LICZBA PROB PRZED ZABLOKOWANIEM KARTY";
        }
    }
    else
    {
        cout << "NIEROZPOZNANA KARTA!";
    }
}

void Bankomat::wysunKarte()
{

}