static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    std::vector<std::vector<int>> pathSum(TreeNode *root, int sum)
    {
        std::vector<std::vector<int>> result;
        if (root)
        {
            if (sum == root->val && !root->left && !root->right)
            {
                result.push_back(std::vector<int>(1, root->val));
                return result;
            }
            std::vector<std::vector<int>> l = pathSum(root->left, sum - root->val);
            std::vector<std::vector<int>> r = pathSum(root->right, sum - root->val);
            l.insert(l.end(), r.begin(), r.end());
            result.reserve(l.size() + 1);
            for (int i = 0; i < l.size(); i++)
            {
                std::vector<int> tmp;
                tmp.reserve(l[i].size() + 1);
                tmp.push_back(root->val);
                tmp.insert(tmp.end(), l[i].begin(), l[i].end());
                result.push_back(tmp);
            }
        }
        return result;
    }
};