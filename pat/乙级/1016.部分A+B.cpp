#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <regex>
#include <sstream>
#include <iomanip>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int da, db;
    std::string a, b;
    while (std::cin >> a >> da >> b >> db)
    {
        int sa = 0, sb = 0;
        int pa = 0, pb = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] - '0' == da)
            {
                pa += da * std::pow(10, sa++);
            }
        }
        for (int i = 0; i < b.size(); ++i)
        {
            if (b[i] - '0' == db)
            {
                pb += db * std::pow(10, sb++);
            }
        }
        std::cout << pa + pb << std::endl;
    }
    return 0;
}
