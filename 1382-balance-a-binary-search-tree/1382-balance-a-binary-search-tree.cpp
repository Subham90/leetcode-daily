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
void inorder(TreeNode* root,vector<int>&ds)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,ds);
    ds.push_back(root->val);
    inorder(root->right,ds);
}
TreeNode* bst(vector<int>&ds,int start,int end)
{
        if(start > end)
            return NULL;
       
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(ds[mid]);
        root->left = bst(ds,start,mid-1);
        root->right = bst(ds,mid+1,end);
    
    return root;
}
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ds;
        inorder(root,ds);
        int start=0;
        int end = ds.size()-1;
        return bst(ds,start,end);
         
    }
};