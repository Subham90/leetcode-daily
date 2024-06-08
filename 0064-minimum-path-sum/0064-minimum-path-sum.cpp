class Solution {
public:
    int solve(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&dp) // Top-down Solution 
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
    
    // Initialize the previous row with size n (number of columns)
    vector<int> prev(n, 0);

    for (int i = 0; i < m; ++i) {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) {
                curr[j] = grid[i][j];
            } else {
                int up = INT_MAX, left = INT_MAX;
                if (i > 0) {
                    up = grid[i][j] + prev[j]; // Previous row's jth column
                }
                if (j > 0) {
                    left = grid[i][j] + curr[j - 1]; // Current row's (j-1)th column
                }
                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    return prev[n - 1]; // Last element in the last row
}
};