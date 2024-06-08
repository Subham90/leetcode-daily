class Solution {
public:
    int solve(int x,int y,vector<vector<int>>&dp)
    {
        if(x==0 and y==0)
        {
            return 1;
        }
        if(x<0 || y<0)
        {
            return 0;
        }
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        
        int up = solve(x-1,y,dp);
        int left = solve(x,y-1,dp);
        
        return dp[x][y] = left+up;
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[0][0] = 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    int up=0,left=0;
                    if(i>=1)
                    up = dp[i-1][j];
                    if(j>=1)
                    left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};