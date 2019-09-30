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
    long long n, p;
    while (std::cin >> n >> p)
    {
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        int cnt = 0;
        for (int j = n - 1; j >= 0; --j)
        {
            for (int i = j - cnt; i >= 0; --i)
            {
                if (a[j] <= a[i] * p)
                {
                    ++cnt;
                }
                else
                {
                    break;
                }
            }
        }
        std::cout << cnt << std::endl;
    }
    return 0;
}
