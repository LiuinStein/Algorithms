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

bool check(std::vector<std::vector<int>> &image, int x, int y, int tol)
{
    for (int i = x - 1; i < x + 2; i++)
    {
        if (i < 0 || i >= image.size())
        {
            continue;
        }
        for (int j = y - 1; j < y + 2; j++)
        {
            if (j < 0 || j >= image[0].size())
            {
                continue;
            }
            if (i == x && j == y)
            {
                continue;
            }
            if (std::abs(image[i][j] - image[x][y]) <= tol)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int m, n, tol;
    std::cin >> m >> n >> tol;
    std::unordered_map<int, int> c;
    std::vector<std::vector<int>> image(n, std::vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> image[i][j];
            if (c.find(image[i][j]) == c.end())
            {
                c[image[i][j]] = 1;
            }
            else
            {
                c[image[i][j]]++;
            }
        }
    }
    int x = -1, y = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c[image[i][j]] == 1 && check(image, i, j, tol))
            {
                if (x == -1 && y == -1)
                {
                    x = i;
                    y = j;
                }
                else
                {
                    std::cout << "Not Unique" << std::endl;
                    return 0;
                }
            }
        }
    }
    if (x == -1 && y == -1)
    {
        std::cout << "Not Exist" << std::endl;
        return 0;
    }
    std::cout << "(" << y + 1 << ", " << x + 1 << "): " << image[x][y] << std::endl;
    return 0;
}
