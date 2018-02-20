// cpp01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>  // C style
#include <iostream> // C++ style

#include <string>

using namespace std;

int main()
{
    // C style
    puts("hello");
    printf("hello\n");

    // C++ style
    std::cout << "hello" << std::endl;
    cout << "hello" << endl;    // using namespace std;

    printf("Jestem Piotr, mam %i lat\n", 31);
    cout << "Jestem Piotr, mam " << 31 << " lat" << endl;

    char a = 1;     // 1 byte
    short b = 2;    // >=2 bytes
    int c = 3;      // >=2 bytes (4 bytes usually)
    long d = 4;     // >=4 bytes
    long long e = 5;// >=8 bytes

    cout << "a = " << +a << ", b = " << b << ", c= " << c << ", d = " << d << ", e = " << e << endl;

    // 1> 2>

    /*
    cout << "Podaj swoje imie: ";
    string imie;
    cin >> imie;

    cout << "Podaj wiek: ";
    int wiek;
    cin >> wiek;

    string zdanie;
    cout << "Co masz do powiedzenia?";
    getline(cin, zdanie);
    getline(cin, zdanie);

    cout << "Jestem " << imie << ", mam " << wiek << " lat" << endl;
    cout << "powiem wam, ze " << zdanie;
    */

    cerr << "O kurde, cos poszlo nie tak!" << endl;


    // int j albo zamknąć w klamerki
    cout << "for loop";
    {
        int i;
        for (i = 0; i < 10; i++)    // for (i = 3; i < 10; i++, cout << "!" << endl)
            cout << i << endl;
        cout << i*i << endl;        // częsty błąd u początkujących!!! uwaga na kolokwium
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
    // czy jest liczbą pirwszą
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

    // string - szyfr cezara, stdin, stdout, wysylanie komunikatow

    int tab[10] = { 1, 2, 3 };  // na początek nie zainicjowane
    // indexowane od 0 do (n-1) !!! // bardzo częsty błąd
    for (int i = 1; i <= 10; i++)
    {
        cout << tab[i] << endl;
    }


    // fibbonaci na tablicach
    int fib[10] = { 1, 1 };
    for (int i = 2; i < 10; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        cout << fib[i] << endl;
    }


    //string tekst = "WSB";
    //cout << tekst[0] << endl;
    //cout << tekst[1] << endl;
    //cout << tekst
    //cout << tekst.length();

    char tekst[] = "WSB";

    return 0;
}

