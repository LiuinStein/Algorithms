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
#include <string>
#include <unordered_map>
#include <vector>

int main()
{
    int a, b, t;
    std::cin >> a >> b;
    t = a + b;
    std::deque<int> ss;
    if (t == 0)
    {
        std::cout << t << std::endl;
        return 0;
    }
    if (t < 0)
    {
        std::cout << "-";
    }
    while (t != 0)
    {
        ss.push_front(std::abs(t % 1000));
        t /= 1000;
    }
    std::printf("%d", ss.front());
    ss.pop_front();
    while (!ss.empty())
    {
        std::printf(",%03d", ss.front());
        ss.pop_front();
    }
    return 0;
}
