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
        int n = prices.size();        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
         
         for(int index=n-1;index>=0;index--)
         {
             for(int flag=0;flag<=1;flag++)
             {
                 for(int day=0;day<3;day++)
                 {
                    if(flag == 0)// means we can buy
                    {
                        int buy = -prices[index] + dp[index+1][1][day];
                        int notBuy = dp[index+1][0][day];
                        dp[index][flag][day]=max(buy,notBuy);
                    }
                    else
                    {
                        int sell=-1e8;
                        if(day-1>=0)
                        {
                        sell = +prices[index] + dp[index+1][0][day-1]; 
                        }//denotes a complete transaction 
                        int notSell = dp[index+1][1][day];
                        dp[index][flag][day]=max(sell,notSell);

                    }
                 }
             }
         }
     return dp[0][0][2];                                 
    }
};