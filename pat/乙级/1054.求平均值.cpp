#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

double checkAndGetNumber(std::string &inp, bool &v)
{
    double res = 0;
    double base = 0;
    int flag = 1;
    int i = 0;
    if (inp[0] == '-')
    {
        flag = -1;
        i = 1;
    }
    for (; i < inp.size(); ++i)
    {
        if (inp[i] <= '9' && inp[i] >= '0' && base <= 100)
        {
            if (base == 0)
            {
                res *= 10;
                res += inp[i] - '0';
            }
            else
            {
                res += double(inp[i] - '0') / base;
                base *= 10;
            }
        }
        else if (inp[i] == '.' && base == 0)
        {
            base = 10;
        }
        else
        {
            v = false;
            return 0;
        }
    }
    res *= flag;
    if (res > 1000 || res < -1000)
    {
        v = false;
    }
    return res;
}

int main()
{
    int n;
    std::cin >> n;
    int valid = 0;
    double sum = 0;
    while (n--)
    {
        std::string inp;
        std::cin >> inp;
        bool v = true;
        double num = checkAndGetNumber(inp, v);
        if (v)
        {
            valid++;
            sum += num;
        }
        else
        {
            std::cout << "ERROR: " << inp
                      << " is not a legal number" << std::endl;
        }
    }
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2)
              << "The average of " << valid
              << (valid == 1 ? " number is " : " numbers is ");
    if (valid == 0)
    {
        std::cout << "Undefined" << std::endl;
    }
    else
    {
        std::cout << sum / valid << std::endl;
    }
    return 0;
}
