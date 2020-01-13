#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>

std::string check(double y, double t)
{
    if (t > y)
    {
        return "Cong";
    }
    if (t < y)
    {
        return "Gai";
    }
    return "Ping";
}

int main()
{
    int m, x, y;
    while (std::cin >> m >> x >> y)
    {
        bool flag{};
        for (int i = 99; i >= 10; i--)
        {
            int b = int(i / 10) + (i % 10) * 10;
            double c = double(b) / double(y);
            if (double(std::abs(i - b)) == double(c * x))
            {
                std::cout << i << " " << check(m, i) << " " << check(m, b) << " " << check(m, c) << std::endl;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            std::cout << "No Solution" << std::endl;
        }
    }
    return 0;
}
