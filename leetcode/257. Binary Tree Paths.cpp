static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    std::vector<std::vector<int>> getPaths(TreeNode *root)
    {
        std::vector<std::vector<int>> result;
        if (root)
        {
            auto left = getPaths(root->left);
            auto right = getPaths(root->right);
            left.insert(left.end(), right.begin(), right.end());
            if (left.empty()) 
            {
                // leaf node
                result.push_back(std::vector<int>(1, root->val));
            }
            else 
            {
                for (auto s : left)
                {
                    s.push_back(root->val);
                    result.push_back(s);
                }
            }
        }
        return result;
    }

public:
    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        auto paths = getPaths(root);
        std::vector<std::string> result;
        for (auto s : paths)
        {
            std::string str;
            std::reverse(s.begin(), s.end());
            for (int i = 0; i < s.size() - 1; i++)
            {
                str += std::to_string(s[i]);
                str += "->";
            }
            result.push_back(str + std::to_string(s[s.size() - 1]));
        }
        return result;
    }
};