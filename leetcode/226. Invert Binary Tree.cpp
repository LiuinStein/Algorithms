static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root)
        {
            auto tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            root->left = invertTree(root->left);
            root->right = invertTree(root->right);
        }
        return root;
    }
};