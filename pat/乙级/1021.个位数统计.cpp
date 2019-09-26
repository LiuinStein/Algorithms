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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string str;
    while (std::cin >> str)
    {
        int nums[10]{};
        for (int i = 0; i < str.size(); ++i)
        {
            ++nums[str[i] - '0'];
        }
        for (int i = 0; i < 10; ++i)
        {
            if (nums[i] != 0)
            {
                std::cout << i << ":" << nums[i] << std::endl;
            }
        }
    }
    return 0;
}