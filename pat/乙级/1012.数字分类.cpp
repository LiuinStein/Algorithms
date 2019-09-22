#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n)
    {
        int a1 = -1, a2 = -1, a3 = -1, a5 = -1;
        bool a2m = false;
        int a2op = 1;
        double a4 = -1;
        int a4n = 0;
        while (n--)
        {
            int inp;
            std::cin >> inp;
            int mod5 = inp % 5;
            // 能被5整除的数字中所有偶数的和
            if ((inp & 1) == 0 && mod5 == 0)
            {
                a1 += inp;
            }
            switch (mod5)
            {
            case 1:
                // 将被5除后余1的数字按给出顺序进行交错求和
                a2m = true;
                a2 += a2op * inp;
                a2op *= -1;
                break;
            case 2:
                // 被5除后余2的数字的个数
                a3++;
                break;
            case 3:
                // 被5除后余3的数字的平均数，精确到小数点后1位
                a4 += inp;
                a4n++;
                break;
            case 4:
                // 被5除后余4的数字中最大数字
                a5 = std::max(inp, a5);
                break;
            }
        }

        if (a1 == -1)
            std::cout << "N" << " ";
        else
            std::cout << a1 + 1 << " ";
        if (a2m)
            std::cout << a2 + 1 << " ";
        else
            std::cout << "N" << " ";
        if (a3 == -1)
            std::cout << "N" << " ";
        else
            std::cout << a3 + 1 << " ";
        if (a4 == -1)
            std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1) << "N" << " ";
        else
            std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1) << (a4 + 1) / a4n << " ";
        if (a5 == -1)
            std::cout << "N" << std::endl;
        else
            std::cout << a5 << std::endl;
    }
    return 0;
}