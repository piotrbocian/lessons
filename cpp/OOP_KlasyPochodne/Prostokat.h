#pragma once

class Prostokat
{
public:
    Prostokat(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    int obliczPole()
    {
        return a * b;
    }

    int obliczObwod()
    {
        return 2 * (a + b);
    }


 //private: // zmieniamy 'private' na:
protected:  // pola 'protected' - dostepne w klasach pochodnych ale nie na zewnatrz
    int a, b;
};


class Prostopadloscian : public Prostokat
{
public:
    Prostopadloscian(int a, int b, int h) : Prostokat(a, b)
    {
        this->h = h;
    }

    int obliczObjetosc()
    {
        return a * b * h;
        return obliczPole() * h;
    }

private:
    int h;
};


int porownajPola(Prostokat p1, Prostokat p2)
{
    cout << "sizeof(p1) = " << sizeof(p1) << endl;
    cout << "sizeof(p2) = " << sizeof(p2) << endl;

    if (p1.obliczPole() > p2.obliczPole())
        return 1;
    else
        return 2;
}





