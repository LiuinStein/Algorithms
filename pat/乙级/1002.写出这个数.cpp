#include <iostream>
#include <string>

const std::string map[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string str;
    while (std::cin >> str)
    {
        int ret = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            ret += str[i] - '0';
        }
        std::string res;
        if (ret == 0)
        {
            res = "ling ";
        }
        else
        {
            while (ret != 0)
            {
                res = map[ret % 10] + " " + res;
                ret /= 10;
            }
        }
        std::cout << res.substr(0, res.size() - 1) << std::endl;
    }
    return 0;
}