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
    std::string right;
    int n;
    std::cin >> right >> n;
    std::string attempt;
    bool flag = false;
    std::getchar();
    while (n--)
    {
        std::getline(std::cin, attempt);
        if (attempt == "#")
        {
            flag = true;
            break;
        }
        if (attempt == right)
        {
            flag = true;
            std::cout << "Welcome in" << std::endl;
            break;
        }
        else
        {
            std::cout << "Wrong password: " << attempt << std::endl;
        }
    }
    if (!flag)
    {
        std::cout << "Account locked" << std::endl;
    }
    return 0;
}
