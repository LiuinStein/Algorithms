static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class BSTIterator
{
    std::vector<int> nums;
    int pos = 0;

    void init(TreeNode *root)
    {
        if (root)
        {
            nums.push_back(root->val);
            init(root->left);
            init(root->right);
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        init(root);
        std::sort(nums.begin(), nums.end());
        pos = 0;
    }
    
    /** @return the next smallest number */
    int next() {
        return nums[pos++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return pos < nums.size();
    }
};