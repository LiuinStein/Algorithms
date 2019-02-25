/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*  ret = new ListNode(0);
        ListNode* ptr = ret;
        int flag = 0;
        for (ListNode * p1 = l1, *p2 = l2; p1 || p2 || flag;)
        {
            int t1 = p1 == NULL ? 0 : p1->val;
            int t2 = p2 == NULL ? 0 : p2->val;
            int sum = t1 + t2 + flag;
            ptr->val = sum % 10;
            flag = sum / 10;
            p1 = p1 == NULL ? NULL : p1->next;
            p2 = p2 == NULL ? NULL : p2->next;
            ptr = p1 == NULL && p2 == NULL && flag == 0 ? NULL : ptr->next = new ListNode(0);
        }
        return ret;
    }
};