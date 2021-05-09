static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
public:
	bool canPartition(std::vector<int>& nums) {
		int sum = 0, max = INT_MIN;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			max = std::max(max, nums[i]);
		}
		int target = sum >> 1;
		if ((sum & 1) || max > target) {
			return false;
		}
		std::vector<std::vector<bool>> f(nums.size(), std::vector<bool>(target + 1, false));
		f[0][nums[0]] = true;
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 1; j <= target; j++) {
				f[i][j] = f[i - 1][j] || (j - nums[i] >= 0 && f[i - 1][j - nums[i]]);
			}
		}
		return f[nums.size() - 1][target];
	}
};