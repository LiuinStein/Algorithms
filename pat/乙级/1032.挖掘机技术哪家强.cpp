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
#include <unordered_map>

struct school
{
    int id;
    int score;
};

bool compare(school a, school b)
{
    return a.score > b.score;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n)
    {
        std::vector<int> scores(n + 1, -1);
        std::vector<school> competitor;
        for (int i = 0; i < n; ++i)
        {
            int id = 0, score = 0;
            std::cin >> id >> score;
            scores[id] += scores[id] == -1 ? score == 0 ? 1 : score + 1 : score;
        }
        for (int i = 0; i < scores.size(); ++i)
        {
            if (scores[i] != -1)
            {
                competitor.push_back(school{ i, scores[i] });
            }
        }
        std::sort(competitor.begin(), competitor.end(), compare);
        std::cout << competitor[0].id << " " << competitor[0].score << std::endl;
    }
    return 0;
}