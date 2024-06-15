class Solution {
public:
    int solve(int index, int n, int prev_index, vector<int>& nums, vector<vector<int>>& dp) {
        if (index >= n) {
            return 0;
        }
        
        // Since prev_index is used to index into dp, we need to ensure it's non-negative
        if (dp[index][prev_index + 1] != -1) {
            return dp[index][prev_index + 1];
        }
        
        int pick = 0;
        if (prev_index == -1 || nums[index] > nums[prev_index]) {
            pick = 1 + solve(index + 1, n, index, nums, dp);
        }
        int notPick = solve(index + 1, n, prev_index, nums, dp);
        
        return dp[index][prev_index + 1] = max(pick, notPick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, n, -1, nums, dp);
    }
};
