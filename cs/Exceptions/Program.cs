using System;

namespace Exceptions
{
    class DivideByZeroException : Exception
    {
        public DivideByZeroException() : base("Nie wolno dzielic przez 0!!!") { }
    }


    class Program
    {

        static int podziel(int a, int b)
        {
            if (b == 0)
            {
                //throw new Exception("Nie wolno dzielic przez 0!!!");
                throw new DivideByZeroException();
            }

            return a / b;
        }

        static void Main(string[] args)
        {
            try
            {
                podziel(5, 0);
                fragmentWiekszegoProgramu();
            }
            catch (DivideByZeroException e)
            {
                Console.WriteLine(e.Message);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            Kalkulator k = new Kalkulator();
            k.dodaj();
            k.Dispose();

            using (Kalkulator k2 = new Kalkulator())
            {
                k2.dodaj();
                k2.dodaj();
            }
        }

        static void fragmentWiekszegoProgramu()
        {
            int a = 7;
            int b = 0;
            double wynik = podziel(a, b);
            if (wynik > 3)
            {
                // ...
            }
            else
            {
                // ...
            }
        }


        // Zadanie
        // Napisz 8-cyfrowy kalkulator liczb całkowitych z funkcją logowania do pliku.
        // 1) W konstuktorze:
        //  a) wczytaj z konsoli dwie liczby:
        // - jeśli podano nie liczbę całkowitą - metoda int.Parse() wygeneruje systemowy wyjątek
        // - jeśli podano liczbę spoza zakresu - rzuć (innym) wyjątkiem
        //  b) otwórz plik w ktorym logowanie będą wykonywane operacje
        //  (zapis do pliku w C#:)
        //    StreamWriter s = new StreamWriter("plik.txt");
        //    s.Write(...);
        //    s.Flush();
        //    s.Close();
        // 2) Napisz metody zwracające wynik oraz logujące operacje do pliku
        //   int dodaj()
        //   int odejmij()
        //   int pomnoz()
        //   int podziel()
        // Jesli w metodzie wystąpi:
        // - przepelnienie zakresu - wyjątek
        // - dzielenie przez zero - wyjątek
        // 3) Dodaj destruktor ('finalizer') z komunikatem o wyjściu z kalkulkatora.
        // 4) Utwórz obiekt zdefiniowanej klasy i wykonaj na nim kilka operacji.
        // 5) Obsłuż wygenerowane wyjątki w sekcji try{} catch{}
        // Extra:
        // Niech zdefiniowana klasa implementuje interfejs IDisposable i w metodzie
        //   public void Dispose()
        // zamknij StreamWriter (s.Close())
        // Użyj kalkulatora używając 'using':
        //   using (Kalkulator k = new Kalkulator())
        //   {
        //     ...
        //   }
    }
}
