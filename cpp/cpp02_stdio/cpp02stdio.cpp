// cpp02stdio.cpp : Defines the entry point for the console application.
//

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
    cerr << max;

    return 0;
}

