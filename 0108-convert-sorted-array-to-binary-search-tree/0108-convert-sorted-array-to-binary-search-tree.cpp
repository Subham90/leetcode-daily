/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
TreeNode* bst(int left,int right,vector<int>&nums)
{
    if(left>right)
        return NULL;
    
    int mid = left+(right-left)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = bst(left,mid-1,nums);
    root->right = bst(mid+1,right,nums);
    
    return root;
}
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        return bst(left,right,nums);
    }
};