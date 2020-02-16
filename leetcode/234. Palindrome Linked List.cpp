static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    ListNode *curr;
    bool result = true;

    bool check(ListNode *head)
    {
        if (head)
        {
            result = result && check(head->next) && curr->val == head->val;
            curr = curr->next;
            return result;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        return check(curr = head);
    }
};