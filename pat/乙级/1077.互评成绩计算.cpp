#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        double t, sum = 0, vc = 0;
        double max = -1, min = m + 1;
        std::cin >> t;
        for (int j = 0; j < n - 1; j++)
        {
            double a;
            std::cin >> a;
            if (a >= 0 && a <= m)
            {
                sum += a;
                vc++;
                if (a > max)
                {
                    max = a;
                }
                if (a < min)
                {
                    min = a;
                }
            }
        }
        sum -= max + min;
        vc -= 2;
        double result = ((sum / vc) + t) / 2.0;
        std::cout << int(result) + (result - int(result) >= 0.5 ? 1 : 0) << std::endl;
    }
    return 0;
}
