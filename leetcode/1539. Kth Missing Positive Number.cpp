static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
public:
	int findKthPositive(std::vector<int>& arr, int k) {
		for (int i = 1, p = 0; i < 2048; i++) {
			if (p >= arr.size() || i != arr[p])
			{
				if (--k == 0) {
					return i;
				}
			}
			else if (i == arr[p]) {
				p++;
			}
		}
		return 0;
	}
};