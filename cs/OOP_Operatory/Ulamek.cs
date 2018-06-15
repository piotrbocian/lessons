using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Operatory
{

    class Ulamek : IComparable
    {
        int licznik;
        int mianownik;

        public Ulamek(int l, int m)
        {
            licznik = l;
            mianownik = m;
        }

        public double wartosc()
        {
            return (double)licznik / mianownik;
        }

        public override string ToString()
        {
            return String.Format("{0}/{1}", licznik, mianownik);
        }

        public static bool operator <(Ulamek lewy, Ulamek prawy)
        {
            return (lewy.wartosc() < prawy.wartosc());
        }

        public static bool operator >(Ulamek lewy, Ulamek prawy)
        {
            return (lewy.wartosc() > prawy.wartosc());
        }

        public static Ulamek operator +(Ulamek lewy, Ulamek prawy)
        {
            return new Ulamek(lewy.licznik * prawy.mianownik + prawy.licznik * lewy.mianownik, lewy.mianownik * prawy.mianownik);
        }

        public static Ulamek operator +(Ulamek lewy, int liczba)
        {
            return lewy + new Ulamek(liczba, 1);
        }

        public static Ulamek operator++(Ulamek lewy)
        {
            return lewy + 1;
        }

        public int CompareTo(object obj)
        {
            var u = (Ulamek)obj;
            return (this.wartosc().CompareTo(u.wartosc()));
        }
    }

    class UlamkiTest
    {
        static void Test()
        {

            Ulamek u1 = new Ulamek(1, 2);
            Ulamek u2 = new Ulamek(1, 3);
            Console.WriteLine(u1 + u2);
            Console.WriteLine(u1 + 5);
            Console.WriteLine(++u2);

            var ulamki = new List<Ulamek>();
            var generator = new Random();
            for (int i = 0; i < 10; i++)
            {
                ulamki.Add(new Ulamek(generator.Next() % 10, generator.Next() % 10));
            }

            ulamki.Sort();

            Console.WriteLine("Lista ulamkow:");
            foreach (var u in ulamki)
            {
                Console.WriteLine(u);
            }
        }
    }

}
