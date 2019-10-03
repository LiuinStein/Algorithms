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

int n = 0;
bool checkIfInsertion(std::vector<int>& a, std::vector<int>& b)
{
    // 前半段有序
    for (int i = 0; i < a.size() - 1; ++i)
    {
        if (b[i + 1] < b[i])
        {
            n = i + 1;
            break;
        }
    }
    // 后半段相等
    for (int i = n; i < a.size(); ++i)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

void insertion(std::vector<int>& t)
{
    std::sort(t.begin(), t.begin() + (n + 1));
}

void merge(std::vector<int> &a)
{
    int cnt = 1;
    bool ended = false;
    while (!ended)
    {
        cnt <<= 1;
        for (int i = 0; i < a.size() - cnt; i += cnt)
        {
            for (int j = i; j < i + cnt - 1; ++j)
            {
                if (a[j + 1] < a[j])
                {
                    ended = true;
                    break;
                }
            }
            if (ended)
            {
                break;
            }
        }
    }
    for (int i = 0; i < a.size() - a.size() % cnt; i += cnt)
    {
        std::sort(a.begin() + i, a.begin() + (i + cnt));
    }
    std::sort(a.begin() + (a.size() - a.size() % cnt), a.end());
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n)
    {
        std::vector<int> inp(n);
        std::vector<int> target(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> inp[i];
        }
        for (int i = 0; i < n; ++i)
        {
            std::cin >> target[i];
        }
        if (checkIfInsertion(inp, target))
        {
            std::cout << "Insertion Sort" << std::endl;
            insertion(target);
        }
        else
        {
            std::cout << "Merge Sort" << std::endl;
            merge(target);
        }

        for (int i = 0; i < n - 1; ++i)
        {
            std::cout << target[i] << " ";
        }
        std::cout << target[n - 1] << std::endl;
    }
    return 0;
}