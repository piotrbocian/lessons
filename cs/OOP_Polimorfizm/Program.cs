// Opracowanie Piotr Bocian 2018
// Copyright 2018 Piotr Bocian

using System;

namespace OOP_KlasyPochodne
{
    class Prostokat
    {
        public Prostokat(int a, int b)
        {
            this.a = a;
            this.b = b;
        }

        public int obliczPole()
        {
            return a * b;
        }

        public int obliczObwod()
        {
            return 2 * (a + b);
        }

        public void wypisz()
        {
            Console.WriteLine("Prostokat o bokach " + a + ", " + b);
        }

        // zadeklarujmy taką samą metodę jak wyżej ale jako metodę "wirtualną"
        // takie metody mogą być nadpisane przez klasy dziedziczące
        public virtual void wypisz2()
        {
            Console.WriteLine("Prostokat o bokach " + a + ", " + b);
        }

        protected int a, b;
    };


    class Prostopadloscian : Prostokat
    {
        public Prostopadloscian(int a, int b, int h) : base(a, b)
        {
            this.h = h;
        }

        public int obliczObjetosc()
        {
            return a * b * h;
            return obliczPole() * h;
        }

        // do metody w klasie dziedziczącej możemy (opcjonalnie) dodać słowo 'new', dzięki temu:
        // - dajemy jasny komunikat że metoda nadpisuje działanie metody z klasy bazowej
        // - gdybyśmy użyli 'new' na metodzie nie-nadpisanej, kompilator zgłosi błąd
        public void wypisz()
        {
            Console.WriteLine("Prostopadloscian o bokach " + a + ", " + b + ", " + h);
        }

        // do metody w klasie dziedziczącej możemy (opcjonalnie) dodać słowo 'override', dzięki temu:
        // - dajemy jasny komunikat że metoda nadpisuje działanie metody z klasy bazowej
        // - gdybyśmy użyli 'override' na metodzie nie-virtualnej, kompilator zgłosi błąd
        public override void wypisz2()
        {
            Console.WriteLine("Prostopadloscian o bokach " + a + ", " + b + ", " + h);
        }

        private int h;
    };

    class Program
    {
        static void Main(string[] args)
        {
            Prostokat prostokat = new Prostokat(1, 2);
            Prostopadloscian prostopadloscian = new Prostopadloscian(3, 4, 5);

            Prostokat[] prostokaty =
            {
                new Prostokat(4, 5),
                new Prostokat(3, 4),
                new Prostopadloscian(2, 4, 5),
                new Prostopadloscian(4, 5, 5)
            };

            // POLIMORFIZM
            // Do klas Prostokat i Prostopadloscian dodajmy metode
            //   void wypisz()
            // ktora wypisze dane obiektu (zobacz metody w klasach)
            prostokat.wypisz();
            prostopadloscian.wypisz();
            // dzialanie programu jest na razie zgodne z oczekiwaniami.

            // Sprawdzmy teraz co zostanie wypisane dla tablicy prostokaty_wsk
            // zawierajacej 2 prostokaty i 2 prostopadlosciany.
            for (int i = 0; i < 4; i++)
            {
                Console.Write("figura nr " + i + " to ");
                prostokaty[i].wypisz();
            }
            Console.WriteLine();

            // Temu "problemowi" możemy zaradzić przez funkcje wirtualne
            // (zobacz metode void wypisz2() w klasach)
            for (int i = 0; i < 4; i++)
            {
                Console.Write("figura nr " + i + " to ");
                prostokaty[i].wypisz2();
            }
            Console.WriteLine();
            Console.WriteLine();
            
            // KLASY ABSTRAKCYJNE
            // definicje tych klas znajduja sie w pliku Figury.h
            Figura[] tablica = {
                new Kolo(10),
                new Kwadrat(10),
            };

            foreach (var figura in tablica)
            {
                Console.WriteLine("pole = " + figura.obliczPole());
                Console.WriteLine("obwod = " + figura.obliczObwod());
                Console.WriteLine();
            }
        }
    }


    // Zadanie
    // Zmodyfikuj poprzedni program Zwierzeta:
    // 1) Poprzednio utworzoną metodę void wypiszInformacje(); zmien na metodę wirtualną i nadpisz ją w każdej klasie.
    // 2) W klasie Zwierze dodaj abstrakcyjna metode void dajGlos()=0,
    //    i nadpisz ją w klasach pochodnych, ktora wypisze na ekran odglos jakie dane zwierze wydaje
    // 3) utworz tablice Zwierzat z kilkoma roznymi gatunkami
    // 4) dla kazdego elementu tabicy wywolaj metode dajGlos() oraz wypiszInformacje()
}
