static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {

public:
    TreeNode * deleteNode(TreeNode* root, int key) {
        if (!root)
        {
            return nullptr;
        }
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left && root->right)
            {
                TreeNode *next = root->right;
                while (next->left)
                {
                    next = next->left;
                }
                std::swap(root->val, next->val);
                root->right = deleteNode(root->right, key);
            }
            else if (root->left || root->right)
            {
                TreeNode *ret = root->left ? root->left : root->right;
                delete root;
                return ret;
            }
            else
            {
                delete root;
                return nullptr;
            }
        }
        return root;
    }
};