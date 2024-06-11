class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> countMap;
        for (const int& num : arr1) {
            countMap[num]++;
        }
        vector<int> ans;
        for (const int& num : arr2) {
            while (countMap[num] > 0) {
                ans.push_back(num);
                countMap[num]--;
            }
        }
        for (const auto& pair : countMap) {
            while (pair.second > 0) {
                ans.push_back(pair.first);
                countMap[pair.first]--;
            }
        }
        return ans;
    }
};
