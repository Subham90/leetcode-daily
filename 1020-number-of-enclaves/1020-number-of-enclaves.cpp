class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int cnt = 0;
        int fill = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1 and !visited[0][i])
            {
                q.push({0,i});
                visited[0][i]=1;
                fill++;
                
            }
            if(grid[n-1][i]==1 and !visited[n-1][i])
            {
                q.push({n-1,i});
                 visited[n-1][i]=1;
                fill++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 and !visited[i][0])
            {
                q.push({i,0});
                visited[i][0]=1;
                fill++;
            }
            if(grid[i][m-1]==1 and !visited[i][m-1])
            {
                q.push({i,m-1});
                visited[i][m-1]=1;
                fill++;
            }
        }
        int dx[4]={-1,0,+1,0};
        int dy[4]={0,+1,0,-1};

        while(!q.empty())
        {
            auto it = q.front();
            int x = it.first;
            int y = it.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(newx >= 0 and newx<n and newy>=0 and newy<m and !visited[newx][newy] and grid[newx][newy]==1)
                {
                    visited[newx][newy]=1;
                    q.push({newx,newy});
                    fill++;
                }
            }
            
        }
        
        return (cnt-fill);
    }
};