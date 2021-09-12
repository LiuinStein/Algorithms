static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {

	bool isPalindromic(std::string& s, int begin, int end) {
		for (int i = begin, j = end - 1; i < j; i++, j--) {
			if (s[i] != s[j]) {
				return false;
			}
		}
		return true;
	}
public:
	int countSubstrings(std::string s) {
		int result = s.size();
		for (int i = 2; i <= s.size(); i++) {
			for (int j = 0; j < s.size() - i + 1; j++) {
				if (isPalindromic(s, j, j + i)) {
					result += 1;
				}
			}
		}
		return result;
	}
};