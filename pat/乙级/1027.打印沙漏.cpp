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
#include <map>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    char star;
    while (std::cin >> n >> star)
    {
        int layer = 0;
        int fn_1 = 1, fn = 1;
        for (int i = 2; fn <= n; ++i)
        {
            fn_1 = fn;
            fn = fn_1 + 4 * i - 2;
            ++layer;
        }
        for (int i = layer; i > 1; --i)
        {
            int space = layer - i;
            for (int j = 0; j < space; ++j)
            {
                std::cout << ' ';
            }
            for (int j = 0; j < 2 * i - 1; ++j)
            {
                std::cout << star;
            }
            std::cout << std::endl;
        }
        for (int i = 1; i <= layer; ++i)
        {
            int space = layer - i;
            for (int j = 0; j < space; ++j)
            {
                std::cout << ' ';
            }
            for (int j = 0; j < 2 * i - 1; ++j)
            {
                std::cout << star;
            }
            std::cout << std::endl;
        }
        std::cout << n - fn_1 << std::endl;
    }
    return 0;
}
