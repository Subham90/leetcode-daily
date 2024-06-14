class Solution {
public:
    int solve(int index,vector<int>&prices,bool flag,int n,int k,
             vector<vector<vector<int>>>&dp)
    {
        if(index >=n || k<=0)
        {
            return 0;
        }
        if(dp[index][flag][k]!=-1)
        {
            return dp[index][flag][k];
        }
        
        if(flag==0)
        {
            int buy = -prices[index]+solve(index+1,prices,1,n,k,dp);
            int notbuy = solve(index+1,prices,0,n,k,dp);
            return dp[index][flag][k]=max(buy,notbuy);
        }
        else
        {
            int sell = +prices[index]+solve(index+1,prices,0,n,k-1,dp);
            int notSell = solve(index+1,prices,1,n,k,dp);
            return dp[index][flag][k]=max(sell,notSell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        bool flag=0;     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,prices,flag,n,k,dp);
    }
};