// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

using System;

namespace OOP_Operatory
{
    // klasa Kwadrat implementuje interfejs IComparable
    // ktory jest omówiony niżej przy funkcji CompareTo()
    class Kwadrat : IComparable
    {
        public Kwadrat(int a)
        {
            this.a = a;
        }

        public double obliczPole()
        {
            return a * a;
        }

        public double obliczObwod()
        {
            return 4 * a;
        }

        private int a;

        // Nadpisujemy systemową funkcję ToString()
        // aby móc wypisywać informacje o obiektach za pomocą
        // Console.WriteLine()
        public override string ToString()
        {
            return "Kwadrat o boku " + a;
            //return String.Format("Kwadrat({0})", a);
        }

        // Napiszmy funkcję do porownania Kwadratow przez 
        // porownanie dlugosci ich bokow.
        // Jednak uzycie funkcji może nie być intuicyjne...
        public static int porownaj(Kwadrat lewy, Kwadrat prawy)
        {
            if (lewy.a < prawy.a)
            {
                return -1;
            }
            else if (lewy.a > prawy.a)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        // W tym przypadku możemy zastosować przeciążanie operatorów:
        // operator 'mniejsze od'
        public static bool operator<(Kwadrat lewy, Kwadrat prawy)
        {
            return (lewy.a < prawy.a);
        }

        // operator 'wieksze od'
        public static bool operator >(Kwadrat lewy, Kwadrat prawy)
        {
            return (lewy.a > prawy.a);
        }

        // Możemy też nadpisać inne operatory,
        // np operator mnożenia aby powiększyć kwadrat
        public static Kwadrat operator*(Kwadrat k, int ile)
        {
            return new Kwadrat(k.a * ile);
        }


        // implementacja interfejsu IComparable,
        // który wymaga nadpisania jednaj funkcji CompareTo(object)
        // czyli przyrównującej obiekt 'this' do 'obj'
        // Wartość zwracana:
        // -1 jeśli this < obj
        //  0 jeśli this == obj
        //  1 jeśli this > obj
        public int CompareTo(object obj)
        {
            Kwadrat k = (Kwadrat)obj;

            if (this < k)
                return -1;
            else if (this > k)
                return 1;
            else
                return 0;

            // Ale możemy skorzystać też z faktu, że dla typów wbudowanych
            // (jakim jest długość boku int a) funkcja CompareTo()
            // jest już zdefiniowana i wystarczy takie wywołanie jak poniżej:
            return this.a.CompareTo(k.a);
        }
    };


    class Operatory
    {

        static void Main(string[] args)
        {
            var k1 = new Kwadrat(10);
            var k2 = new Kwadrat(20);

            // Wypisanie informacji o obiekcie używając przeciążonej metody ToString()
            Console.WriteLine(k1);

            // użycie oryginalnej funkcji do porownywania
            if (Kwadrat.porownaj(k1, k2)<0)
            {
                Console.WriteLine("k1 mniejszy od k2");
            }

            // użycie przeciążonych operatorów do porównywania
            if (k1 < k2)
            {
                Console.WriteLine(k1 + " mniejszy od " + k2);
            }
            else if (k1 > k2)
            {
                Console.WriteLine(k1 + " wiekszy od " + k2);
            }

            // używamy operatora mnożenia kwadratu przez liczbę całkowitą
            k1 = k1 * 3;

            if (k1 < k2)
            {
                Console.WriteLine(k1 + " mniejszy od " + k2);
            }
            else if (k1 > k2)
            {
                Console.WriteLine(k1 + " wiekszy od " + k2);
            }


            // Demonstracja działania interfejsu IComparable:
            // 1) Tworzymy tablice Kwadratow
            Kwadrat[] tablica = new Kwadrat[10];

            // 2) Inicjujemy tablice losowymi wartościami
            var generator = new Random();
            for (int i=0; i<tablica.Length; i++)
            {
                tablica[i] = new Kwadrat(generator.Next() % 100);
                Console.WriteLine(i + ": " + tablica[i]);
            }

            // 3) Używamy wbudowanej metody do sortowania tablicy
            // Array.Sort() wymaga zaimplementowania funkcji CompareTo()
            // co już zrobiliśmy
            Console.WriteLine("Sortuje tablice");
            Array.Sort(tablica);

            // 4) Wypisujemy posortowane elementy tablicy 
            for (int i = 0; i < tablica.Length; i++)
            {
                Console.WriteLine(i + ": " + tablica[i]);
            }
        }
    }
}
