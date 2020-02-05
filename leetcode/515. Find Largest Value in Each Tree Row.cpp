static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    std::vector<int> largestValues(TreeNode *root)
    {
        std::vector<int> result;
        if (root)
        {
            std::queue<TreeNode *> next;
            next.push(root);
            while (!next.empty())
            {
                int s = next.size();
                int largest = INT_MIN;
                while (s--)
                {
                    if (next.front()->val > largest)
                    {
                        largest = next.front()->val;
                    }
                    if (next.front()->left)
                    {
                        next.push(next.front()->left);
                    }
                    if (next.front()->right)
                    {
                        next.push(next.front()->right);
                    }
                    next.pop();
                }
                result.push_back(largest);
            }
        }
        return result;
    }
};