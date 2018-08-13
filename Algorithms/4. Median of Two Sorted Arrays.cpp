static int __init = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int i = 0, j = 0;
		int size1 = nums1.size();
		int size2 = nums2.size();
		std::vector<int> combined(size1 + size2 + 1);
		while (i < size1 && j < size2) {
			combined.emplace_back(nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
		}
		combined.insert(combined.end(), nums1.begin() + i, nums1.end());
		combined.insert(combined.end(), nums2.begin() + j, nums2.end());
		double median;
		if ((combined.size() & 1) == 0) {
			int index = (combined.size() >> 1) - 1;
			median = double(combined.at(index) + combined.at(index + 1)) / 2;
		}
		else {
			int index = combined.size() >> 1;
			median = double(combined.at(index));
		}
		return median;
    }
};