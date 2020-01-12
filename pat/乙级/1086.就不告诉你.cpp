#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::string s;
    std::stringstream ss;
    ss << a * b;
    ss >> s;
    std::reverse(s.begin(), s.end());
    ss.clear();
    ss << s;
    ss >> a;
    std::cout << a << std::endl;
    return 0;
}
