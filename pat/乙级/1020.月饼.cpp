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

struct cake
{
    double stock;
    double unit_price;
    double total;
};

bool compare(cake a, cake b)
{
    return a.unit_price > b.unit_price;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    double d;
    while (std::cin >> n >> d)
    {
        std::vector<cake> cakes(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> cakes[i].stock;
        }
        for (int i = 0; i < n; ++i)
        {
            std::cin >> cakes[i].total;
            cakes[i].unit_price = cakes[i].total / cakes[i].stock;
        }
        std::sort(cakes.begin(), cakes.end(), compare);
        double profit = 0;
        for (int i = 0; i < n; ++i)
        {
            if (d == 0)
            {
                break;
            }
            if (d >= cakes[i].stock)
            {
                d -= cakes[i].stock;
                profit += cakes[i].total;
            }
            else
            {
                profit += d * cakes[i].unit_price;
                d = 0;
            }
        }
        std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2)
            << profit << std::endl;
    }
    return 0;
}
