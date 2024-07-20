class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        vector<vector<int>>mat(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat[j][n-i-1] = matrix[i][j];
            }
        }
        
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j] = mat[i][j];
            }
        }
    }
};