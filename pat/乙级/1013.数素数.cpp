#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int isPrime(int x)
{
    if (x == 2 || x == 3)
    {
        return true;
    }
    if (x % 6 != 1 && x % 6 != 5)
    {
        return false;
    }
    int tmp = std::sqrt(x);
    for (int i = 5; i <= tmp; i += 6)
    {
        if (x % i == 0 || x % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, n = 0;
    const int primes[] = { 0,2,3,5,7,11,13,17,19,23,29 };
    while (std::cin >> m >> n)
    {
        int mth = 0;
        if (m == 1)
        {
            mth = 2;
        }
        else
        {
            for (int j = 3, i = 0; i < m - 1; j += 2)
            {
                if (isPrime(j))
                {
                    ++i;
                    mth = j;
                }
            }
        }
        int t = n - m + 1;
        int* list = new int[t];
        list[0] = mth;
        int li = 1;
        for (int i = mth == 2 ? 3 : mth + 2; t != 0; i += 2)
        {
            if (isPrime(i))
            {
                --t;
                list[li++] = i;
            }
        }
        for (int i = 1; i <= n - m; ++i)
        {
            std::cout << list[i - 1];
            if (i % 10 == 0)
            {
                std::cout << std::endl;
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << list[n - m] << std::endl;
    }
    return 0;
}