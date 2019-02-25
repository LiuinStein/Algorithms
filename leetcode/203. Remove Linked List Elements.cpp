static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode * removeElements(ListNode* head, int val) {
        if (!head)
        {
            return nullptr;
        }
        ListNode *prev{ head }, *current{ head->next };
        while (current)
        {
            if (current->val == val)
            {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        if (head->val == val)
        {
            ListNode *dummy{ head->next };
            delete head;
            return dummy;
        }
        return head;
    }
};