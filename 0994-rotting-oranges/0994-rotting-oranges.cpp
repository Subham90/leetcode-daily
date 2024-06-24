class Solution {
    int dx[4]={-1,0,+1,0};
    int dy[4]={0,+1,0,-1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q; // This Will store {i,j},{time}
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        int cntFresh = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                if(grid[i][j]==1)
                {
                    cntFresh++;
                }
                
            }
        }
        int tym = 0;
        int cntrot = 0;
        while(!q.empty())
        {
            auto it = q.front();
            int row = it.first.first;
            int col = it.first.second;
            int time = it.second;
            tym = max(tym,time);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newrow = row + dx[i];
                int newcol = col + dy[i];
                if(newrow>=0 and newrow<n and newcol>=0 and newcol<m and !visited[newrow][newcol] and grid[newrow][newcol]==1)
                {
                    visited[newrow][newcol] = 2;
                    q.push({{newrow,newcol},time+1});
                    cntrot++;
                }
            }
            
        }
        
        if(cntrot!=cntFresh)
            return -1;
        else
            return tym;
        
    }
};