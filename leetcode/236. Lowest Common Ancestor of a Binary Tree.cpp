static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{

    bool findPath(TreeNode *root, TreeNode *find, std::vector<TreeNode *> &path)
    {
        if (root)
        {
            path.push_back(root);
            int i = path.size();
            if (root == find || findPath(root->left, find, path))
            {
                return true;
            }
            while (path.size() != i)
            {
                path.pop_back();
            }
            if (findPath(root->right, find, path))
            {
                return true;
            }
        }
        return false;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root)
        {
            std::vector<TreeNode *> pp;
            findPath(root, p, pp);
            for (int i = pp.size() - 1; i >= 0; i--)
            {
                std::vector<TreeNode *> dummy;
                if (pp[i] == q || findPath(pp[i]->left, q, dummy) || findPath(pp[i]->right, q, dummy))
                {
                    return pp[i];
                }
            }
        }
        return nullptr;
    }
};