// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "stdafx.h"
#include "Pokoj.h"

#include <iostream> // biblioteka do funkcji wypisujących dane na ekran

using namespace std;    // pozwala używać funkcji biblioteki standardowej (std) 
                        // bez używania przedrostka za każdym razem
                        // np. cout << "tekst" zamiast std::cout<< "tekst"


class Hotel
{
public:
    void wypiszPokoje()
    {
        for (int i = 0; i < 10; i++)
        {
            pokoje[i].wypisz();
        }
    }

    void zamelduj(int numerPokoju, string nazwisko)
    {
        pokoje[numerPokoju].zamelduj(nazwisko);
    }

    void wymelduj(int numerPokoju)
    {
        pokoje[numerPokoju].wymelduj();
    }

private:
    Pokoj pokoje[10] = {
        Pokoj(1, 1, 49.99),
        Pokoj(1, 1, 49.99),
        Pokoj(1, 2, 59.99),
        Pokoj(1, 2, 59.99),
        Pokoj(1, 2, 59.99),
        Pokoj(2, 21, 149.99),
        Pokoj(2, 21, 149.99),
        Pokoj(2, 22, 149.99),
        Pokoj(3, 22, 149.99),
        Pokoj(3, 22, 199.99),
    };

};
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

            hotel.zamelduj(numerPokoju, nazwisko);
            break;
        }
        case '3':
        {
            int numerPokoju;
            cout << "Podaj numer pokoju: ";
            cin >> numerPokoju;

            hotel.wymelduj(numerPokoju);
            break;
        }

        }

    } while (c != 'q');

    return 0;
}
