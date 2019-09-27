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
    std::string str;
    while (std::cin >> str)
    {
        std::string result;
        if (str[0] == '-')
        {
            result.push_back('-');
        }
        int ep = str.find('E');
        int exp = std::atoi(str.substr(ep + 2).c_str());
        if (str[ep + 1] == '+' || exp == 0)
        {
            result.push_back(str[1]);
            int i = 0;
            for (; i < exp && i + 3 < ep; ++i)
            {
                result.push_back(str[i + 3]);
            }
            for (; i < exp; ++i)
            {
                result.push_back('0');
            }
            if (i + 3 < ep)
            {
                result.push_back('.');
                for (; i + 3 < ep; ++i)
                {
                    result.push_back(str[i + 3]);
                }
            }
        }
        else
        {
            result.append("0.");
            exp -= 1;
            for (int i = 0; i < exp; ++i)
            {
                result.push_back('0');
            }
            result.push_back(str[1]);
            result.append(str.substr(3, ep - 3));
        }
        std::cout << result << std::endl;
    }
    return 0;
}