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

const std::string marsLow[] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
const std::string marsHigh[] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

const std::unordered_map<std::string, int> numsLow{
        {"tret", 0}, {"jan", 1}, {"feb", 2}, {"mar",3},
        {"apr", 4}, {"may", 5}, {"jun", 6}, {"jly", 7},
        {"aug", 8}, {"sep", 9}, {"oct", 10}, {"nov", 11},
        {"dec", 12}
};

const std::unordered_map<std::string, int> numsHigh{
        {"tret", 0}, {"tam", 1}, {"hel", 2}, {"maa",3},
        {"huh", 4}, {"tou", 5}, {"kes", 6}, {"hei", 7},
        {"elo", 8}, {"syy", 9}, {"lok", 10}, {"mer", 11},
        {"jou", 12}
};

std::string toMars(int a)
{
    std::string result;
    if (a >= 13)
    {
        result.append(marsHigh[a / 13]);
        if (a % 13 != 0)
        {
            result.push_back(' ');
            result.append(marsLow[a % 13]);
        }
    }
    else
    {
        result.append(marsLow[a % 13]);
    }
    return result;
}

int toNumber(std::string a)
{
    int result = 0;
    int m = a.find(' ');
    if (m != std::string::npos)
    {
        result = numsHigh.at(a.substr(0, m)) * 13;
        result += numsLow.at(a.substr(m + 1));
    }
    else
    {
        result = numsHigh.find(a) == numsHigh.end() ? numsLow.at(a) : numsHigh.at(a) * 13;
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n)
    {
        std::string inp;
        std::getline(std::cin, inp);
        for (int i = 0; i < n; ++i)
        {
            std::getline(std::cin, inp);
            if (isdigit(inp[0]))
            {
                std::cout << toMars(std::atoi(inp.c_str())) << std::endl;
            }
            else
            {
                std::cout << toNumber(inp) << std::endl;
            }
        }
    }
    return 0;
}