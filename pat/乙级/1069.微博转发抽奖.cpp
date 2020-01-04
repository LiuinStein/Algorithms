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
    int m, n, s;
    std::cin >> m >> n >> s;
    if (s > m)
    {
        std::cout << "Keep going..." << std::endl;
        return 0;
    }
    std::getchar();
    std::vector<std::string> winner;
    bool flag = false;
    for (int i = 1; i <= m; i++)
    {
        std::string inp;
        std::getline(std::cin, inp);
        if (i == s || flag)
        {
            if (std::find(winner.begin(), winner.end(), inp) == winner.end())
            {
                flag = false;
                winner.push_back(inp);
                s = i + n;
            }
            else
            {
                flag = true;
            }
        }
    }
    for (int i = 0; i < winner.size(); i++)
    {
        std::cout << winner[i] << std::endl;
    }
    return 0;
}
