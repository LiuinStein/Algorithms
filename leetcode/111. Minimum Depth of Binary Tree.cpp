static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        if (!root->left && !root->right)
        {
            return 1;
        }
        if (root->left && root->right)
        {
            return std::min(minDepth(root->left), minDepth(root->right)) + 1;
        }
        TreeNode *dummy = root->left ? root->left : root->right;
        return minDepth(dummy) + 1;
    }
};