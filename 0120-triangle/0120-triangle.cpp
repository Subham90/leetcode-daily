class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (x == triangle.size() - 1) {
            return triangle[x][y];
        }
        
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        
        int down = triangle[x][y] + solve(x + 1, y, triangle, dp);
        int downRight = triangle[x][y] + solve(x + 1, y + 1, triangle, dp);
        
        return dp[x][y] = min(down, downRight);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // Initialize DP table with the same dimensions as triangle
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return solve(0, 0, triangle, dp);
    }
};
