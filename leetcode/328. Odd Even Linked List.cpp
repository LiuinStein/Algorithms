static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode * oddEvenList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *dummyHead{ head }, *even{ new ListNode(0) }, *dummyEven{ even };
        ListNode *dummyHeadPrev{};
        while (dummyHead && dummyHead->next)
        {
            dummyEven->next = dummyHead->next;
            dummyEven = dummyEven->next;
            dummyHead->next = dummyHead->next->next;
            dummyHeadPrev = dummyHead;
            dummyHead = dummyHead->next;
        }
        dummyEven->next = nullptr;
        ListNode **tail{ dummyHead ? &dummyHead : &dummyHeadPrev };
        (*tail)->next = even->next;
        return head;
    }
};