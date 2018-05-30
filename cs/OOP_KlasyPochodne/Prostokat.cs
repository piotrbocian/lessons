// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

using System;

namespace OOP_KlasyPochodne
{
    class Prostokat
    {
        public Prostokat(int a, int b)
        {
            this.a = a;
            this.b = b;
        }

        public int obliczPole()
        {
            return a * b;
        }

        public int obliczObwod()
        {
            return 2 * (a + b);
        }


        //private: // zmieniamy 'private' na:
        protected int a, b;  // pola 'protected' - dostepne w klasach pochodnych ale nie na zewnatrz
    };


    class Prostopadloscian : Prostokat
    {
    public Prostopadloscian(int a, int b, int h) : base(a, b)
    {
        this.h = h;
    }

    public int obliczObjetosc()
    {
        return a * b * h;
        return obliczPole() * h;
    }

    private int h;
};


}
