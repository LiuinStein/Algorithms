static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();


class Solution {
public:
	int longestCommonSubsequence(std::string s1, std::string s2) {
		std::vector<std::vector<int>> vec(s2.size() + 1, std::vector<int>(s1.size() + 1, 0));
		for (int i = 1; i <= s2.size(); i++) {
			for (int j = 1; j <= s1.size(); j++) {
				vec[i][j] = std::max(std::max(vec[i - 1][j - 1] + (s1[j - 1] == s2[i - 1] ? 1 : 0), vec[i - 1][j]), vec[i][j - 1]);
			}
		}
		return vec[s2.size()][s1.size()];
	}
};