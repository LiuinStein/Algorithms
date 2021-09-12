static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
		std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& v1, std::vector<int>& v2) {
			return v1[1] < v2[1];
		});
		int ans = 1, left = 0;
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] >= intervals[left][1]) {
				ans++, left = i;
			}
		}
		return intervals.size() - ans;
	}
};