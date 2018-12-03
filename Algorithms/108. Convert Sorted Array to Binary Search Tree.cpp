static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {

    TreeNode * sortedArrayToBST(std::vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, left, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, right);
        return root;
    }
public:
    TreeNode * sortedArrayToBST(std::vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};