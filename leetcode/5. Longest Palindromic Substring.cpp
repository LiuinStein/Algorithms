static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {

	std::vector<std::vector<int>> label;

	bool isPalindrome(std::string &s, int begin, int end) {
		if (label[begin][end] != -1) {
			return label[begin][end];
		}
		if (begin == end) {
			return label[begin][end] = 1;
		}
		if (end == begin + 1) {
			return label[begin][end] = s[begin] == s[end];
		}
		if (label[begin + 1][end - 1] == -1) {
			label[begin + 1][end - 1] = isPalindrome(s, begin + 1, end - 1);
		}
		return label[begin][end] = label[begin + 1][end - 1] == 1 && s[begin] == s[end];
	}

public:
	std::string longestPalindrome(std::string s) {
		label = std::vector<std::vector<int>>(s.size(), std::vector<int>(s.size(), -1));
		int length = -1, from;
		for (int i = 0; i < s.size(); i++) {
			for (int j = s.size() - 1; j >= i && (j - i + 1) > length; j--) {
				if (isPalindrome(s, i, j)) {
					from = i, length = j - i + 1;
				}
			}
		}
		return s.substr(from, length);
	}
};