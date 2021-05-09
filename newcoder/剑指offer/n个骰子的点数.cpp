// https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
public:
    std::vector<double> dicesProbability(int n) {
        // p(k, x) = p(k-1, x-1)*1/6 + ... + p(k-1, x-6)*1/6
		std::vector<std::vector<double>> p(n + 1, std::vector<double>(6 * n + 1, 0));
		for (int i = 1; i < 7; i++) p[1][i] = 1. / 6.;
		for (int i = 2; i < p.size(); i++) {
			for (int j = i; j < p[i].size(); j++) {
				for (int m = 1; m < 7 && j - m >-1; m++) {
					p[i][j] += 1. / 6.*p[i - 1][j - m];
				}
			}
		}
		std::vector<double> res;
		for (int i = 0; i < p[n].size(); i++) {
			if (p[n][i] > 0) {
				res.push_back(p[n][i]);
			}
		}
		return res;
	}
};