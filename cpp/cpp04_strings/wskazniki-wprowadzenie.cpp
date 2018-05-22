// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
#include <string>

using namespace std;

// funkcja ktory modyfikuje swoj parametr - implementacja na wskazniku
void zwieksz_o_100(int *a)
{
    *a += 100;
}

// dla porownania wersja z referencja (zalecana!)
void zwieksz_o_100(int &a)
{
    a += 100;
}

int wskazniki_wprowadzenie()
{ 
    // deklarujemy wskaznik 'p_a' jako zmienna pokazujaca na adres pamieci pod ktorym jest zmienna 'a'
    {
        int a = 5;
        int b = 7;
        int *p = &a;

        cout << "a = " << a << ", &a = " << &a << endl;
        cout << "p = " << p << endl;

        // aby odczytac wartosc obiektu wskazywanego
        cout << "*p = " << *p << endl;

        // aby zapisac wartosc obiektu wskazywanego
        *p = b;

        // aby przestawic wskaznik na inny obiekt
        p = &b;

        // ile teraz wynosi a, b, *p?
        a += 2;
        b += 1;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "*p = " << *p << endl;
    }

    // porownanie wskaznikow
    {
        // zainicjuj dwie takie same zmienne
        int a, b;
        a = b = 1;

        // ustaw na nie wskazniki
        int *p_a = &a;
        int *p_b = &b;

        // sprawdz czy zmienne sa takie same
        if (a == b)
        {
            cout << "a == b" << endl;
        }
        else
        {
            cout << "a = " << a << ", b = " << b << endl;
        }

        // sprawdz czy wskazniki sa takie same
        if (p_a == p_b)
        {
            cout << "p_a == p_b" << endl;
        }
        else
        {
            cout << "p_a = " << p_a << ", p_b = " << p_b << endl;
        }
    }

    // wskaŸniki const - jaka jest ró¿nica?
    {
        int a = 5;
        int b = 7;
        const int *pc_a = &a;
        int *const pc_b = &b;

        //*pc_a = 6;   // wskaŸnik na sta³¹ (const int) - nie mo¿na zmodyfikowaæ obiektu na który pokazuje
        pc_a = &b;     // ale mo¿na pokazaæ na inny obiekt

        *pc_b = 7;     // sta³y wskaŸnik - mo¿na zmodyfikowaæ obiekt
        //pc_b = &a;   // ale nie mo¿na zmieniæ obiektu na który pokazuje
    }

    // Zastosowanie nr 1 - funkcje modyfikujace parametry
    // UWAGA!
    // przekazywanie parametrow przez wskazniki pochodzi jeszcze z jezyka C
    // C++ zaleca referencje jako bezpieczniejszy sposob
    {
        int a = 2;
        cout << "a = " << a << endl;
        zwieksz_o_100(&a);
        cout << "a = " << a << endl;
    }


    // Zastosowanie nr 2 - poruszanie sie po tablicach
    {
        cout << "na podstawie indeksu" << endl;
        int tab[10] = { 1, 2, 3, 4 };
        for (int i = 0; i < 10; i++)
        {
            cout << i << ": " << tab[i] << endl;
        }

        cout << "przez wskaznik" << endl;
        int *p_tab = &tab[0];   // rownoznaczne z p_tab = tab
        for (int i = 0; i < 10; i++)
        {
            cout << p_tab << ": " << *p_tab << endl;
            p_tab++;    // inkrementacja wskaznika!
        }
        // dlaczego adres przeskakuje co 4?
        
        cout << "przez wskaznik na short" << endl;
        short *p_short_tab = reinterpret_cast<short*>(tab);   // rownoznaczne z p_tab = tab
        for (int i = 0; i < 10; i++)
        {
            cout << p_short_tab << ": " << *p_short_tab << endl;
            p_short_tab++;
        }
        // dlaczego adres przeskakuje o 2? dlaczego pojawily sie 0 miedzy liczbami?
    }


    // Cwiczenie
    // Czy dostep przez wskazniki jest szybszy?
    // Zadeklaruj duza tablice
    const int SIZE = 100000;
    // Wypelnij cala tablice N razy 
    const int N = 10000;
    // 1) uzywajac indeksowania []
    // 2) uzywajac przesuniecia wskaznika
    // Zmierz czas obu operacji (http://en.cppreference.com/w/cpp/chrono)
    /*
    UWAGA - Kompilator ma okreœlony limit dostêpnej pamiêci na stosie (ile mog¹ zaj¹æ wszystkie zmienne lokalne programu, w tym du¿a tablica z tego zadania.
    W przypadku Visual Studio jest to domyœlnie 1MB. Zaalokowanie wiêkszej tablicy np.
    int tab[1000000]; // sizeof(tab) = sizeof(int) * 1000000 ~= 4MB
    spowoduje b³¹d stack overflow!
    */

    return 0;
}
