#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <regex>
#include <sstream>
#include <iomanip>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a, b, d;
    while (std::cin >> a >> b >> d)
    {
        long long c = a + b;
        if (c == 0)
        {
            std::cout << 0 << std::endl;
            continue;
        }
        std::string result;
        long long p = 1l;
        int i = 0;
        while (true)
        {
            long long p1 = d * p;
            if (c >= p && c < p1)
            {
                break;
            }
            ++i;
            p *= d;
        }
        for (; i >= 0; --i)
        {
            long long base = std::pow(d, i);
            int m = c / base;
            result.push_back(m + '0');
            c -= m * base;
        }
        std::cout << result << std::endl;
    }
    return 0;
}