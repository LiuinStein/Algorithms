static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += 'a' - 'A';
            }
        }
        return str;
    }
};