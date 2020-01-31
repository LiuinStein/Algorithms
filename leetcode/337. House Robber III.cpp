static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    std::unordered_map<TreeNode *, int> bor;

public:
    int rob(TreeNode *root)
    {
        if (root)
        {
            int t = (bor.find(root->left) == bor.end() ? bor[root->left] = rob(root->left) : bor[root->left]) +
                    (bor.find(root->right) == bor.end() ? bor[root->right] = rob(root->right) : bor[root->right]);
            int l = root->left ? (bor.find(root->left->left) == bor.end() ? bor[root->left->left] = rob(root->left->left) : bor[root->left->left]) +
                                     (bor.find(root->left->right) == bor.end() ? bor[root->left->right] = rob(root->left->right) : bor[root->left->right])
                               : 0;
            int r = root->right ? (bor.find(root->right->left) == bor.end() ? bor[root->right->left] = rob(root->right->left) : bor[root->right->left]) +
                                      (bor.find(root->right->right) == bor.end() ? bor[root->right->right] = rob(root->right->right) : bor[root->right->right])
                                : 0;
            return std::max(t, l + r + root->val);
        }
        return 0;
    }
};