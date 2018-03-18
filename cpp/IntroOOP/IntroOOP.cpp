// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
using namespace std;


class Kwadrat
{
    // deklarujemy wszystkie pola i metody jako PUBLICZNE
    // czyli takie do ktorych mozna sie dostac spoza klasy
public:
    int a;

    int obliczPole()
    {
        return a * a;
    }
    int obliczObwod()
    {
        return 4 * a;
    }
};


class Prostokat
{
public:
    int obliczPole()
    {
        return a * b;
    }

    int obliczObwod()
    {
        return 2 * (a + b);
    }

    // teraz boki są zadeklarowane jako pola PRYWATNE
    // czyli takie do ktorych mamy dostęp wyłacznie z klasy
private:
    int a, b;
};


class Prostokat2
{
public:
    // specjalna metoda KONSTRUKTOR, ktorej zadaniem jest konstrukcja obiektu - 
    // - ustawienie wartosci poczatkowych
    Prostokat2(int _a, int _b)
    {
        a = _a;
        b = _b;
    }

    int obliczPole()
    {
        return a * b;
    }

    int obliczObwod()
    {
        return 2 * (a + b);
    }

    // teraz boki są zadeklarowane jako pola PRYWATNE
    // czyli takie do ktorych mamy dostęp wyłacznie z klasy
private:
    int a, b;
};


// Program do obliczania właściwości figur geometrycznych.
int main()
{
    Kwadrat k;
    k.a = 5;
    cout << "Pole kwardratu = " << k.obliczPole() << endl;
    cout << "Obwod kwadratu = " << k.obliczObwod() << endl << endl;

    Prostokat p;
    // a i b są polami prywatnymi - nie mamy tutaj do nich dostępu
    //p.a = 5;
    //p.b = 7;
    cout << "Pole prostokata = " << p.obliczPole() << endl;
    cout << "Obwod prostokata = " << p.obliczObwod() << endl << endl;

    // Teraz użyjmy figury dla której zdefiniowalismy konstruktor
    // ale teraz taka konstrukcja jest niedozwolona - brak konstruktora domyślnego
    // Prostokat2 p2;
    Prostokat2 p2(5, 7);
    cout << "Pole prostokata = " << p2.obliczPole() << endl;
    cout << "Obwod prostokata = " << p2.obliczObwod() << endl << endl;


    // Cwiczenie
    // Napisz program obsługujący kantor.
    // 1) Zdefiniuj klasę Kantor:
    //  a) W konstrukorze pobierz jako argumenty:
    //  - średni kurs USD/PLN
    //  - średni kurs EUR/PLN
    //  b) Zdefiniuj na stałe spread wymiany na poziomie 10%
    //  c) Zdefiniuj interfejs klasy z metodami:
    //  - kupUsd(float pln);
    //  - sprzedajUsd(float pln);
    //  - kupEur(float pln);
    //  - sprzedajUsd(float pln);
    //  wszystkie pozostałe pola i metody powinny zostać ukryte!
    // 2) utwórz obiekt typu Kantor i dokonaj operacji:
    //  a) kup USD za 100 PLN
    //  b) sprzedaj otrzymane USD
    //  c) za otrymane PLNy kup EUR
    //  d) sprzedaj otrzymane EUR

    // Ile kantor zarobił na tych operacjach?

    return 0;
}

