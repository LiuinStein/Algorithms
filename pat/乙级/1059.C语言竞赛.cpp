#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool checkPrim(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        int t = n / i;
        if (t * i == n)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    std::cin >> n;
    std::unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        int id;
        std::cin >> id;
        map[id] = i + 1;
    }
    int k;
    std::cin >> k;
    while (k--)
    {
        int q;
        std::cin >> q;
        printf("%04d: ", q);
        // std::cout << q << ": ";
        if (map.find(q) != map.end())
        {
            if (map[q] == 1)
            {
                std::cout << "Mystery Award" << std::endl;
            }
            else if (map[q] == -1)
            {
                std::cout << "Checked" << std::endl;
            }
            else if (checkPrim(map[q]))
            {
                std::cout << "Minion" << std::endl;
            }
            else
            {
                std::cout << "Chocolate" << std::endl;
            }
            map[q] = -1;
        }
        else
        {
            std::cout << "Are you kidding?" << std::endl;
        }
    }
    return 0;
}
