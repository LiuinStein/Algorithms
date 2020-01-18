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
    std::string a, b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);
    a.append(b);
    b.clear();
    for (int i = 0; i < a.size(); i++)
    {
        if (b.find(a[i]) == std::string::npos)
        {
            b.push_back(a[i]);
        }
    }
    std::cout << b << std::endl;
    return 0;
}
