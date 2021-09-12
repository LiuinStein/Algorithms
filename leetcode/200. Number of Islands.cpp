static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
	std::unordered_map<int, std::unordered_map<int, bool>> visited;
	int count = 0;

	void help(std::vector<std::vector<char>>& grid, int sr, int sc, bool add) {
		if (sr < 0 || sr >= grid.size() || sc < 0 || sc >= grid[0].size() ||
			grid[sr][sc] == '0' || visited[sr][sc]) {
			return;
		}
		visited[sr][sc] = true;
		if (add) {
			count += 1;
		}
		help(grid, sr - 1, sc, false);
		help(grid, sr + 1, sc, false);
		help(grid, sr, sc - 1, false);
		help(grid, sr, sc + 1, false);
	}
public:
	int numIslands(std::vector<std::vector<char>>& grid) {
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				help(grid, i, j, true);
			}
		}
		return count;
	}
};