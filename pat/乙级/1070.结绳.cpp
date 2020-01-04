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
    int n;
    std::cin >> n;
    std::vector<double> nums(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end());
    double result = (nums[0] + nums[1]) / 2.0;
    for (int i = 2; i < n; i++)
    {
        result = result / 2.0 + nums[i] / 2.0;
    }
    std::cout << int(result) << std::endl;
    return 0;
}
