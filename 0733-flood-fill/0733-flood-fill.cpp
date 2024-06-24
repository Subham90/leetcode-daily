class Solution {
    int dx[4]={-1,0,+1,0};
    int dy[4]={0,+1,0,-1};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>> ans = image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        ans[sr][sc]=color;
        int initialcolor = image[sr][sc];
        while(!q.empty())
        {
            auto it = q.front();
            int row = it.first;
            int col = it.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newrow = row + dx[i];
                int newcol = col + dy[i];
                if(newrow>=0 and newrow<n and newcol>=0 and newcol<m and !visited[newrow][newcol] and !visited[newrow][newcol] and image[newrow][newcol]==initialcolor)
                {
                    visited[newrow][newcol]=1;
                    q.push({newrow,newcol});
                    ans[newrow][newcol]=color;
                }
            }
            
        }
        return ans;
    }
};