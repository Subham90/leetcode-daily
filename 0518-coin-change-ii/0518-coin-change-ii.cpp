class Solution {
public:
    int solve(int index,int target,vector<int>&coins,
             vector<vector<int>>&dp)
    {
        if(index == 0)
        {
            if(target%coins[0]==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(target == 0)
        {
            return 1;
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        int notPick = solve(index-1,target,coins,dp);
        int pick = 0;
        if(target-coins[index]>=0)
        {
            pick = solve(index,target-coins[index],coins,dp);
        }
        
        return dp[index][target] = pick+notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};