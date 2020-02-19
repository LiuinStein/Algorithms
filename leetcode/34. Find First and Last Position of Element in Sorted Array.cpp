static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        int pos = -1, lo = 0, hi = nums.size();
        while (lo < hi)
        {
            int mid = (lo + hi) >> 1;
            if (nums[mid] == target)
            {
                pos = mid;
                break;
            }
            if (nums[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        std::vector<int> result(2, -1);
        if (pos != -1)
        {
            for (int i = pos; i >= 0; i--)
            {
                if (nums[i] == nums[pos])
                {
                    result[0] = i;
                }
                else
                {
                    break;
                }
            }
            for (int i = pos; i < nums.size(); i++)
            {
                if (nums[i] == nums[pos])
                {
                    result[1] = i;
                }
                else
                {
                    break;
                }
            }
            result[0] = result[0] == -1 ? pos : result[0];
            result[1] = result[1] == -1 ? pos : result[1];
        }
        return result;
    }
};