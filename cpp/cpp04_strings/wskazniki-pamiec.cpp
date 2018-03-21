// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
using namespace std;

struct MojaStruktura
{
    MojaStruktura()
    {
        cout << "konstruktor - utworzenie MojeStruktura" << endl;
    }
    ~MojaStruktura()
    {
        cout << "destruktor - usuniecie MojaSturktura" << endl;
    }
};

void wskazniki_pamiec()
{
    // co oznaczaj� poni�sze instrukcje?
    {
        int a1;             // niezainicjowana zmienna na stosie
        int a2 = 2;         // zainicjowana zmienna na stosie 
        int a3(3);          // inna forma inicjalizacji zmiennej na stosie

        int *b1;            // niezainicjowana zmienna wska�nikowa na stosie
        int *b2 = &a1;      // zainicjowana zmienna wska�nikowa na stosie

        new int;            // niezainicjowana zmienna int na stercie
        new int();          // zainicjowana zerem zmienna int na stercie
        new int(5);         // zainicjowana zmienna int na stercie
        b1 = new int(4);    // przypisanie do zmiennej wska�nikowej adresu zmiennej ze sterty

        // W C++ mo�emy decydowa� kt�re zmienne/obiekte deklarowane s� na stosie ('stack'),
        // a kt�re na stercie ('heap').

        // czas �ycia obiekt�w na STOSIE - do ko�ca zakresu {}
        // czas �ycia obiekt�w na STERCIE - do czasu ich zwolnienia
    }

    // Czy to oznacza, �e mo�emy teraz skorzysta� z a4?
    //cout << a4;
    // Nie- obiekt new int(4) zosta� zadeklarowany co prawda na stercie,
    // ale wska�nik do niego by� "tylko" na stosie.

    // Dla niedowiark�w
    {
        MojaStruktura ms;
    }

    {
        MojaStruktura * ms = new MojaStruktura();
    }


    {
        int a_stos = 5;

        int *a_sterta = new int(5);
        delete a_sterta;

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