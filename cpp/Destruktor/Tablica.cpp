// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "Tablica.h"
#include <iostream>

using namespace std;

Tablica::Tablica(int n) : size(n)
{
    cout << "Tworze tablice o rozmiarze " << size << endl;
    tab = new int[n];
}

Tablica::~Tablica()
{
    cout << "Usuwam tablice o rozmiarze " << size << endl;
    delete[] tab;
}
