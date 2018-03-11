// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "stdafx.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "podaj a b c: ";
    int a, b, c;
    cin >> a >> b >> c;
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    cout << endl << max;
    cerr << "program wykonal sie bez bledow";

    return 0;
}

