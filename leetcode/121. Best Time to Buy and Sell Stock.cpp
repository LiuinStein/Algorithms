static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() < 2)
        {
            return 0;
        }
        int max = INT_MIN;
        int f1 = 0;
        int f = 0;
        for (int i = prices.size() - 2; i >= 0; --i)
        {
            int tmp = prices[i + 1] - prices[i] + f1;
            f = tmp < 0 ? 0 : tmp;
            max = f > max ? f : max;
            f1 = f;
        }
        return max;
    }
};