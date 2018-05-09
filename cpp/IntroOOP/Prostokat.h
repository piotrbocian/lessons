#pragma once

class Prostokat
{
public:
    // deklaracje metod przenosimy do pliku .cpp
    // a tutaj zostawiamy tylko definicje
    int obliczPole();

    int obliczObwod();

    // teraz boki s¹ zadeklarowane jako pola PRYWATNE
    // czyli takie do ktorych mamy dostêp wy³acznie z klasy
private:
    int a, b;
};