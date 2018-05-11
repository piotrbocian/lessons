// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

using System;
//using InnyNamespace;

namespace IntroOOP
{

    // Poddamy program z poprzednich zajec lekkim modyfikacjom:
    // 1/ Dobra praktyka jest umieszczenie kazdej wiekszej klasy w osobnym pliku.
    // Klasę Kwadrat przenosimy w całości do pliku Kwadrat.cs
    // Konwencja: taka sama nazwa pliku jak nazwa klasy.
    // W programie mozemy uzywac klas z innych plikow o ile znajduja sie w tym samym namespace.

    /*
    class Kwadrat
    {
        (...)
    };
    */


    // Klase Prostokat przenosimy w całości do pliku Prostokat.cs,
    // Ponadto klase umieszczamy w innym namespacie.

    /*
    class Prostokat
    {
        (...)
    };
    */

    // Modyfikator 'readonly' do zmiennych, które nie są stałe ale nie chcemy pozwolić na ich modyfikację
    // Jaka jest różnica między 'const' a 'readonly'?
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

        private readonly double r;      // r jest polem readonly, może zostać zainicjowane w konstruktorze
                                        // ale potem nie może być zmienione
        private const double pi = 3.1416;   // pi jest polem const, musi być znane w czasie kompilacji,
                                            // potem też nie może zostać zmienione
    };


    // Pola i metody statyczne - wspolne dla wszystkich obiektow klasy
    class Trojkat
    {
        public Trojkat()
        {
            Console.WriteLine("Tworze trojkat nr {0}", ++licznikTrojkatow);
        }

        private int a, h;

        // pole statyczne - wspolne dla wszystkich obiektow klasy
        private static int licznikTrojkatow = 0;

        // metoda statyczna:
        // - moze odwolywac sie tylko do pol i metod statycznych
        // - moze byc wywolana tylko na klasie, nie na obiekcie
        public static void wypiszLiczbeTrojkatow()
        {
            Console.WriteLine("Utworzono juz {0} trojkatow", licznikTrojkatow);
            //a = 1;  // nie mozemy modyfikowac wlasciwosci obiektow w metodach statycznych
        }

    };


    // Program do obliczania właściwości figur geometrycznych.
    class Program
    {
        // Przekazywanie obiektów jako parametrów
        // Dodajmy teraz funkcję ktora sprawdzi ktora z figur jest wieksza - kwadrat czy okrag?
        // Parametrami funkcji są obiekty typu Kwadrat i Kolo
        static string porownajPola(Kwadrat kwadrat, Kolo kolo)
        {
            if (kwadrat.obliczPole() < kolo.obliczPole())
                return "kwadrat";
            else
                return "kolo";

            // Bonus - jaki musi byc promien kola i bok kwadratu aby pola byly rowne?:)
        }


        static void Main(string[] args)
        {
            Kwadrat k = new Kwadrat();
            k.a = 5;
            Console.WriteLine("Pole kwardratu = " + k.obliczPole());
            Console.WriteLine("Obwod kwadratu = " + k.obliczObwod());
            Console.WriteLine();

            // Klasa Prostokat jest w innym namespace - aby jej uzyc musimy uzyc formatu:
            // Namespace.Klasa
            // lub na początku programu (linijka 5) dodac:
            // using InnyNamespace;
            InnyNamespace.Prostokat p = new InnyNamespace.Prostokat();

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

            // możemy uzyc juz istniejącego obiektu (Kwadrat k) lub utworzyc nowy podczas wywolania (Kolo(5)):
            Console.WriteLine("Wieksza pole ma " + porownajPola(k, new Kolo(5)));

            for (int i=0; i<10; i++)
            {
                new Trojkat();
            }

            Trojkat trojkat = new Trojkat();
            //trojkat.wypiszLiczbeTrojkatow();  // metoda statyczna - moze byc wywolana na klasie, nie na obiekcie
            Trojkat.wypiszLiczbeTrojkatow();

            // TODO: get/set
        }
    }


    // Cwiczenie
    // Przerob poprzedni program Kantor:
    // 0) rozdziel klasy na pliki
    // 1) pola przechowujace kursy USD_PLN, EUR_PLN (podane jako parametry) zmien na readonly
    // 3) utworz drugi obiekt typu Kantor z innymi kursami i wywolaj kilka metod na nim
    // 4) napisz metode, ktora porowna w ktorym Kantorze bardziej oplaca sie kupic USD
    // 5) Dodaj pole prywatne, ktore bedzie zliczalo liczbe operacji WSZYSTKICH kantorow
    // 6) Dodaj i wywolaj metode publiczna, ktora wypisze liczbe wszystkich operacji
}
