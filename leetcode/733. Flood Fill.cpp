static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {

	std::unordered_map<int, std::unordered_map<int, bool>> visited;

	void help(std::vector<std::vector<int>>& image, std::vector<std::vector<int>>& result, int sr, int sc, int newColor) {
		if (sr < 0 || sr >= result.size() || sc < 0 || sc >= result[sr].size() || visited[sr][sc]) {
			return;
		}
		result[sr][sc] = newColor;
		visited[sr][sc] = true;
		if (sr - 1 >= 0 && result[sr - 1][sc] == image[sr][sc]) {
			result[sr - 1][sc] = newColor;
			help(image, result, sr - 1, sc, newColor);
		}
		if (sr + 1 < result.size() && result[sr + 1][sc] == image[sr][sc]) {
			result[sr + 1][sc] = newColor;
			help(image, result, sr + 1, sc, newColor);
		}
		if (sc - 1 >= 0 && result[sr][sc - 1] == image[sr][sc]) {
			result[sr][sc - 1] = newColor;
			help(image, result, sr, sc - 1, newColor);
		}
		if (sc + 1 < result[sr].size() && result[sr][sc + 1] == image[sr][sc]) {
			result[sr][sc + 1] = newColor;
			help(image, result, sr, sc + 1, newColor);
		}
	}
public:
	std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
		std::vector<std::vector<int>> result(image);
		help(image, result, sr, sc, newColor);
		return result;
	}
};