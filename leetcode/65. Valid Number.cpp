static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {

	bool isInteger(std::string &s, int from, int end) {
		from = s[from] == '+' || s[from] == '-' ? from + 1 : from;
		for (int i = from; i < end; i++) {
			if (!std::isdigit(s[i])) {
				return false;
			}
		}
		return from != end;
	}

public:
	bool isNumber(std::string s) {
		if (s.size() == 1) {
			return std::isdigit(s[0]);
		}
		int from = s[0] == '+' || s[0] == '-' ? 1 : 0;
		bool havePoint = false, prefixNumber = false;
		for (int i = from; i < s.size(); i++) {
			if (s[i] == 'e' || s[i] == 'E') {
				return prefixNumber && i != s.size() - 1 && isInteger(s, i + 1, s.size());
			}
			if (s[i] == '.') {
				if (havePoint) {
					return false;
				}
				havePoint = true;
				continue;
			}
			if (!std::isdigit(s[i])) {
				return false;
			}
			prefixNumber = true;
		}
		return prefixNumber;
	}
};