static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
    bool isSymmetric(TreeNode *l, TreeNode *r)
    {
        if (!l || !r)
        {
            return l == r;
        }
        return l->val == r->val && isSymmetric(l->left, r->right) &&
               isSymmetric(l->right, r->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        return !root || isSymmetric(root->left, root->right);
    }
};