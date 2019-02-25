static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {

    bool isValidBST(TreeNode* root, long min, long max)
    {
        if (!root)
        {
            return true;
        }
        if (root->val <= min || root->val >= max)
        {
            return false;
        }
        return isValidBST(root->left, min, root->val) &&
            isValidBST(root->right, root->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};