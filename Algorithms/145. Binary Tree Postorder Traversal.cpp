static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> ret;
        if (root)
        {
            std::vector<int> left = postorderTraversal(root->left);
            ret.insert(ret.end(), left.begin(), left.end());
            std::vector<int> right = postorderTraversal(root->right);
            ret.insert(ret.end(), right.begin(), right.end());
            ret.emplace_back(root->val);
        }
        return ret;
    }
};