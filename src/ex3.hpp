#pragma once
#include <array>
#include <iostream>

template <int i>
int fibonacci()
{
    std::array<int, i> a;

    for (int n = 0; n < i; n++)
    {
        if (n == 0 || n == 1)
        {
            a[i] = 1;
            continue;
        }
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[i - 1];
}