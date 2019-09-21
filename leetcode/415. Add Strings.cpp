static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string addStrings(string longer, string shorter) {
        if (longer.size() < shorter.size())
        {
            return addStrings(shorter, longer);
        }
        std::string result;
        result.reserve(longer.size() + 1);
        int carry = 0;
        int j = longer.size() - 1;
        for (int i = shorter.size() - 1; i >= 0 && j >= 0; --i, --j)
        {
            int tmp = (shorter[i] - '0') + (longer[j] - '0') + carry;
            carry = tmp / 10;
            result.push_back('0' + (tmp - carry * 10));
        }
        while (carry != 0)
        {
            // must equals to 1
            int tmp = j >= 0 ? (longer[j--] - '0') + carry : carry;
            carry = tmp / 10;
            result.push_back('0' + (tmp - carry * 10));
        }
        while (j >= 0)
        {
            result.push_back(longer[j--]);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};