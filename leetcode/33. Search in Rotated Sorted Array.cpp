static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        if (!nums.empty())
        {
            int lo = 0, hi = nums.size();
            while (lo < hi)
            {
                int mid = (lo + hi) >> 1;
                if (nums[mid] == target)
                {
                    return mid;
                }
                if (nums[0] <= target)
                {
                    if (nums[mid] < nums[0] || target < nums[mid])
                    {
                        hi = mid;
                    }
                    else
                    {
                        lo = mid + 1;
                    }
                }
                else
                {
                    if (nums[mid] > nums[0] || target > nums[mid])
                    {
                        lo = mid + 1;
                    }
                    else
                    {
                        hi = mid;
                    }
                }
            }
        }
        return -1;
    }
};