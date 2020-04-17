static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    void sort(std::vector<int> &nums, int begin, int end)
    {
        if (begin + 1 >= end)
        {
            return;
        }
        int p = end - 1, i = begin - 1;
        for (int j = begin; j < p; j++)
        {
            if (nums[j] <= nums[p])
            {
                std::swap(nums[++i], nums[j]);
            }
        }
        std::swap(nums[++i], nums[p]);
        sort(nums, begin, i);
        sort(nums, i + 1, end);
    }

public:
    std::vector<int> sortArray(std::vector<int> &nums)
    {
        sort(nums, 0, nums.size());
        return nums;
    }
};