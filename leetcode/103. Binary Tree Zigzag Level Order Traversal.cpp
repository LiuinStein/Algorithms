static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    std::vector<std::vector<int>> zigzagLevelOrder(std::vector<TreeNode *> &nodes)
    {
        std::vector<std::vector<int>> result;
        std::vector<TreeNode *> next;
        std::vector<int> current;
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i])
            {
                current.push_back(nodes[i]->val);
                next.push_back(nodes[i]->left);
                next.push_back(nodes[i]->right);
            }
        }
        if (!current.empty())
        {
            result.push_back(current);
        }
        if (!nodes.empty())
        {
            std::vector<std::vector<int>> nr = zigzagLevelOrder(next);
            result.insert(result.end(), nr.begin(), nr.end());
        }
        return result;
    }

public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        std::vector<TreeNode *> nodes;
        nodes.push_back(root);
        std::vector<std::vector<int>> result = zigzagLevelOrder(nodes);
        for (int i = 0; i < result.size(); i++)
        {
            if (i & 1)
            {
                std::reverse(result[i].begin(), result[i].end());
            }
        }
        return result;
    }
};