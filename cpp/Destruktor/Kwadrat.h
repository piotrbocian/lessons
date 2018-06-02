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

    // destruktor - metoda wywo�ywana kiedy obiekt jest usuwany
    // destruktora u�ywamy do zwalniania zasob�w kt�rych wcze�niej u�ywali�my, np.
    // - zwalniania zaalokowanej pami�ci
    // - zamykania utwartych plik�w
    ~Kwadrat()
    {
        cout << "Usuwam kwadrat o boku " << a << endl;
    }

private:
    int a;
};