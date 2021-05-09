static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution 
{
public:
	std::string convert(std::string s, int numRows) 
	{
		std::vector<std::string> result(numRows);
		for (int i = 0; i < s.size();)
		{
			for (int j = 0; j < numRows && i < s.size(); j++)
			{
				result[j].push_back(s[i++]);
			}
			for (int j = numRows - 2; j > 0 && i < s.size(); j--)
			{
				result[j].push_back(s[i++]);
			}
		}
		std::string ret;
		for (int i = 0; i < numRows; i++)
		{
			ret += result[i];
		}
		return ret;
	}
};