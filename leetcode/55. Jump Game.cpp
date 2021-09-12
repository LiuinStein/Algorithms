static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int rightmost = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= rightmost) {
                rightmost = std::max(rightmost, i + nums[i]);
                if (rightmost >= nums.size() - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};