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


class Kolo
{
public:
    // specjalna metoda KONSTRUKTOR, ktorej zadaniem jest konstrukcja obiektu - 
    // - ustawienie wartosci poczatkowych
    Kolo(double promien)
    {
        r = promien;
        std::cout << "Tworze kolo o promieniu " << promien << endl;
    }

    double obliczPole()
    {
        return pi * r * r;
    }

    double obliczObwod()
    {
        return 2 * pi * r;
    }

    // teraz boki są zadeklarowane jako pola PRYWATNE
    // czyli takie do ktorych mamy dostęp wyłacznie z klasy
private:
    double r;
    double pi = 3.1416;
};


// Program do obliczania właściwości figur geometrycznych.
int main()
{
    Kwadrat k;
    k.a = 5;
    cout << "Pole kwardratu = " << k.obliczPole() << endl;
    cout << "Obwod kwadratu = " << k.obliczObwod() << endl << endl;

    // obowiązują te same zasady tworzenia obiektów co przy typach prostych:
    // - mogą być tworzone na stosie (jak 'int a'), powyżej ^
    // - mogą być tworzone na stercie (jak 'int *a = new int), poniżej
    Kwadrat *k_na_stercie = new Kwadrat;
    // aby dostać się do elementów k_na_stercie musimy użyć operatora *
    (*k_na_stercie).a = 6;
    // ponieważ taki zapis '*().' jest skomplikowany to możemy użyć uproszczonej formy
    // z operatorem '->'
    k_na_stercie->a = 6;


    Prostokat p;
    // a i b są polami prywatnymi - nie mamy tutaj do nich dostępu
    //p.a = 5;
    //p.b = 7;
    cout << "Pole prostokata = " << p.obliczPole() << endl;
    cout << "Obwod prostokata = " << p.obliczObwod() << endl << endl;


    // Teraz użyjmy figury dla której zdefiniowalismy konstruktor
    // ale teraz taka konstrukcja jest niedozwolona - brak konstruktora domyślnego
    //Kolo kolo;
    Kolo kolo(10);
    cout << "Pole kola = " << kolo.obliczPole() << endl;
    cout << "Obwod kola = " << kolo.obliczObwod() << endl << endl;


    // Cwiczenie
    // Napisz program obsługujący kantor.
    // 1) Zdefiniuj klasę Kantor:
    //  a) W konstrukorze pobierz jako argumenty:
    //  - średni kurs USD/PLN
    //  - średni kurs EUR/PLN
    //  b) Zdefiniuj na stałe spread wymiany na poziomie 10%/10gr
    //  c) Zdefiniuj interfejs (metody publiczne) klasy z metodami:
    //  - kupUsd(float pln);
    //  - sprzedajUsd(float usd);
    //  - kupEur(float pln);
    //  - sprzedajEur(float eur);
    //  wszystkie pozostałe pola i metody powinny zostać ukryte (prywatne)!
    // 2) utwórz obiekt typu Kantor i dokonaj operacji:
    //  a) kup USD za 100 PLN
    //  b) sprzedaj otrzymane USD
    //  c) za otrymane PLNy kup EUR
    //  d) sprzedaj otrzymane EUR

    // Ile kantor zarobił na tych operacjach?

    return 0;
}

