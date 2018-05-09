#pragma once

class Kwadrat
{
    // deklarujemy wszystkie pola i metody jako PUBLICZNE
    // czyli takie do ktorych mozna sie dostac spoza klasy
public:
    int a;

    int obliczPole()
    {
        return a * a;
    }
    int obliczObwod() const
    {
        return 4 * a;
    }
};