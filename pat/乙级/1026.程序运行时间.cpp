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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long c1, c2;
    while (std::cin >> c1 >> c2)
    {
        long long t = c2 - c1;
        if (t % 100 >= 50)
        {
            t += 100 - (t % 100);
        }
        double sec = t / 100.0;
        int hr = sec / 3600;
        int min = (sec - hr * 3600) / 60;
        int s = sec - hr * 3600 - min * 60;
        std::printf("%02d:%02d:%02d\n", hr, min, s);
    }
    return 0;
}