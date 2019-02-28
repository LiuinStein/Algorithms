static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3)
        {
            return n;
        }
        n -= 3;
        int f = 3, f1 = 2;
        while (n--)
        {
            f += f1;
            f1 = f - f1;
        }
        return f;
    }
};