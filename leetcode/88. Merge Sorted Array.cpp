static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		std::vector<int> result;
		int i{}, j{};
		nums1.erase(nums1.begin() + m, nums1.end());
		while (i < m && j < n)
		{
			result.push_back(nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
		}
		result.insert(result.end(), nums1.begin() + i, nums1.begin() + m);
		result.insert(result.end(), nums2.begin() + j, nums2.begin() + n);
		nums1 = result;
    }
};