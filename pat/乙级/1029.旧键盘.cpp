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

char toUpperCase(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return char(c - 'a' + 'A');
    }
    return c;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string original;
    std::string real;
    while (std::cin >> original >> real)
    {
        std::string result;
        for (int i = 0, j = 0; i < original.size(); ++i)
        {
            if (original[i] != real[j])
            {
                if (result.find(toUpperCase(original[i])) == std::string::npos)
                {
                    result.push_back(toUpperCase(original[i]));
                }
            }
            else
            {
                j += j < real.size() ? 1 : 0;
            }
        }
        std::cout << result << std::endl;
    }
    return 0;
}