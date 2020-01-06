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

std::string add(std::string &a, std::string &b, std::string &t)
{
    if (b.size() > a.size())
    {
        return add(b, a, t);
    }
    int q = t.size() - 1;
    std::string result;
    int u = 0;
    int i = b.size() - 1, j = a.size() - 1;
    for (; i >= 0 && j >= 0; i--, j--, q--)
    {
        int v = a[j] + b[i] + u - 2 * '0';
        int n = q < 0 || t[q] - '0' == 0 ? 10 : t[q] - '0';
        result.push_back((v % n) + '0');
        u = v / n;
    }
    for (; j >= 0; j--, q--)
    {
        int v = a[j] - '0' + u;
        int n = q < 0 || t[q] - '0' == 0 ? 10 : t[q] - '0';
        result.push_back((v % n) + '0');
        u = v / n;
    }
    while (u != 0)
    {
        int v = u;
        int n = q < 0 || t[q] - '0' == 0 ? 10 : t[q] - '0';
        result.push_back((v % n) + '0');
        u = v / n;
        q--;
        j--;
    }
    std::reverse(result.begin(), result.end());
    int pos = result.find_first_not_of('0');
    if (pos == result.npos)
    {
        return "0";
    }
    return result.substr(pos);
}

int main()
{
    std::string table, a, b;
    std::cin >> table >> a >> b;
    std::cout << add(a, b, table) << std::endl;
    return 0;
}
