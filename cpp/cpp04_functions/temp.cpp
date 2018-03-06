#include "stdafx.h"

#include <string>
#include <iostream>

using namespace std;

void temp_avg_std_dev(float temp[], float &avg, float &std_dev)
{
    const int num_of_months = 12;
    float sum = 0;
    for (int i = 0; i < num_of_months; i++)
    {
        sum += temp[i];
    }
    avg = sum / num_of_months;

    sum = 0;
    for (int i = 0; i < num_of_months; i++)
    {
        sum += (temp[i] - avg)*(temp[i] - avg);
    }
    std_dev = sqrt(sum / num_of_months);
}

void zadanie2_temperatury()
{
    while (!cin.eof())
    {
        std::string miasto;
        cin >> miasto;

        float temp[12] = {};
        for (int i = 0; i < 12; i++)
        {
            cin >> temp[i];
        }

        float avg;
        float std_dev;
        temp_avg_std_dev(temp, avg, std_dev);
        cout << miasto << " avg = " << avg << ", std_dev = " << std_dev << endl;
    }
}
