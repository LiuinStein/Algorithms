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
    int m, n, a, b, h;
    std::cin >> m >> n >> a >> b >> h;
    std::vector<std::vector<int>> image(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t;
            std::cin >> t;
            image[i][j] = (t >= a && t <= b) ? h : t;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            printf("%03d ", image[i][j]);
        }
        printf("%03d\n", image[i][n - 1]);
    }
    return 0;
}
