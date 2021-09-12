static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int minimumDeleteSum(std::string s1, std::string s2) {
		std::vector<std::vector<int>> dp(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));
		for (int i = 1; i <= s1.size(); i++) {
			dp[i][0] = dp[i - 1][0] + s1[i - 1];
		}
		for (int i = 1; i <= s2.size(); i++) {
			dp[0][i] = dp[0][i - 1] + s2[i - 1];
		}
		for (int i = 1; i <= s1.size(); i++) {
			for (int j = 1; j <= s2.size(); j++) {
				dp[i][j] = std::min(dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : s1[i - 1] + s2[j - 1]),
					std::min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]));
			}
		}
		return dp[s1.size()][s2.size()];
	}
};