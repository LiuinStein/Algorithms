static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{

    void postOrderAndDelete(TreeNode *root, std::vector<int> &result, bool del = true)
    {
        if (root)
        {
            result.push_back(root->val);
            postOrderAndDelete(root->left, result);
            postOrderAndDelete(root->right, result);
            if (del)
            {
                delete root;
            }
        }
    }

public:
    void flatten(TreeNode *root)
    {
        if (root)
        {
            std::vector<int> p;
            postOrderAndDelete(root, p, false);
            root->val = p[0];
            TreeNode *t = root;
            for (int i = 1; i < p.size(); i++)
            {
                t->left = nullptr;
                t->right = new TreeNode(p[i]);
                t = t->right;
            }
        }
    }
};