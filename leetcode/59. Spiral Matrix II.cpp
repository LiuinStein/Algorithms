static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
	void generateMatrix(std::vector<std::vector<int>> &result, int start, int x, int y, int move)
	{
		if (move <= 0)
		{
			return;
		}
		for (int i = y; i < y + move; i++)
		{
			if (result[x][i] == -1)
			{
				result[x][i] = start++;
			}
		}
		for (int i = x + 1; i < x + move; i++)
		{
			if (result[i][y + move - 1] == -1)
			{
				result[i][y + move - 1] = start++;
			}
		}
		for (int i = y + move - 2; i > y; i--)
		{
			if (result[x + move - 1][i] == -1)
			{
				result[x + move - 1][i] = start++;
			}
		}
		for (int i = x + move - 1; i > x; i--)
		{
			if (result[i][y] == -1)
			{
				result[i][y] = start++;
			}
		}
		generateMatrix(result, start, x + 1, y + 1, move - 2);
	}
public:
	std::vector<std::vector<int>> generateMatrix(int n) {
		std::vector<std::vector<int>> result(n, std::vector<int>(n, -1));
		generateMatrix(result, 1, 0, 0, n);
		return result;
	}
};