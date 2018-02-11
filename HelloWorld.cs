// A Hello World! program in C#.
using System;
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
            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();

            // 3. use variable
            string witaj = "Witej";
            Console.WriteLine(a);
            var imie = "Piotr"
            Console.WriteLine(a + b);

            Console.WriteLine(123);
            var c = 7;
            Console.WriteLine(7);

            Console.WriteLine("napisz cos")
            var cos = Console.ReadLine();
            Console.WriteLine(cos);


            int[10] = {2, 5, 4, 34, 53125, 424245, 1352145, 252, 24, 24, 24};

        }

        static int findMax(int[] tab)
        {
            int max = tab[0];
            for (int i=1; i<tab.length; i++)
            {
                if (max > tab[i])
                {
                    max = tab[i];
                }
            }
            return max;

            foreach (int t in tab)
            {
                if (max > t)
                {
                    max = tab[i];
                }
            }

            foreach (int t in tab)
            {
                max = max(max, t);
            }

            return tab.Max();
        }

        // sort
        // other table properties

        string InWords(int n)
        {
            string[10] hundreds = {"", "sto", "dwieście", "trzysta", "czterysta", "pięćset", "sześćset", "siedemset", "osiemset", "dziewięćset"};
            string[10] dozens;
            string[10] units;

            int h = n/100;
            ind d = (n - (100*h))/10;
            int u = n % 10;

            return hundreds[h] + " " + dozens[d] + " " + units[u];
        }
    }
}