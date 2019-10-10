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
    std::string a, b;
    while (std::cin >> a >> b)
    {
        if (b.size() < a.size())
        {
            for (int i = b.length(); i < a.length(); i++) 
            {
                b = "0" + b;
            }
        }
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        std::string result;
        for (int i = 1; i < b.size() + 1; ++i)
        {
            if (i - 1 >= a.size())
            {
                result.push_back(b[i - 1]);
                continue;
            }
            if (i & 1)
            {
                int t = (a[i - 1] + b[i - 1] - 2 * '0') % 13;
                switch (t)
                {
                case 10:
                    result.push_back('J');
                    break;
                case 11:
                    result.push_back('Q');
                    break;
                case 12:
                    result.push_back('K');
                    break;
                default:
                    result.push_back(t + '0');
                }
            }
            else
            {
                int t = b[i - 1] - a[i - 1];
                if (t < 0)
                {
                    t += 10;
                }
                result.push_back(t + '0');
            }
        }
        std::reverse(result.begin(), result.end());
        std::cout << result << std::endl;
    }
    return 0;
}