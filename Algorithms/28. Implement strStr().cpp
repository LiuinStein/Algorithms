static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {

    void getPartialMatchTable(std::string& needle, std::vector<int>& next)
    {
        int i = 0;
        int j = -1;
        next[0] = -1;
        while (i < needle.size() - 1)
        {
            if (j == -1 || needle[i] == needle[j])
            {
                next[++i] = ++j;
            }
            else
            {
                j = next[j];
            }
        }
    }
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.size() == 0)
        {
            return 0;
        }
        std::vector<int> next(needle.size());
        getPartialMatchTable(needle, next);

        int i = 0;
        int j = 0;
        int hs = haystack.size();
        int ns = needle.size();

        while (i < hs && j < ns)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
        }
        return j == needle.size() ? i - j : -1;
    }
};