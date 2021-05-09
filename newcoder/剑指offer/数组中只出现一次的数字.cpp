class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < data.size(); i++) {
            map[data[i]] += 1;
        }
        int num[2]{}, cur = 0;
        for (int i = 0; i < data.size(); i++) {
            if (map[data[i]] == 1) {
                num[cur++] = data[i];
            }
        }
        *num1 = num[1];
        *num2 = num[0];
    }
};