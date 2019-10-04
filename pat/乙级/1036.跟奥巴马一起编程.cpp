#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <regex>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <cctype>
#include <unordered_map>

void printLine(int n, char c)
{
    std::cout << c;
    for (int i = 0; i < n - 2; ++i)
    {
        std::cout << " ";
    }
    std::cout << c << std::endl;
}

void printBoundary(int n, char c)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << c;
    }
    std::cout << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    char c;
    while (std::cin >> n >> c)
    {
        int l = (n * 5) % 10 >= 5 ? (n >> 1) + 1 : (n >> 1);
        printBoundary(n, c);
        for (int i = 0; i < l - 2; ++i)
        {
            printLine(n, c);
        }
        printBoundary(n, c);
    }
    return 0;
}