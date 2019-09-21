static int __init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
    double myPow(double x, long long p)
    {
        switch (p)
        {
        case 0:
            return 1.0;
        case 1:
            return x;
        case 2:
            return x * x;
        default:
            long long raised = p >> 1;
            double tmp = myPow(x, raised);
            return tmp * tmp * (p % 2 == 0 ? 1.0 : x);
        }
    }
public:
    double myPow(double x, int n) {
        // avoid INT_MIN's buggy absolute value
        return n < 0 ? 1.0 / myPow(x, llabs(n)) : myPow(x, static_cast<long long>(n));
    }
};