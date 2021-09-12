static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int lengthOfLIS(std::vector<int>& nums) {
		std::vector<int> dp(nums.size() + 1, 1);
		int max = 1;
		for (int i = 2; i < nums.size() + 1; i++) {
			for (int j = 1; j < i; j++) {
				if (nums[i - 1] > nums[j - 1]) {
					dp[i] = std::max(dp[i], dp[j] + 1);
					max = std::max(max, dp[i]);
				}
			}
		}
		return max;
	}
};