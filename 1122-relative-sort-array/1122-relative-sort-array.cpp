class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> countMap;
        
        // Count occurrences of each number in arr1
        for (const int& num : arr1) {
            countMap[num]++;
        }
        
        vector<int> ans;
        
        // Add elements of arr2 in the order they appear in arr2
        for (const int& num : arr2) {
            while (countMap[num] > 0) {
                ans.push_back(num);
                countMap[num]--;
            }
        }
        
        // Add remaining elements not in arr2, in ascending order
        vector<int> remaining;
        for (const auto& pair : countMap) {
            while (pair.second > 0) {
                remaining.push_back(pair.first);
                countMap[pair.first]--;
            }
        }
        sort(remaining.begin(), remaining.end());
        ans.insert(ans.end(), remaining.begin(), remaining.end());
        
        return ans;
    }
};
