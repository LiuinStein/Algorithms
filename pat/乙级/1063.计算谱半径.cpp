#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        double t = std::sqrt(a * a + b * b);
        if (t > result)
        {
            result = t;
        }
    }
    printf("%.2f\n", result);
    return 0;
}
