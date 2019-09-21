static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// dynamic programming #non-recursive 0ms
class Solution {

public:
    int numDecodings(std::string s) {
        // given an NON-EMPTY string
        if (s[0] == '0')
        {
            return 0;
        }
        if (s.size() == 1)
        {
            return 1;
        }
        std::vector<int> dp(s.size() + 1, 0);
        dp[s.size() - 1] = s[s.size() - 1] == '0' ? 0 : 1;
        dp[s.size()] = 1;
        for (int i = s.size() - 2; i >= 0; --i)
        {
            if (s[i] != '0')
            {
                dp[i] = dp[i + 1] + (s[i] < '2' || (s[i] == '2' && s[i + 1] < '7') ? dp[i + 2] : 0);
            }
        }
        return dp[0];
    }
};

// dynamic programming #recursive 8ms
class Solution {

    std::vector<int> *dp;

    int numDecodings(std::string s, int start)
    {
        if (start >= s.size() || s[start] == '0' || (s[s.size() - 1] == '0' && s[s.size() - 2] > '2'))
        {
            return 0;
        }
        if ((*dp)[start] != -1)
        {
            return (*dp)[start];
        }
        int len = s.size() - start;
        if (len == 1)
        {
            (*dp)[start] = 1;
        }
        else if (len == 2)
        {
            (*dp)[start] = s[s.size() - 1] != '0' && ((s[start] - '0') * 10 + (s[start + 1] - '0')) <= 26 ? 2 : 1;
        }
        else
        {
            (*dp)[start] = numDecodings(s, start + 1) +
                (((s[start] - '0') * 10 + (s[start + 1] - '0')) <= 26 ? numDecodings(s, start + 2) : 0);
        }
        return (*dp)[start];
    }
public:
    int numDecodings(std::string s) {
        // given an NON-EMPTY string
        dp = new std::vector<int>(s.size(), -1);
        return numDecodings(s, 0);
    }
};