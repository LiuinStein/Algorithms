static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    bool validPalindrome(std::string &s, int begin, int end, bool d)
    {
        if (begin >= end)
        {
            return true;
        }
        for (int i = begin, j = end - 1; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                if (d)
                {
                    return false;
                }
                return validPalindrome(s, i + 1, j + 1, true) || validPalindrome(s, i, j, true);
            }
        }
        return true;
    }

public:
    bool validPalindrome(std::string s)
    {
        return validPalindrome(s, 0, s.size(), false);
    }
};