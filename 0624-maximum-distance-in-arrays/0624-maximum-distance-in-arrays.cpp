class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int ans = INT_MIN;
        int mx = arr[0].back();
        int mn = arr[0].front();
        for(int i=1;i<arr.size();i++)
        {
            ans = max(ans,max(abs(mn-arr[i].back()),abs(mx-arr[i].front())));
            mx = max(mx,arr[i].back());
            mn = min(mn,arr[i].front());
        }
        return ans;
    }
};