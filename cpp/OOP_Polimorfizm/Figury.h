// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
using namespace std;

// klasa abstrakcyjna
// Nie można stworzyć obiektu tej klasy tylko można po niej dziedziczyć.
// Ponadto klasa dziedzicząca musi zaimplementować wszystkie metody oznaczone jako = 0;
class Figura
{
public:
    // metody abstrakcyjne, zwane w C++ czysto wirtualnymi ('pure virtual')
    virtual double obliczPole() = 0;
    virtual double obliczObwod() = 0;
};

class Kwadrat : public Figura
{
public:
    Kwadrat(int _a) : a(_a) {}

    double obliczPole() override
    {
        return a * a;
    }
    double obliczObwod() override
    {
        return 4 * a;
    }

private:
    int a;
};


class Kolo : public Figura
{
public:
    Kolo(double promien)
    {
        r = promien;
        std::cout << "Tworze kolo o promieniu " << promien << endl;
    }

    double obliczPole() override
    {
        return pi * r * r;
    }

    double obliczObwod() override
    {
        return 2 * pi * r;
    }

private:
    double r;
    double pi = 3.1416;
};

