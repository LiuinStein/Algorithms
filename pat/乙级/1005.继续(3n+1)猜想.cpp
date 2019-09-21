#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int num = 0;
    while (std::cin >> num)
    {
        // 99 98 97这样的数字，会把变化产生的结果累加地非常大
        bool coverd[100000]{};
        int* inputs = new int[num];
        for (int i = 0; i < num; ++i)
        {
            std::cin >> inputs[i];
            if (!coverd[inputs[i]])
            {
                int x = inputs[i];
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
                    coverd[x] = true;
                }
            }
        }
        std::sort(inputs, inputs + num);
        std::string result;
        for (int i = 0; i < num; ++i)
        {
            if (!coverd[inputs[i]])
            {
                char* buff = new char[5];
                std::sprintf(buff, "%d", inputs[i]);
                result = buff + (" " + result);
            }
        }
        std::cout << result.substr(0, result.size() - 1) << std::endl;
    }
    return 0;
}