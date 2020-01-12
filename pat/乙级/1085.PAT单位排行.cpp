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

struct School
{
    std::string name;
    int b = 0;
    int a = 0;
    int t = 0;
    int all = 0;
    int students = 0;
};

void toLowercase(std::string &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = std::tolower(a[i]);
    }
}

bool operator<(School &a, School &b)
{
    if (a.all != b.all)
    {
        return a.all > b.all;
    }
    if (a.students != b.students)
    {
        return a.students < b.students;
    }
    return a.name < b.name;
}

int main()
{
    int n;
    std::cin >> n;
    std::unordered_map<std::string, School> map;
    for (int i = 0; i < n; i++)
    {
        std::string junk, name;
        int score;
        std::cin >> junk >> score >> name;
        toLowercase(name);
        map[name].name = name;
        map[name].students++;
        switch (junk[0])
        {
        case 'B':
            map[name].b += score;
            break;
        case 'A':
            map[name].a += score;
            break;
        case 'T':
            map[name].t += score;
            break;
        }
    }
    std::vector<School> schools;
    for (auto s : map)
    {
        s.second.all = double(s.second.b) / 1.5 + double(s.second.a) + double(s.second.t) * 1.5;
        schools.push_back(s.second);
    }
    std::sort(schools.begin(), schools.end());
    std::cout << schools.size() << std::endl;
    std::cout << "1 " << schools[0].name << " " << schools[0].all << " " << schools[0].students << std::endl;
    int t = 1;
    for (int i = 1; i < schools.size(); i++)
    {
        t = schools[i].all == schools[i - 1].all ? t : i + 1;
        std::cout << t << " "<< schools[i].name << " " << schools[i].all << " " << schools[i].students << std::endl;
    }
    return 0;
}
