class Solution {
private:
    bool check(int start,vector<int>&colour,vector<vector<int>>& graph)
    {
        queue<int>q;
        q.push(start);
        colour[start]=0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it: graph[node])
            {
                if(colour[it]==-1)
                {
                    colour[it] = !colour[node];
                    q.push(it);
                }
                else if(colour[it]==colour[node])
                {
                    return 0;
                }
            }
        }
        return 1;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colour(n);
        for(int i=0;i<n;i++)
        {
            colour[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(colour[i]==-1)
            {
                if(check(i,colour,graph)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};