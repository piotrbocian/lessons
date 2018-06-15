// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

using System;

// UWAGA
// W C# istnieje tzw "Garbage Collector" który zdejmuje z programisty obowiązek zarządzania pamięcią.
// Dla porónania w C++ dla każdej alokacji operatem 'new' musi nastąpić dealokacja (zwolnienie) operatorem 'delete'.
// W C# tworzymy obiekty operatorem 'new' ale środowisko zwalnia je za nas - operator 'delete' nie jest potrzebny.
// Dlatego też użycie destruktora jest bardzo ograniczone w stosunku do tego co mamy w C++.
// Przykład poniżej dla formalności pokazuje użycie destruktora (nazwanego w C# 'finalizer') 
// ale dużo powszechniejsze jest używanie interfejsu 'IDisposable' który jednak nie jest w tym kursie poruszany.
namespace Destruktor
{
    class Kwadrat
    {
        // konstruktor
        public Kwadrat(int a)
        {
            this.a = a;
            Console.WriteLine("Tworze kwadrat o boku " + a);
        }

        // destruktor - metoda wywoływana kiedy obiekt jest usuwany
        // w C# jest on wołany automatycznie przez Garbage Collector
        ~Kwadrat()
        {
            Console.WriteLine("Usuwam kwadrat o boku " + a);
        }

        private int a;
    };

    class ProgramDestruktor
    {
        static void Main(string[] args)
        {
            new Kwadrat(100);
            new Kwadrat(5555);

            Console.WriteLine("Wyjście z programu");
            // uruchom program i zobacz co zostanie wypisane na ekranie
        }
    }
}
