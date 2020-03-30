static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
	void spiralOrder(std::vector<std::vector<int>>& matrix, std::vector<int>& result,
		std::vector<std::vector<bool>> &visited,
		int x, int y, int left, int down)
	{
		if (left <= 0 || down <= 0)
		{
			return;
		}
		for (int i = y; i < y + left; i++)
		{
			if (!visited[x][i])
			{
				result.push_back(matrix[x][i]);
				visited[x][i] = true;
			}
		}
		for (int i = x + 1; i < x + down; i++)
		{
			if (!visited[i][y + left - 1])
			{
				result.push_back(matrix[i][y + left - 1]);
				visited[i][y + left - 1] = true;
			}
		}
		for (int i = y + left - 2; i > y; i--)
		{
			if (!visited[x + down - 1][i])
			{
				result.push_back(matrix[x + down - 1][i]);
				visited[x + down - 1][i] = true;
			}
		}
		for (int i = x + down - 1; i > x; i--)
		{
			if (!visited[i][y])
			{
				result.push_back(matrix[i][y]);
				visited[i][y] = true;
			}
		}
		spiralOrder(matrix, result, visited, x + 1, y + 1, left - 2, down - 2);
	}
public:
	std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
		std::vector<int> result;
		if (matrix.size())
		{
			std::vector<std::vector<bool>> visited(matrix.size(), std::vector<bool>(matrix[0].size(), false));
			spiralOrder(matrix, result, visited, 0, 0, matrix[0].size(), matrix.size());
		}
		return result;
	}
};
