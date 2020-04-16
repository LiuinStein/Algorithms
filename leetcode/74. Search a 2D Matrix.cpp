static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) 
        {
            return false;
        }
		int lo = 0, hi = matrix.size(), mid = 0;
		while (lo < hi)
		{
			mid  = (lo + hi) >> 1;
			if (matrix[mid][0] == target)
			{
				return true;
			}
			if (matrix[mid][0] < target)
			{
				if (mid + 1 >= matrix.size() || matrix[mid + 1][0] > target) 
				{
					break;
				}
				lo = mid + 1;
			}
			else 
			{
				hi = mid;
			}
		}
		if (mid < 0 || mid >= matrix.size() || matrix[mid][0] > target) 
		{
			return false;
		}
		std::vector<int> &row = matrix[mid];
		lo = 0;
		hi = row.size();
		while (lo < hi)
		{
			mid = (lo + hi) >> 1;
			if (row[mid] == target)
			{
				return true;
			}
			if (row[mid] < target)
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid;
			}
		}
		return false;
	}
};