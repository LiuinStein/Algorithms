static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	bool checkPerfectNumber(int num) {
		int count = 1;
		for (int i = 2; i <= (int)std::sqrt(num); i++) {
			if (num % i == 0) {
				count += i + int(num / i);
				if (count > num) {
					return false;
				}
			}
		}
		return num != 1 && count == num;
	}
};