static int __init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
// DFS best


// BF worst
class Solution {

    // the target size
    const unsigned int size[13]{ 1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600 };

    std::vector<std::list<int>> permute(std::vector<std::list<int>>& pre, int next)
    {
        std::vector<std::list<int>> result;
        int count = 0;
        for (std::list<int> list : pre)
        {
            for (auto iter = list.begin(); iter != list.end(); ++iter)
            {
                auto tmp = list.insert(iter, next);
                result.push_back(list);
                list.erase(tmp);
            }
            list.insert(list.end(), next);
            result.push_back(list);
        }
        return result;
    }
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result(size[nums.size()]);
        int count = 0;
        if (!nums.empty())
        {
            std::vector<std::list<int>> dummy;
            std::list<int> tmp;
            tmp.push_back(nums[0]);
            dummy.push_back(tmp);
            for (int i = 1; i < nums.size(); ++i)
            {
                dummy = permute(dummy, nums[i]);
            }
            for (std::list<int> list : dummy)
            {
                result[count++] = *new std::vector<int>(list.begin(), list.end());
            }
        }
        return result;
    }
};