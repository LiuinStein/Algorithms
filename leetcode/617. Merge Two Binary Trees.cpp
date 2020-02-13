static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (t1 || t2)
        {
            if (t1)
            {
                t1->val += t2 ? t2->val : 0;
            }
            else
            {
                t1 = new TreeNode(t2->val);
            }
            if (t2)
            {
                t1->left = mergeTrees(t1->left, t2->left);
                t1->right = mergeTrees(t1->right, t2->right);
            }
        }
        return t1;
    }
};