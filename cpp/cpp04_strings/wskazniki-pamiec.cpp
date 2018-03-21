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
    // co oznaczaj¹ poni¿sze instrukcje?
    {
        int a1;             // niezainicjowana zmienna na stosie
        int a2 = 2;         // zainicjowana zmienna na stosie 
        int a3(3);          // inna forma inicjalizacji zmiennej na stosie

        int *b1;            // niezainicjowana zmienna wskaŸnikowa na stosie
        int *b2 = &a1;      // zainicjowana zmienna wskaŸnikowa na stosie

        new int;            // niezainicjowana zmienna int na stercie
        new int();          // zainicjowana zerem zmienna int na stercie
        new int(5);         // zainicjowana zmienna int na stercie
        b1 = new int(4);    // przypisanie do zmiennej wskaŸnikowej adresu zmiennej ze sterty

        // W C++ mo¿emy decydowaæ które zmienne/obiekte deklarowane s¹ na stosie ('stack'),
        // a które na stercie ('heap').

        // czas ¿ycia obiektów na STOSIE - do koñca zakresu {}
        // czas ¿ycia obiektów na STERCIE - do czasu ich zwolnienia
    }

    // Czy to oznacza, ¿e mo¿emy teraz skorzystaæ z a4?
    //cout << a4;
    // Nie- obiekt new int(4) zosta³ zadeklarowany co prawda na stercie,
    // ale wskaŸnik do niego by³ "tylko" na stosie.

    // Dla niedowiarków
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