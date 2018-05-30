using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_KlasyPochodne
{
    // klasa abstrakcyjna
    // Nie można stworzyć obiektu tej klasy tylko można po niej dziedziczyć.
    // Ponadto klasa dziedzicząca musi zaimplementować wszystkie metody oznaczone jako = 0;
    abstract class Figura
    {
        // metody abstrakcyjne
        public abstract double obliczPole();
        public abstract double obliczObwod();
    };

    class Kwadrat : Figura
    {
        public Kwadrat(int a)
        {
            this.a = a;
        }

        public override double obliczPole()
        {
            return a* a;
        }

        public override double obliczObwod()
        {
            return 4 * a;
        }

        private int a;
    };


    class Kolo : Figura
    {
        public Kolo(double promien)
        {
            r = promien;
        }

        public override double obliczPole()
        {
            return pi * r * r;
        }

        public override double obliczObwod()
        {
            return 2 * pi * r;
        }

        private double r;
        private double pi = 3.1416;
    };
}
