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

int main()
{
    int m;
    std::cin >> m;
    while (m--)
    {
        int k;
        std::cin >> k;
        bool flag = false;
        for (int i = 1; i < 10; i++)
        {
            int num = i * k * k;
            std::stringstream ss;
            std::string a, b;
            ss << num << " " << k;
            ss >> a >> b;
            if (a.substr(a.size() - b.size()) == b)
            {
                flag = true;
                std::cout << i << " " << num << std::endl;
                break;
            }
        }
        if (!flag)
        {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
