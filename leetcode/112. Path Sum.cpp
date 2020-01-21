static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
        {
            return false;
        }
        if (sum == root->val && !root->left && !root->right)
        {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};