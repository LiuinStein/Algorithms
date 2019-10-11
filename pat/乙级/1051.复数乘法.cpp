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
#include <climits>


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    double r1, p1, r2, p2;
    while (std::cin >> r1 >> p1 >> r2 >> p2)
    {
        double a = (r1 * r2) * cos(p1 + p2);
        double b = (r1 * r2) * sin(p1 + p2);
        a = std::fabs(a) < 0.01 ? 0 : a;
        b = std::fabs(b) < 0.01 ? 0 : b;
        std::cout << setiosflags(std::ios::fixed) << std::setprecision(2)
            << a << (b < 0 ? "" : "+") << b << "i" << std::endl;
    }
    return 0;
}