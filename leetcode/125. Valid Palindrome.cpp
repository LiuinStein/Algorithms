static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        std::string ss, pp;
        for (int i = 0; i < s.size(); i++)
        {
            if (std::isalnum(s[i]))
            {
                ss.push_back(std::tolower(s[i]));
            }
        }
        pp = ss;
        std::reverse(pp.begin(), pp.end());
        return pp == ss;
    }
};