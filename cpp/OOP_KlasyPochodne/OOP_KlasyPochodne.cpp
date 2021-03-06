// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
using namespace std;

#include "Prostokat.h"

#include "Zwierzeta.h"

int main()
{
    zoo();
    Prostokat prostokat(5, 6);
    prostokat.obliczObwod();
    prostokat.obliczPole();

    Prostopadloscian prostopadloscian(10, 20, 40);
    prostopadloscian.obliczPole();
    prostopadloscian.obliczObwod();
    prostopadloscian.obliczObjetosc();

    // W funkcji ktora wymaga obiektu klasy Prostokat, mozemy podac prostokat lub prostopadloscian,
    // poniewaz prostopadloscian dziedziczy po prostokacie wiec ma wszystkie jego wlasciwosci.
    // Zachodzi tutaj "object slicing" - Prostopadlosc jest "przycinany" do rozmiarow "prostokata":
    cout << "sizeof(prostokat) = " << sizeof(prostokat) << endl;
    cout << "sizeof(prostopadloscian) = " << sizeof(prostopadloscian) << endl;
    cout << "wieksze pole ma figura nr " << porownajPola(prostokat, prostopadloscian) << endl;

    // Inny przykład "object slicing". Próba przypisania: Prostopadloscian -> Prostokat -> Prostopadloscian
    Prostokat p2 = prostopadloscian;    // mozemy rzutować "w dół"
    //Prostopadloscian pp2 = p2;        // ale nie możemy "w górę"

    // Jeszcze inny:
    // Tworząc tablice Prostokatow, mozemy podawac Prostokaty i Prostopadlosciany,
    // ale...
    Prostokat prostokaty[] =
    {
        Prostokat(4, 5),
        Prostokat(3, 4),
        Prostopadloscian(2, 4, 5),  // zostanie natychmiast rzutowany na Prostokat
        Prostopadloscian(4, 5, 5)   // zostanie natychmiast rzutowany na Prostokat
    };

    for (int i = 0; i < 4; i++)
    {
        cout << "figura nr " << i << endl;

        cout << "Obwod = " << prostokaty[i].obliczObwod() << endl;
        cout << "Pole = " << prostokaty[i].obliczPole() << endl;

        cout << endl;
    }

    // Inaczej sprawa ma się z tablicą wskaźników, w ktorej trzymamy adresy obiektow, a nie same obiekty
    Prostokat* prostokaty_wsk[] =
    {
        new Prostokat(4, 5),
        new Prostokat(3, 4),
        new Prostopadloscian(2, 4, 5),
        new Prostopadloscian(4, 5, 5)
    };


    for (int i = 0; i < 4; i++)
    {
        cout << "figura nr " << i << endl;
        
        cout << "Obwod = "  << prostokaty_wsk[i]->obliczObwod() << endl;
        cout << "Pole = "   << prostokaty_wsk[i]->obliczPole() << endl;
        
        cout << endl;
    }

    //tablica[3]->obliczObjetosc();   // tablica[] jest typu Prostokat, nie Prostopoadloscia
                                    // więc nie ma metody obliczObjetosc()
    static_cast<Prostopadloscian*>(prostokaty_wsk[3])->obliczObjetosc();

    // co sie moze stac jesli wszystkie figury potraktujemy jak prostopadlosciany?
    for (int i = 0; i < 4; i++)
    {
        cout << "figura nr " << i << endl;

        Prostopadloscian *prosto = static_cast<Prostopadloscian*>(prostokaty_wsk[i]);
        cout << "Obwod = "      << prosto->obliczObwod() << endl;
        cout << "Pole = "       << prosto->obliczPole() << endl;
        cout << "Objetosc = "   << prosto->obliczObjetosc() << endl;

        cout << endl;
    }

    // WNIOSEK
    // static_cast<> mozemy uzywac TYLKO wtedy kiedy znamy typ obiektu



    return 0;
}

