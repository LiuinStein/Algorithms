#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string inp;
    while (std::getline(std::cin, inp))
    {
        int e = inp.size();
        for (int i = inp.size() - 1; i >= 0; --i)
        {
            if (inp[i] == ' ')
            {
                std::cout << inp.substr(i + 1, e - i - 1) << " ";
                e = i;
            }
        }
        std::cout << inp.substr(0, e) << std::endl;
    }
    return 0;
}