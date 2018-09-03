static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
    int m, n;

    void reverseTravel(ListNode *head)
    {
        if (head)
        {
            ++m;
            reverseTravel(head->next);
        }
        if (!--n)
        {
            ListNode *dummy{ head->next };
            head->next = dummy->next;
            delete dummy;
        }
    }
public:
    ListNode * removeNthFromEnd(ListNode* head, int n) {
        this->n = n + 2;
        this->m = 0;
        reverseTravel(head);
        if (m == n)
        {
            ListNode *dummy{ head->next };
            delete head;
            return dummy;
        }
        return head;
    }
};