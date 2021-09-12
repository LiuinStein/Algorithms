static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
	std::unordered_map<int, std::unordered_map<int, int>> visited;
	std::vector<int> sizes;

	void help(std::vector<std::vector<int>>& grid, int sr, int sc, bool connected) {
		if (sr < 0 || sr >= grid.size() || sc < 0 || sc >= grid[0].size() ||
			grid[sr][sc] == 0 || visited[sr][sc]) {
			return;
		}
		visited[sr][sc] = true;
		if (!connected) {
			sizes.push_back(0);
		}
		sizes[sizes.size() - 1]++;
		help(grid, sr - 1, sc, true);
		help(grid, sr + 1, sc, true);
		help(grid, sr, sc - 1, true);
		help(grid, sr, sc + 1, true);
	}

public:
	int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				help(grid, i, j, false);
			}
		}
		int max = 0;
		for (int i = 0; i < sizes.size(); i++) {
			if (sizes[i] > max) {
				max = sizes[i];
			}
		}
		return max;
	}
};
