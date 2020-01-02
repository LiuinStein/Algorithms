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
    std::unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        map[a] = b;
        map[b] = a;
    }
    std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }
    std::vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (map.find(vec[i]) == map.end() ||
            std::find(vec.begin(), vec.end(), map[vec[i]]) == vec.end())
        {
            result.push_back(vec[i]);
        }
    }
    std::sort(result.begin(), result.end());
    std::cout << result.size() << std::endl;
    if (result.size() >= 1)
    {
        for (int i = 0; i < result.size() - 1; i++)
        {
            printf("%05d ", result[i]);
        }
        printf("%05d\n", result[result.size() - 1]);
    }
    return 0;
}
