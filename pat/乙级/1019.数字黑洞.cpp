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

bool biggerThan(char a, char b)
{
    return a > b;
}

std::string format(std::string str)
{
    while (str.size() != 4)
    {
        str = '0' + str;
    }
    return str;
}

std::string minus(std::string left, std::string right)
{
    std::stringstream sstream;
    sstream << left << " " << right;
    int l, r;
    sstream >> l >> r;
    sstream.clear();
    std::string str;
    sstream << l - r;
    sstream >> str;
    return format(str);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string str;
    while (std::cin >> str)
    {
        str = format(str);
        if (str == "6174")
        {
            std::cout << "7641 - 1467 = 6174" << std::endl;
            continue;
        }
        while (str != "6174")
        {
            std::string left{ str }, right{ str };
            std::sort(left.begin(), left.end(), biggerThan);
            std::sort(right.begin(), right.end());
            if (left == right)
            {
                std::cout << left << " - " << right << " = 0000" << std::endl;
                break;
            }
            str = minus(left, right);
            std::cout << left << " - " << right << " = " << str << std::endl;
        }
    }
    return 0;
}