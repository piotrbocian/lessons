// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

// cpp01.cpp:
// Temat 1 - wypisywanie tekstu na konsole
// Temat 2 - zmienne
// Temat 3 - wczytywanie danych z konsoli przy pomocy std::cin
// Temat 4 - instrukcje warunkowe
// Temat 5 - pêtle

#include "stdafx.h"

#include <stdio.h>  // C style (printf)
#include <iostream> // C++ style (cout/cin)

#include <string>

using namespace std;

int main()
{
    // Temat 1 - wypisywanie tekstu na konsole
    // C++ style
    std::cout << "hello" << std::endl;
    cout << "hello" << endl;    // mo¿emy pomin¹æ std:: dziêki linijce (11) using namespace std;
    cout << "Jestem Piotr, mam " << 31 << " lat" << endl;   // 31 jest konwertowane na tekst (string)
    cout << "Jestem nerdem, mam " << 0x1f << " lat" << endl;// 0x1f jest konwertowane na tekst i efekt dzia³ania bêdzie identyczny jak powy¿ej


    // C style
    puts("hello");
    printf("hello\n");
    printf("Jestem Piotr, mam %i lat\n", 31);   // http://www.cplusplus.com/reference/cstdio/printf/


    // Temat 2 - zmienne
    // przyk³ady deklaracji zmiennych
    // oraz u¿ycie operatora sizeof() do sprawdzenia ile bajtów ma dany typ
    {
        bool b1 = true, b2 = false;
        char c1 = 1, c2 = '1', c3 = 0x1, c4 = 'a', c5 = 0xa;          // 1 byte
        short int s1 = 32767; short s2 = -100; short s3 = 0x1234;    // >=2 bytes
        int i = 2147483647;                      // >=2 bytes (4 bytes usually)
        long int l1 = 2147483647; long l2 = 0;       // >=4 bytes
        long long int ll1 = 9223372036854775807; long long ll2 = 0;   // >=8 bytes
        float f1 = 167.899f, f2 = 124e4f;

        cout << "size of bool: " << sizeof(bool) << endl;
        cout << "size of char: " << sizeof(char) << endl;
        cout << "size of short (int): " << sizeof(short) << endl;
        cout << "size of int: " << sizeof(int) << endl;
        cout << "size of long (int): " << sizeof(long) << endl;
        cout << "size of long long: " << sizeof(long long) << endl;

        cout << "b1 = " << b1 << ", b2 = " << b2 << endl;
        cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
        cout << "s1 = " << s1 << ", s2 = " << s2 << endl;
        cout << "i = " << i << endl;
        cout << "l1 = " << l1 << ", l2 = " << l2 << endl;
        cout << "f1 = " << f1 << ", f2 = " << f2 << endl;


        // signed - liczby "ze znakiem" czyli dodatnie i ujemne
        // signed jest domyœlne czyli: int a = signed int a
        // unsigned - liczby "bez znaku" czyli tylko dodatnie
        unsigned short int us = s2;
        cout << "signed short = " << s2 << ", unsigned short = " << us << endl;

        // const
        int c = 300000;
        const int C = 300000;

        c = 4;
        //C = 5;    // b³¹d - nie mo¿na ponownie przypisaæ do sta³ej

    }

    // Temat 3 - wczytywanie danych z konsoli przy pomocy std::cin
    cout << "Podaj swoje imie: ";
    string imie;
    cin >> imie;

    cout << "Podaj wiek: ";
    int wiek;
    cin >> wiek;

    cout << "Jestem " << imie << ", mam " << wiek << " lat" << endl;



    // Cwiczenie 1
    // Napisz program ktory spyta o dane i przeliczy PLN na USD/EUR



    // Temat 4 - instrukcje warunkowe
    if (wiek >= 18)
        cout << "moge honorowo oddac krew" << endl;
    cout << "moge zrobic prawo jazdy" << endl;  // czêsty b³¹d u pocz¹tkuj¹cych!!!
    // po sprawdzeniu warunku w if() wykonana jest TYLKO jedna nastêpna instrukcja
    // jesli chcemy wykonac wiecej instrukcji, musz¹ byæ zawarte w { }
    if (wiek >= 18)
    {
        cout << "moge honorowo oddac krew" << endl;
        cout << "moge zrobic prawo jazdy" << endl;
    }


    // Cwiczenie 2
    // Napisz program wczytujacy 3 liczby calkowite i wypisujacy liczbe najwieksza


    // Temat 5 - pêtle
    cout << "for loop";
    {
        int i;
        for (i = 0; i < 10; i++)
            cout << i << endl;
        cout << i*i << endl;        // czêsty b³¹d u pocz¹tkuj¹cych!!!
        // podobnie jak w instrukcji if(),
        // po wykonaniu operacji w nawiasach for(;;) wykonana jest TYLKO jedna nastêpna instrukcja
        // jesli chcemy wykonac wiecej instrukcji, musz¹ byæ zawarte w { }
        for (i = 0; i < 10; i++)
        {
            cout << i << endl;
            cout << i*i << endl;
        }
    }


    // while / do-while
    cout << "while loop";
    {
        int i = 0;
        while (i < 10)
        {
            cout << i << endl;
            i++;
        }
    }


    // Przyklad - policz sume liczb od 1 do 100
    {
        int i = 0;
        int sum = 0;
        for (i = 1; i <= 100; i = i + 1)
            sum = sum + i;

        cout << "Suma liczb od 1 do 100 = " << sum << endl;
    }


    // Cwiczenie - sprawdz czy liczba jest pierwsza
    // liczba pierwsza - liczba, ktora dzieli sie tylko przez 1 i przez sam¹ siebie


}

