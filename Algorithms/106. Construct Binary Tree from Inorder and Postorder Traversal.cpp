static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {

    std::unordered_map<int, int> iMap;

    TreeNode * buildTree(std::vector<int>& inorder, int is, int ie, std::vector<int>& postorder, int ps, int pe)
    {
        if (is >= ie || ps >= pe)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[pe - 1]);
        int lsize = iMap[postorder[pe - 1]] - is;
        root->left = buildTree(inorder, is, is + lsize, postorder, ps, ps + lsize);
        root->right = buildTree(inorder, iMap[postorder[pe - 1]] + 1, ie, postorder, ps + lsize, pe - 1);
        return root;
    }
public:
    TreeNode * buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i)
        {
            iMap[inorder[i]] = i;
        }
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};