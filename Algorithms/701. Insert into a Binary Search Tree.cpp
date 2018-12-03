static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {

public:
    TreeNode * insertIntoBST(TreeNode* root, int val) {
        std::stack<TreeNode*> stk;
        TreeNode **target{ &root };
        TreeNode *dummy{ root };
        while (dummy)
        {
            if (dummy->val < val)
            {
                stk.push(dummy->right);
                target = &dummy->right;
            }
            else if (dummy->val > val)
            {
                stk.push(dummy->left);
                target = &dummy->left;
            }
            else
            {
                return root;
            }
            dummy = stk.top();
            stk.pop();
        }
        *target = new TreeNode(val);
        return root;
    }
};