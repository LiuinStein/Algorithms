static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {

	int getNumberOfZero(std::string &str) {
		int res = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '0') {
				res++;
			}
		}
		return res;
	}
public:
	int findMaxForm(std::vector<std::string>& strs, int m, int n) {
		std::vector<std::vector<std::vector<int>>> f(strs.size() + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0)));
		for (int i = 1; i <= strs.size(); i++) {
			int mm = getNumberOfZero(strs[i - 1]), nn = strs[i - 1].size() - mm;
			for (int x = 0; x <= m; x++) {
				for (int y = 0; y <= n; y++) {
					f[i][x][y] = f[i - 1][x][y];
					if (x >= mm && y >= nn) {
						f[i][x][y] = std::max(f[i - 1][x - mm][y - nn] + 1, f[i - 1][x][y]);
					}
				}
			}
		}
		return f[strs.size()][m][n];
	}
};