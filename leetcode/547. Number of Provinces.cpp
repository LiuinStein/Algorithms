static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
	std::unordered_map<int, bool> visited;
	int count = 0;

	void help(std::vector<std::vector<int>>& grid, int from, bool add) {
		if (visited[from]) {
			return;
		}
		if (add) {
			count += 1;
		}
		for (int i = 0; i < grid[from].size(); i++) {
			if (i != from && grid[from][i] == 1) {
				visited[from] = true;
				help(grid, i, false);
			}
		}
	}

public:
	int findCircleNum(std::vector<std::vector<int>>& grid) {
		for (int i = 0; i < grid.size(); i++) {
			help(grid, i, true);
		}
		return count;
	}
};