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
void bst(vector<int>&ans,TreeNode* root,int key)
{
    if(root==NULL)
    {
        return;
    }
    bst(ans,root->left,key);
    if(key!=root->val)
    {
        ans.push_back(root->val);
    }
    bst(ans,root->right,key);
}
private:
TreeNode* buildTree(vector<int>&ans,int left,int right)
{
    if(left>right)
    return NULL;
    
    int mid = (left+right)/2;
    TreeNode* root = new TreeNode(ans[mid]);
    root->left = buildTree(ans,left,mid-1);
    root->right = buildTree(ans,mid+1,right);
    
    return root;
}
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int>ans;
        bst(ans,root,key);
        int left=0;
        int right=ans.size()-1;
        return buildTree(ans,left,right);
        
    }
};