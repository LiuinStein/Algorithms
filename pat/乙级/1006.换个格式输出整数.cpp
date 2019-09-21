#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string num;
    while (std::cin >> num)
    {
        if (num.size() == 3)
        {
            for (int i = 0; i < num[0] - '0'; ++i)
            {
                std::cout << 'B';
            }
            for (int i = 0; i < num[1] - '0'; ++i)
            {
                std::cout << 'S';
            }
        }
        if (num.size() == 2)
        {
            for (int i = 0; i < num[0] - '0'; ++i)
            {
                std::cout << 'S';
            }
        }
        for (int i = 0; i < num[num.size() - 1] - '0'; ++i)
        {
            std::cout << i + 1;
        }
        std::cout << std::endl;
    }
    return 0;
}