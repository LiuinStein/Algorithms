#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::unordered_map<int, bool> prohibited;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        std::cin >> tmp;
        prohibited[tmp] = true;
    }
    int sc = 0, bc = 0;
    for (int i = 0; i < n; i++)
    {
        std::string name;
        int num;
        std::cin >> name >> num;
        std::vector<int> list;
        for (int j = 0; j < num; j++)
        {
            int belonging;
            std::cin >> belonging;
            if (prohibited[belonging])
            {
                list.push_back(belonging);
            }
        }
        if (list.size() > 0)
        {
            sc++;
            bc += list.size();
            std::cout << name << ": ";
            for (int j = 0; j < list.size() - 1; j++)
            {
                std::printf("%04d ", list[j]);
            }
            std::printf("%04d\n", list[list.size() - 1]);
        }
    }
    std::cout << sc << " " << bc << std::endl;
    return 0;
}
