// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
using namespace std;

void wsk2()
{

    {
        int *aa = new int(5);
        delete aa;
    }

    // TODO - jak pokaza� �e trzeba uwa�a� na a?
    // czas �ycia obiekt�w
    int *p_a;
    int *p_b;
    {
        int a = 5;
        p_a = &a;
        p_b = new int(7);

        cout << "p_a = " << p_a << ", *p_a = " << *p_a << endl;
        cout << "p_b = " << p_b << ", *p_b = " << *p_b << endl;
    }
    cout << "p_a = " << p_a << ", *p_a = " << *p_a << endl;
    cout << "p_b = " << p_b << ", *p_b = " << *p_b << endl;


    // wyciek pami�ci
    {
        int *p_a;
        int *p_b;

        p_a = new int(5);
        p_b = new int(7);

        cout << "*p_a = " << *p_a << ", *p_b = " << *p_b << endl;

        p_a = p_b;

        cout << "*p_a = " << *p_a << ", *p_b = " << *p_b << endl;
        delete p_a;
        //delete p_b;   // p_b pokazuje teraz na pami�� p_a, kt�ra zosta�a ju� zwolniona!!!
        // za to nie zwolniono pami�ci p_a - wyst�pi� tzw WYCIEK PAMI�CI ("MEMORY LEAK")s
    }



    // alokowanie dynamicznych tablic
    {
        // dla przypomnienia - statyczna tablica
        int statyczna[100];

        // tablica dynamiczna alokowana - 
        // rozmiar mo�e by� podany w trakcie dzia�ania programu
        int n = 100;
        int *dynamiczna = new int[100];
        // zwr�� uwag� na r�nic�:
        int *tablica = new int[100];
        int *pojedyncza_zmienna = new int(100);

        // taka tablica MUSI zosta� zwolniona kiedy przestaje by� potrzebna
        // w C++ nie ma Garbage Collectora!!!
        delete[] dynamiczna;
    }

    // sprawdz ile maksymalnie pami�ci uda si� zaalokowa� w �rodowisku x86 (32 bity)
    for (int i = 1; ; i++)
    {
        new char[1024 * 1024];
        cout << i << " MB!" << endl;
    }
    // Zadanie
    // Vector-Sort raz jeszcze
    // https://www.hackerrank.com/challenges/vector-sort/problem
    // Tylko tym razem zamiast std::vector prosze uzyc dynamicznej tablicy (new int[])
}