#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int isPrime(int x)
{
    if (x == 2 || x == 3)
    {
        return true;
    }
    if (x % 6 != 1 && x % 6 != 5)
    {
        return false;
    }
    int tmp = std::sqrt(x);
    for (int i = 5; i <= tmp; i += 6)
    {
        if (x % i == 0 || x % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n = 0;
    while (std::cin >> n)
    {
        int res = 0;
        if (n >= 5)
        {
            res = 1;
            int last = 5;
            for (int i = 7; i < n; i += 2)
            {
                if (isPrime(i))
                {
                    if (i - last == 2)
                    {
                        ++res;
                    }
                    last = i;
                }
            }
        }
        std::cout << res << std::endl;
    }
    return 0;
}
