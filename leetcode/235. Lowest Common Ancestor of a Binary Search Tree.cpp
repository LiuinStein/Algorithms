static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root)
        {
            int max = std::max(p->val, q->val), min = std::min(p->val, q->val);
            if (root->val <= max && root->val >= min)
            {
                return root;
            }
            if (root->val > max)
            {
                return lowestCommonAncestor(root->left, p, q);
            }
            if (root->val < min)
            {
                return lowestCommonAncestor(root->right, p, q);
            }
        }
        return nullptr;
    }
};