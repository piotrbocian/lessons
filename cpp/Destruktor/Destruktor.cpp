// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "Kwadrat.h"

// W C++ obowiązkiem programisty jest zarządzanie pamięcią.
// Upraszczając mamy dwie metody tworzenia obiektów w pamięci:
// 1) na stosie ('stack')
// 2) na stercie ('heap')
int main()
{
    // tworzenie obiektu na stosie
    // obiekt żyje do czasu wyjścia z zakresu - do napotkania klamry zamykającej '}'
    Kwadrat k1(100);

    // tworzenie obiektu na stercie
    // obiekty żyje do czasu wywołania operatora 'delete'
    Kwadrat *k2 = new Kwadrat(5555);
    delete k2;

    return 0;
}

