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

struct student
{
    std::string id;
    std::string seat;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n)
    {
        std::vector<student> info(n + 1);
        for (int i = 0; i < n; ++i)
        {
            std::string t1, t2;
            int tmp;
            std::cin >> t1 >> tmp >> t2;
            info[tmp] = { t1, t2 };
        }
        int m, t;
        std::cin >> m;
        for (int i = 0; i < m; ++i)
        {
            std::cin >> t;
            std::cout << info[t].id << " " << info[t].seat << std::endl;
        }
    }
    return 0;
}
