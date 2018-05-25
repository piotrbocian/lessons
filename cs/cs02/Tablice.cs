// Opracowanie Piotr Bocian 2018
// Copyright 2018 Piotr Bocian

using System;

namespace cs02
{
    class Tablice
    {
        static void Main(string[] args)
        {
            // Temat 1 - tablice jednowymiarowe
            // tablice definiujemy podajac typ nazwe oraz liczbe elementow
            // liczba elementow musi byc stala i znana na etapie kompilacji
            int[] tab1 = new int[10];

            // dostep do elemenetow tablicy przez indeks
            // indeksowanie od 0 do (n-1) !!!
            Console.WriteLine(tab1[0]);
            Console.WriteLine(tab1[1]);
            Console.WriteLine(tab1[9]);
            //Console.WriteLine(tab[10];    // blad, indeks poza zakresem!

            // tab1 jest zainicjowana wartościami domyślnymi (dla typów prostych zerami)
            Console.WriteLine("Elementy tablicy nie-zainicjowanej: ");
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(tab1[i]);
            }
            

            // Aby zainicjować tablicę używamy nawiasów { }
            // rozmiary pominięty - kompilator wydedukuje rozmiar równy liczbie elementów w klamrach
            int[] tab2 = { 1, 2 };        // = {1, 2}

            // Temat 2 - tablice wielowymiarowe

            // tablice wielowymiarowe
            int[,] tab_2d = {
                { 1, 2, 3, 0, 0 },
                { 4, 5, 6, 7, 8 }
            };


            // tabliczka mnozenia
            // zdefiniuj tablice[20][20]
            // wypelnij tablice 20x20 wartosciami tabliczki mnozenia
            {
                int[,] tab = new int[20, 20];
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        tab[i, j] = i * j;
                    }
                }
            }


            // Zadanie1
            // wypelnij tablice 50 pierwszymi elementami ciągu Fibonacciego definiowanego następująco:
            // F[0] = 0,
            // F[1] = 1,
            // F[n] = F[n-1] + F[n-2]
            //
            // wydrukuj te elementy
            // 

        }
    }
}
