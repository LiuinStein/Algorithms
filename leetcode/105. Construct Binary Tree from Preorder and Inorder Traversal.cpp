static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {

    std::unordered_map<int, int> iMap;

    TreeNode * buildTree(std::vector<int>& preorder, int ps, std::vector<int>& inorder, int is, int ie)
    {
        if (ps >= preorder.size() || is >= ie)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[ps]);
        int i = iMap[preorder[ps]];
        root->left = buildTree(preorder, ps + 1, inorder, is, i);
        root->right = buildTree(preorder, ps + i - is + 1, inorder, i + 1, ie);
        return root;
    }
public:
    TreeNode * buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i)
        {
            iMap[inorder[i]] = i;
        }
        return buildTree(preorder, 0, inorder, 0, inorder.size());
    }
};