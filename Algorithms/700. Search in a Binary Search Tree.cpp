static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    TreeNode * searchBST(TreeNode* root, int val) {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val > val)
        {
            return searchBST(root->left, val);
        }
        else if (root->val < val)
        {
            return searchBST(root->right, val);
        }
        return root;
    }
};
