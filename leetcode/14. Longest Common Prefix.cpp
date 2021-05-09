static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        } 
        int n = 0;
        for (int i = 0; i < strs[0].size(); i++, n++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[0][i] != strs[j][i]) {
                    return strs[0].substr(0, n);
                }
            }
        }
        return strs[0].substr(0, n);
    }
};