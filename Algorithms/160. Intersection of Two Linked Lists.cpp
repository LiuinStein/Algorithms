static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {

    ListNode *getIntersection(ListNode *headA, int lenA, ListNode *headB, int lenB)
    {
        if (lenB < lenA)
        {
            return getIntersection(headB, lenB, headA, lenA);
        }
        while (lenB-- != lenA)
        {
            headB = headB->next;
        }
        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
public:
    ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA{}, lenB{};
        ListNode *dummy{ headA };
        while(dummy)
        {
            dummy = dummy->next;
            ++lenA;
        }
        dummy = headB;
        while (dummy)
        {
            dummy = dummy->next;
            ++lenB;
        }
        if (!lenA || !lenB)
        {
            return nullptr;
        }
        return getIntersection(headA, lenA, headB, lenB);
    }
};