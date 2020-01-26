static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    void sumNumbers(TreeNode *root, int sum, int &res)
    {
        if (root)
        {
            sum = sum * 10 + root->val;
            if (!root->left && !root->right)
            {
                res += sum;
            }
            else
            {
                sumNumbers(root->left, sum, res);
                sumNumbers(root->right, sum, res);
            }
        }
    }

public:
    int sumNumbers(TreeNode *root)
    {
        int res = 0;
        sumNumbers(root, 0, res);
        return res;
    }
};