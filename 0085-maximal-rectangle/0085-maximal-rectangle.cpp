class Solution {
public:
    int largestRectangleArea(vector<int>&heights) {
        int n = heights.size();
        vector<int>prev(n);
        vector<int>next(n);
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                prev[i] = -1;
            }
            else
            {
                prev[i] = st.top();
            }
            
            st.push(i);
        }
        
        st=stack<int>();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                next[i] = n;
            }
            else
            {
                next[i] = st.top();
            }
            
            st.push(i);
        }
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int mx = (next[i] - prev[i] - 1)*heights[i];
            ans = max(ans,mx);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>dp(m,0);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                    if(matrix[i][j]=='0')
                    dp[j] = 0;
                    else
                    dp[j]++;
            }
            int p = largestRectangleArea(dp);
            ans = max(ans,p);
        }
        return ans;
    }
};