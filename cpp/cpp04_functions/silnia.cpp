#include "stdafx.h"

#include <iostream>
using namespace std;

// n! = 1 * 2 * ... * n = (n-1)! * n
int silnia_r(int n)
{
    cout << "licze silnia(" << n << ")" << endl;

    if (n > 1)
        return silnia_r(n - 1) * n;
    else
        return 1;
}

int silnia_n(int n)
{
    int silnia = 1;
    for (int i = 2; i <= n; i++)
    {
        silnia *= i;
    }
    return silnia;
}