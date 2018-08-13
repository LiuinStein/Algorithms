static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    std::string frequencySort(std::string s) {
        std::string ret;
        std::map<char, int> m;
        for (char c : s)
        {
            ++m[c];
        }
        std::vector<std::pair<char, int>> vec;
        for (std::pair<const char, int> pair : m)
        {
            vec.push_back(pair);
        }
        std::sort(vec.begin(), vec.end(), [](std::pair<const char, int> a, std::pair<const char, int> b)
        {
            return a.second > b.second;
        });
        for (std::pair<char, int> pair : vec)
        {
            while (pair.second-- > 0)
            {
                ret.push_back(pair.first);
            }
        }
        return ret;
    }
};