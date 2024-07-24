class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int suffix[n];
        suffix[n-1] = height[n-1];
        int prefix=INT_MIN;
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            prefix = max(prefix,height[i]);
            ans+=min(prefix,suffix[i]) - height[i];
        }
        return ans;
    }
};