static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// Approach #1 0ms
class Solution {

    std::string map[10]{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        auto result = new std::vector<std::string>;
        if (!digits.empty())
        {
            std::string& last = map[digits[digits.size() - 1] - '0'];
            for (int i = 0; i < last.size(); ++i)
            {
                result->push_back(last.substr(i, 1));
            }
            for (int i = digits.size() - 2; i >= 0; --i)
            {
                int beforeSize = result->size();
                std::string& mapped = map[digits[i] - '0'];
                int mappedSize = mapped.size();
                int afterSize = (beforeSize == 0 ? 1 : beforeSize) * mappedSize;
                auto tmp = result;
                result = new std::vector<std::string>;
                for (int j = 0; j < beforeSize; ++j)
                {
                    result->insert(result->end(), mappedSize, (*tmp)[j]);
                }
                for (int j = 0; j < afterSize; ++j)
                {
                    (*result)[j] = mapped[j % mappedSize] + (*result)[j];
                }
                delete tmp;
            }
        }
        return *result;
    }
};