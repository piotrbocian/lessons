// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include "stdafx.h" // for Visual Studio only

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/challenges/vector-sort/problem
int vector_sort() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for (auto t : v)
    {
        cout << t << " ";
    }
    return 0;
}

int vector_sort_new_int() {
    int n;
    cin >> n;
    int *v = new int[n];
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    sort(v, v+n);
    for (int i=0; i<n; i++)
    {
        cout << v[i] << " ";
    }
    delete[] v;
    return 0;
}


// https://www.hackerrank.com/challenges/vector-erase/problem
int vector_erase() {
    vector<int> v;
    int N;
    cin >> N;
    for (int i = 0; i<N; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    int x, a, b;
    cin >> x;
    cin >> a >> b;
    v.erase(v.begin() + x - 1);                 // decrement 1-based indexes as arguments
    v.erase(v.begin() + a - 1, v.begin() + b - 1);  // decrement 1-based indexes as arguments
    cout << v.size() << endl;
    for (auto t : v)
    {
        cout << t << " ";
    }
    return 0;
}