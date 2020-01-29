static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    bool kthSmallest(TreeNode *root, int &k, int &res)
    {
        if (root)
        {
            if (kthSmallest(root->left, k, res))
            {
                return true;
            }
            k -= 1;
            if (!k)
            {
                res = root->val;
                return true;
            }
            if (kthSmallest(root->right, k, res))
            {
                return true;
            }
        }
        return false;
    }
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int res = 0;
        kthSmallest(root, k, res);
        return res;
    }
};