// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

using System;

// dodatkowe materiały:
// https://www.tutorialspoint.com/csharp/csharp_exception_handling.htm
namespace Exceptions
{
    // deklaracja wyjątku przez dziedziczenie z wyjątku wbudowanego
    // spójrz na funkcję niżej (int podziel(a, b)) po przykład użycia
    class DivideByZeroException : Exception
    {
        // wywołujemy konstruktor bazowy gdzie nadpisujemy parametr 'message'
        public DivideByZeroException() : base("Nie wolno dzielic przez 0!!!") { }
    }

    class ProgramExceptions
    {
        // Funkcja do dzielenia odporna na dzielenie przez zero
        static int podziel(int a, int b)
        {
            // gdy pojawi się sytuacja błędna, dobrym sposobem zasygnalizowania tego użytkownikowi jest
            // "rzucenie wyjątku" (ang. 'throw exception')
            if (b == 0)
            {
                // możemy tutaj użyć wbudowanego typu std::exception albo rzucić własnym wyjątkiem:

                // wyjątek wbudowany:
                //throw new Exception("Nie wolno dzielic przez 0!!!");

                // wyjątek zdefiniowany przez nas:
                throw new DivideByZeroException();
            }

            return a / b;
        }

        // Przykłady użycia powyższych funkcji
        static void Main(string[] args)
        {
            // wyjątek nieobsłużony:
            //podziel(5, 0);

            // obsługa wyjątków w sekcji try{} catch{}
            // try{} - umieszczamy tutaj fragment kodu gdzie możemy otrzymać wyjątek
            try
            {
                podziel(5, 0);

                // Przykład - propagacja wyjątków
                // wyjątek zostanie spropagowany z funkcji podziel() do fragmentWiekszegoProgramu() i dopiero w main() go złapiemy
                fragmentWiekszegoProgramu();
            }
            // catch(){} - wyłapujemy określone wyjątki
            // wyjątki łapiemy w kolejności od szczegółowych do ogólnych
            catch (DivideByZeroException e)
            {
                Console.WriteLine(e.Message);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            // Przykład - zastosowanie wyjątków w konstuktorze
            try
            {
                Kalk k = new Kalk();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

        }

        // Funkcja służąca do ilustracji 'propagacji wyjątków'.
        // Funkcja ta woła funkcję podziel(a, b) gdzie powstanie wyjątek z powodu dzielenia przez 0
        // ale ten wyjątek nie zostanie tutaj obsłużony tylko zostanie przesłany wyżej
        static void fragmentWiekszegoProgramu()
        {
            // ...
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

    // Zastosowanie wyjątków w konstuktorach
    // Jak wiemy, funkcja konstruktora nie zwraca żadnego typu,
    // więc w jaki sposób powiedzieć, że coś poszło nie tak? Rzucić wyjątkiem.
    class Kalk
    {
        public Kalk()
        {
            // coś w konstuktorze poszło nie tak...
            throw new Exception("wyjątek w konstuktorze");
        }
    }
}
