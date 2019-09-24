#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <regex>
#include <sstream>
#include <iomanip>
#include <vector>

struct student
{
    int id, d, c, t;
};

bool compare(const student& l, const student& r)
{
    if (l.t != r.t)
    {
        return l.t > r.t;
    }
    if (l.d != r.d)
    {
        return l.d > r.d;
    }
    return l.id < r.id;
}

void output(const std::vector<student> &out)
{
    for (auto i : out)
    {
        std::cout << i.id << " " << i.d << " " << i.c << std::endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, l, h;
    while (std::cin >> n >> l >> h)
    {
        std::vector<student> best; // 才德全尽, 德分和才分均不低于h
        std::vector<student> better; // 德胜才, 才分不到但德分到h
        std::vector<student> good; // 才德兼亡但尚有德胜才, 德才分均低于h但德分不低于才分
        std::vector<student> stupid; // 其他达到最低线L的考生

        for (int i = 0; i < n; ++i)
        {
            student tmp{};
            std::cin >> tmp.id >> tmp.d >> tmp.c;
            tmp.t = tmp.d + tmp.c;
            if (tmp.d < l || tmp.c < l)
            {
                continue;
            }
            if (tmp.d >= h && tmp.c >= h)
            {
                best.push_back(tmp);
            }
            else if (tmp.d >= h && tmp.c < h)
            {
                better.push_back(tmp);
            }
            else if (tmp.d < h && tmp.c < h && tmp.d >= tmp.c)
            {
                good.push_back(tmp);
            }
            else
            {
                stupid.push_back(tmp);
            }
        }

        // 第一行首先给出达到最低分数线的考生人数
        std::cout << best.size() + better.size() + good.size() + stupid.size() << std::endl;
        // 才德全尽按德才总分从高到低排序
        std::sort(best.begin(), best.end(), compare);
        output(best);
        // 德胜才也按总分排序
        std::sort(better.begin(), better.end(), compare);
        output(better);
        // 才德兼亡但尚有德胜才按总分排序
        std::sort(good.begin(), good.end(), compare);
        output(good);
        // 其他达到最低线L的考生也按总分排序
        std::sort(stupid.begin(), stupid.end(), compare);
        output(stupid);
    }
    return 0;
}