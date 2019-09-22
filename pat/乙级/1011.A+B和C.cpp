#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        long long a, b, c;
        std::cin >> a >> b >> c;
        std::cout << "Case #" << i + 1 << ": " << (a + b > c ? "true" : "false") << std::endl;
    }
    return 0;
}