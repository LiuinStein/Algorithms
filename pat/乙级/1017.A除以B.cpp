#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <regex>
#include <sstream>
#include <iomanip>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string a;
    int b;
    while (std::cin >> a >> b)
    {
        std::string q;
        int r = 0;
        for (int i = 0; i < a.size();)
        {
            int num = a[i] - '0';
            if (num < b)
            {
                if (i + 1 == a.size())
                {
                    r = num;
                    break;
                }
                num = num * 10 + a[++i] - '0';
            }
            q.push_back(num / b + '0');
            a[i] = num % b + '0';
        }
        std::cout << (q.empty() ? "0" : q) << " " << r << std::endl;
    }
    return 0;
}