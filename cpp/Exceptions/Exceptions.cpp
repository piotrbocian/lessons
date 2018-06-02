// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian


#include <iostream>


using namespace std;

// deklaracja wyjątku przez dziedziczenie z wyjątku wbudowanego
class DivideByZeroException : public std::exception
{
public:
    const char * what() const throw () {
        return "Nie wolno dzielic przez 0!!!";
    }
};

// Funkcja do dzielenia odporna na dzielenie przez zero
int podziel(int a, int b)
{
    if (b == 0)
    {
        //throw std::exception("Nie wolno dzielic przez 0!!!"); // wyjątek wbudowany
        throw DivideByZeroException();  // wyjątek zdefiniowany przez nas
    }

    return a / b;
}

// Funkcja służąca do ilustracji 'propagacji wyjątków'
void fragmentWiekszegoProgramu()
{
    int a = 7;
    int b = 0;
    double wynik = podziel(a, b);
    if (wynik > 3)
    {
        // ...
    }
    else
    {
        // ...
    }
}


// Zastosowanie wyjątków w konstuktorach
class Kalk
{
public:
    Kalk()
    {
        // coś w konstuktorze poszło nie tak...
        throw std::exception("Wyjatek z konstuktora");
    }
};


int main()
{
    // wyjątek nieobsłużony:
    //cout << podziel(5, 0);

    // obsługa wyjątków
    try
    {
        cout << podziel(7, 2) << endl;
        cout << podziel(5, 0) << endl;
    }
    // wyjątki łapiemy w kolejności od szczegółowych do ogólnych
    catch (DivideByZeroException e)
    {
        cout << e.what() << endl;
    }
    catch (std::exception e)
    {
        cout << e.what() << endl;
    }
    
    // wyjątek zostanie spropagowany z funkcji podziel() do fragmentWiekszegoProgramu() i dopiero w main() go złapiemy
    try
    {
        fragmentWiekszegoProgramu();
    }
    catch (DivideByZeroException e)
    {
        cout << e.what() << endl;
    }

    // wyjątek złapany w konstuktorze kalkulatora
    try
    {
        Kalk k;
    }
    catch (std::exception e)
    {
        cout << e.what() << endl;
    }


    // Zadanie
    // Napisz 8-cyfrowy kalkulator liczb całkowitych z funkcją logowania do pliku.
    // 1) W konstuktorze:
    //  a) wczytaj z konsoli dwie liczby:
    // - jeśli podano nie liczbę całkowitą - rzuć wyjątkiem
    //   (wczytanie i sprawdzenie liczby np. przy pomocy std::cin>> oraz std::cin.good())
    // - jeśli podano liczbę spoza zakresu - rzuć (innym) wyjątkiem
    //  b) otwórz plik w ktorym logowanie będą wykonywane operacje
    //  obsługa plików w C++:
    //   http://www.cplusplus.com/doc/tutorial/files/:
    //   ofstream: Stream class to write on files
    //   ifstream: Stream class to read from files
    //   fstream : Stream class to both read and write from / to files.
    // 2) Napisz metody zwracające wynik oraz logujące operacje do pliku
    //   int dodaj()
    //   int odejmij()
    //   int pomnoz()
    //   int podziel()
    // Jesli w metodzie wystąpi:
    // - przepelnienie zakresu - wyjątek
    // - dzielenie przez zero - wyjątek
    // 3) W destruktorze zamknij plik oraz dodaj komunikat o wyjściu z kalkulkatora.
    // 4) Utwórz obiekt zdefiniowanej klasy i wykonaj na nim kilka operacji.
    // 5) Obsłuż wygenerowane wyjątki w sekcji try{} catch{}
    return 0;
}

