static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        return root ? (root->left && !root->left->left && !root->left->right ? root->left->val : 0) + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) : 0;
    }
};