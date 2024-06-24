class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>>q; // This will store {{i,j},dist}
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        int dx[4]={-1,0,+1,0};
        int dy[4]={0,+1,0,-1};
        while(!q.empty())
        {
            auto it = q.front();
            int x = it.first.first;
            int y = it.first.second;
            int dist = it.second;
            ans[x][y]=dist;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx>=0 and newx<n and newy>=0 and newy<m and !visited[newx][newy])
                {
                    visited[newx][newy] = 1;
                    q.push({{newx,newy},dist+1});
                }
            }
        }
        return ans;
    }
};