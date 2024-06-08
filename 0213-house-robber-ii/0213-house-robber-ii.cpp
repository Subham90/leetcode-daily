class Solution {
public:
    int solve(int index,vector<int> &nums,int end,vector<int>&dp)
    {
        if(index == end)
        {
            return nums[index];
        }
        if(index < end)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
        int NotTake = 0 + solve(index-1,nums,end,dp);
        int Take = INT_MIN;
        if(index > 1)
        {
            Take = nums[index] + solve(index - 2,nums,end,dp);
        }
        
        return dp[index]=max(Take,NotTake);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int p = solve(n-1,nums,1,dp1);
        int q = INT_MIN;
        if(n>1)
        q = solve(n-2,nums,0,dp2);
        
        return max(p,q);
        
    }
};