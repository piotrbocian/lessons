// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#pragma once

#include <iostream>
using namespace std;

class Kwadrat
{
public:
    // konstruktor
    Kwadrat(int a)
    {
        this->a = a;
        cout << "Tworze kwadrat o boku " << a << endl;
    }

    // destruktor - metoda wywo³ywana kiedy obiekt jest usuwany
    // destruktora u¿ywamy do zwalniania zasobów których wczeœniej u¿ywaliœmy, np.
    // - zwalniania zaalokowanej pamiêci
    // - zamykania utwartych plików
    ~Kwadrat()
    {
        cout << "Usuwam kwadrat o boku " << a << endl;
    }

private:
    int a;
};