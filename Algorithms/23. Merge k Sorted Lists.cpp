static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
	ListNode * merge(ListNode *lhs, ListNode *rhs)
	{
		ListNode *head = new ListNode(0);
		ListNode *cur = head;
		while (lhs != nullptr || rhs != nullptr)
		{
			if (lhs != nullptr && rhs != nullptr)
			{
				ListNode ** smallest = lhs->val < rhs->val ? &lhs : &rhs;
				cur->next = *smallest;
				*smallest = (*smallest)->next;
				cur = cur->next;
			}
			else
			{
				cur->next = lhs != nullptr ? lhs : rhs;
				break;
			}
		}
		return head->next;
	}
public:
	ListNode * mergeKLists(std::vector<ListNode*>& lists)
	{
		int sz = lists.size();
		while (sz > 1) {
			int j = sz - 1;
			for (int i = 0; i < sz >> 1; i++) 
             {
				lists[i] = merge(lists[i], lists[j]);
				j--;
			}
             sz = (sz & 1) == 1 ? (sz >> 1) + 1 : sz >> 1;
		}
		return sz > 0 ? lists[0] : NULL;
	}
};