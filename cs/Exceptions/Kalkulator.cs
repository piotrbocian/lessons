using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exceptions
{
    class Kalkulator : IDisposable
    {
        public Kalkulator()
        {
            a = int.Parse(Console.ReadLine());
            b = int.Parse(Console.ReadLine());
            s = new StreamWriter("logowanie.txt");
        }

        public void Dispose()
        {
            Console.WriteLine("zamykanie pliku");
            s.Close();
        }

        ~Kalkulator()
        {
            Console.WriteLine("destruktor");
        }

        public int dodaj()
        {
            s.Write(a + " + " + b + " = " + (a + b) + Environment.NewLine);
            return a + b;
            
        }

        private int a, b;
        private StreamWriter s;

    }
}
