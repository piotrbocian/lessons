// Stos.cpp : Defines the entry point for the console application.
//

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

int main()
{
    Stos stos;
    stos.push('a');
    stos.push('b');
    stos.push('c');

    cout << stos.pop();
    cout << stos.pop();

    stos.poloz('d');
    cout << stos.push();
    cout << stos.push();

    return 0;
}

