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

bool checksAllZeros(std::vector<int> nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> nums(10);
    for (int i = 0; i < 10; ++i)
    {
        std::cin >> nums[i];
    }
    // first digit
    for (int i = 1; i < 10; ++i)
    {
        if (nums[i] != 0)
        {
            std::cout << i;
            nums[i] = std::max(0, nums[i] - 1);
            break;
        }
    }
    while (!checksAllZeros(nums))
    {
        for (int i = 0; i < 10; ++i)
        {
            if (nums[i] != 0)
            {
                for (int j = 0; j < nums[i]; ++j)
                {
                    std::cout << i;
                }
                nums[i] = 0;
            }
        }
    }
    std::cout << std::endl;
    return 0;
}