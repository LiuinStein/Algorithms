#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>

int getSameCharCount(std::string &str, int pos)
{
    int c = 0;
    for (int i = pos; i < str.size() && str[pos] == str[i]; i++)
    {
        ++c;
    }
    return c;
}

std::string itoa(int val)
{
    std::stringstream ss;
    ss << val;
    std::string result;
    ss >> result;
    return result;
}

std::string compress(std::string &str)
{
    std::string result;
    for (int i = 0; i < str.size();)
    {
        int c = getSameCharCount(str, i);
        if (c == 1)
        {
            result.push_back(str[i++]);
        }
        else
        {
            result.append(itoa(c));
            result.push_back(str[i]);
            i += c;
        }
    }
    return result;
}

int getNumber(std::string &str, int pos, int &cpos)
{
    std::string s;
    int i = pos, val = 0;
    for (; i < str.size() && isdigit(str[i]); i++)
    {
        s.push_back(str[i]);
    }
    cpos = i;
    std::stringstream ss;
    ss << s;
    ss >> val;
    return val;
}

std::string decompress(std::string &str)
{
    std::string result;
    for (int i = 0; i < str.size();)
    {
        if (isdigit(str[i]))
        {
            int val = getNumber(str, i, i);
            for (int j = 0; j < val; j++)
            {
                result.push_back(str[i]);
            }
            ++i;
        }
        else
        {
            result.push_back(str[i++]);
        }
    }
    return result;
}

int main()
{
    char mode;
    std::cin >> mode;
    std::string inp;
    std::getchar();
    std::getline(std::cin, inp);
    std::cout << (mode == 'C' ? compress(inp) : decompress(inp)) << std::endl;
    return 0;
}
