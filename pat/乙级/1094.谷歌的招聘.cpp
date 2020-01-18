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

bool checkPrime(std::string &a)
{
    int m = std::atoi(a.c_str());
    int k = std::sqrt(m);
    for (int i = 2; i <= k; i++)
    {
        if (m % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::string num;
    std::cin >> num;
    for (int i = 0; i <= n - k; i++)
    {
        std::string c = num.substr(i, k);
        if (checkPrime(c))
        {
            std::cout << c << std::endl;
            return 0;
        }
    }
    std::cout << 404 << std::endl;
    return 0;
}
