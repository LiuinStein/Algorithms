static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    std::unordered_map<long long, int> sums;

    long long minimumTotal(std::vector<std::vector<int>> &triangle, std::pair<int, int> from)
    {
        if (from.first >= triangle.size() || from.second >= triangle[from.first].size())
        {
            return 0;
        }
        long long hash = (((long long)from.first) << 32) | from.second;
        if (sums.find(hash) != sums.end())
        {
            return sums[hash];
        }
        long long sum = triangle[from.first][from.second];
        sum += std::min(minimumTotal(triangle, {from.first + 1, from.second}),
                        minimumTotal(triangle, {from.first + 1, from.second + 1}));
        return sums[hash] = sum;
    }

public:
    int minimumTotal(std::vector<std::vector<int>> &triangle)
    {
        return minimumTotal(triangle, {0, 0});
    }
};