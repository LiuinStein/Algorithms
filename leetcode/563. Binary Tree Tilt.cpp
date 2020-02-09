static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    std::unordered_map<TreeNode *, int> sum;
    int getSum(TreeNode *root)
    {
        return root ? (sum.find(root) == sum.end() ? sum[root] = root->val + getSum(root->left) + getSum(root->right) : sum[root]) : 0;
    }

public:
    int findTilt(TreeNode *root)
    {
        return root ? std::abs(getSum(root->left) - getSum(root->right)) + findTilt(root->left) + findTilt(root->right) : 0;
    }
};