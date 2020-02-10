static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    bool result = false;
    bool isSame(TreeNode *s, TreeNode *t)
    {
        return (s == t) || (s && t && s->val == t->val && isSame(s->left, t->left) && isSame(s->right, t->right));
    }

public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        return result || (result = isSame(s, t) || (s && (isSame(s->left, t) || isSame(s->right, t) || isSubtree(s->left, t) || isSubtree(s->right, t))));
    }
};