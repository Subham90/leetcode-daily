class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
        if (y < 0 || y >= matrix[0].size()) {
            return 1e8; 
        }
        if (x == 0) {
            return matrix[0][y];
        }
        if (memo[x][y] != -1) {
            return memo[x][y];
        }
        
        int up = matrix[x][y] + solve(x - 1, y, matrix, memo);
        int left = matrix[x][y] + solve(x - 1, y - 1, matrix, memo);
        int right = matrix[x][y] + solve(x - 1, y + 1, matrix, memo);
        
        return memo[x][y] = min(up, min(left, right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0;i<n;i++)
        {
            dp[0][i] = matrix[0][i];
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=0)
                {
                    int up=1e8,left=1e8,right=1e8;
                    if(i>=1)
                    up = matrix[i][j] + dp[i-1][j]; 
                    if(i>=1 && j>=1)
                    left = matrix[i][j] + dp[i - 1][j-1]; 
                    if(i>=1 and j<=n-2)
                    right = matrix[i][j] + dp[i - 1][j + 1];
                    
                    dp[i][j] = min(up,min(left,right));
                }
            }
        }
        int ans = INT_MAX;
        for(int j=0;j<n;j++)
        {
            ans = min(ans,dp[m-1][j]);
        }
        return ans;
       
    }
};
