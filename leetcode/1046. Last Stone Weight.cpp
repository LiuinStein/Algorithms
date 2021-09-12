static int ____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        if (stones.size() > 1) {
            do {
                std::sort(stones.begin(), stones.end());
                int smashed = std::abs(stones[stones.size() - 1] - stones[stones.size() - 2]);
                stones.pop_back();
                stones.pop_back();
                if (smashed) {
                    stones.push_back(smashed);
                }
            } while (stones.size() > 1);
        }
        return stones.size() == 0 ? 0 : stones[0];
    }
};