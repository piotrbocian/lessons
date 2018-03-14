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

    // TODO - jak pokazaæ ¿e trzeba uwa¿aæ na a?
    // czas ¿ycia obiektów
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


    // wyciek pamiêci
    {
        int *p_a;
        int *p_b;

        p_a = new int(5);
        p_b = new int(7);

        cout << "*p_a = " << *p_a << ", *p_b = " << *p_b << endl;

        p_a = p_b;

        cout << "*p_a = " << *p_a << ", *p_b = " << *p_b << endl;
        delete p_a;
        //delete p_b;   // p_b pokazuje teraz na pamiêæ p_a, która zosta³a ju¿ zwolniona!!!
        // za to nie zwolniono pamiêci p_a - wyst¹pi³ tzw WYCIEK PAMIÊCI ("MEMORY LEAK")s
    }



    // alokowanie dynamicznych tablic
    {
        // dla przypomnienia - statyczna tablica
        int statyczna[100];

        // tablica dynamiczna alokowana - 
        // rozmiar mo¿e byæ podany w trakcie dzia³ania programu
        int n = 100;
        int *dynamiczna = new int[100];
        // zwróæ uwagê na ró¿nicê:
        int *tablica = new int[100];
        int *pojedyncza_zmienna = new int(100);

        // taka tablica MUSI zostaæ zwolniona kiedy przestaje byæ potrzebna
        // w C++ nie ma Garbage Collectora!!!
        delete[] dynamiczna;
    }

    // sprawdz ile maksymalnie pamiêci uda siê zaalokowaæ w œrodowisku x86 (32 bity)
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