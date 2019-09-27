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
#include <unordered_map>

struct node
{
    std::string data;
    int next;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int start;
    int n, k;
    while (std::cin >> start >> n >> k)
    {
        std::unordered_map<int, node> map;
        for (int i = 0; i < n; ++i)
        {
            int addr;
            node x;
            std::cin >> addr >> x.data >> x.next;
            map[addr] = x;
        }
        std::vector<int> list;
        node tmp = map[start];
        list.push_back(start);
        while (tmp.next != -1)
        {
            list.push_back(tmp.next);
            tmp = map[tmp.next];
        }
        # 要注意此处有个坑就是，输入的数据未必都是链表中的结点
        n = list.size();
        for (int i = 0; i < n && n - i >= k; i += k)
        {
            std::reverse(list.begin() + i, list.begin() + i + k);
        }
        for (int i = 0; i < list.size() - 1; ++i)
        {
            std::printf("%05d %s %05d\n", list[i], map[list[i]].data.c_str(), list[i + 1]);
        }
        std::printf("%05d %s -1\n", list[list.size() - 1], map[list[list.size() - 1]].data.c_str());
    }
    return 0;
}
