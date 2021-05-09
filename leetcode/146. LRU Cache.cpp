static int _____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

struct Cache {
	int value, times;

	Cache() {

	}

	Cache(int v, int t) {
		value = v, times = t;
	}
};

class LRUCache {
	std::unordered_map<int, Cache> kv;
	int capacity, time = 0;
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (kv.find(key) == kv.end()) {
			return -1;
		}
		kv[key].times = time += 1;
		return kv[key].value;
	}

	void put(int key, int value) {
		if (kv.size() < capacity || kv.find(key) != kv.end()) {
			kv[key] = Cache(value, time += 1);
			return;
		}
		int min = INT_MAX, remove = 0;
		for (auto i = kv.begin(); i != kv.end(); i++) {
			if (i->second.times < min) {
				min = i->second.times;
				remove = i->first;
			}
		}
		kv.erase(remove);
		kv[key] = Cache(value, time += 1);
	}
};