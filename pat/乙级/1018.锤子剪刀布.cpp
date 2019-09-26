#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <regex>
#include <sstream>
#include <iomanip>
#include <vector>

bool checkIfAWin(char a, char b)
{
    return (a == 'C' && b == 'J') || (a == 'J' && b == 'B') || (a == 'B' && b == 'C');
}

char mostWonGesture(int wg[26])
{
    if (wg['B' - 'A'] >= wg['C' - 'A'])
    {
        return wg['B' - 'A'] >= wg['J' - 'A'] ? 'B' : 'J';
    }
    // B < C
    return wg['C' - 'A'] >= wg['J' - 'A'] ? 'C' : 'J';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n)
    {
        int aw = 0, draw = 0, bw = 0;
        int awg[26]{}, bwg[26]{};
        char a, b;
        while (n--)
        {
            std::cin >> a >> b;
            if (a == b)
            {
                ++draw;
                continue;
            }
            if (checkIfAWin(a, b))
            {
                ++aw;
                ++awg[a - 'A'];
            }
            else
            {
                ++bw;
                ++bwg[b - 'A'];
            }
        }
        std::cout << aw << " " << draw << " " << bw << std::endl;
        std::cout << bw << " " << draw << " " << aw << std::endl;
        std::cout << mostWonGesture(awg) << " " << mostWonGesture(bwg) << std::endl;
    }
    return 0;
}
