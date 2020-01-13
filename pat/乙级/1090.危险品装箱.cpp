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
    std::unordered_map<int, std::vector<int>> map;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        std::cin >> k;
        std::unordered_map<int, bool> goods;
        bool flag = true;
        for (int j = 0; j < k; j++)
        {
            int t;
            std::cin >> t;
            if (flag)
            {
                goods[t] = true;
                for (int p = 0; p < map[t].size(); p++)
                {
                    if (goods[map[t][p]])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        std::cout << (flag ? "Yes" : "No") << std::endl;
    }
    return 0;
}
