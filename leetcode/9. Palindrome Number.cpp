static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        std::string s = std::to_string(x), p = s;
        std::reverse(p.begin(), p.end());
        return s == p;
    }
};