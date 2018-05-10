// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

using System;


namespace IntroOOP
{

    class Kwadrat
    {
        // deklarujemy wszystkie pola i metody jako PUBLICZNE
        // czyli takie do ktorych mozna sie dostac spoza klasy
        public int a;

        public int obliczPole()
        {
            return a * a;
        }
        public int obliczObwod()
        {
            return 4 * a;
        }
    };



    class Prostokat
    {
        public int obliczPole()
        {
            return a * b;
        }

        public int obliczObwod()
        {
            return 2 * (a + b);
        }

        // teraz boki są zadeklarowane jako pola PRYWATNE
        // czyli takie do ktorych mamy dostęp wyłacznie z klasy
        private int a, b;
    };


    class Kolo
    {
        // specjalna metoda KONSTRUKTOR, ktorej zadaniem jest konstrukcja obiektu - 
        // - ustawienie wartosci poczatkowych
        public Kolo(double promien)
        {
            r = promien;
            Console.WriteLine("Tworze kolo o promieniu {0}", promien);
        }

        public double obliczPole()
        {
            return pi * r * r;
        }

        public double obliczObwod()
        {
            return 2 * pi * r;
        }

        // teraz boki są zadeklarowane jako pola PRYWATNE
        // czyli takie do ktorych mamy dostęp wyłacznie z klasy
        private double r;
        private const double pi = 3.1416;
    };

    // Program do obliczania właściwości figur geometrycznych.
    class Program
    {
        static void Main(string[] args)
        {
            Kwadrat k = new Kwadrat();
            k.a = 5;
            Console.WriteLine("Pole kwardratu = " + k.obliczPole());
            Console.WriteLine("Obwod kwadratu = " + k.obliczObwod());
            Console.WriteLine();

            Prostokat p = new Prostokat();
            // a i b są polami prywatnymi - nie mamy tutaj do nich dostępu
            //p.a = 5;
            //p.b = 7;
            Console.WriteLine("Pole prostokata = " + p.obliczPole());
            Console.WriteLine("Obwod prostokata = " + p.obliczObwod());
            Console.WriteLine();

            // Teraz użyjmy figury dla której zdefiniowalismy konstruktor
            // ale teraz taka konstrukcja jest niedozwolona - brak konstruktora domyślnego
            //Kolo kolo;
            Kolo kolo = new Kolo(10);
            Console.WriteLine("Pole kola = " + kolo.obliczPole());
            Console.WriteLine("Obwod kola = " + kolo.obliczObwod());
            Console.WriteLine();

            // Cwiczenie
            // Napisz program obsługujący kantor.
            // 1) Zdefiniuj klasę Kantor:
            //  a) W konstrukorze pobierz jako argumenty:
            //  - średni kurs USD/PLN
            //  - średni kurs EUR/PLN
            //  b) Zdefiniuj na stałe spread wymiany na poziomie 10% lub 10gr
            //  c) Zdefiniuj interfejs (metody publiczne) klasy z metodami:
            //  - kupUsd(float pln);
            //  - sprzedajUsd(float usd);
            //  - kupEur(float pln);
            //  - sprzedajEur(float eur);
            //  wszystkie pozostałe pola i metody powinny zostać ukryte (prywatne)!
            // 2) utwórz obiekt typu Kantor i dokonaj operacji:
            //  a) kup USD za 100 PLN
            //  b) sprzedaj otrzymane USD
            //  c) za otrymane PLNy kup EUR
            //  d) sprzedaj otrzymane EUR

            // Ile kantor zarobił na tych operacjach?
        }
    }
}
