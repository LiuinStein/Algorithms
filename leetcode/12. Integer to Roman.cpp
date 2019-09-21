static int __init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
// Best
class Solution {
public:
    string intToRoman(int num) {
        vector<string> Symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int>    Value  = {1000, 900, 500, 400,  100, 90,   50,  40,   10,   9,    5,   4,    1};
        
        string res;
        int len = Value.size();
        for (int i = 0; i < len; i++)
        {
            while(num >= Value[i])
            {
                res += Symbol[i];
                num -= Value[i];
            }
        }
        
        return res;
    }
};
// Good
class Solution {

    std::string intToRoman(int num, int unit)
    {
        if (num == 0)
        {
            return "";
        }
        // 1 10 100
        std::string one[5]{ "", "I", "X", "C", "M" };
        // 5 50 500
        std::string five[4]{ "", "V", "L", "D" };
        // 10 100 1000
        std::string ten[4]{ "", "X", "C", "M" };
        switch (num)
        {
        case 1:
            return one[unit];
        case 2:
            return one[unit] + one[unit];
        case 3:
            return one[unit] + one[unit] + one[unit];
        case 4:
            return one[unit] + five[unit];
        case 5:
            return five[unit];
        case 6:
            return five[unit] + one[unit];
        case 7:
            return five[unit] + one[unit] + one[unit];
        case 8:
            return five[unit] + one[unit] + one[unit] + one[unit];
        case 9:
            return one[unit] + ten[unit];
        default:
            return "";
        }
    }
public:
    std::string intToRoman(int num) {
        int thousand = num / 1000;
        int hundred = num / 100 - thousand * 10;
        int ten = num / 10 - thousand * 100 - hundred * 10;
        int one = num - thousand * 1000 - hundred * 100 - ten * 10;
        return intToRoman(thousand, 4) + intToRoman(hundred, 3) +
            intToRoman(ten, 2) + intToRoman(one, 1);
    }
};