// Opracowanie Piotr Bocian 2018
// Copyright 2018 Piotr Bocian

using System;
using System.Linq;
using System.Threading;

namespace HelloWorld
{
    class Hello 
    {
        static void Main(string[] args)
        {
            // Temat 1 - wypisywanie tekstu na konsole
            Console.WriteLine("hello");
            Console.WriteLine("Jestem Piotr, mam " + 31 + " lat");   // 31 jest konwertowane na tekst (string)
            Console.WriteLine("Jestem nerdem, mam " + 0x1f + " lat");// 0x1f jest konwertowane na tekst i efekt działania będzie identyczny jak powyżej
            Console.WriteLine("Jestem Piotr, mam {0} lat", 31);

            // Temat 2 - zmienne
            // przykłady deklaracji zmiennych
            // oraz użycie operatora sizeof() do sprawdzenia ile bajtów ma dany typ
            {
                bool b1 = true, b2 = false;
                byte by1 = 1, by2 = 0xf;
                char c1 = '1', c2 = 'a';          // 1 byte
                short s1 = 32767; short s2 = -100; short s3 = 0x1234;    // 2 bytes
                int i = 2147483647;               // 4 bytes
                long l1 = 2147483647; long l2 = 0;// 8 bytes
                float f1 = 167.899f, f2 = 124e4f;   // 4 bytes
                double d1 = 123.23;                 // 8 bytes

                Console.WriteLine("size of bool: {0}", sizeof(bool));
                Console.WriteLine("size of char: {0}", sizeof(char));
                Console.WriteLine("size of short: {0}", sizeof(short));
                Console.WriteLine("size of int: {0}", sizeof(int));
                Console.WriteLine("size of long: {0}", sizeof(long));
                Console.WriteLine("size of float: {0}", sizeof(float));

                // const
                int c = 300000;
                const int C = 300000;

                c = 4;
                //C = 5;    // błąd - nie można ponownie przypisać do stałej

            }

            // Temat 3 - wczytywanie danych z konsoli przy pomocy std::cin
            Console.WriteLine("Podaj swoje imie: "); ;
            string imie = Console.ReadLine();

            Console.WriteLine("Podaj wiek: ");
            int wiek = int.Parse(Console.ReadLine());

            Console.WriteLine("Jestem {0}, mam {1} lat", imie, wiek);


            // Cwiczenie 1
            // Napisz program ktory spyta o dane i przeliczy PLN na USD/EUR


            // Temat 4 - instrukcje warunkowe
            if (wiek >= 18)
                Console.WriteLine("moge honorowo oddac krew");
            Console.WriteLine("moge zrobic prawo jazdy");   // częsty błąd u początkujących!!!
                                                            // po sprawdzeniu warunku w if() wykonana jest TYLKO jedna następna instrukcja
                                                            // jesli chcemy wykonac wiecej instrukcji, muszą być zawarte w { }
            if (wiek >= 18)
            {
                Console.WriteLine("moge honorowo oddac krew");
                Console.WriteLine("moge zrobic prawo jazdy");
            }


            // Cwiczenie 2
            // Napisz program wczytujacy 3 liczby calkowite i wypisujacy liczbe najwieksza


            // Temat 5 - pętle
            Console.WriteLine("for loop");
            {
                int i;
                for (i = 0; i < 10; i++)
                    Console.WriteLine(i);
                Console.WriteLine(i * i);        // częsty błąd u początkujących!!!
                                                 // podobnie jak w instrukcji if(),
                                                 // po wykonaniu operacji w nawiasach for(;;) wykonana jest TYLKO jedna następna instrukcja
                                                 // jesli chcemy wykonac wiecej instrukcji, muszą być zawarte w { }
                for (i = 0; i < 10; i++)
                {
                    Console.WriteLine(i);
                    Console.WriteLine(i * i);
                }
            }


            // while / do-while
            Console.WriteLine("while loop");
            {
                int i = 0;
                while (i < 10)
                {
                    Console.WriteLine(i);
                    i++;
                }
            }


            // Przyklad - policz sume liczb od 1 do 100
            {
                int i = 0;
                int sum = 0;
                for (i = 1; i <= 100; i = i + 1)
                    sum = sum + i;

                Console.WriteLine("Suma liczb od 1 do 100 = {0}", sum);
            }


            // Cwiczenie - sprawdz czy liczba jest pierwsza
            // liczba pierwsza - liczba, ktora dzieli sie tylko przez 1 i przez samą siebie
        }
    }
}