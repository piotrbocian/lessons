// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
using namespace std;

// dodatkowe materiały:
// https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm

// deklaracja wyjątku przez dziedziczenie z wyjątku wbudowanego
// spójrz na funkcję niżej (int podziel(a, b)) po przykład użycia
class DivideByZeroException : public std::exception
{
public:
    // nadpisujemy komunikat funkcji what() naszym własnym komunikatem
    const char * what() const throw () {
        return "Nie wolno dzielic przez 0!!!";
    }
};

// Funkcja do dzielenia odporna na dzielenie przez zero
int podziel(int a, int b)
{
    // gdy pojawi się sytuacja błędna, dobrym sposobem zasygnalizowania tego użytkownikowi jest
    // "rzucenie wyjątku" (ang. 'throw exception')
    if (b == 0)
    {
        // możemy tutaj użyć wbudowanego typu std::exception albo rzucić własnym wyjątkiem:
        
        // wyjątek wbudowany:
        //throw std::exception("Nie wolno dzielic przez 0!!!");

        // wyjątek zdefiniowany przez nas:
        throw DivideByZeroException();
    }

    return a / b;
}

// Funkcja służąca do ilustracji 'propagacji wyjątków'.
// Funkcja ta woła funkcję podziel(a, b) gdzie powstanie wyjątek z powodu dzielenia przez 0
// ale ten wyjątek nie zostanie tutaj obsłużony tylko zostanie przesłany wyżej
void fragmentWiekszegoProgramu()
{
    // ...
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
// Jak wiemy, funkcja konstruktora nie zwraca żadnego typu,
// więc w jaki sposób powiedzieć, że coś poszło nie tak? Rzucić wyjątkiem.
class Kalk
{
public:
    Kalk()
    {
        // coś w konstuktorze poszło nie tak...
        throw std::exception("Wyjatek z konstuktora");
    }
};


// Przykłady użycia powyższych funkcji
int main()
{
    // wyjątek nieobsłużony:
    //cout << podziel(5, 0);

    // obsługa wyjątków w sekcji try{} catch{}
    // try{} - umieszczamy tutaj fragment kodu gdzie możemy otrzymać wyjątek
    try
    {
        cout << podziel(7, 2) << endl;
        cout << podziel(5, 0) << endl;
    }
    // catch(){} - wyłapujemy określone wyjątki
    // wyjątki łapiemy w kolejności od szczegółowych do ogólnych
    catch (DivideByZeroException e)
    {
        cout << e.what() << endl;
    }
    catch (std::exception e)
    {
        cout << e.what() << endl;
    }
    
    // Przykład - propagacja wyjątków
    // wyjątek zostanie spropagowany z funkcji podziel() do fragmentWiekszegoProgramu() i dopiero w main() go złapiemy
    try
    {
        // funkcja poniżej nie wyłapuje wyjątku dlatego zostanie on przekazany aż tutaj
        // gdybyśmy teraz tego wyjątku nie złapali, program by się wywalił
        fragmentWiekszegoProgramu();
    }
    catch (DivideByZeroException e)
    {
        cout << e.what() << endl;
    }

    // Przykład - zastosowanie wyjątków w konstuktorze
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

