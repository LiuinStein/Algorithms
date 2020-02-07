static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    int getMinimumDifference(TreeNode *root, int min)
    {
        if (root)
        {
            TreeNode *l = root->left, *r = root->right;
            while (l && l->right)
            {
                l = l->right;
            }
            while (r && r->left)
            {
                r = r->left;
            }
            int lmin = l ? std::abs(root->val - l->val) : INT_MAX,
                rmin = r ? std::abs(root->val - r->val) : INT_MAX;
            min = std::min(min, std::min(lmin, rmin));
            lmin = getMinimumDifference(root->left, min);
            rmin = getMinimumDifference(root->right, min);
            return std::min(min, std::min(lmin, rmin));
        }
        return INT_MAX;
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        return getMinimumDifference(root, INT_MAX);
    }
};