static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};