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
    ListNode* insertionSortList(ListNode* head) {
		if(head == NULL)
		{
			return NULL;
		}
		ListNode* pLeft = head;
		for (ListNode* p = head->next; p != NULL; pLeft = p, p = p->next)
		{
			ListNode* qLeft = NULL;
            if (p->val >= pLeft->val)
			{
				continue;
			}
			for (ListNode* q = head; q != p; qLeft = q, q = q->next)
			{
				if (p->val < q->val)
				{
					pLeft->next = p->next;
					// insert p into q left 
					if (qLeft != NULL)
					{
						ListNode* tmp = qLeft->next;
						qLeft->next = p;
						p->next = tmp;
					}
					else
					{
						p->next = head;
						head = p;
					}
					break;
				}
			}
		}
		return head;
    }
};