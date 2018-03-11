#include "stdafx.h"
#include <iostream>
using namespace std;

struct LICZBA_INDEKS
{
    int liczba;
    int indeks;
};

int najwieksza(int tablica[10]);
LICZBA_INDEKS najwieksza_indeks(int tablica[10]);
int najwieksza_indeks(int tablica[10], int &indeks);

void backlog()
{
    int tablica[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    cout << najwieksza(tablica) << endl;

    cout << najwieksza_indeks(tablica).liczba << " na pozycji " << najwieksza_indeks(tablica).indeks << endl;
    LICZBA_INDEKS liczba_indeks = najwieksza_indeks(tablica);
    cout << liczba_indeks.liczba << " na pozycji " << liczba_indeks.indeks << endl;

    int indeks;
    int max = najwieksza_indeks(tablica, indeks);

    cout << max << " na pozycji " << indeks << endl;

}

// !!! pierwsza grupa nie miala znajdowania maxa
int najwieksza(int tablica[10])
{
    int max = tablica[0];
    for (int i = 1; i < 10; i++)
    {
        if (tablica[i] > max)
        {
            max = tablica[i];
        }
    }
    return max;
}


int najwieksza_indeks(int tablica[10], int &indeks)
{
    indeks = 0;
    int max = tablica[indeks];
    for (int i = 1; i < 10; i++)
    {
        if (tablica[i] > max)
        {
            max = tablica[i];
            indeks = i;
        }
    }
    return max;
}


LICZBA_INDEKS najwieksza_indeks(int tablica[10])
{
    int indeks = 0;
    int max = tablica[indeks];
    for (int i = 1; i < 10; i++)
    {
        if (tablica[i] > max)
        {
            max = tablica[i];
            indeks = i;
        }
    }
    return LICZBA_INDEKS{ max, indeks };
}
