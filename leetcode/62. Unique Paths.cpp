static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        std::vector<std::vector<unsigned long long>> paths(m + 1, std::vector<unsigned long long>(n + 1, 0));
        paths[0][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // Move down
                paths[i][j] = paths[i][j - 1] + paths[i - 1][j];
            }
        }
        return paths[m][n];
    }
};