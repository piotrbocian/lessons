// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

// UWAGA!
// Program przedstawia b³êdne rozwi¹zanie zadania 'Temperatury'

#include "stdafx.h"

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

float gAvg = 0;

float srednia(float temp[])
{
    const int num_of_months = 12;
    for (int i = 0; i < num_of_months; i++)
    {
        gAvg += temp[i];
    }
    gAvg /= num_of_months;

    return gAvg;
}


void temp_blednie()
{
    // http://www.cplusplus.com/doc/tutorial/files/:
    // ofstream: Stream class to write on files
    // ifstream: Stream class to read from files
    // fstream : Stream class to both read and write from / to files.
    ifstream plik;
    plik.open("temperatury.txt");
    if (!plik.is_open())
    {
        cout << "nie ma takiego pliku!" << endl;
        return;
    }
    while (!plik.eof())
    {
        std::string miasto;
        plik >> miasto;

        float temp[12] = {};
        for (int i = 0; i < 12; i++)
        {
            plik >> temp[i];
        }

        cout << miasto << " avg = " << srednia(temp) << endl;
    }
    plik.close();
}