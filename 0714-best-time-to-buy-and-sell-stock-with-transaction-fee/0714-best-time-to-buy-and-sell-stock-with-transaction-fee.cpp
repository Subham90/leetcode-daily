class Solution {
public:
    int solve(int index,vector<int>&prices,int &fee,int n,bool flag
             ,vector<vector<int>>&dp)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index][flag]!=-1)
        {
            return dp[index][flag];
        }
        if(flag==0)
        {
            int buy = -prices[index] + solve(index+1,prices,fee,n,1,dp);
            int notBuy = solve(index+1,prices,fee,n,0,dp);
            return dp[index][flag]=max(buy,notBuy);
        }
        else
        {
            int sell = (prices[index]-fee)+ solve(index+1,prices,fee,n,0,dp);
            int Notsell = solve(index+1,prices,fee,n,1,dp);
            return dp[index][flag]=max(sell,Notsell);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        bool flag = 0;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,prices,fee,n,flag,dp);
    }
};