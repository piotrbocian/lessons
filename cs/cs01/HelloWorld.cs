// A Hello World! program in C#.
using System;
using System.Linq;
using System.Threading;

namespace HelloWorld
{
    // everything is object
    class Hello 
    {
        // program entry point
        static void Main() 
        {
            // 1. print and close window
            Console.WriteLine("Hello World!");

            // 2. Keep the console window open in debug mode.
            // alternatively - run w/o debugging
            //Console.WriteLine("Press any key to exit.");
            //Console.ReadKey();


            // 3. use variable
            {
                string imie = "Piotr";
                string nazwisko = "Bocian";
                Console.WriteLine("Prowadzący: " + imie + " " + nazwisko);
            }

            {
                string imie = "Jan";
                string nazwisko = "Kowalski";
                Console.WriteLine("Student: {0} {1}", imie, nazwisko);
            }

            Console.WriteLine(123);
            var c = 7;
            Console.WriteLine(c);



            int[] numbers = {2, 5, 4, 34, 53125, 424245, 1352145, 252, 24, 24, 24};

            Console.WriteLine(findMax1(numbers));
            Console.WriteLine(findMax2(numbers));
            Console.WriteLine(findMax3(numbers));
            Console.WriteLine(findMax4(numbers));
            Console.WriteLine(findMax5(numbers));
            

            Console.WriteLine(InWords(234));

            Drive();

            ReadAndSum();

        }


        // function with error to debug
        static int findMax1(int[] tab)
        {
            int max = tab[0];
            for (int i = 1; i < tab.Length; i++)
            {
                if (max > tab[i])
                {
                    max = tab[i];
                }
            }
            return max;
        }
        
        static int findMax2(int[] tab)
        {
            int max = tab[0];

            foreach (int t in tab)
            {
                if (max < t)
                {
                    max = t;
                }
            }

            return max;
        }

        static int findMax3(int[] tab)
        {
            int max = tab[0];

            foreach (int t in tab)
            {
                max = Math.Max(max, t);
            }

            return max;
        }

        static int findMax4(int[] tab)
        {
            // using System.Linq;
            return tab.Max();
        }

        static int findMax5(int[] tab)
        {
            Array.Sort(tab);
            return tab[tab.Length - 1];
        }

        // sort
        // other table properties

        static string InWords(int n)
        {
            string[] hundreds = {"", "sto", "dwieście", "trzysta", "czterysta", "pięćset", "sześćset", "siedemset", "osiemset", "dziewięćset"};
            string[] dozens = {"", "dziesięć", "dwadzieścia", "trzydzieści", "czterdzieści", "pięćdziesiąt", "szcześćdziesiąt", "siedemdziesiąt", "osiemdziesiąt", "dziewięćdziesiąt" };
            string[] units = { "", "jeden", "dwa", "trzy", "cztery", "pięć", "sześć", "siedem", "osiem", "dziewięć" };

            int h = n/100;
            int d = (n - (100*h))/10;
            int u = n % 10;

            return hundreds[h] + " " + dozens[d] + " " + units[u];
        }

        static int ReadAndSum()
        {
            string line;
            do
            {
                line = Console.ReadLine();
                Console.WriteLine(line.ToUpper());
            }
            while (line != "koniec");

            return 0;
        }


        static void Drive()
        {
            Console.Write("__________________________________________");

            Console.SetCursorPosition(0, Console.CursorTop);

            Console.CursorVisible = false;
            for (int i=0; i<40; i++)
            {
                Console.Write("_");
                Console.ForegroundColor = ConsoleColor.Blue;
                Console.Write("o-o");
                Console.ForegroundColor = ConsoleColor.White;
                Console.SetCursorPosition(Console.CursorLeft - 3, Console.CursorTop);
                Thread.Sleep(100);
            }
        }
    }
}