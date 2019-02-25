static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> ret;
        if (root)
        {
            ret.emplace_back(root->val);
            std::vector<int> left = preorderTraversal(root->left);
            ret.insert(ret.end(), left.begin(), left.end());
            std::vector<int> right = preorderTraversal(root->right);
            ret.insert(ret.end(), right.begin(), right.end());
        }
        return ret;
    }
};