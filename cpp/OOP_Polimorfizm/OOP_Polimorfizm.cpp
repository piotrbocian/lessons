// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
#include "Figury.h"
using namespace std;

class Prostokat
{
public:
    Prostokat(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    int obliczPole()
    {
        return a * b;
    }

    int obliczObwod()
    {
        return 2 * (a + b);
    }

    void wypisz()
    {
        cout << "Prostokat o bokach " << a << ", " << b << endl;
    }

    // zadeklarujmy taką samą metodę jak wyżej ale jako metodę "wirtualną"
    // takie metody mogą być nadpisane przez klasy dziedziczące
    virtual void wypisz2()
    {
        cout << "Prostokat o bokach " << a << ", " << b << endl;
    }

protected:
    int a, b;
};


class Prostopadloscian : public Prostokat
{
public:
    Prostopadloscian(int a, int b, int h) : Prostokat(a, b)
    {
        this->h = h;
    }

    int obliczObjetosc()
    {
        return a * b * h;
        return obliczPole() * h;
    }

    void wypisz()
    {
        cout << "Prostopadloscian o bokach " << a << ", " << b << ", " << h << endl;
    }

    // do metody w klasie dziedziczącej możemy (opcjonalnie) dodać słowo 'override', dzięki temu:
    // - dajemy jasny komunikat że metoda nadpisuje działanie metody z klasy bazowej
    // - gdybyśmy użyli 'override' na metodzie nie-virtualnej, kompilator zgłosi błąd
    void wypisz2() override
    {
        cout << "Prostopadloscian o bokach " << a << ", " << b << ", " << h << endl;
    }

private:
    int h;
};


int main()
{
    Prostokat prostokat(1, 2);
    Prostopadloscian prostopadloscian(3, 4, 5);

    // POLIMORFIZM
    // Do klas Prostokat i Prostopadloscian dodajmy metode
    //   void wypisz()
    // ktora wypisze dane obiektu (zobacz metody w klasach)
    prostokat.wypisz();
    prostopadloscian.wypisz();
    // dzialanie programu jest na razie zgodne z oczekiwaniami.

    // Sprawdzmy teraz co zostanie wypisane dla tablicy prostokaty_wsk
    // zawierajacej 2 prostokaty i 2 prostopadlosciany.
    Prostokat* prostokaty_wsk[] =
    {
        new Prostokat(4, 5),
        new Prostokat(3, 4),
        new Prostopadloscian(2, 4, 5),
        new Prostopadloscian(4, 5, 5)
    };

    for (int i = 0; i < 4; i++)
    {
        cout << "figura nr " << i << " to ";
        prostokaty_wsk[i]->wypisz();
    }
    cout << endl;

    // Temu "problemowi" możemy zaradzić przez funkcje wirtualne
    // (zobacz metode void wypisz2() w klasach)
    for (int i = 0; i < 4; i++)
    {
        cout << "figura nr " << i << " to ";
        prostokaty_wsk[i]->wypisz2();
    }
    cout << endl << endl;

    // KLASY ABSTRAKCYJNE
    // definicje tych klas znajduja sie w pliku Figury.h
    Figura *tablica[] = {
        new Kolo(10),
        new Kwadrat(10),
    };

    for (auto figura : tablica)
    {
        cout << "pole = " << figura->obliczPole() << endl;
        cout << "obwod = " << figura->obliczObwod() << endl;
        cout << endl;
    }


    return 0;

    // Zadanie
    // Zmodyfikuj poprzedni program Zwierzeta:
    // 1) Poprzednio utworzoną metodę void wypiszInformacje(); zmien na metodę wirtualną i nadpisz ją w każdej klasie.
    // 2) W klasie Zwierze dodaj abstrakcyjna metode void dajGlos()=0,
    //    i nadpisz ją w klasach pochodnych, ktora wypisze na ekran odglos jakie dane zwierze wydaje
    // 3) utworz tablice Zwierzat z kilkoma roznymi gatunkami
    // 4) dla kazdego elementu tabicy wywolaj metode dajGlos() oraz wypiszInformacje()
}

