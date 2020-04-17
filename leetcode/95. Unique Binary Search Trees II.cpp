static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    std::vector<TreeNode *> generateTrees(int s, int e)
    {
        std::vector<TreeNode *> result;
        if (s > e)
        {
            result.push_back(nullptr);
            return result;
        }
        if (s == e)
        {
            result.push_back(new TreeNode(s));
            return result;
        }
        for (int i = s; i <= e; i++)
        {
            std::vector<TreeNode *> lefts = generateTrees(s, i - 1);
            std::vector<TreeNode *> rights = generateTrees(i + 1, e);
            for (int j = 0; j < lefts.size(); j++)
            {
                for (int k = 0; k < rights.size(); k++)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = lefts[j];
                    node->right = rights[k];
                    result.push_back(node);
                }
            }
        }
        return result;
    }

public:
    std::vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
        {
            std::vector<TreeNode *> result;
            return result;
        }
        return generateTrees(1, n);
    }
};