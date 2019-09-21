static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// Approach #1 0ms
class Solution {

public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        int len1 = num1.size();
        int len2 = num2.size();
        std::string ret(len1 + len2 + 1, '0');
        int start = 0;
        for (int i = num1.size() - 1; i >= 0; --i)
        {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; --j)
            {
                int tmp = (num1[i] - '0') * (num2[j] - '0') + carry;
                tmp += ret[start + num2.size() - 1 - j] - '0';
                ret[start + num2.size() - 1 - j] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            ret[start + num2.size()] = carry + '0';
            ++start;
        }
        std::reverse(ret.begin(), ret.end());
        int begin = 0;
        while (ret[begin] == '0')
        {
            ++begin;
        }
        return ret.substr(begin);
    }
};

// Approach #2 16ms
class Solution {

    std::string tr[10]{ "0","","","","","","","","","" };

    std::string times(std::string num1, char num2)
    {
        if (!tr[num2 - '0'].empty())
        {
            return tr[num2 - '0'];
        }
        int carry = 0;
        std::string result;
        result.reserve(num1.size() + 1);
        for (int i = num1.size() - 1; i >= 0; --i)
        {
            int tmp = (num1[i] - '0') * (num2 - '0') + carry;
            carry = tmp / 10;
            result.push_back('0' + tmp % 10);
        }
        if (carry != 0)
        {
            result.push_back('0' + carry);
        }
        std::reverse(result.begin(), result.end());
        tr[num2 - '0'] = result;
        return result;
    }

    std::string plus(std::string longer, std::string shorter)
    {
        if (longer.size() < shorter.size())
        {
            return plus(shorter, longer);
        }
        std::string result;
        result.reserve(longer.size() + 1);
        int carry = 0;
        int j = longer.size() - 1;
        for (int i = shorter.size() - 1; i >= 0 && j >= 0; --i, --j)
        {
            int tmp = (shorter[i] - '0') + (longer[j] - '0') + carry;
            carry = tmp / 10;
            result.push_back('0' + tmp % 10);
        }
        while (carry != 0)
        {
            // must equals to 1
            int tmp = j >= 0 ? (longer[j--] - '0') + carry : carry;
            carry = tmp / 10;
            result.push_back('0' + tmp % 10);
        }
        while (j >= 0)
        {
            result.push_back(longer[j--]);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num2.size() > num1.size())
        {
            return multiply(num2, num1);
        }
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        std::string result = "0";
        std::string zeros;
        for (int i = num2.size() - 1; i >= 0; --i)
        {
            std::string tmp = times(num1, num2[i]);
            result = plus(tmp + zeros, result);
            zeros.push_back('0');
        }
        return result;
    }
};