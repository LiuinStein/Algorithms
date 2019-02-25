static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {

    void swap(ListNode *prev, ListNode *current, ListNode *next)
    {
        current->next = next->next;
        next->next = current;
        prev->next = next;
    }
public:
    ListNode * swapPairs(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *current{ head }, *next{ head->next };
        current->next = next->next;
        next->next = current;
        head = next;
        while (current && current->next && current->next->next)
        {
            swap(current, current->next, current->next->next);
            current = current->next->next;
        }
        return head;
    }
};