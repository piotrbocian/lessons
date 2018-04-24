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
    // zadeklarujmy kilka zmiennych wskaŸnikowych
    int *p_i;
    char *p_c;
    long long *p_ll;

    // jaki jest rozmiar tych zmiennych?
    cout << "sizeof(int *) = " << sizeof(p_i) << endl;
    cout << "sizeof(char *) = " << sizeof(p_i) << endl;
    cout << "sizeof(long long *) = " << sizeof(p_i) << endl;

    // Skompilujmy program w konfiguracji x64 (64-bitowej) - jakie teraz otrzymamy rozmiary?


    // Rozmiar zmiennej wskaŸnikowej dla danej architektury (x86/x64) jest zawsze taki sam,
    // niezale¿nie od rozmiaru wskazywanego typu!


    // W przypadku tablic:
    char tab[100];
    cout << "sizeof(tab) = " << sizeof(tab) << endl;
    char * p_tab = tab;
    cout << "sizeof(p_tab) = " << sizeof(p_tab) << endl;
    // Nastêpuje tzw 'array decaying' (~rozk³ad, zanik):
    // - przy u¿yciu wskaŸnika kompilator traci informacjê o rozmiarze tablicy


    // Ma to ogromne znaczenie jeœli przekazujemy parametry do funkcji przez wskaŸnik
    // tak jak to ma miejsce w przypadku tablic:
    fun(tab);
    fun(p_tab);
    fun(&tab[0]);
    // kod kompiluje siê niezale¿nie od tego czy przekazaliœmy tablice czy wskaŸnik czy adres 
    // pierwszego elementu poniewa¿ dla kompilatora wszystkie te deklaracje s¹ to¿same!
    // Dlaczego:
    // Tablice przekazywane s¹ do funkcji przez adres (przez wskaŸnik).
    // Deklaracja:
    //   void fun(char tab[100])
    // dla kompilatora jest równowa¿na z:
    //   void fun(char *tab)

    return 0;
}