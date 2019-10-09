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
#include <cctype>
#include <unordered_map>
#include <climits>


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n)
    {
        int a{}, b{};
        for (int i = 0; i < n; ++i)
        {
            int aa, ab, ba, bb;
            std::cin >> aa >> ab >> ba >> bb;
            if (ab != bb)
            {
                if (ab == aa + ba)
                {
                    ++b;
                }
                if (bb == aa + ba)
                {
                    ++a;
                }
            }
        }
        std::cout << a << " " << b << std::endl;
    }
    return 0;
}
