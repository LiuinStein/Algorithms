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
#include <cctype>
#include <unordered_map>


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n)
    {
        std::vector<int> scores(101);
        for (int i = 0; i < n; ++i)
        {
            int tmp;
            std::cin >> tmp;
            ++scores[tmp];
        }
        int k;
        std::cin >> k;
        int s;
        for (int i = 0; i < k - 1; ++i)
        {
            std::cin >> s;
            std::cout << scores[s] << " ";
        }
        std::cin >> s;
        std::cout << scores[s] << std::endl;
    }
    return 0;
}