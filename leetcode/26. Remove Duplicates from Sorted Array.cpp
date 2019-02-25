static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        unsigned size{ nums.size() };
        if (size < 2)
        {
            return size;
        }
        std::vector<int> ret;
        ret.emplace_back(nums[0]);
        for (int i{ 1 }; i < size; ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                ret.emplace_back(nums[i]);
            }
        }
        nums = ret;
        return ret.size();
    }
};