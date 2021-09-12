static int ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
	std::unordered_map<int, int> id2pos;

	int calc(std::vector<Employee*>& employees, int id) {
		Employee* current = employees[id2pos[id]];
		int result = current->importance;
		for (int i = 0; i < current->subordinates.size(); i++) {
			result += calc(employees, current->subordinates[i]);
		}
		return result;
	}

public:
	int getImportance(std::vector<Employee*> employees, int id) {
		for (int i = 0; i < employees.size(); i++) {
			id2pos[employees[i]->id] = i;
		}
		return calc(employees, id);
	}
};