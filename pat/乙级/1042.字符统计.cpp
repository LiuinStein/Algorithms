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
        int a[257]{};
        for (int i = 0; i < inp.size(); ++i)
        {
            if (isalpha(inp[i]))
            {
                ++a[inp[i] >= 'A' && inp[i] <= 'Z' ? inp[i] - 'A' + 'a' : inp[i]];
            }
        }
        char c = 0;
        int num = 0;
        for (int i = 0; i < 257; ++i)
        {
            if (a[i] > num)
            {
                num = a[i];
                c = i;
            }
        }
        std::cout << c << " " << num << std::endl;
    }
    return 0;
}

