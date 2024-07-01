class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int dx[4]={-1,0,+1,0};
        int dy[4]={0,+1,0,-1};
        int ans = INT_MAX;
        while(!pq.empty())
        {
            auto it = pq.top();
            int diff = it.first;
            int x = it.second.first;
            int y = it.second.second;
            pq.pop();
            if(x==n-1 and y==m-1)
            {
                ans = min(ans,diff);
            }
            for(int i=0;i<4;i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx>=0 and newx<n and newy>=0 and newy<m)
                {
                    int neweffort = max(diff,abs(heights[x][y]-heights[newx][newy]));
                    if(neweffort < dist[newx][newy])
                    {
                        dist[newx][newy] = neweffort;
                        pq.push({neweffort,{newx,newy}});
                    }
                }
            }
        }
        return ans;
    }
};