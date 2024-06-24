class Solution {
    int dx[4]={-1,0,+1,0};
    int dy[4]={0,+1,0,-1};
    private:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&visited,int n,int m)
    {
        visited[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty())
        {
            auto it = q.front();
            int x = it.first;
            int y = it.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    if(newx >= 0 and newx < n and newy>=0 and newy<m and !visited[newx][newy] and grid[newx][newy]=='1')
                    {
                        visited[newx][newy] = 1;
                        q.push({newx,newy});
                    }
            }
        }
    }
    public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] and grid[i][j]=='1')
                {
                    cnt++;
                    dfs(i,j,grid,visited,n,m);
                }
            }
        }
        return cnt;
    }
};