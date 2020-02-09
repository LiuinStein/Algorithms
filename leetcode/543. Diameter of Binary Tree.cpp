static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    int result = 0;
    int getDepth(TreeNode *root)
    {
        if (root)
        {
            int ld = getDepth(root->left), rd = getDepth(root->right);
            result = std::max(result, ld + rd);
            return std::max(ld, rd) + 1;
        }
        return 0;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        getDepth(root);
        return result;
    }
};