// randoms
// 1. najpierw wypisac i niech ka�dy powie co wysz�o
// 2. �wiczenie z rozk�adem

#include "stdafx.h"
#include <iostream>

int random_example()
{

    int randoms[10] = { 0 };
    for (int i = 0; i<1000000; i++)
    {
        int r = std::rand() % 10;
        randoms[r]++;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << "randoms[" << i << "]: " << randoms[i] << std::endl;
    }

    return 0;
}
