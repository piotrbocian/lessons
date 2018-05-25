using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_KlasyPochodne
{
    class Program
    {
        static int porownajPola(Prostokat p1, Prostokat p2)
        {
            if (p1.obliczPole() > p2.obliczPole())
                return 1;
            else
                return 2;
        }

        static void Main(string[] args)
        {
            Prostokat prostokat = new Prostokat(5, 6);
            prostokat.obliczObwod();
            prostokat.obliczPole();

            Prostopadloscian prostopadloscian = new Prostopadloscian(10, 20, 40);
            prostopadloscian.obliczPole();
            prostopadloscian.obliczObwod();
            prostopadloscian.obliczObjetosc();

            // W funkcji ktora wymaga obiektu klasy Prostokat, mozemy podac prostokat lub prostopadloscian,
            // poniewaz prostopadloscian dziedziczy po prostokacie wiec ma wszystkie jego wlasciwosci.
            // Zachodzi tutaj "object slicing" - Prostopadlosc jest "przycinany" do rozmiarow "prostokata":
            Console.WriteLine("wieksze pole ma figura nr " + porownajPola(prostokat, prostopadloscian));

            // Inny przykład "object slicing". Próba przypisania: Prostopadloscian -> Prostokat -> Prostopadloscian
            Prostokat p2 = prostopadloscian;    // mozemy rzutować "w dół"
            //Prostopadloscian pp2 = p2;        // ale nie możemy "w górę"


            // Tworząc tablice Prostokatow, mozemy podawac Prostokaty i Prostopadlosciany,
            Prostokat[] prostokaty =
            {
                new Prostokat(4, 5),
                new Prostokat(3, 4),
                new Prostopadloscian(2, 4, 5),
                new Prostopadloscian(4, 5, 5)
            };

            for (int i = 0; i < 4; i++)
            {
                Console.WriteLine("figura nr " + i);

                Console.WriteLine("Obwod = " + prostokaty[i].obliczObwod());
                Console.WriteLine("Pole = " + prostokaty[i].obliczPole());
                Console.WriteLine();
            }


            // Elementy tablicy prostokaty[] są typu Prostokat, nie Prostopoadloscian
            // więc nie możemy zawołać metody obliczObjetosc()
            //prostokaty[3].obliczObjetosc();

            // ale my wiemy że jest tam rzeczywiscie Prostopadloscian wiec mozemy rzutowac ('castowac') ten typ:
            ((Prostopadloscian)prostokaty[3]).obliczObjetosc();

            // co sie moze stac jesli wszystkie figury potraktujemy jak prostopadlosciany?
            for (int i = 0; i < 4; i++)
            {
                Console.WriteLine("figura nr " + i);

                Prostopadloscian prosto = (Prostopadloscian)(prostokaty[i]);
                Console.WriteLine("Obwod = " + prosto.obliczObwod());
                Console.WriteLine("Pole = " + prosto.obliczPole());
                Console.WriteLine("Objetosc = " + prosto.obliczObjetosc());

                Console.WriteLine();
            }
            // zostanie rzucony wyjątek (błąd) System.InvalidCastException

            // WNIOSEK
            // rzutować mozemy uzywac TYLKO wtedy kiedy znamy typ obiektu

        }
    }
}
