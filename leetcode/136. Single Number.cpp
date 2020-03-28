static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};