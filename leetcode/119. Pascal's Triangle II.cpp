static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	std::vector<int> getRow(int rowIndex) {
		std::vector<std::vector<int>> result;
		result.push_back(std::vector<int>(1, 1));
		for (int i = 2; i <= rowIndex + 1; i++) {
			std::vector<int> dummy(i, 1);
			for (int j = 1; j < i - 1; j++) {
				dummy[j] = result[result.size() - 1][j - 1] + result[result.size() - 1][j];
			}
			result.push_back(dummy);
		}
		return result[rowIndex];
	}
};