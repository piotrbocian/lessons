// cpp01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>  // C style
#include <iostream> // C++ style

#include <string>

using namespace std;

int main()
{


    // C++ style
    std::cout << "hello" << std::endl;
    cout << "hello" << endl;    // using namespace std;
    cout << "Jestem Piotr, mam " << 31 << " lat" << endl;   // 31 is converted into string
    cout << "Jestem nerdem, mam " << 0x1f << " lat" << endl;// 0x1f is also sonverted into string


    // C style
    puts("hello");
    printf("hello\n");
    printf("Jestem Piotr, mam %i lat\n", 31);   // http://www.cplusplus.com/reference/cstdio/printf/


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


        // signed / unsigned
        unsigned short int us = s2;
        cout << "signed short = " << s2 << ", unsigned short = " << us << endl;

        // const
        int c = 300000;
        const int C = 300000;

        c = 4;
        //C = 5;    // error

    }
    // 1> 2>

    cout << "Podaj swoje imie: ";
    string imie;
    cin >> imie;

    cout << "Podaj wiek: ";
    int wiek;
    cin >> wiek;

    cout << "Jestem " << imie << ", mam " << wiek << " lat" << endl;


    // cwiczenie 1
    // Napisz program ktory spyta o dane i policzy
    // 1) BMI
    // 2) kW -> KM
    // 3) kurs $/€/z³

    cout << "Ile masz PLN?";
    float pln;
    cin >> pln;

    const float USD_PLN = 3.36f;
    const float EUR_PLN = 4.15f;

    cout << "Masz " << pln / USD_PLN << "USD / " << pln / EUR_PLN << "EUR" << endl;

    // if
    if (wiek >= 18)
        cout << "moge pic alkohol" << endl;
    cout << "moge chodzic na imprezy" << endl;  // czêsty b³¹d u pocz¹tkuj¹cych!!! uwaga na kolokwium

    // else-if
    // else

    // cwiczenie 2
    // Napisz program wczytujacy 3 liczby calkowite i wypisujacy liczbe najwieksza
    {
        cout << "podaj a b c: ";
        int a, b, c;
        cin >> a >> b >> c;
        int max = a;
        if (b > max) max = b;
        if (c > max) max = c;
        cout << max;
    }

    /*
    string zdanie;
    cout << "Co masz do powiedzenia?";
    getline(cin, zdanie);
    getline(cin, zdanie);
    */

    //cout << "powiem wam, ze " << zdanie;


    cerr << "O kurde, cos poszlo nie tak!" << endl;


    // int j albo zamkn¹æ w klamerki
    cout << "for loop";
    {
        int i;
        for (i = 0; i < 10; i++)    // for (i = 3; i < 10; i++, cout << "!" << endl)
            cout << i << endl;
        cout << i*i << endl;        // czêsty b³¹d u pocz¹tkuj¹cych!!! uwaga na kolokwium
    }


    // while / do-while
    cout << "while loop";
    int i = 0;
    while (i < 10)
    {
        cout << i << endl;
        i++;
    }


    {
        int i = 0;
        int sum = 0;
        for (i = 1; i <= 100; i = i + 1)
            sum = sum + i;

        cout << "Suma liczb od 1 do 100 = " << sum << endl;
    }

    cout << "-----------------------" << endl;

    {
        int start = 1;
        int stop = 10000;
        int i = 0;
        int sum = 0;
        for (i = start; i <= stop; i = i + 1) // int i; i += 1; i++;
            sum = sum + i;  // sum += i;

        cout << "Suma liczb od " << start << " "<< stop <<" = " << sum << endl;
    }


    int chybaLiczbaPierwsza = 104708;
    bool czyNaPewno = true;
    // czy jest liczb¹ pirwsz¹
    for (int i = 2; i < chybaLiczbaPierwsza; i++)
    {
        if (chybaLiczbaPierwsza % i == 0)
            czyNaPewno = false;
    }
    if (czyNaPewno)
        cout << "liczba pierwsza" << endl;
    else
        cout << "NIE" << endl;


    // 1
    // 12
    // ...
    // 123456789
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }

    /*
    // liczby pierwsze
    {
        for (int i = 1; i < 1000000; i++)
        {
            bool isPrime = true;
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
                cout << i << endl;
        }
    }
    */

    // fibbonacci
    {
        int a = 0;
        int b = 1;
        int sum = 0;
        for (int i = 0; sum < 1000; i++)
        {
            sum = a + b;
            a = b;
            b = sum;
            cout << sum << endl;
        }
    }




    // randoms
    // 1. najpierw wypisac i niech ka¿dy powie co wysz³o
    // 2. æwiczenie z rozk³adem
    int randoms[10] = { 0 };
    for (int i = 0; i<1000000; i++)
    {
        int r = rand() % 10;
        randoms[r]++;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << "randoms[" << i << "]: " << randoms[i] << endl;
    }

    return 0;
}

