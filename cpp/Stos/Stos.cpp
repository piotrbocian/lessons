// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
using namespace std;


struct Element
{
    char wartosc;
    Element *poprzedni;
};

struct Stos
{
    Element *wierzcholek = nullptr;

    void push(char c)
    {
        wierzcholek = new Element{ c, wierzcholek };
    }

    void pop()
    {
        Element * do_skasowania = wierzcholek;
        wierzcholek = do_skasowania->poprzedni;
        delete do_skasowania;
    }

    char top()
    {
        return wierzcholek->wartosc;
    }
};

int stos()
{
    Stos stos;
    stos.push('a');
    stos.push('b');
    stos.push('c');

    stos.pop();
    stos.pop();

    stos.push('d');
    cout << stos.top();
    cout << stos.top();

    return 0;
}

