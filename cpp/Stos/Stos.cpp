// Stos.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;


struct Element
{
    int wartosc;
    Element *poprzedni;
};


struct Stos
{
    Element *wierzcholek = nullptr;

    void poloz(int w)
    {
        wierzcholek = new Element{ w, wierzcholek };
    }

    int zdejmij()
    {
        auto w = wierzcholek;
        int ret = w->wartosc;
        wierzcholek = wierzcholek->poprzedni;
        delete w;
        return ret;
    }
};


int main()
{
    Stos stos;
    stos.poloz(5);
    stos.poloz(7);
    stos.poloz(4);

    cout << stos.zdejmij();
    cout << stos.zdejmij();

    stos.poloz(1);
    cout << stos.zdejmij();
    cout << stos.zdejmij();

    return 0;
}

