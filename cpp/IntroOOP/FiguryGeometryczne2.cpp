// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
#include <string>
using namespace std;

// Poddamy program z poprzednich zajec lekkim modyfikacjom:
// 1/ Dobra praktyka jest umieszczenie kazdej wiekszej klasy w osobnym pliku:
//   a/ możemy całość przenieść do pliku .h
//   b/ lub rozbić na plik .h i .cpp

// Klasę Kwadrat przenosimy w całości do pliku Kwadrat.h
// Konwencja: taka sama nazwa pliku jak nazwa klasy.
// Teraz tylko includujemy naglowek:
#include "Kwadrat.h"

/*
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
*/

// Klase Prostokat rozbijemy na plik Prostokat.h i Prostokat.cpp,
// Tutaj wystarczy tylko includowac Prostokat.h:
#include "Prostokat.h"

/*
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
*/


// LISTA INICJALIZACYJNA:
// 1) do inicjalizacji skladnikow const
// 2) pomijamy kopiowanie obiektow

// Na przykladzie klasy Kolo - co gdyby pole 'r' bylo const?
class Kolo
{
public:
    // specjalna metoda KONSTRUKTOR, ktorej zadaniem jest konstrukcja obiektu - 
    // - ustawienie wartosci poczatkowych
    Kolo(double promien) : r(promien)
    {
        //r = promien; // BŁĄD - nie mozna modyfikowac stalej!!!
        std::cout << "Tworze kolo o promieniu " << promien << endl;
    }

    double obliczPole()
    {
        return pi * r * r;
    }

    double obliczObwod() const
    {
        return 2 * pi * r;
    }

    // teraz boki są zadeklarowane jako pola PRYWATNE
    // czyli takie do ktorych mamy dostęp wyłacznie z klasy
private:
    const double r;
    const double pi = 3.1416;
};


// Przekazywanie obiektów jako parametrów
// Dodajmy teraz funkcję ktora sprawdzi ktora z figur jest wieksza - kwadrat czy okrag?
// Parametrami funkcji są obiekty typu Kwadrat i Kolo
string porownajPola(Kwadrat kwadrat, Kolo kolo)
{
    if (kwadrat.obliczPole() < kolo.obliczPole())
        return "kwadrat";
    else
        return "kolo";

    // Bonus - jaki musi byc promien kola i bok kwadratu aby pola byly rowne?:)
}

// Teraz napiszmy funkcje do porownywania obwodow
// ALE dodajmy atrybut const do parametrow - w koncu nie chcemy ich modyfikowac tutaj
string porownajObwody(const Kwadrat kwadrat, const Kolo kolo)
{
    if (kwadrat.obliczObwod() < kolo.obliczObwod())
        return "kwadrat";
    else
        return "kolo";
}


// Oczywiscie mozemy przekazywac tez przez referencje.
// Zysk pojawia sie przy DUZYCH obiektach - unikamy kopiowania kilkudziesieciu/kilkuset bajtow
string porownajPola_ref(Kwadrat &kwadrat, Kolo &kolo)
{
    if (kwadrat.obliczPole() < kolo.obliczPole())
        return "kwadrat";
    else
        return "kolo";
}

string porownajObwody_ref(const Kwadrat &kwadrat, const Kolo &kolo)
{
    if (kwadrat.obliczObwod() < kolo.obliczObwod())
        return "kwadrat";
    else
        return "kolo";
}

// Pola i metody statyczne - wspolne dla wszystkich obiektow klasy
class Trojkat
{
public:
    Trojkat()
    {
        cout << "Tworze trojkat nr " << licznikTrojkatow++ << endl;
    }

    // metoda statyczna:
    // - moze odwolywac sie tylko do pol i metod statycznych
    // - moze byc wywolana na klasie a nie na obiekcie
    static void wypiszLiczbeTrojkatow()
    {
        cout << "Utworzono " << licznikTrojkatow << " trojkatow." << endl;
        //a = 5;  // nie mozemy modyfikowac wlasciwosci obiektow w metodach statycznych
    }
private:
    // pole statyczne - wspolne dla wszystkich obiektow klasy
    static int licznikTrojkatow;

    int a, h;
};

// statyczny skladnik musi byc zainicjowany poza klasa:
int Trojkat::licznikTrojkatow = 0;


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
    //Kolo kolo;
    Kolo kolo(10);
    cout << "Pole kola = " << kolo.obliczPole() << endl;
    cout << "Obwod kola = " << kolo.obliczObwod() << endl << endl;

    // możemy uzyc juz istniejącego obiektu (Kwadrat k) lub utworzyc nowy podczas wywolania (Kolo(5)):
    cout << "Wieksza pole ma " << porownajPola(k, Kolo(5)) << endl;
    cout << "Wiekszy obwod ma " << porownajObwody(k, Kolo(5)) << endl;

    Trojkat tablicaTrojkatow[10];

    // wywolanie metody statycznej:
    tablicaTrojkatow[0].wypiszLiczbeTrojkatow();    // na obiekcie
    Trojkat::wypiszLiczbeTrojkatow();               // na klasie

    return 0;
}


// Cwiczenie
// Przerob poprzedni program Kantor:
// 0) rozdziel klase na plik .h i .cpp
// 1) pola przechowujace kursy USD_PLN, EUR_PLN (podane jako parametry) zmien na const
// 2) metody ktore nie modyfikuja obiektow oznacz jako const
// 3) utworz drugi obiekt typu Kantor z innymi kursami i wywolaj kilka metod na nim
// 4) napisz metode, ktora porowna w ktorym Kantorze bardziej oplaca sie kupic USD:
// - przekazane parametry (obiekty lub refencje) powinny byc typu const
// 5) Dodaj pole prywatne, ktore bedzie zliczalo liczbe operacji WSZYSTKICH kantorow
// 6) Dodaj i wywolaj metode publiczna, ktora wypisze liczbe operacji WSZYSTKICH kantorow