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
    std::set<int> result;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        std::string str;
        std::cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            sum += str[j] - '0';
        }
        result.insert(sum);
    }
    std::cout << result.size() << std::endl;
    for (auto i = result.begin(); i != (--result.end()); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << *(--result.end()) << std::endl;
    return 0;
}
