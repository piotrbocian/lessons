// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian


// Program wypisuje adresy zmiennych aby zademostowaæ w jaki sposób roœnie stos

#include <iostream>

using namespace std;

void funkcja(
    int param_1, 
    int param_2, 
    int param_3, 
    int param_4)
{
    cout << "adres przekazanych parametrow:" << endl;
    // parametry przekazywane s¹ od prawej do lewej (konwencja __cdecl)
    cout << "&param_4 = " << &param_4 << endl;
    cout << "&param_3 = " << &param_3 << endl;
    cout << "&param_2 = " << &param_2 << endl;
    cout << "&param_1 = " << &param_1 << endl;

    // po wszystkich parametrach zapisany jest ADRES POWROTU

    // a potem zmienne lokalne
    int lokal_1 = 0x77777777;
    int lokal_2 = 0x88888888;

    cout << "adres zmiennych lokalnych:" << endl;
    cout << "&lokal_1 = " << &lokal_1 << endl;
    cout << "&lokal_2 = " << &lokal_2 << endl;
}

int main(int argc, char *argv[])
{
    cout << "&argc = " << &argc << endl;

    int zmienna_lokalna_w_main = 5;
    cout << "&zmienna_lokalna_w_main = " << &zmienna_lokalna_w_main << endl;

    funkcja(1, 2, 3, 4);
    funkcja(23, 34, 45, 56);

    return 0;
}