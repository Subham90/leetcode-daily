class Solution {
public:
    int solve(vector<int>&nums,int index,int n,vector<int> &dp)
    {
        if(index >= n)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int notTake = 0 + solve(nums,index+1,n,dp);
        int Take = nums[index] + solve(nums,index+2,n,dp);
        
        return dp[index]=max(Take,notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
             int notTake = 0+dp[i-1];
             int Take = nums[i];
             if(i>1)
             Take = nums[i] + dp[i-2];
             
             dp[i] = max(Take,notTake);
        }
        
        return dp[n-1];
    }
};