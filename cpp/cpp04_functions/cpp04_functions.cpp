// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "stdafx.h"

#include <iostream>

#include "funkcje.h"

using namespace std;

// deklaracja
int dodaj(int a, int b)
{
    cout << a << " + " << b << " = ";
    return a + b;
}

int dodaj(int a, int b, int c)
{
    cout << a << " + " << b << " + " << c << " = ";
    return a + b + c;
}

// definicja
int odejmij(int a, int b);

int licznik_globalny;

#include <iomanip> // setprecision
#include <climits> // ULLONG_MAX

void zadanie2_temperatury_z_pliku();

int main()
{
    // Analiza zadania nr 1 z poprzednich cwiczen (nr 2)
    // ciąg Fibonacciego
    // F[0] = 0,
    // F[1] = 1,
    // F[n] = F[n-1] + F[n-2]

    cout << "Fibonnaci na tablicach" << endl;
    unsigned long long F[50] = { 0, 1 };
    for (int i = 2; i < 50; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
        cout << "F[" << i << "] = " << F[i] << endl;
    }

    // Cwiczenie - zmien w petli powyzej znak '<' na '<='
    // for (int i = 2; i <= 50; i++)
    // 1) uruchom w Visualu
    // 2) uruchom w http://cpp.sh/
    // Skad roznice w wykonaniu?
    // Dlaczego program w cpp.sh tak sie zachowuje?


    // Czy mozna uzyc typu double?
    {
        // zwiekszmy zakres do 100 i wypiszmy wszystkie elementy
        // dodajmy tez zabezpieczenie przed przepelnieniem wartosci typu ULLONG
        const int RANGE = 100;
        cout << "Fibonnaci ULLONG" << endl;
        unsigned long long F[RANGE] = { 0, 1 };
        for (int i = 2; i < RANGE; i++)
        {
            if (F[i - 1] > ULLONG_MAX / 2)
            {
                cout << "przepelnienie ULLONG!" << endl;
                break;
            }

            F[i] = F[i - 1] + F[i - 2];
            cout << "F[" << i << "] = " << F[i] << endl;
        }

        // teraz to samo za pomoca typu double
        cout << "Fibonnaci DOUBLE" << endl;
        cout << setprecision(80);
        long double dF[RANGE] = { 0, 1 };
        for (int i = 2; i < RANGE; i++)
        {
            dF[i] = dF[i - 1] + dF[i - 2];
            cout << "F[" << i << "] = " << dF[i] << endl;
        }

        // przekopiuj obie wartosci do programu typu "diff", np. online https://text-compare.com/
        // porownaj wyniki
    }


    // jeszcze troche wiecej o typach zmiennoprzecinkowych
    {
        if (0.1 + 0.1 == 0.2)
        {
            cout << "dobrze!" << endl;
        }
        else
        {
            cout << "WTF?!" << endl;
        }

        if (0.1 + 0.1 + 0.1 == 0.3)
        {
            cout << "dobrze!" << endl;
        }
        else
        {
            cout << "WTF?!" << endl;
        }

        cout << "0.1 = " << 0.1 << endl;
    }
  

    // Wracamy do fibonnaciego
    cout << "Fibonnaci rekurencyjnie" << endl;
    for (int i = 2; i < 30; i++)
    {
        F[i] = fib(i);
        cout << "F[" << i << "] = " << F[i] << endl;
    }

    // Dlaczego dziala to tak wolno?
    // - narysuj na tablicy graf jak te funkcje są wywoływane
    // - dodaj licznik ktory policzy wywolania funkcji:
    cout << "Fibonnaci rekurencyjnie z licznikiem" << endl;
    for (int i = 2; i < 30; i++)
    {
        licznik_globalny = 0;
        F[i] = fib_licznik(i);
        cout << "F[" << i << "] = " << F[i] << ", liczba wywolan fib() = " << licznik_globalny << endl;
    }
    // jaka jest zlozonosc obliczeniowa tego programu i programu powyzej


    // Zadanie 1: moodle -> Silnia 

    // Zadanie 2 (ekstra): moodle -> Bisekcja


    // Temat 1 - Funkcje
    int wynik = dodaj(1, 2);    // wywołanie funkcji napisanej przez nas
    cout << wynik << endl;  // wypisze: 1 + 2 = 3

    // funkcji możemy użyć bezpośrednio w wyrażeniu:
    cout << odejmij(7, 2) << endl;  // wypisze: 7 - 2 = 5

    // a nawet funkcji w funkcji:
    cout << odejmij(dodaj(4, 5), dodaj(7, -1)) << endl; // wynik: ???

    // możemy zadeklarować funkcję o takiej samej nazwie ale z innymi parametrami (lub inną liczbą parametrów)
    cout << dodaj(1, 2, 3) << endl;


    // Typy proste do funkcji przekazywane są przez wartość:
    // na stosie robiona jest lokalna KOPIA zmiennej, a oryginalna zmienna nie jest modyfikowana!
    int oryginal = 5;
    zwieksz(oryginal);
    cout << "oryginal = " << oryginal << endl;

    // Ale możemy przekazac przez tzw referencje:
    // przekazujemy wtedy adres oryginalnej zmiennej
    naprawde_zwieksz(oryginal);
    cout << "oryginal = " << oryginal << endl;

    // A jak to jest z tablicami?
    int tablica[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Elementy tablicy przekazujemy przez wartość (kopię)
    cout << endl << "elementy tablicy przekazane jako argument" << endl;
    for (int i = 0; i < 10; i++)
    {
        zwieksz(tablica[i]);
        cout << "tablica[i] = " << tablica[i] << endl;
    }

    // Ale całą tablice przez adres* (oryginal!)
    // *czyli przez wskaźnik, będzie o tym więcej kiedy dojdziemy do tematu wskaźników
    // na razie możemy utożsamiać: referencja = wskaźnik = adres
    cout << endl << "tablica przekazana jako argument" << endl;
    zwieksz(tablica, 10);   // przeciazenie funkcji
    for (int i = 0; i < 10; i++)
    {
        cout << "tablica[i] = " << tablica[i] << endl;
    }
    // dlaczego?
    // sama nazwa zmiennej ('tablica') oznacza dla kompilatora adres tablicy
    cout << "tablica = " << tablica << endl;
    // zatrzymaj sie tutaj Debugerem
    // z menu wybierz Debug->Windows->Memory->Memory 1
    // wpisz adres wystepujący po "tablica = "


    // - uwaga! druga grupa jeszcze nie miała prekierowania STDIN!

    // Zadanie 3
    // Wczytaj średnie miesieczne temparatury dla różnych miast 
    // (dane z serwisu https://pl.climate-data.org/) z pliku temperatury.txt.
    // Podpowiedzi:
    // - wczytaj parametry tak jak z konsoli i uzyj przekierowanie standardowego wejscia (STDIN)
    // - uzyj funkcji cin.eof() aby sprawdzic czy przeczytano caly plik (cin.eof() zwroci wtedy true)
    // Napisz funkcje, ktora policzy dla każdego miasta średnią roczną oraz odchylenie standardowe.
    // Pierwszym argumentem funkcji powinna byc tablica temperatur.
    // https://www.matemaks.pl/odchylenie-standardowe.html
    // 
    // Oczekiwany wynik:
    // Gdansk avg = ..., std_dev = ...
    // Gdynia avg = ..., std_dev = ...
    // ... pozostale miasta ...

    //cin.get();
    return 0;
}



int odejmij(int a, int b)
{
    cout << a << " - " << b << " = ";
    return a - b;
}

