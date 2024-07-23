class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        sort(nums.begin(), nums.end(), [&map](int a, int b) {
        if (map[a] == map[b]) {
        return a > b;
        }
            return map[a] < map[b];
        });

        return nums;
    }
};