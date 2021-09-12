static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {

	void swap(TreeNode* left, TreeNode* right) {
		int dummy = left->val;
		left->val = right->val;
		right->val = dummy;
	}

	void lmr(TreeNode* root, std::vector<TreeNode*>& table) {
		if (root) {
			lmr(root->left, table);
			table.push_back(root);
			lmr(root->right, table);
		}
	}

public:
	void recoverTree(TreeNode* root) {
		std::vector<TreeNode*> table;
		lmr(root, table);
		int test[2]{};
		int pos = 0;
		for (int i = 0; i < table.size() - 1; i++) {
			if (table[i]->val > table[i + 1]->val) {
				test[pos++] = i;
			}
		}
		if (pos > 1) {
			swap(table[test[0]], table[test[1] + 1]);
		}
		else if (pos == 1) {
			swap(table[test[0]], table[test[0] + 1]);
		}
		return;
	}
};