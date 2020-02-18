static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        std::vector<std::vector<unsigned long long>> paths(obstacleGrid.size() + 1, std::vector<unsigned long long>(obstacleGrid[0].size() + 1, 0));
        paths[0][1] = 1;
        for (int i = 1; i < paths.size(); i++)
        {
            for (int j = 1; j < paths[0].size(); j++)
            {
                if (!obstacleGrid[i - 1][j - 1])
                {
                    paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                }
            }
        }
        return paths[paths.size() - 1][paths[0].size() - 1];
    }
};