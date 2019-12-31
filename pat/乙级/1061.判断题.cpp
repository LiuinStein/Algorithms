#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct Question
{
    int mark;
    int rightAnswer;
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<Question> questions(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> questions[i].mark;
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> questions[i].rightAnswer;
    }
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            int t;
            std::cin >> t;
            sum += questions[j].rightAnswer == t ? questions[j].mark : 0;
        }
        std::cout << sum << std::endl;
    }
    return 0;
}
