static int __init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
    const int primes[26]{ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101 };
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> result;
        std::unordered_map<unsigned long long, int> map;
        for (std::string str : strs)
        {
            unsigned long long num = 1;
            for (char c : str)
            {
                num *= primes[c - 'a'];
            }
            if (map.count(num) == 1)
            {
                result[map[num]].push_back(str);
            }
            else
            {
                // not exits
                map[num] = result.size();
                result.push_back(*new std::vector<std::string>{ str });
            }
        }
        return result;
    }
};