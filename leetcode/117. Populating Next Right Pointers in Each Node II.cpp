static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root)
        {
            std::vector<Node *> next;
            next.push_back(root);
            while (!next.empty())
            {
                std::vector<Node *> tmp;
                tmp.reserve(2 * next.size());
                for (int i = 0; i + 1 < next.size(); i++)
                {
                    next[i]->next = next[i + 1];
                    if (next[i]->left)
                    {
                        tmp.push_back(next[i]->left);
                    }
                    if (next[i]->right)
                    {
                        tmp.push_back(next[i]->right);
                    }
                }
                if (next[next.size() - 1])
                {
                    next[next.size() - 1]->next = nullptr;
                    if (next[next.size() - 1]->left)
                    {
                        tmp.push_back(next[next.size() - 1]->left);
                    }
                    if (next[next.size() - 1]->right)
                    {
                        tmp.push_back(next[next.size() - 1]->right);
                    }
                }
                next.clear();
                next.insert(next.end(), tmp.begin(), tmp.end());
            }
        }
        return root;
    }
};