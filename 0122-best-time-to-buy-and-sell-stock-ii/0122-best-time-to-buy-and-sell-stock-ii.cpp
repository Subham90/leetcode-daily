class Solution {
public:
    int solve(int index,bool flag,vector<int>&prices,int n,vector<vector<int>>&dp)
    {
        if(index >= n)
        {
            return 0;
        }
        if(dp[index][flag]!=-1)
        {
            return dp[index][flag];
        }
        
        if(flag==0)
        {
            int buy = -prices[index]+solve(index+1,1,prices,n,dp);
            int notbuy = solve(index+1,0,prices,n,dp);
            return dp[index][flag] = max(buy,notbuy);
        }
        else
        {
            int sell = +prices[index]+solve(index+1,0,prices,n,dp);
            int notSell = 0+solve(index+1,1,prices,n,dp);
            return dp[index][flag]=max(sell,notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        bool flag=0;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,flag,prices,n,dp);
    }
};