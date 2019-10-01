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

char toUpper(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c + 'A' - 'a';
    }
    return c;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string bad;
    // 人家保证输入第二行不为空，可没说第一行也不为空
    while (std::getline(std::cin, bad))
    {
        std::string inp;
        std::getline(std::cin, inp);
        bool map[256]{};
        for (int i = 0; i < bad.size(); ++i)
        {
            map[bad[i]] = true;
        }
        for (int i = 0; i < inp.size(); ++i)
        {
            char c = toUpper(inp[i]);
            if ((isalpha(c) &&
                ((isupper(inp[i]) && !map['+'] && !map[c]) || (islower(inp[i]) && !map[c])))
                || (!isalpha(c) && !map[c]))
            {
                std::cout << inp[i];
            }
        }
        std::cout << std::endl;
    }
    return 0;
}