static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    int pathSum(TreeNode *root, int sum, bool consecutive)
    {
        int result = 0;
        if (root)
        {
            if (sum == root->val)
            {
                result += 1;
            }
            result += pathSum(root->left, sum - root->val, true) +
                      pathSum(root->right, sum - root->val, true);
            if (!consecutive)
            {
                result += pathSum(root->left, sum, false) +
                          pathSum(root->right, sum, false);
            }
        }
        return result;
    }

public:
    int pathSum(TreeNode *root, int sum)
    {
        return pathSum(root, sum, false);
    }
};