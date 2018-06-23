using System;
using System.IO;

public class Example
{
   
    class Plik : IDisposable
    {
        public Plik(string filePath)
        {
            Console.WriteLine("otwieram plik " + filePath);
            f = new FileStream(filePath, FileMode.Open, FileAccess.Read, FileShare.None);
        }
        FileStream f;

        public void Czytaj()
        {
            StreamReader s = new StreamReader(f);
            Console.WriteLine(s.ReadToEnd());
        }

        public void Zamknij()
        {
            Console.WriteLine("zamykam plik w metodzie Zamknij");
            f.Close();
        }

        // metoda dla interfejsu IDisposable, robi to samo co Zamknij()
        public void Dispose()
        {
            Console.WriteLine("zamykam plik w metodzie Dispose");
            f.Close();
        }

        ~Plik()
        {
            Console.WriteLine("zamykam plik w destruktorze!");
            f.Close();
        }
    }

    public static void Main()
    {

        // za pomocą try-catch-finally
        Plik plik1 = new Plik("test.txt");
        try
        {
            plik1.Czytaj();
        }
        catch (Exception e)
        {
            // obsługa wyjątków
        }
        finally // sekcja finally - wolana zawsze, 
                // niezależnie czy wyjątek pojawił się czy nie
        {
            plik1.Zamknij();
            // alternatywnie
            //plik1.Dispose();
        }

        // za pomocą sekcji using () {}
        using (Plik plik2 = new Plik("test.txt"))
        {
            plik2.Czytaj();
        } // plik2.Dispose() jest tutaj zawołany automatycznie

        // ten plik nie zostanie zamkniety
        Plik plik3 = new Plik("test.txt");
        plik3.Czytaj();
    }
}