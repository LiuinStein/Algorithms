static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ret;
        if (root)
        {
            std::vector<int> left = inorderTraversal(root->left);
            ret.insert(ret.end(), left.begin(), left.end());
            ret.emplace_back(root->val);
            std::vector<int> right = inorderTraversal(root->right);
            ret.insert(ret.end(), right.begin(), right.end());
        }
        return ret;
    }
};