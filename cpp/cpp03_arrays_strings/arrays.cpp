// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "stdafx.h"

#include <iostream>

#include <array>        // naglowek dla std::array
#include <vector>        // naglowek dla std::vector
#include <algorithm>    // naglowek dla funkcji operujacych na zbiorach danych
                        // np. std::fill, std::generate, std::sort

using namespace std;

int main()
{
    // Temat 1 - tablice jednowymiarowe
    // tablice definiujemy podajac typ nazwe oraz liczbe elementow
    // liczba elementow musi byc stala i znana na etapie kompilacji
    int tab1[10];

    // rozmiar tablicy = rozmiar przechowywanego typu * liczba elementow
    cout << "sizeof = " << sizeof(tab1) << endl;    // sizeof(int) * 10 = 4 * 10 = 40
    
    // dost�p do elemenet�w tablicy przez indeks
    // indeksowanie od 0 do (n-1) !!!
    cout << tab1[0] << endl;
    cout << tab1[1] << endl;
    cout << tab1[9] << endl;
    //cout << tab[10];    // b��d, indeks poza zakresem!

    // tab1 jest niezainicjowana, przechowuje niezdefiniowane warto�ci
    cout << "Elementy tablicy nie-zainicjowanej: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << tab1[i] << endl;
    }
    // powy�szy kod wydrukowa� u mnie ale przy ka�dym uruchomieniu warto�ci mog� by� r�ne
    /*
    -858993460
    -858993460
    -858993460
    -858993460
    -858993460
    -858993460
    -858993460
    -858993460
    -858993460
    -858993460
    */

    // Aby zainicjowa� tablic� u�ywamy nawias�w { }
    // rozmiary pomini�ty - kompilator za�o�y rozmiar r�wny liczbie element�w w klamrach
    int tab2[] = { 1, 2 };        // = {1, 2}
    // rozmiar zadany (10) - kompilator zainicjuje 3 pierwsze elementy, a pozosta�e wype�ni zerami
    int tab[10] = { 1, 2, 3 };    // = {1, 2, 3, 0, 0, 0, 0, 0, 0, 0}


    // Zadanie1
    // wypelnij tablice 50 pierwszymi elementami ci�gu Fibonacciego definiowanego nast�puj�co:
    // F[0] = 0,
    // F[1] = 1,
    // F[n] = F[n-1] + F[n-2]
    //
    // wydrukuj te elementy
    // 
    // PRACA W�ASNA STUDENTOW


    // Temat 2 - tablice wielowymiarowe


    // Temat 3 - std::array
    // C++ definiuje tablice na nowo: std::array

    // std::array - C++ array
    // deklaracja jest nieco inna, w nawiasach < > podajemy typ oraz liczbe elementow
    std::array<int, 10> arr = { 1, 2 };
    // do element�w tablicy dostajemy si� w taki sam spos�b co poprzednio
    arr[3] = 7;
    // i tak samo musimy uwa�a� na przekroczenie zakresu
    //arr[10] = 77;    // b��d, poza zakresem!

    // operator for each - mo�e by� u�yty zamiast operatora for(;;)
    cout << "Elementy std::array wypisane przy pomocy operatora for each" << endl;
    for (int i : arr)
    {
        cout << i << endl;
    }

    // Operuj�c na typach zdefiniowanych w standardowej bibliotece (std::)
    // mamy do dyspozycji wiele algorytm�w zdefiniowej w std::
    // wymagany naglowek <algorithm>
    // Np.
    // wypelnij tablice danym elementem
    std::fill(arr.begin(), arr.end(), 7);
    // zawartosc tablicy = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7}

    // wypelnij tablice liczbami pseudo-losowymi
    std::generate(arr.begin(), arr.end(), std::rand);
    // zawartosc tablicy = {41, 18467, 6334, 26500, 19169, 15724, 11478, 29358, 26962, 24464}

    // posortuj tablice
    std::sort(arr.begin(), arr.end());
    // zawartosc tablicy = {41, 6334, 11478, 15724, 18467, 19169, 24464, 26500, 26962, 29358}

    // Z drugiej strony C++11 wprowadzil operatory std::begin/std::end dla zwyklych tablic
    // Dzieki temu mozliwe jest uzyskanie tego samego co dla std::array
    {
        int tab[10];
        std::generate(std::begin(tab), std::end(tab), std::rand);
        std::sort(std::begin(tab), std::end(tab));
    }

    // Temat 4 - std::vector
    // Oba wspomniane typy tablicowe maj� ograniczenie:
    // liczba element�w musi by� sta�a i znana na pocz�tku programu.
    // Przy nieznanej ilo�ci element�w mo�na u�y� typu std::vector.
    // Deklaracja jest podobna jak std::array:
    // std::array<int, 10> arr = { 1, 2, 3 };
    std::vector<int> v = { 1, 2, 3 };
    // R�nica jest taka, �e nie podajemy wielko�ci tablicy.
    // Do element�w std::vector dostajemy si� tak samo jak do tablicy
    v[0] = 6;    // v = {6, 2, 3}
    // i wci�� musimy pami�ta� o zakresie
    //v[4] = 7;    // b��d, poza zakresem!
    // Przy czy vector daje nam mo�liwo�� rozszerzenia:
    v.resize(10);    // teraz v ma 10 element�w, nowe zosta�y wype�nione zerami, v = {6, 2, 3, 0, 0, 0, 0, 0, 0, 0}
    v[4] = 7;        // i mo�emy bezpiecznie dosta� si� do elementu pod indeksem [4], v = {6, 2, 3, 0, 7, 0, 0, 0, 0, 0}
    v.push_back(10);// push_back() dodaje element na ko�cu wektora, resize jest robiony automatycznie, v = {6, 2, 3, 0, 7, 0, 0, 0, 0, 0, 10}
    v.push_back(20);// kolejny element, v = {6, 2, 3, 0, 7, 0, 0, 0, 0, 0, 10, 20}
    v.push_back(30);// kolejny element, v = {6, 2, 3, 0, 7, 0, 0, 0, 0, 0, 10, 20, 30}
    v.pop_back();    // usuni�cie elementu z ko�ca wektora, v = {6, 2, 3, 0, 7, 0, 0, 0, 0, 0, 10, 20}

    // Zadanie dla student�w:
    // https://www.hackerrank.com/challenges/vector-sort/problem

    // Zadanie dla student�w:
    // https://www.hackerrank.com/challenges/vector-erase/problem

    return 0;
}

