static int ____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (nums.size() == 1) {
            return nums[0] == std::abs(target);
        }
        if (sum == target) {
            return std::pow(2, std::count(nums.begin(), nums.end(), 0));
        }
        if ((target = sum - target) & 1) {
            return 0;
        }
        target >>= 1;
        // find the count of sub-sequences made the sum of it equivalent to the new target
        std::vector<std::unordered_map<int, int>> dp(nums.size() + 1);
        dp[1][nums[0]] = 1;
        for (int i = 2; i <= nums.size(); i++) {
            dp[i][nums[i - 1]] += 1;
            for (auto pair = dp[i - 1].begin(); pair != dp[i - 1].end(); ++pair) {
                dp[i][pair->first] += pair->second;
                dp[i][pair->first + nums[i - 1]] += pair->second;
            }
        }
        return dp[nums.size()][target];
    }
};