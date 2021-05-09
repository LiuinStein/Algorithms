static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int numTrees(int n)
    {
        std::vector<int> result(n + 1, -1);
        result[0] = result[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int sum = 0;
            for (int j = 1; j <= i; j++)
            {
                sum += result[j - 1] * result[i - j];
            }
            result[i] = sum;
        }
        return result[n];
    }
};