#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

double parseFrac(std::string &a)
{
    int pos = a.find('/');
    int up = std::atoi(a.substr(0, pos).c_str());
    int down = std::atoi(a.substr(pos + 1).c_str());
    return double(up) / double(down);
}

int main()
{
    std::string a, b;
    int k;
    std::cin >> a >> b >> k;
    double l = parseFrac(a), r = parseFrac(b);
    if (l > r)
    {
        std::swap(l, r);
    }
    std::vector<bool> flags(k, true);
    for (int i = 2; i < k; i++)
    {
        if (flags[i])
        {
            int u = k / i;
            if (u * i == k)
            {
                for (int j = 1; j < u; j++)
                {
                    flags[i * j] = false;
                }
            }
        }
    }
    std::stringstream out;
    for (int i = 1; i < k; i++)
    {
        if (flags[i])
        {
            double v = double(i) / double(k);
            if (v > l && v < r)
            {
                out << i << "/" << k << " ";
            }
        }
    }
    std::string s;
    out >> s;
    std::cout << s;
    while (out >> s)
    {
        std::cout << " " << s;
    }
    std::cout << std::endl;
    return 0;
}
