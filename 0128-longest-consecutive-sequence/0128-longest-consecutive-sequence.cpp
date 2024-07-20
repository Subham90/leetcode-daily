class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int lastsmaller = INT_MIN;
        int ans = 1;
        int cnt = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]-1 == lastsmaller)
            {
                cnt++;
                lastsmaller = nums[i];
            }
            else if(nums[i]==lastsmaller)
            {
                continue;
            }
            else if(nums[i]!=lastsmaller)
            {
                cnt = 1;
                lastsmaller = nums[i];
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};