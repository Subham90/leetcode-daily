class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() and nums[i%n] >= st.top())
            {
                st.pop();
            }
            if(st.empty()==1)
            {
                ans[i%n]=-1;
            }
            else
            {
                ans[i%n] = st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};