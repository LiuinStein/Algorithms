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

struct Student
{
    std::string id;
    int score;
};

bool operator<(Student &a, Student &b)
{
    return a.score == b.score ? a.id < b.id : a.score > b.score;
}

struct Venue
{
    int id = 0;
    int count = 0;
    int score = 0;
};

bool operator<(Venue &a, Venue &b)
{
    return a.count == b.count ? a.id < b.id : a.count > b.count;
}

int main()
{
    int n, m;
    std::scanf("%d%d", &n, &m);
    std::vector<Student> t, a, b;                               // 1
    std::vector<Venue> venues(1000);                            // 2
    std::unordered_map<int, std::unordered_map<int, int>> date; //3
    t.reserve(n);
    a.reserve(n);
    b.reserve(n);
    Student stu{};
    stu.id.resize(14);
    for (int i = 0; i < n; i++)
    {
        std::scanf("%s%d", &stu.id[0], &stu.score);
        // 1
        switch (stu.id[0])
        {
        case 'T':
            t.push_back(stu);
            break;
        case 'A':
            a.push_back(stu);
            break;
        case 'B':
            b.push_back(stu);
            break;
        }
        // 2
        int vid = std::atoi(stu.id.substr(1, 3).c_str());
        venues[vid].count++;
        venues[vid].score += stu.score;
        // 3
        int d = std::atoi(stu.id.substr(4, 6).c_str());
        date[d][vid]++;
    }
    // 1
    std::sort(t.begin(), t.end());
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    // 3
    std::unordered_map<int, std::vector<Venue>> dateVenue;
    for (auto i : date)
    {
        for (auto j : i.second)
        {
            dateVenue[i.first].push_back({j.first, j.second, 0});
        }
        std::sort(dateVenue[i.first].begin(), dateVenue[i.first].end());
    }
    // cmd
    for (int i = 1; i <= m; i++)
    {
        int type;
        std::scanf("%d", &type);
        if (type == 1)
        {
            std::string l;
            l.resize(3);
            std::scanf("%s", &l[0]);
            std::printf("Case %d: %d %s\n", i, type, l.c_str());
            std::vector<Student> *out{};
            switch (l[0])
            {
            case 'T':
                out = &t;
                break;
            case 'A':
                out = &a;
                break;
            case 'B':
                out = &b;
                break;
            }
            if (out == nullptr || out->size() == 0)
            {
                std::printf("NA\n");
            }
            else
            {
                for (int j = 0; j < out->size(); j++)
                {
                    std::printf("%s %d\n", (*out)[j].id.c_str(), (*out)[j].score);
                }
            }
        }
        else if (type == 2)
        {
            int para;
            std::scanf("%d", &para);
            std::printf("Case %d: %d %d\n", i, type, para);
            if (para < 101 || para > 999 || venues[para].count == 0)
            {
                std::printf("NA\n");
            }
            else
            {
                std::printf("%d %d\n", venues[para].count, venues[para].score);
            }
        }
        else if (type == 3)
        {
            int para;
            std::scanf("%d", &para);
            std::printf("Case %d: %d %06d\n", i, type, para);
            if (dateVenue.find(para) == dateVenue.end())
            {
                std::printf("NA\n");
            }
            else
            {
                for (int j = 0; j < dateVenue[para].size(); j++)
                {
                    std::printf("%d %d\n", dateVenue[para][j].id, dateVenue[para][j].count);
                }
            }
        }
    }
    return 0;
}
