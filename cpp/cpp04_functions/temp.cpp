// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "stdafx.h"

#include <string>
#include <iostream>

using namespace std;

void temp_avg_std_dev(float temp[], float &avg, float &std_dev)
{
    const int num_of_months = 12;
    float sum = 0;
    for (int i = 0; i < num_of_months; i++)
    {
        sum += temp[i];
    }
    avg = sum / num_of_months;

    sum = 0;
    for (int i = 0; i < num_of_months; i++)
    {
        sum += (temp[i] - avg)*(temp[i] - avg);
    }
    std_dev = sqrt(sum / num_of_months);
}

void zadanie2_temperatury()
{
    while (!cin.eof())
    {
        std::string miasto;
        cin >> miasto;

        float temp[12] = {};
        for (int i = 0; i < 12; i++)
        {
            cin >> temp[i];
        }

        float avg;
        float std_dev;
        temp_avg_std_dev(temp, avg, std_dev);
        cout << miasto << " avg = " << avg << ", std_dev = " << std_dev << endl;
    }
}


#include <fstream>
void zadanie2_temperatury_z_pliku()
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

        float avg;
        float std_dev;
        temp_avg_std_dev(temp, avg, std_dev);
        cout << miasto << " avg = " << avg << ", std_dev = " << std_dev << endl;
    }
    plik.close();
}