#include <iostream>

int callatz(int x)
{
    int ret = 0;
    while (x != 1)
    {
        if (x & 1)
        {
            x = (3 * x + 1) >> 1;
        }
        else
        {
            x >>= 1;
        }
        ++ret;
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int inp = 1;
    while (std::cin >> inp)
    {
        std::cout << callatz(inp) << std::endl;
    }
    return 0;
}