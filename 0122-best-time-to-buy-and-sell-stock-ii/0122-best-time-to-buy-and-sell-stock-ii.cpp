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
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        for(int index=n-1;index>=0;index--)
        {
            for(int flag=0;flag<2;flag++)
            {
                if(flag==0)
                {
                    int buy = -prices[index]+dp[index+1][1];
                    int notbuy = dp[index+1][0];
                    dp[index][flag] = max(buy,notbuy);
                }
                else
                {
                    int sell = +prices[index]+dp[index+1][0];
                    int notSell = 0+dp[index+1][1];
                    dp[index][flag] = max(sell,notSell);
                }
            }
        }
        return dp[0][0];
    }
};