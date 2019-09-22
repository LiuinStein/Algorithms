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
        std::stringstream sstream;
        sstream << inp;
        int d, u;
        sstream >> d >> u;
        std::cout << d * u << " " << (u != 0 ? u - 1 : 0);
        while (sstream >> d >> u)
        {
            if (u != 0)
            {
                std::cout << " " << d * u << " " << u - 1;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}