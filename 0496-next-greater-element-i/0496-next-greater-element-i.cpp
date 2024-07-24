class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n = nums2.size();
        vector<int>ans(n);
        vector<int>v;
        
        map<int,int>mp;
        for(int i=n-1;i>=0;i--)
        {
            mp[nums2[i]]=i;
            while(!st.empty() and nums2[i] >= st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }
            st.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            int num = nums1[i];
            if(mp.find(num)!=mp.end())
            {
                int index = mp[num];
                v.push_back(ans[index]);
            }
        }
        return v;
    }
};