static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode * deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *current{ head }, *next{ head->next };
        while (next)
        {
            if (current->val == next->val)
            {
                current->next = next->next;
                delete next;
                next = current->next;
            }
            else
            {
                current = next;
                next = next->next;
            }
        }
        return head;
    }
};