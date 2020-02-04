static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    void getNums(TreeNode *root, std::unordered_map<int, int> &nums)
    {
        if (root)
        {
            getNums(root->left, nums);
            nums[root->val]++;
            getNums(root->right, nums);
        }
    }

public:
    std::vector<int> findMode(TreeNode *root)
    {
        std::vector<int> result;
        std::unordered_map<int, int> nums;
        getNums(root, nums);
        int freq = 0;
        for (auto s : nums)
        {
            if (s.second > freq)
            {
                freq = s.second;
                result.clear();
                result.push_back(s.first);
            }
            else if (s.second == freq)
            {
                result.push_back(s.first);
            }
        }
        return result;
    }
};