class Solution {
public:
    int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int ans = 1e8;
        for(int index=i;index<=j;index++)
        {
            int cost = cuts[j+1] - cuts[i-1] + solve(i,index-1,cuts,dp)+    solve(index+1,j,cuts,dp);
            ans = min(ans,cost);
        }
        
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return solve(1,m,cuts,dp);
    }
};