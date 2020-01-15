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

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> moons(n);
    while (m--)
    {
        for (int i = 0; i < n; i++)
        {
            int t;
            std::cin >> t;
            moons[i] += t;
        }
    }
    std::vector<int> num;
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (moons[i] > max)
        {
            max = moons[i];
            num.clear();
            num.push_back(i + 1);
        }
        else if (moons[i] == max)
        {
            num.push_back(i + 1);
        }
    }
    std::sort(num.begin(), num.end());
    std::cout << max << std::endl;
    for (int i = 0; i < num.size() - 1; i++)
    {
        std::cout << num[i] << " ";
    }
    std::cout << num[num.size() - 1] << std::endl;
    return 0;
}
