class Solution {
public:
    int solve(int index,bool flag,vector<int>&prices,int day,int &n,
              vector<vector<vector<int>>>&dp)
    {
        //Base Cases
        if(index >= n || day<=0)
        {
            return 0;
        }
        if(dp[index][flag][day]!=-1)
        {
            return dp[index][flag][day];
        }
        if(flag == 0)// means we can buy
        {
            int buy = -prices[index] + solve(index+1,1,prices,day,n,dp);
            int notBuy = solve(index+1,0,prices,day,n,dp);
            return  dp[index][flag][day]=max(buy,notBuy);
        }
        else
        {
            int sell = +prices[index] + solve(index+1,0,prices,day-1,n,dp);               //denotes a complete transaction 
            int notSell = solve(index+1,1,prices,day,n,dp);
            return  dp[index][flag][day]=max(sell,notSell);
          
        }
    }
    int maxProfit(vector<int>& prices) {
        int day = 2;
        int n = prices.size();
        bool flag=0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,flag,prices,day,n,dp);
    }
};