static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max = 0;
        for (int i = 1; i < prices.size(); i++) {
            max += std::max(0, prices[i] - prices[i - 1]);
        }
        return max;
    }
};