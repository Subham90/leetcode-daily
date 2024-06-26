class Solution {
    private:
   void solve(int n, vector<vector<int>>& prerequisites, vector<int>&ans) {
        vector<int>adj[n];
        int size = prerequisites.size();
        for(int i=0;i<size;i++)
        {
            auto it = prerequisites[i];
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        int cnt = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        solve(numCourses,prerequisites,ans);
        if(ans.size() == numCourses)
        {
            // reverse(ans.begin(),ans.end());
            return ans;
        }
        else
        {
            return {};
        }
    }
};