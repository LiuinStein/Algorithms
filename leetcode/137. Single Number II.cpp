static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            if (i+1 < nums.size() && nums[i] == nums[i+1]) {
                i += 3;
            } else {
                return nums[i];
            }
        }
        return nums[nums.size() - 1];
    }
};