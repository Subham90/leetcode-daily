class Solution {
public:
    int solve(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
       if(x==0 and y==0)
       {
           return grid[x][y];
       }
       if(x<0 || y<0)
       {
           return 0;
       }
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        int up = INT_MAX,left = INT_MAX;
        if(x>0)
        up = grid[x][y] + solve(x-1,y,grid,dp);
        if(y>0)
        left = grid[x][y] + solve(x,y-1,grid,dp);
        
        return dp[x][y] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return solve(m-1,n-1,grid,dp);
    }
};