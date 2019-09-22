#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, n = 0;
    while (std::cin >> n >> m)
    {
        m = m % n;
        int* inp = new int[n];
        for (int i = 0; i < n; ++i)
        {
            std::cin >> inp[i];
        }
        if (m != 0)
        {
            for (int i = n - m; i < n; ++i)
            {
                std::cout << inp[i] << " ";
            }
            for (int i = 0; i < n - m - 1; ++i)
            {
                std::cout << inp[i] << " ";
            }
            std::cout << inp[n - m - 1] << std::endl;
        }
        else
        {
            for (int i = 0; i < n - 1; ++i)
            {
                std::cout << inp[i] << " ";
            }
            std::cout << inp[n - 1] << std::endl;
        }
    }
    return 0;
}