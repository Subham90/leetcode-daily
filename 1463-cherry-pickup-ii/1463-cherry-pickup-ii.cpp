class Solution {
public:
    int solve(int x, int y1, int y2, int m, vector<vector<int>>& matrix,
             vector<vector<vector<int>>>&dp)
    {
        if (y1 < 0 || y2 < 0 || y1 >= m || y2 >= m) {
            return -1e8; 
        }
        if (x == matrix.size() - 1) {
            if (y1 == y2) {
                return matrix[x][y1];
            } else {
                return matrix[x][y1] + matrix[x][y2];
            }
        }
        if(dp[x][y1][y2]!=-1)
        {
            return dp[x][y1][y2];
        }

        int maxi = INT_MIN;
        for (int dx1 = -1; dx1 <= 1; dx1++) {
            for (int dx2 = -1; dx2 <= 1; dx2++) {
                int newY1 = y1 + dx1;
                int newY2 = y2 + dx2;
                
                int value = 0;
                if (y1 == y2) {
                    value = matrix[x][y1];
                } else {
                    value = matrix[x][y1] + matrix[x][y2];
                }
                value += solve(x + 1, newY1, newY2, m, matrix,dp);
                maxi = max(maxi, value);
            }
        }
        
        return dp[x][y1][y2]=maxi;
    }

    int cherryPickup(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
             vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0, 0, m - 1, m, matrix,dp);
    }
};
