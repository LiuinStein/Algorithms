static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    std::unordered_map<TreeNode *, int> sum;
    std::unordered_map<int, int> freq;
    int getSum(TreeNode *root)
    {
        if (root)
        {
            int s = sum.find(root) == sum.end() ? sum[root] = root->val + getSum(root->left) + getSum(root->right) : sum[root];
            freq[s]++;
            return s;
        }
        return 0;
    }

public:
    std::vector<int> findFrequentTreeSum(TreeNode *root)
    {
        getSum(root);
        std::vector<int> result;
        int max = INT_MIN;
        for (auto s : freq)
        {
            if (s.second > max)
            {
                result.clear();
                max = s.second;
                result.push_back(s.first);
            }
            else if (s.second == max)
            {
                result.push_back(s.first);
            }
        }
        return result;
    }
};