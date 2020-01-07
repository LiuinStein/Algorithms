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

struct Node
{
    int addr;
    int value;
    int next;
};

int main()
{
    int begin, n, k;
    std::cin >> begin >> n >> k;
    std::unordered_map<int, Node> list;
    for (int i = 0; i < n; i++)
    {
        int addr, value, next;
        std::cin >> addr >> value >> next;
        list[addr] = {addr, value, next};
    }
    std::vector<Node> result;
    // add the negative numbers
    for (int i = begin; i != -1; i = list[i].next)
    {
        if (list[i].value < 0)
        {
            result.push_back(list[i]);
        }
    }
    for (int i = begin; i != -1; i = list[i].next)
    {
        if (list[i].value >= 0 && list[i].value <= k)
        {
            result.push_back(list[i]);
        }
    }
    for (int i = begin; i != -1; i = list[i].next)
    {
        if (list[i].value > k)
        {
            result.push_back(list[i]);
        }
    }
    //
    for (int i = 0; i + 1 < result.size(); i++)
    {
        result[i].next = result[i + 1].addr;
    }
    result[result.size() - 1].next = -1;
    //
    for (int i = 0; i < result.size() - 1; i++)
    {
        std::printf("%05d %d %05d\n", result[i].addr, result[i].value, result[i].next);
    }
    std::printf("%05d %d -1\n", result[result.size() - 1].addr, result[result.size() - 1].value);
    return 0;
}
