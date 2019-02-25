/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode * reverseList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *prev{ nullptr }, *current{ head }, *next{ current->next };
        while (next)
        {
            current->next = prev;
            prev = current;
            current = next;
            next = current->next;
        }
        current->next = prev;
        return current;
    }
};