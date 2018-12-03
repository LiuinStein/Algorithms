static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {

    int depth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return std::max(depth(root->left) + 1, depth(root->right) + 1);
    }
public:
    bool isBalanced(TreeNode* root) {
        return !root || 
            std::abs(depth(root->left) - depth(root->right)) < 2 &&
            isBalanced(root->left) && isBalanced(root->right);
    }
};