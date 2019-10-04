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

class money
{
    long long g, s, k;

public:
    void print()
    {
        std::cout << g << '.' << s << '.' << k << std::endl;
    }

    money(long long kk)
    {
        long long ka = std::llabs(kk);
        k = ka % 29;
        ka -= k;
        s = (ka / 29) % 17;
        ka -= s * 17;
        g = ka / 17 / 29;
        g *= kk < 0 ? -1 : 1;
    }

    money(std::string str)
    {
        int f = str.find('.');
        g = std::atoi(str.substr(0, f).c_str());
        int n = str.find('.', f + 1);
        s = std::atoi(str.substr(f + 1, n - f - 1).c_str());
        k = std::atoi(str.substr(n + 1).c_str());
    }

    money operator-(money b)
    {
        long long ak = g * 17 * 29 + 29 * s + k;
        long long bk = b.g * 17 * 29 + b.s * 29 + b.k;
        return {ak - bk};
    }
};



int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string p, a;
    while (std::cin >> p >> a)
    {
        money aa(p), bb(a);
        (bb - aa).print();
    }
    return 0;
}