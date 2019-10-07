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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string inp;
    while (std::getline(std::cin, inp))
    {
        int P{}, A{}, T{}, e{}, s{}, t{};
        for (int i = 0; i < inp.size(); ++i)
        {
            switch (inp[i])
            {
            case 'P':
                ++P; break;
            case 'A':
                ++A; break;
            case 'T':
                ++T; break;
            case 'e':
                ++e; break;
            case 's':
                ++s; break;
            case 't':
                ++t; break;
            }
        }
        while (P + A + T + e + s + t != 0)
        {
            if (P)
            {
                std::cout << 'P';
                --P;
            }
            if (A)
            {
                std::cout << 'A';
                --A;
            }
            if (T)
            {
                std::cout << 'T';
                --T;
            }
            if (e)
            {
                std::cout << 'e';
                --e;
            }
            if (s)
            {
                std::cout << 's';
                --s;
            }
            if (t)
            {
                std::cout << 't';
                --t;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
