#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string inp;
    std::getline(std::cin, inp);
    unsigned long long sum = 0;
    for (int i = 0; i < inp.size(); i++)
    {
        if (isalpha(inp[i]))
        {
            sum += tolower(inp[i]) - 'a' + 1;
        }
    }
    unsigned long long zc = 0, oc = 0;
    while (sum != 0)
    {
        if (sum & 1)
        {
            oc++;
        }
        else
        {
            zc++;
        }
        sum >>= 1;
    }
    std::cout << zc << " " << oc << std::endl;
    return 0;
}
