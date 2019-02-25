static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode * reverseBetween(ListNode* head, int m, int n) {
        ListNode *prev{}, *current{}, *next{}, *dummy{ head }, *left{};
        for (int i = 1; i <= n; ++i)
        {
            if (i > m)
            {
                current->next = prev;
                prev = current;
                current = next;
                next = current->next;
            }
            else if (i == m)
            {
                current = dummy;
                next = current->next;
            }
            else
            {
                left = dummy;
                dummy = dummy->next;
            }
        }
        current->next = prev;
        dummy->next = next;
        if (left)
        {
            left->next = current;
        }
        if (m == 1)
        {
            return current;
        }
        return head;
    }
};