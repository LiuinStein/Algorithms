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
    std::string a, b;
    while (std::cin >> a >> b)
    {
        std::vector<int> have(256);
        int lack = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            ++have[a[i]];
        }
        for (int i = 0; i < b.size(); ++i)
        {
            if (have[b[i]] - 1 < 0)
            {
                ++lack;
            }
            else
            {
                --have[b[i]];
            }
        }
        if (lack == 0)
        {
            int rich = 0;
            for (int i = 0; i < have.size(); ++i)
            {
                rich += have[i];
            }
            std::cout << "Yes " << rich << std::endl;
        }
        else
        {
            std::cout << "No " << lack << std::endl;
        }
    }
    return 0;
}
