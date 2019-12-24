#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

void getEMoji(std::string &inp, std::vector<std::string> &out)
{
    std::string tmp;
    for (int i = 0; i < inp.size(); ++i)
    {
        if (inp[i] == '[')
        {
            tmp = "[";
        }
        else if (inp[i] == ']' && !tmp.empty() && tmp[0] == '[')
        {
            out.push_back(tmp.substr(1));
            tmp = "";
        }
        else
        {
            tmp.push_back(inp[i]);
        }
    }
}

int main()
{
    std::vector<std::string> hand, eye, mouth;
    std::string tmp;
    std::getline(std::cin, tmp);
    getEMoji(tmp, hand);
    std::getline(std::cin, tmp);
    getEMoji(tmp, eye);
    std::getline(std::cin, tmp);
    getEMoji(tmp, mouth);
    int n;
    std::cin >> n;
    while (n--)
    {
        std::string res;
        try
        {
            int a, b, c, d, e;
            std::cin >> a >> b >> c >> d >> e;
            res = hand[a - 1] + '(' + eye[b - 1] + mouth[c - 1] + eye[d - 1] + ')' + hand[e - 1];
        }
        catch (std::exception &oor)
        {
            res = "Are you kidding me? @\\/@";
        }
        std::cout << res << std::endl;
    }
    return 0;
}