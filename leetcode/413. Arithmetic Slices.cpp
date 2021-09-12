static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int res = 0;
        for (int i = 0; i + 3 <= nums.size(); i++) {
            int ans = nums[i + 2] - nums[i + 1];
            if (ans == nums[i + 1] - nums[i]) {
                res += 1;
                for (int j = i + 3; j < nums.size() && ans == nums[j] - nums[j - 1]; j++) {
                    res += 1;
                }
            }
        }
        return res;
    }
};