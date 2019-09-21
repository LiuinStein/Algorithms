static int __init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int line = matrix.size();
        int col = -1;
        if (line == 0 || (col = matrix[0].size()) == 0)
        {
            return;
        }
        std::vector<std::vector<int>> rotated(col, *new std::vector<int>(line));
        for (int i = 0; i < col; ++i)
        {
            for (int j = line - 1; j >= 0; --j)
            {
                rotated[i][line - j - 1] = matrix[j][i];
            }
        }
        matrix = rotated;
    }
};