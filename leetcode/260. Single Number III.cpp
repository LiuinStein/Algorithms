static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> result;
        for (int i = 0; i < nums.size();) {
            if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i += 2;
            } else {
                result.push_back(nums[i++]);
                if (result.size() == 2) {
                    break;
                }
            }
        }
        return result;
    }
};