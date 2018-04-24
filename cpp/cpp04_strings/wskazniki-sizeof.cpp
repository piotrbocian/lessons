// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>

using namespace std;

void fun(char tab[])    // deklaracja z rozmiarem 'char tab[100]' nic tu nie zmieni
{
    cout << "wewnatrz funkcji: sizeof(tab) = " << sizeof(tab) << endl;
}

int main()
{
    // zadeklarujmy kilka zmiennych wska�nikowych
    int *p_i;
    char *p_c;
    long long *p_ll;

    // jaki jest rozmiar tych zmiennych?
    cout << "sizeof(int *) = " << sizeof(p_i) << endl;
    cout << "sizeof(char *) = " << sizeof(p_i) << endl;
    cout << "sizeof(long long *) = " << sizeof(p_i) << endl;

    // Skompilujmy program w konfiguracji x64 (64-bitowej) - jakie teraz otrzymamy rozmiary?


    // Rozmiar zmiennej wska�nikowej dla danej architektury (x86/x64) jest zawsze taki sam,
    // niezale�nie od rozmiaru wskazywanego typu!


    // W przypadku tablic:
    char tab[100];
    cout << "sizeof(tab) = " << sizeof(tab) << endl;
    char * p_tab = tab;
    cout << "sizeof(p_tab) = " << sizeof(p_tab) << endl;
    // Nast�puje tzw 'array decaying' (~rozk�ad, zanik):
    // - przy u�yciu wska�nika kompilator traci informacj� o rozmiarze tablicy


    // Ma to ogromne znaczenie je�li przekazujemy parametry do funkcji przez wska�nik
    // tak jak to ma miejsce w przypadku tablic:
    fun(tab);
    fun(p_tab);
    fun(&tab[0]);
    // kod kompiluje si� niezale�nie od tego czy przekazali�my tablice czy wska�nik czy adres 
    // pierwszego elementu poniewa� dla kompilatora wszystkie te deklaracje s� to�same!
    // Dlaczego:
    // Tablice przekazywane s� do funkcji przez adres (przez wska�nik).
    // Deklaracja:
    //   void fun(char tab[100])
    // dla kompilatora jest r�wnowa�na z:
    //   void fun(char *tab)

    return 0;
}