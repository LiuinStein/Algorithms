static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {

    void levelOrder(std::vector<std::vector<int>> &res, std::vector<TreeNode*> current)
    {
        std::vector<int> nums;
        std::vector<TreeNode*> next;
        for (TreeNode* node : current)
        {
            if (node)
            {
                nums.emplace_back(node->val);
                next.emplace_back(node->left);
                next.emplace_back(node->right);
            }
        }
        if (nums.size())
        {
            res.emplace_back(nums);
        }
        if (next.size())
        {
            levelOrder(res, next);
        }
    }
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<TreeNode*> current;
        current.emplace_back(root);
        std::vector<std::vector<int>> res;
        levelOrder(res, current);
        return res;
    }
};