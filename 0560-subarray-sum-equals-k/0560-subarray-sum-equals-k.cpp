class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int currSum = 0;
        map<int,int>mp;
        mp[currSum]=1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            currSum+=nums[i];
            int remove = currSum-k;
            ans+=mp[remove];
            mp[currSum]++;
        }
        return ans;
    }
};