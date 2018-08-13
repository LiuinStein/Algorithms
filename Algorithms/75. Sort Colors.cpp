static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_index = 0;
	    int two_index = nums.size() - 1;
		for (int i = 0; i <= two_index; i++) {
			if (nums[i] == 0)
				swap(nums[i], nums[zero_index++]);
			else if (nums[i] == 2)
				swap(nums[i--], nums[two_index--]);
        }
    }
};