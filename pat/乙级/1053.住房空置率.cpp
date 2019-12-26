#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int h;
    double e, D;
    std::cin >> h >> e >> D;
    int possible = 0, definate = 0;
    for (int i = 0; i < h; ++i)
    {
        int k;
        std::cin >> k;
        int v = 0;
        for (int j = 0; j < k; j++)
        {
            double t;
            std::cin >> t;
            if (t < e)
                v++;
        }
        if (v > k / 2)
        {
            if (k > D)
                definate++;
            else
                possible++;
        }
    }
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1)
              << (double(possible) / h) * 100.0 << "% "
              << (double(definate) / h) * 100.0 << "%" << std::endl;
    return 0;
}
