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
#include <climits>


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n)
    {
        std::vector<int> team(1001);
        for (int i = 0; i < n; ++i)
        {
            std::string inp;
            int score;
            std::cin >> inp >> score;
            team[std::atoi(inp.substr(0, inp.find('-')).c_str())] += score;
        }
        int maxt = INT_MIN, maxs = INT_MIN;
        for (int i = 0; i < team.size(); ++i)
        {
            if (team[i] > maxs)
            {
                maxs = team[i];
                maxt = i;
            }
        }
        std::cout << maxt << " " << maxs << std::endl;
    }
    return 0;
}
