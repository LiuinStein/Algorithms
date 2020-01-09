#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>

std::string add(std::string &a, std::string &b)
{
    std::string result;
    int u = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int r = a[i] + b[i] + u - 2 * '0';
        u = r / 10;
        result.push_back((r % 10) + '0');
    }
    while (u)
    {
        result.push_back((u % 10) + '0');
        u /= 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    std::string str;
    while (std::cin >> str)
    {
        bool con = true;
        int count = 0;
        while (count++ < 10 && con)
        {
            std::string r = str;
            std::reverse(r.begin(), r.end());
            if (r == str)
            {
                std::cout << str << " is a palindromic number." << std::endl;
                con = false;
                continue;
            }
            std::cout << str << " + " << r << " = " << (str = add(str, r)) << std::endl;
        }
        if (count > 10 && con)
        {
            std::cout << "Not found in 10 iterations." << std::endl;
        }
    }
    return 0;
}
