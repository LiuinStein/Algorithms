#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

void generateMN(int num, int &m, int &n)
{
    int s = std::sqrt(num);
    n = s;
    m = num / s;
    while (m * n != num)
    {
        n -= 1;
        m = num / n;
    }
}

int main()
{
    int num;
    std::cin >> num;
    std::vector<int> nums(num);
    for (int i = 0; i < num; i++)
    {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end());
    int m = 0, n = 0;
    generateMN(num, m, n);
    std::vector<std::vector<int *>> res(m, std::vector<int *>(n, nullptr));
    int r = num - 1;
    int c = 0, l = 0;
    while (r >= 0)
    {
        res[l][c] = new int(nums[r--]);
        if (c + 1 <= n - 1 && res[l][c + 1] == nullptr &&
            (l - 1 < 0 || res[l - 1][c] != nullptr))
        {
            // go right
            c++;
        }
        else if (l + 1 <= m - 1 && res[l + 1][c] == nullptr)
        {
            // go downwards
            l++;
        }
        else if (c - 1 >= 0 && res[l][c - 1] == nullptr)
        {
            // go left
            c--;
        }
        else if (l - 1 >= 0 && res[l - 1][c] == nullptr)
        {
            // go upwards
            l--;
        }
    }
    // output
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            std::cout << *res[i][j] << " ";
        }
        std::cout << *res[i][n - 1] << std::endl;
    }
    return 0;
}