#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int num = 0;
    while(std::cin >> num)
    {
        std::string scores[101];
        while (num--)
        {
            std::string tmp1, tmp2;
            std::cin >> tmp1;
            tmp2 += tmp1 + " ";
            std::cin >> tmp1;
            tmp2 += tmp1;
            int score = 0;
            std::cin >> score;
            scores[score] = tmp2;
        }
        for (int i = 100; i >= 0; --i)
        {
            if (!scores[i].empty())
            {
                std::cout << scores[i] << std::endl;
                break;
            }
        }
        for (int i = 0; i < 101; ++i)
        {
            if (!scores[i].empty())
            {
                std::cout << scores[i] << std::endl;
                break;
            }
        }
    }
    return 0;
}
