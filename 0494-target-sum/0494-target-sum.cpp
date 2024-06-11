class Solution {
public:
    
    int solve(int sum,int index,vector<int>&nums)
    {
        if(index==0)
        {
            if(sum==0 && nums[0]==0)
            {
                return 2;
            }
            if(sum==0 || nums[0]==sum)
            {
                return 1;
            }
            return 0;
        }
        
        int notTake = solve(sum,index-1,nums);
        int take = 0;
        if(sum-nums[index]>=0)
        {
            take = solve(sum-nums[index],index-1,nums);
        }
        
        return  take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(auto it: nums)
        {
            totalSum+=it;
        }
        
        if((totalSum-target)&1 || (totalSum-target)<0)
            return 0;
        int n = nums.size();
        return solve((totalSum-target)/2,n-1,nums);
    }
};