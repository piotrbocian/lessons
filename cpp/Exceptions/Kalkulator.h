// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian


#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class Kalkulator
{
public:
    Kalkulator()
    {
        cin >> a;
        if (!cin.good())
            throw std::exception("Nie podano liczby");

        cin >> b;
        if (!cin.good())
            throw std::exception("Nie podano liczby");
        // wczytaj dwie liczby calkowite z konsoli
        // podano cos innego niz liczby

        // coœ posz³o nie tak w konstruktorze :(
        //throw std::exception("ups");

        // http://www.cplusplus.com/doc/tutorial/files/:
        // ofstream: Stream class to write on files
        // ifstream: Stream class to read from files
        // fstream : Stream class to both read and write from / to files.
        plik.open("logowanie.txt");
    }

    ~Kalkulator()
    {
        cout << "Zamykam plik" << endl;
        plik.close();
    }


    int dodaj()
    {
        if ((long long)(a + b) > INT32_MAX)
            throw std::exception();

        return a + b;
        // przepelnienie
        return 0;
    }

    int pomnoz()
    {
        plik << a << " * " << b << " = " << a * b << endl;
        // przepelnienie
        return 0;
    }

    int podziel()
    {
        // dzielenie przez 0
        return 0;
    }

private:
    int a, b;
    ofstream plik;


};