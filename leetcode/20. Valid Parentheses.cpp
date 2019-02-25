static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stk;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stk.push(s[i]);
            }
            else if (s[i] == ')' && !stk.empty() && stk.top() == '(' ||
                s[i] == ']' && !stk.empty() && stk.top() == '[' ||
                s[i] == '}' && !stk.empty() && stk.top() == '{')
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }
        return stk.empty();
    }
};