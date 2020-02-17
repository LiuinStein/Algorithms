static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            char dummy = s[i];
            s[i] = s[j];
            s[j] = dummy;
        }
    }
};