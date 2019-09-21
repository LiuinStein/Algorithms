static int __init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {

    int getVal(char c) {
        switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
public:
    int romanToInt(std::string s) {
        int result = 0;
        int i = 0;
        for (; i < s.size() - 1; )
        {
            if (getVal(s[i]) < getVal(s[i + 1]))
            {
                result += getVal(s[i + 1]) - getVal(s[i]);
                i += 2;
            }
            else
            {
                result += getVal(s[i]);
                ++i;
            }
        }
        return result + (i != s.size() ? getVal(s[s.size() - 1]) : 0);
    }
};