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
    void deleteNode(ListNode* node) {
        if(node != NULL && node->next != NULL) {
            node->val=node->next->val;
            free(node->next);
            node->next=node->next->next;
        }
    }
};

// This solution and problem is meaningless, this code is from discuss linked below
// https://leetcode.com/problems/delete-node-in-a-linked-list/discuss/159976/0ms-C-3-line-code