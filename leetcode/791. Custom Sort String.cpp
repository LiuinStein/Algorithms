static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    std::string customSortString(std::string S, std::string T) {
        int ss[26]{};
        std::string ret = "";
        for (char t : T)
        {
            ++ss[t - 'a'];
        }
        for (char s : S)
        {
            while (ss[s - 'a']-- > 0)
            {
                ret.push_back(s);
            }
        }
        for (int i = 0; i < 26; ++i)
        {
            while (ss[i]-- > 0)
            {
                ret.push_back(i + 'a');
            }
        }
        return ret;
    }
};