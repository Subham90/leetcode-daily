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
        int target = 0;
        int n = nums.size();
        for(auto &it: nums)
        {
            target+=it;
        }
        if(target&1)
        {
            return false;
        }
        target = target/2;
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
        
        for(int i=0;i<n;i++) // BC
        {
            dp[i][0] = true;
        }
        if(nums[0] <= target)
        {
            dp[0][nums[0]] = true; // BC
        }
        
        for(int i=1;i<n;i++)
        {
            for(int tar=0;tar<=target;tar++)
            {
                int NotTake = dp[i-1][tar];
                int Take = false;
                if(tar-nums[i] >= 0)
                {
                    Take = dp[i-1][tar-nums[i]];
                }
                dp[i][tar]=Take||NotTake;
            }
        }
        return dp[n-1][target];
    }
};