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
    int n;
    std::cin >> n;
    std::getchar();
    std::string inp, result;
    for (int i = 0; i < n; i++)
    {
        std::getline(std::cin, inp);
        int pos = inp.find("T");
        result.push_back(inp[pos - 2] - 'A' + '1');
    }
    std::cout << result << std::endl;
    return 0;
}
