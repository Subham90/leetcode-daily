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
        vector<int>curr(amount+1,0);
        vector<int>prev(amount+1,0);
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
                prev[i] = 1;
            }
        }
        for(int index=1;index<n;index++)
        {
            for(int target=0;target<=amount;target++)
            {
                int notPick = prev[target];
                int pick = 0;
                if(target-coins[index]>=0)
                {
                    pick = curr[target-coins[index]];
                }
                 
             curr[target] = pick + notPick;
            }
            prev = curr;
        }
        return prev[amount];
    }
};