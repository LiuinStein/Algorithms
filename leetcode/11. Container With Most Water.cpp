static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
public:
	int maxArea(std::vector<int>& height) {
		int lo = 0, hi = height.size() - 1, max = 0;
		while(lo < hi) {
			max = std::max(max, (hi - lo)*std::min(height[lo], height[hi]));
			if (height[lo] < height[hi]) {
				lo += 1;
			}
			else {
				hi -= 1;
			}
		}
		return max;
	}
};