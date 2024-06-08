class Solution {
public:
    int solve(int x,int y,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp)
    {
        if(x==0 and y==0)
        {
            return 1;
        }
        if(x<0 || y<0 || obstacleGrid[x][y]==1)
        {
            return 0;
        }
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        int up=0,left=0;
        if(x>=1 && obstacleGrid[x-1][y]==0)
        {
            up = solve(x-1,y,obstacleGrid,dp);
        }
        if(y>=1 && obstacleGrid[x][y-1]==0)
        {
            left = solve(x,y-1,obstacleGrid,dp);
        }
        return dp[x][y]=up+left;
    }
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        if(obstacleGrid[0][0] == 1)
        return 0;
    
        return solve(m-1,n-1,obstacleGrid,dp);
    }
};