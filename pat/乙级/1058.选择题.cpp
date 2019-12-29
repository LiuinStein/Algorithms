#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Question
{
    int id;
    int mark;
    int allLabelCount;
    int rightLabelCount;
    int wrongCount;
    std::string rightAnswer;
};

bool operator!=(Question &l, std::string &r)
{
    return l.rightAnswer != r;
}

bool operator<(Question &l, Question &r)
{
    return l.wrongCount > r.wrongCount;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<Question> questions(m);
    for (int i = 0; i < m; i++)
    {
        questions[i].id = i + 1;
        std::cin >> questions[i].mark >> questions[i].allLabelCount >> questions[i].rightLabelCount;
        for (int j = 0; j < questions[i].rightLabelCount; j++)
        {
            char t;
            std::cin >> t;
            questions[i].rightAnswer.push_back(tolower(t));
        }
        std::sort(questions[i].rightAnswer.begin(), questions[i].rightAnswer.end());
    }
    bool allRight = true;
    std::vector<int> scores(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char t;
            int ac;
            std::cin >> t >> ac;
            std::string answer;
            for (int p = 0; p < ac; p++)
            {
                std::cin >> t;
                answer.push_back(tolower(t));
            }
            std::cin >> t;
            std::sort(answer.begin(), answer.end());
            if (questions[j] != answer)
            {
                allRight = false;
                questions[j].wrongCount++;
            }
            else
            {
                scores[i] += questions[j].mark;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << scores[i] << std::endl;
    }
    if (allRight)
    {
        std::cout << "Too simple" << std::endl;
    }
    else
    {
        std::sort(questions.begin(), questions.end());
        std::cout << questions[0].wrongCount << " ";
        int i = 0;
        for (; i + 1 < questions.size() && questions[0].wrongCount == questions[i + 1].wrongCount; i++)
        {
            std::cout << questions[i].id << " ";
        }
        std::cout << questions[i].id << std::endl;
    }
    return 0;
}
