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
    int m, k;
    std::cin >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int n1, b, t, n2;
        std::cin >> n1 >> b >> t >> n2;
        if (m < t)
        {
            std::cout << "Not enough tokens.  Total = " << m << "." << std::endl;
            continue;
        }
        if ((n2 > n1) == bool(b))
        {
            m += t;
            std::cout << "Win " << t << "!  Total = " << m << "." << std::endl;
        }
        else
        {
            m -= t;
            std::cout << "Lose " << t << ".  Total = " << m << "." << std::endl;
            if (m == 0)
            {
                std::cout << "Game Over." << std::endl;
                return 0;
            }
        }
    }
    return 0;
}
