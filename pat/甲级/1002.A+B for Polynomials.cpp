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
#include <string>
#include <unordered_map>
#include <vector>

struct KV
{
    int k;
    double v;
};

int main()
{
    int k, e;
    while (std::cin >> k)
    {
        std::unordered_map<int, double> ec;
        double c;
        while (k--)
        {
            std::cin >> e >> c;
            ec[e] = c;
        }
        std::cin >> k;
        while (k--)
        {
            std::cin >> e >> c;
            ec[e] += c;
            if (ec[e] == 0)
            {
                ec.erase(e);
            }
        }
        std::vector<KV> kvs;
        for (auto s : ec)
        {
            kvs.push_back({s.first, s.second});
        }
        std::sort(kvs.begin(), kvs.end(), [](KV a, KV b) {
            return a.k > b.k;
        });
        std::cout << ec.size();
        for (KV s : kvs)
        {
            std::printf(" %d %.1f", s.k, s.v);
        }
    }
    return 0;
}
