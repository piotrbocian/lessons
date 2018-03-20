// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
#include <chrono>

using namespace std;

void index_vs_array()
{

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

    int tab[SIZE];

    // dostêp przez tablicê
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            tab[j] = i;
        }
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> seconds = end - start;
    cout << "Dostep przez tablice:  " << seconds.count() << " sekund." << endl;

    // dostêp przez wskaŸnik
    start = std::chrono::system_clock::now();
    for (int i = 0; i < N; i++)
    {
        int *pt = tab;  // reset wskaŸnika
        for (int j = 0; j < SIZE; j++)
        {
            *pt++ = i;  // dostêp i ustawienie kolejnego elementu tablicy
        }
    }
    end = std::chrono::system_clock::now();
    seconds = end - start;
    cout << "Dostep przez wskaznik: " << seconds.count() << " sekund." << endl;

}
