#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>

struct S
{
    int k, v;
};

bool operator<(S &a, S &b)
{
    return a.k > b.k;
}

int main()
{
    int n;
    std::cin >> n;
    std::unordered_map<int, int> map;
    std::vector<S> s;
    for (int i = 1; i <= n; i++)
    {
        int t;
        std::cin >> t;
        map[std::abs(t - i)] += 1;
    }
    for (auto p : map)
    {
        S t;
        t.k = p.first;
        t.v = p.second;
        s.push_back(t);
    }
    std::sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i].v > 1)
        {
            std::cout << s[i].k << " " << s[i].v << std::endl;
        }
    }
    return 0;
}
