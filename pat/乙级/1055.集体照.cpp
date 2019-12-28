#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Person
{
    std::string name;
    int height;
};

bool operator<(Person a, Person b)
{
    if (a.height == b.height)
    {
        return a.name < b.name;
    }
    return a.height > b.height;
}

void output(std::deque<std::string> &deque)
{
    for (int i = 0; i < deque.size() - 1; i++)
    {
        std::cout << deque[i] << " ";
    }
    std::cout << deque[deque.size() - 1] << std::endl;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<Person> people(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> people[i].name >> people[i].height;
    }
    std::sort(people.begin(), people.end());
    int num = n / k;
    int last = n - (k - 1) * num;
    // output the last line
    std::deque<std::string> name;
    bool left = false;
    int i = 0;
    for (; i < last; i++)
    {
        if (left)
        {
            name.push_front(people[i].name);
        }
        else
        {
            name.push_back(people[i].name);
        }
        left = !left;
    }
    output(name);
    for (int j = 0; j < k - 1; j++)
    {
        left = false;
        name.clear();
        for (int m = 0; m < num; m++)
        {
            if (left)
            {
                name.push_front(people[i++].name);
            }
            else
            {
                name.push_back(people[i++].name);
            }
            left = !left;
        }
        output(name);
    }
    return 0;
}
