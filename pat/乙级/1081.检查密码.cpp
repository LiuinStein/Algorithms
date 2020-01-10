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

int main()
{
    int n;
    std::cin >> n;
    std::getchar();
    while (n--)
    {
        std::string str;
        std::getline(std::cin, str);
        if (str.size() < 6)
        {
            std::cout << "Your password is tai duan le." << std::endl;
            continue;
        }
        bool a = false, d = false, v = true;
        for (int i = 0; i < str.size(); i++)
        {
            if (isalpha(str[i]))
            {
                a = true;
            }
            else if (isdigit(str[i]))
            {
                d = true;
            }
            else if (str[i] != '.')
            {
                v = false;
            }
        }
        if (!v)
        {
            std::cout << "Your password is tai luan le." << std::endl;
            continue;
        }
        if (!d)
        {
            std::cout << "Your password needs shu zi." << std::endl;
            continue;
        }
        if (!a)
        {
            std::cout << "Your password needs zi mu." << std::endl;
            continue;
        }
        std::cout << "Your password is wan mei." << std::endl;
    }
    return 0;
}