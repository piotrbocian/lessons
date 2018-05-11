// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

using System;

namespace IntroOOP
{
    class Kwadrat
    {
        // deklarujemy wszystkie pola i metody jako PUBLICZNE
        // czyli takie do ktorych mozna sie dostac spoza klasy
        public int a;

        public int obliczPole()
        {
            return a * a;
        }
        public int obliczObwod()
        {
            return 4 * a;
        }
    };
}
