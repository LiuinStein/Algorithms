static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        std::vector<std::vector<unsigned long long>> paths(grid.size() + 1, std::vector<unsigned long long>(grid[0].size() + 1, INT_MAX));
        paths[0][1] = 0;
        for (int i = 1; i < paths.size(); i++)
        {
            for (int j = 1; j < paths[0].size(); j++)
            {
                paths[i][j] = grid[i - 1][j - 1] + std::min(paths[i - 1][j], paths[i][j - 1]);
            }
        }
        return paths[paths.size() - 1][paths[0].size() - 1];
    }
};