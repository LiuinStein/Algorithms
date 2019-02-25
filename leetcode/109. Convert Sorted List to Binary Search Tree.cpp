static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
    TreeNode * sortedListToBST(ListNode *begin, ListNode *end)
    {
        if (!begin || begin == end)
        {
            return nullptr;
        }
        if (!begin->next || begin->next == end)
        {
            return new TreeNode(begin->val);
        }
        ListNode *slow = begin->next;
        ListNode *fast = begin->next->next;
        while (fast && fast != end && fast->next && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(begin, slow);
        root->right = sortedListToBST(slow->next, end);
        return root;
    }
public:
    TreeNode * sortedListToBST(ListNode* head) {
        return sortedListToBST(head, nullptr);
    }
};