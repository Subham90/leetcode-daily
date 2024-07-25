class Solution {
    private:
     int largestRectangleArea(vector<int >& heights) {
        int n = heights.size();
        vector<int>prev(n,-1);
        vector<int>next(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and heights[i] <= heights[st.top()])
            {
                st.pop();
            }
            if(!st.empty())
            {
                next[i] = st.top();
            }
            st.push(i);
        }
        stack<int>().swap(st);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and heights[i] <= heights[st.top()])
            {
                st.pop();
            }
            if(!st.empty())
            {
                prev[i] = st.top();
            }
            st.push(i);
        }
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        ans = max(ans,(next[i]-prev[i]-1)*(heights[i]));
    }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>dp(m,0);
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                {
                    dp[j]=0;
                }
                else
                {
                    dp[j]++;
                }
            }
            ans = max(ans,largestRectangleArea(dp));
        }
        return ans;
    }
};