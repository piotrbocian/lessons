// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "stdafx.h"

#include <iostream> // biblioteka do funkcji wypisuj¹cych dane na ekran
#include <string>   // biblioteka do pracy z tekstami (std::string)
#include <iomanip>  // biblioteka do manipulacji tekstem (np. wyrownanie)

using namespace std;    // pozwala u¿ywaæ funkcji biblioteki standardowej (std) 
                        // bez u¿ywania przedrostka za ka¿dym razem
                        // np. cout << "tekst" zamiast std::cout<< "tekst"


void WypiszPokoje(const int liczbaPokoi, int standard[], int lozka[], float cena[]);


/*
Napiszemy aplikacjê do obs³ugi hotelu.
Wymagania:
1) zarz¹dzanie pokojami
2) zarz¹dzanie goœæmi
3) ...
*/
int main()
{
    // Zacznijmy od pokoi, których w hotelu mamy 10
    // ka¿dy pokój posiada pewne parametry:
    // - standard
    // - konfiguracjê ³ó¿ek
    // - cenê

    // Mo¿emy utworzyæ 3 tablice które nam bêd¹ definiowa³y pokoje
    const int LICZBA_POKOI = 10;

    // 1 - standard "ekonomiczny"
    // 2 - standard "apartament"
    // 3 - standard "prezydencki"
    int standardPokoju[LICZBA_POKOI] = {
        1, 1, 1, 1, 1,
        2, 2, 2, 2, 3 };

    // 1 - pojedyncze
    // 11- 2 x pojedyncze
    // 2 - podwojne
    // 22- 2 x podwojne
    // 21- podwojne + pojedyncze
    int konfiguracjaLozek[LICZBA_POKOI] = {
        1, 1, 11, 11, 2,
        2, 2, 21, 21, 22
    };

    float cena[LICZBA_POKOI] = {
        49.99, 49.99, 49.99, 79,
        109, 129, 129, 129, 199
    };

    // Dodajmy funkcjê która wydrukuje dane o wszystkich pokojach
    WypiszPokoje(LICZBA_POKOI, standardPokoju, konfiguracjaLozek, cena);


    // Pokoje mog¹ byæ zajête lub nie...
    bool zajety[LICZBA_POKOI] = {
        false, false, false, false, false,
        false, false, false, false, false
    };

    string nazwiskoGoscia[LICZBA_POKOI];

    // na razie zameldujmy goœcia tylko do pokoju prezydenckiego
    zajety[9] = true;
    nazwiskoGoscia[9] = "Nowak";


    // Interfejs uzytkownika w konsoli
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
            WypiszPokoje(LICZBA_POKOI, standardPokoju, konfiguracjaLozek, cena);
            break;
        case '2':
        {
            int numerPokoju;
            cout << "Podaj numer pokoju: ";
            cin >> numerPokoju;

            cout << "Podaj nazwisko goscia: ";
            std::string nazwisko;
            cin >> nazwisko;

            if (zajety[numerPokoju])
            {
                cout << "Pokoj jest juz zajety przez " << nazwiskoGoscia[numerPokoju] << endl;
            }
            else
            {
                zajety[numerPokoju] = true;
                nazwiskoGoscia[numerPokoju] = nazwisko;
            }
            break;
        }
        case '3':
        {
            int numerPokoju;
            cout << "Podaj numer pokoju: ";
            cin >> numerPokoju;

            if (zajety[numerPokoju])
            {
                zajety[numerPokoju] = false;
                nazwiskoGoscia[numerPokoju] = "";
            }
            else
            {
                cout << "W pokoju nikt nie jest zameldowany!" << endl;
            }
            break;
        }

        }

    } while (c != 'q');

    return 0;
}
// Taki program przestaje nam siê szybko skalowaæ.
// Za ka¿dym razem gdy dodajemy nowy parametr do pokoju
// musimy modyfikowaæ znaczn¹ czêœæ kodu.

void WypiszPokoje(const int liczbaPokoi, int standard[], int lozka[], float cena[])
{
    for (int i = 0; i < liczbaPokoi; i++)
    {
        cout << setw(5) << (i+1)        // numer pokoju (od 1 do 10)
             << setw(5) << standard[i]
             << setw(5) << lozka[i] 
             << setw(10) << cena[i];
        cout << endl;
    }
}
