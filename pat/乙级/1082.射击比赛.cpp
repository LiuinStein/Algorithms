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
    int maxId, minId;
    double maxD = INT_MIN, minD = INT_MAX;
    while (n--)
    {
        int id, a, b;
        std::cin >> id >> a >> b;
        double d = std::sqrt(a * a + b * b);
        if (d > maxD)
        {
            maxId = id;
            maxD = d;
        }
        if (d < minD)
        {
            minId = id;
            minD = d;
        }
    }
    std::printf("%04d %04d\n", minId, maxId);
    return 0;
}