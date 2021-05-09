static int ____ = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int minCostClimbingStairs(std::vector<int>& cost) {
		cost.push_back(0);
		std::vector<int> f(cost.size() + 1, 0);
		f[1] = cost[0]; f[2] = cost[1];
		for (int i = 2; i < cost.size(); i++) {
			f[i + 1] = cost[i] + std::min(f[i], f[i - 1]);
		}
		return f[cost.size()];
	}
};