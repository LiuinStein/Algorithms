static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        std::vector<TreeNode *> next;
        next.push_back(root);
        while (!next.empty())
        {
            std::vector<TreeNode *> tmp;
            tmp.reserve(next.size() << 1);
            for (int i = 0; i < next.size(); i++)
            {
                if (next[i]->left)
                {
                    tmp.push_back(next[i]->left);
                }
                if (next[i]->right)
                {
                    tmp.push_back(next[i]->right);
                }
            }
            if (tmp.empty())
            {
                return next[0]->val;
            }
            next = tmp;
        }
        return -1;
    }
};