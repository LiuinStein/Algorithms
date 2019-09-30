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

bool valid(std::string str)
{
    if (str.size() != 18)
    {
        return false;
    }
    const int w[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
    int z = 0;
    for (int i = 0; i < 17; ++i)
    {
        if (str[i] < '0' || str[i] >'9')
        {
            return false;
        }
        z += w[i] * (str[i] - '0');
    }
    z %= 11;
    const char m[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3','2' };
    return str[17] == m[z];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n)
    {
        std::string str;
        bool allPassed = true;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> str;
            if (!valid(str))
            {
                std::cout << str << std::endl;
                allPassed = false;
            }
        }
        if (allPassed)
        {
            std::cout << "All passed" << std::endl;
        }
    }
    return 0;
}
