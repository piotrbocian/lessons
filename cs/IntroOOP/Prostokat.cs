// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

using System;

namespace InnyNamespace
{
    class Prostokat
    {
        public int obliczPole()
        {
            return a * b;
        }

        public int obliczObwod()
        {
            return 2 * (a + b);
        }

        // teraz boki są zadeklarowane jako pola PRYWATNE
        // czyli takie do ktorych mamy dostęp wyłacznie z klasy
        private int a, b;
    };

}
