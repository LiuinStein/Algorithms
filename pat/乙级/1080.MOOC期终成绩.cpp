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
    int p = -1;
    int m = -1;
    int f = -1;
    double g = 0;
};

bool operator<(Student &a, Student &b)
{
    if (a.g == b.g)
    {
        return a.id < b.id;
    }
    return a.g > b.g;
}

int main()
{
    int p, m, n;
    std::cin >> p >> m >> n;
    std::unordered_map<std::string, Student> students;
    std::string st;
    int it;
    for (int i = 0; i < p; i++)
    {
        std::cin >> st >> it;
        students[st].id = st;
        students[st].p = it;
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> st >> it;
        students[st].id = st;
        students[st].m = it;
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> st >> it;
        students[st].id = st;
        students[st].f = it;
        students[st].g = students[st].m > students[st].f ? (double(students[st].m == -1 ? 0 : students[st].m) * 0.4 + double(students[st].f == -1 ? 0 : students[st].f) * 0.6) : students[st].f;
        students[st].g = students[st].g - int(students[st].g) >= 0.5 ? int(students[st].g) + 1 : int(students[st].g);
    }
    std::vector<Student> stu;
    for (auto s : students)
    {
        stu.push_back(s.second);
    }
    std::sort(stu.begin(), stu.end());
    for (int i = 0; i < stu.size(); i++)
    {
        if (stu[i].p < 200 || stu[i].g < 60)
        {
            continue;
        }
        std::cout << stu[i].id << " " << stu[i].p << " " << stu[i].m << " " << stu[i].f << " " << stu[i].g << std::endl;
    }
    return 0;
}
