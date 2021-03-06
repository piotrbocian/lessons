// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "stdafx.h"

#include <iostream> // biblioteka do funkcji wypisujących dane na ekran
#include <string>   // biblioteka do pracy z tekstami (std::string)
#include <iomanip>  // biblioteka do manipulacji tekstem (np. wyrownanie)

using namespace std;    // pozwala używać funkcji biblioteki standardowej (std) 
                        // bez używania przedrostka za każdym razem
                        // np. cout << "tekst" zamiast std::cout<< "tekst"


class Pokoj
{
public:
    // 1 - standard "ekonomiczny"
    // 2 - standard "apartament"
    // 3 - standard "prezydencki"
    int standard;

    // 1 - pojedyncze
    // 11- 2 x pojedyncze
    // 2 - podwojne
    // 22- 2 x podwojne
    // 21- podwojne + pojedyncze
    int lozka;

    // cena pokoju za noc
    float cena;

    // true - pokój jest zajety
    // false - pokój jest wolny
    bool zajety;

    // nazwisko gościa zameldowanego w pokoju
    string nazwiskoGoscia;

    /*
    // wypisz informacje o pokoju
    void wypisz()
    {
        cout << setw(5) << standard << setw(5) << lozka << setw(10) << cena;
        cout << setw(20) << nazwiskoGoscia << endl;
    }

    void zamelduj(string nazwisko)
    {
        if (zajety)
        {
            cout << "Pokoj jest juz zajety przez " << nazwiskoGoscia << endl;
        }
        else
        {
            zajety = true;
            nazwiskoGoscia = nazwisko;
        }
    }

    void wymelduj()
    {
        if (zajety)
        {
            zajety = false;
            nazwiskoGoscia = "";
        }
        else
        {
            cout << "W pokoju nikt nie jest zameldowany!" << endl;
        }
    }
    */

};  // pamiętajmy o średniku na końcu deklaracji klasy


// KLASA definiująca obiekt Hotel
// klasa czyli zbiór obiektów (pól składowych) oraz metod (funkcji)
class Hotel
{
public:
    // pola klasy
    Pokoj pokoje[10];

    // metody klasy
    void wypiszPokoje()
    {
        // najprostsza implementacja metody wypiszPokoje():
        // iterujemy po wszystkich pokojach i wypisujemy parametry pokojy
        for (int i = 0; i < 10; i++)
        {
            cout << setw(5) << pokoje[i].standard 
                 << setw(5) << pokoje[i].lozka 
                 << setw(10) << pokoje[i].cena
                 << setw(20) << pokoje[i].nazwiskoGoscia << endl;

            // Ale może przenieść funkcjonalność do klasy Pokoj
            // tak aby mógł sam siebie wypisać?

            //pokoje[i].wypisz();
        }
    }

    void zameldujDoPokoju(int numerPokoju, string nazwisko)
    {
        //pokoje[numerPokoju].zamelduj(nazwisko);
    }

    void wymeldujZPokoju(int numerPokoju)
    {
        //pokoje[numerPokoju].wymelduj();
    }

    /*
    // specjalna metoda zwana KONSTRUKTOREM
    // - zadaniem konstruktora jest powołanie obiekty do życia
    // - jeśli nie zdefiniowalismy swojego konstruktora to zostanie użyty konstruktor domyślny
    // - nie podajemy zwracanego typu
    Hotel() 
    {
        pokoje[0].standard = 1;
        pokoje[0].lozka = 1;
        pokoje[0].cena = 49.99;
        pokoje[0].zajety = false;
        pokoje[0].nazwiskoGoscia = "";

        pokoje[1].standard = 1;
        pokoje[1].lozka = 1;
        pokoje[1].cena = 49.99;
        pokoje[1].zajety = false;
        pokoje[1].nazwiskoGoscia = "";

        pokoje[2].standard = 1;
        pokoje[2].lozka = 2;
        pokoje[2].cena = 69.99;
        pokoje[2].zajety = false;
        pokoje[2].nazwiskoGoscia = "";

        // ...
    }
    */

};  // pamiętajmy o średniku na końcu deklaracji klasy


/*
Napiszemy aplikację do obsługi hotelu.
Wymagania:
1) zarządzanie pokojami
2) zarządzanie gośćmi
3) ...
*/
int main()
{
    // Budujemy nasz hotel przez deklarację obiektu
    Hotel hotel;
    // Wszystko jest już gotowe.
    // Teraz możemy przejść do części kontrolnej programu

    char c;
    do {
        cout << "Wybierz opcje" << endl;
        cout << "[1] Wypisz pokoje" << endl;
        cout << "[2] Zamelduj goscia" << endl;
        cout << "[3] Wymelduj goscia" << endl;
        cout << "[q] Wyjdz" << endl;
        cin >> c;

        switch (c)
        {
        case '1':
            hotel.wypiszPokoje();
            break;
        case '2':
        {
            int numerPokoju;
            cout << "Podaj numer pokoju: ";
            cin >> numerPokoju;

            cout << "Podaj nazwisko goscia: ";
            std::string nazwisko;
            cin >> nazwisko;

            hotel.zameldujDoPokoju(numerPokoju, nazwisko);
            break;
        }
        case '3':
        {
            int numerPokoju;
            cout << "Podaj numer pokoju: ";
            cin >> numerPokoju;

            hotel.wymeldujZPokoju(numerPokoju);
            break;
        }

        }

    } while (c != 'q');

    return 0;
}
