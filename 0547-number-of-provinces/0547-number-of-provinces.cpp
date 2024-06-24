class Solution {
    private:
    void dfs(int node,vector<int>adj[],vector<int>&visited)
    {
        visited[node] = 1;
        for(auto it: adj[node])
        {
            if(!visited[it])
            {
                dfs(it,adj,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>visited(n,0);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
            ans++;
            dfs(i,adj,visited);
            }
        }
        return ans;
    }
};