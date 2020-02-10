static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    std::string tree2str(TreeNode *t)
    {
        return t ? (std::to_string(t->val)
                        .append(t->right ? "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")"
                                         : t->left ? "(" + tree2str(t->left) + ")" : ""))
                 : "";
    }
};