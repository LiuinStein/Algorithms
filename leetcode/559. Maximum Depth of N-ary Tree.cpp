static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
public:
	int maxDepth(Node* root) {
		if (root == nullptr) {
			return 0;
		}
		if (root->children.empty()) {
			return 1;
		}
		int m = INT_MIN;
		for (int i = 0; i < root->children.size(); i++) {
			m = std::max(m, maxDepth(root->children[i]));
		}
		return m + 1;
	}
};
