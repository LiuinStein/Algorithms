static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class NumArray {
	std::vector<int> sums{ 0 };
public:
	NumArray(std::vector<int>& n) {
		int sum = 0;
		for (int i = 0; i < n.size(); i++) {
			sums.push_back(sum += n[i]);
		}
	}

	int sumRange(int left, int right) {
		return sums[right + 1] - sums[left];
	}
};