class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O')
            {
                q.push({0,i});
                visited[0][i]=1;
            }
            if(board[n-1][i]=='O')
            {
                q.push({n-1,i});
                 visited[n-1][i]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                q.push({i,0});
                visited[i][0]=1;
            }
            if(board[i][m-1]=='O')
            {
                q.push({i,m-1});
                visited[i][m-1]=1;
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
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx >= 0 and newx < n and newy>=0 and newy<m and !visited[newx][newy] and board[newx][newy]=='O')
                {
                    visited[newx][newy] = 1;
                    q.push({newx,newy});
                }
            }
            
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j] == 1)
                {
                    board[i][j]='O';
                }
                else
                {
                    board[i][j]='X';
                }
            }
        }
    }
};