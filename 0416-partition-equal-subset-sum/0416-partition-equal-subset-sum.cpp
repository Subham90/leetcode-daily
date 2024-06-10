class Solution {
public:
    bool solve(int index,int target,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(target == 0)
        {
            return true;
        }
        if(index == 0)
        {
            if(nums[index] == target)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if(index < 0)
        {
            return false;
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        int NotTake = solve(index-1,target,nums,dp);
        int Take = false;
        if(target-nums[index] >= 0)
        {
            Take = solve(index-1,target-nums[index],nums,dp);
        }
        
        return dp[index][target]=Take|NotTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto &it: nums)
        {
            sum+=it;
        }
        if(sum%2==1)
        {
            return false;
        }
        int target = sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);
    }
};