static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
	std::vector<int> split(std::string &ver)
	{
		std::vector<int> result;
		int dummy = 0;
		for (int i = 0; i < ver.size(); i++)
		{
			if (ver[i] == '.')
			{
				result.push_back(std::atoi(ver.substr(dummy, i - dummy).c_str()));
				dummy = i + 1;
			}
		}
		result.push_back(std::atoi(ver.substr(dummy).c_str()));
		return result;
	}

	int compare(std::vector<int> &v1, std::vector<int> &v2)
	{
		if (v1.size() > v2.size())
		{
			int res = compare(v2, v1);
			return res == 1 ? -1 : (res == 0 ? 0 : 1);
		}
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i] > v2[i])
			{
				return 1;
			}
			else if (v1[i] < v2[i])
			{
				return -1;
			}
		}
		for (int i = v1.size(); i < v2.size(); i++) 
		{
			if (v2[i] != 0)
			{
				return -1;
			}
		}
		return 0;
	}
public:
	int compareVersion(string version1, string version2) {
		std::vector<int> v1 = split(version1), v2 = split(version2);
		return compare(v1, v2);
	}
};