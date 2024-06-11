class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>count(1001,0);
        int n = arr1.size();
        for(int i=0;i<n;i++)
        {
            count[arr1[i]]++;
        }
        vector<int>ans;
        for(int j=0;j<arr2.size();j++)
        {
            while(count[arr2[j]] > 0)
            {
                ans.push_back(arr2[j]);
                count[arr2[j]]--;
            }
        }
        
        for(int i=0;i<count.size();i++)
        {
            while(count[i] > 0)
            {
                ans.push_back(i);
                count[i]--;
            }
        }
        return ans;
    }
};