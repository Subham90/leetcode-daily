class Solution {
    const int mod = 1e9+7;
public:
    int maxProduct(vector<int>& nums) {
       double ans = INT_MIN;
       double prod = 1;
        for(int i=0;i<nums.size();i++)
        {
            prod*=nums[i];
            ans = max(1LL*ans,prod);
            if(prod == 0)
            {
                prod = 1;
            }
        }
        prod = 1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            prod*=nums[i];
            ans = max(1LL*ans,prod);
            if(prod == 0)
            {
                prod = 1;
            }
        }
        return ans;
    }
};