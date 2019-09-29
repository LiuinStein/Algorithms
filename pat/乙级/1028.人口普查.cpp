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
#include <unordered_map>

struct man
{
    std::string name;
    int year;
    int month;
    int day;
};

bool smaller(man a, man b)
{
    return a.year > b.year || a.year == b.year && a.month > b.month ||
        a.year == b.year && a.month == b.month && a.day > b.day;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n)
    {
        man max{ "", 2014,9,7 };
        man min{ "", 300,300,300 };
        man today{ "", 2014,9,6 };
        man oldest{ "", 1814,9,5 };
        int valid = 0;
        for (int i = 0; i < n; ++i)
        {
            man tmp;
            std::string date;
            std::cin >> tmp.name >> date;
            tmp.year = std::atoi(date.substr(0, 4).c_str());
            tmp.month = std::atoi(date.substr(5, 2).c_str());
            tmp.day = std::atoi(date.substr(8, 2).c_str());
            if (!smaller(tmp, today) && smaller(tmp, oldest))
            {
                if (smaller(tmp, min))
                {
                    min = tmp;
                }
                if (!smaller(tmp, max))
                {
                    max = tmp;
                }
                ++valid;
            }
        }
        std::cout << valid;
        if (valid != 0)
        {
            std::cout<< " " << max.name << " " << min.name;
        }
        std::cout << std::endl;
    }
    return 0;
}