static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    std::vector<int> rightSideView(TreeNode *root)
    {
        std::vector<int> result;
        std::vector<TreeNode *> next;
        next.push_back(root);
        while (!next.empty())
        {
            std::vector<TreeNode *> tmp;
            tmp.reserve(next.size() << 1);
            int p = 0;
            bool flag = false;
            for (int i = 0; i < next.size(); i++)
            {
                if (next[i])
                {
                    flag = true;
                    p = next[i]->val;
                    tmp.push_back(next[i]->left);
                    tmp.push_back(next[i]->right);
                }
            }
            if (flag)
            {
                result.push_back(p);
            }
            next.clear();
            next.insert(next.end(), tmp.begin(), tmp.end());
        }
        return result;
    }
};