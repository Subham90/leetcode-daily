class Solution {
public:
    int dx[8] = {-1,1,0,0,-1, 1, -1, 1};
    int dy[8] = {0,0,-1,1, 1, 1, -1, -1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<pair<int,pair<int,int>>>st;
        vector<vector<int>>dist(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dist[i][j] = 1e9;
            }
        }
        if(grid[0][0]!=0)
        {
            return -1;
        }
        dist[0][0] = 1;
        st.insert({1,{0,0}});
        while(!st.empty())
        {
            auto it = *(st.begin());
            int distance = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            st.erase(it);
            for(int i=0;i<8;i++)
            {
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    if(newx>=0 and newx<n and newy>=0 and newy<m and grid[newx][newy]==0)
                    {
                        if(distance + 1 < dist[newx][newy])
                        {
                            dist[newx][newy] = distance + 1;
                            st.insert({dist[newx][newy],{newx,newy}});
                        }
                    }
            }
        }
        if(dist[n-1][m-1]!=1e9)
        return dist[n-1][m-1];
        else
            return -1;
    }
};