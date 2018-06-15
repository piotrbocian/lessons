using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Operatory
{
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

        public static int porownaj(Kwadrat lewy, Kwadrat prawy)
        {
            if (lewy < prawy)
            {
                return -1;
            }
            else if (lewy > prawy)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        public static bool operator<(Kwadrat lewy, Kwadrat prawy)
        {
            return (lewy.a < prawy.a);
        }

        public static bool operator>(Kwadrat lewy, Kwadrat prawy)
        {
            return (lewy.a > prawy.a);
        }

        public static Kwadrat operator*(Kwadrat k, int ile)
        {
            return new Kwadrat(k.a * ile);
        }

        public override string ToString()
        {
            return String.Format("Kwadrat({0})", a);
        }

        public int CompareTo(object obj)
        {
            var k = (Kwadrat)obj;
            return this.a.CompareTo(k.a);
        }
    };


    class Program
    {


        static void Main(string[] args)
        {
            var k1 = new Kwadrat(10);
            var k2 = new Kwadrat(20);

            if (Kwadrat.porownaj(k1, k2)<0)
            {
                Console.WriteLine("k1 mniejszy od k2");
            }

            if (k1 < k2)
            {
                Console.WriteLine("k1 mniejszy od k2");
                Console.WriteLine(k1 + " mniejszy od " + k2);
            }
            else if (k1 > k2)
            {
                Console.WriteLine("k1 wiekszy od k2");
            }

            k1 *= 3;
            if (k1 < k2)
            {
                Console.WriteLine(k1 + " mniejszy od " + k2);
            }
            else if (k1 > k2)
            {
                Console.WriteLine(k1 + " wiekszy od " + k2);
            }



            Kwadrat[] tablica = new Kwadrat[10];

            var generator = new Random();
            for (int i=0; i<tablica.Length; i++)
            {
                tablica[i] = new Kwadrat(generator.Next() % 100);
                Console.WriteLine(i + ": " + tablica[i]);
            }

            Console.WriteLine("Sortuje tablice");
            Array.Sort(tablica);

            for (int i = 0; i < tablica.Length; i++)
            {
                Console.WriteLine(i + ": " + tablica[i]);
            }

        }
    }
}
