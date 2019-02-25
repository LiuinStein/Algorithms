/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int __init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *node = &dummy;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                node->next = l1;
                l1 = l1->next;
            }
            else
            {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        node->next = l1 ? l1 : l2;
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        return merge(sortList(head),sortList(fast));
    }
};