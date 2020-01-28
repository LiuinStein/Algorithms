static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        return root ? countNodes(root->left) + countNodes(root->right) + 1 : 0;
    }
};