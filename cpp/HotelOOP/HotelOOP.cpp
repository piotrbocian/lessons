// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "stdafx.h"
#include "Pokoj.h"

#include <iostream> // biblioteka do funkcji wypisujących dane na ekran

using namespace std;    // pozwala używać funkcji biblioteki standardowej (std) 
                        // bez używania przedrostka za każdym razem
                        // np. cout << "tekst" zamiast std::cout<< "tekst"


// KLASA definiująca obiekt Hotel
// klasa czyli zbiór obiektów (pól składowych) oraz metod (funkcji)
class Hotel
{
public:
    // metody publiczne klasy (tzw. "interfejs klasy")
    void wypiszPokoje()
    {
        for (int i = 0; i < 10; i++)
        {
            pokoje[i].wypisz();
        }
    }

    void zameldujDoPokoju(int numerPokoju, string nazwisko)
    {
        pokoje[numerPokoju].zamelduj(nazwisko);
    }

    void wymeldujZPokoju(int numerPokoju)
    {
        pokoje[numerPokoju].wymelduj();
    }

    // specjalna metoda zwana KONSTRUKTOREM
    // - zadaniem konstruktora jest powołanie obiekty do życia
    // - jeśli nie zdefiniowalismy swojego konstruktora to zostanie użyty konstruktor domyślny
    // - nie podajemy zwracanego typu
    Hotel() 
    {
        // konstruktor klasy Hotel używa kolejnych konstruktorów - klasy Pokoj
        pokoje[0] = Pokoj(1, 1, 49.99);
        pokoje[1] = Pokoj(1, 1, 49.99);
        pokoje[2] = Pokoj(1, 2, 59.99);
        pokoje[3] = Pokoj(1, 2, 59.99);
        pokoje[4] = Pokoj(1, 2, 59.99);
        pokoje[5] = Pokoj(2, 21, 149.99);
        pokoje[6] = Pokoj(2, 21, 149.99);
        pokoje[7] = Pokoj(2, 22, 149.99);
        pokoje[8] = Pokoj(3, 22, 149.99);
        pokoje[9] = Pokoj(3, 22, 199.99);
    }

private:
    // pola klasy
    Pokoj pokoje[10];

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
    Hotel hilton;
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
            hilton.wypiszPokoje();
            break;
        case '2':
        {
            int numerPokoju;
            cout << "Podaj numer pokoju: ";
            cin >> numerPokoju;

            cout << "Podaj nazwisko goscia: ";
            std::string nazwisko;
            cin >> nazwisko;

            hilton.zameldujDoPokoju(numerPokoju, nazwisko);
            break;
        }
        case '3':
        {
            int numerPokoju;
            cout << "Podaj numer pokoju: ";
            cin >> numerPokoju;

            hilton.wymeldujZPokoju(numerPokoju);
            break;
        }

        }

    } while (c != 'q');

    return 0;
}
