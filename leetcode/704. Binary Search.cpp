static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int lo = 0, hi = nums.size(), mid;
        while (lo < hi)
        {
            mid = (lo + hi) >> 1;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return -1;
    }
};