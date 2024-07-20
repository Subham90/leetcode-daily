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
    public:
    TreeNode* solve(int pstart,int pend,int istart,int iend,map<int,int>&mp
                   ,vector<int>& preorder, vector<int>& inorder)
    {
        if(pstart > pend || istart > iend)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pstart]);
        int inroot = mp[root->val];
        int numsleft = inroot-istart;
        
        root->left = solve(pstart+1,pstart+numsleft,istart,inroot-1,mp,preorder,inorder);
        root->right = solve(pstart+numsleft+1,pend,inroot+1,iend,mp,preorder,inorder);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode* root =    solve(0,preorder.size()-1,0,inorder.size()-1,mp,preorder,inorder);
        return root;
    }
};