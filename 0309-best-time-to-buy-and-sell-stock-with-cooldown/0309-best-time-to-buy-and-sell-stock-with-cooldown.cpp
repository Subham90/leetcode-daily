class Solution {
public:
    int solve(int index,bool flag,vector<int>&prices,int &n,
             vector<vector<int>>&dp)
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
            int buy = -prices[index] + solve(index+1,1,prices,n,dp);
            int notBuy = solve(index+1,0,prices,n,dp);
            return max(buy,notBuy);
        }
        else
        {
            int sell = prices[index] + solve(index+2,0,prices,n,dp);
            int notSell = solve(index+1,1,prices,n,dp);
            return max(sell,notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int flag=0;flag<=1;flag++)
            {
            if(flag==0)
            {
                int buy = -prices[index] + dp[index+1][1];
                int notBuy = dp[index+1][0];
                dp[index][flag] = max(buy,notBuy);
            }
            else
            {
               int sell = (index+2 < n ? prices[index] + dp[index+2][0] : prices[index]);
                int notSell = dp[index+1][1];
                dp[index][flag] = max(sell,notSell);
            }           
            }
        }
        
        return dp[0][0];
    }
};