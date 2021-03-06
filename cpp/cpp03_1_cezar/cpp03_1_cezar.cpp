// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "stdafx.h"

#include <iostream>

using namespace std;

int main()
{
    // ETAP 1
    // 1) wczytaj TEKST (1 linijke) ze standardowego wejscia (STDIN) (max length = 255 znaków) -> jak wczytać linijke tekstu
    // 2) wczytaj KLUCZ (liczba typu int) ze STDIN
    // 3) zakoduj TEKST szyfrem cezara używając KLUCZa
    // 4) wypisz zaszyfrowany TEKST do standardowego wyjścia (STDOUT)
    // 5) wypisz KLUCZ ze znakiem minus do STDOUT

    // ETAP 2
    // 1) wczytaj TEKST (1 linijke) ze standardowego wejscia (STDIN) (max length = 255 znaków) -> jak wczytać linijke tekstu
    // 2) KLUCZ (liczba typu int) jest niejawna 
    // 3) napisz program który pomoże Ci rozszyfrować tekst (brute force)
    // 4) wyślij rozszyfrowany tekst oraz program na moodle
    char tekst[256];
    int klucz;
    cin.getline(tekst, 256);
    cin >> klucz;
    //if (!cin.eof())
    {
        for (int i = 0; i < strlen(tekst); i++)
        {
            tekst[i] += klucz;
        }
        cout << tekst << endl;
        cout << klucz * (-1);
    }
    /*
    else
    {
        char wiadomosc[256] = { 0 };

        for (int klucz = 0; klucz < 256; klucz++)
        {
            for (int i = 0; i < strlen(tekst); i++)
            {
                wiadomosc[i] = tekst[i] + klucz;
            }
            cout << klucz << ": " << wiadomosc << endl;
        }
    }
    */


    return 0;

}

