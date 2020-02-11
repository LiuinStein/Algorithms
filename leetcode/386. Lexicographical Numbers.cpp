static int _____ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution
{
    void lexicalOrder(std::vector<int> &result, int base, int n)
    {
        if (base > n)
        {
            return;
        }
        result.push_back(base);
        for (int i = 0; i < 10; i++)
        {
            lexicalOrder(result, base * 10 + i, n);
        }
    }

public:
    std::vector<int> lexicalOrder(int n)
    {
        std::vector<int> result;
        result.reserve(n);
        for (int i = 1; i < 10; i++)
        {
            lexicalOrder(result, i, n);
        }
        return result;
    }
};