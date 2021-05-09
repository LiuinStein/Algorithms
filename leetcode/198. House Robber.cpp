static int ____ = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        std::vector<int> f(nums.size(), 0);
        f[0] = nums[0], f[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            f[i] = std::max(f[i - 2] + nums[i], f[i - 1]);
        }
        return f[nums.size() - 1];
    }
};