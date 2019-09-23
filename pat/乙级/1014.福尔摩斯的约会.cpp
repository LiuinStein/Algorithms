#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <regex>
#include <sstream>
#include <iomanip>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    const std::string days[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    std::string str1, str2, str3, str4;;
    while (std::cin >> str1 >> str2 >> str3 >> str4)
    {
        if (str1.size() > str2.size())
        {
            std::string tmp = str1;
            str1 = str2;
            str2 = tmp;
        }
        if (str3.size() > str4.size())
        {
            std::string tmp = str3;
            str3 = str4;
            str4 = tmp;
        }
        // extract data from str1 and str2
        int i = 0;
        for (; i < str1.size(); ++i)
        {
            if (str1[i] == str2[i] && (str1[i] >= 'A' && str1[i] <= 'G'))
            {
                std::cout << days[str1[i] - 'A'] << " ";
                break;
            }
        }
        for (i = i + 1; i < str1.size(); ++i)
        {
            if (str1[i] == str2[i] && ((str1[i] >= '0' && str1[i] <= '9')
                || (str1[i] >= 'A' && str1[i] <= 'N')))
            {
                int hrs = str1[i] >= '0' && str1[i] <= '9' ? str1[i] - '0' : 9;
                hrs += str1[i] >= 'A' && str1[i] <= 'N' ? str1[i] - 'A' + 1 : 0;
                std::cout << (hrs < 10 ? "0" : "") << hrs << ":";
                break;
            }
        }
        // extract data from str3 and str4
        for (int j = 0; j < str3.size(); ++j)
        {
            if (str3[j] == str4[j] && (str3[j] >= 'a' && str3[j] <= 'z' ||
                str3[j] >= 'A' && str3[j] <= 'Z'))
            {
                std::cout << (j < 10 ? "0" : "") << j << std::endl;
                break;
            }
        }
    }
    return 0;
}