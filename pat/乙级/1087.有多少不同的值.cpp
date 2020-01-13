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
    std::set<int> set;
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        set.insert(int(double(i) / 2.0) + int(double(i) / 3.0) + int(double(i) / 5.0));
    }
    std::cout << set.size() << std::endl;
    return 0;
}
