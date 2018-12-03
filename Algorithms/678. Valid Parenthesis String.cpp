static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool checkValidString(std::string s) {
        std::stack<int> left, star;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                left.push(i);
            }
            else if (s[i] == ')')
            {
                if (left.empty() && star.empty())
                {
                    return false;
                }
                if (!left.empty())
                {
                    left.pop();
                }
                else if (!star.empty())
                {
                    star.pop();
                }
            }
            else
            {
                star.push(i);
            }
        }
        while (!left.empty() && !star.empty())
        {
            if (left.top() > star.top())
            {
                return false;
            }
            left.pop();
            star.pop();
        }
        return left.empty();
    }
};