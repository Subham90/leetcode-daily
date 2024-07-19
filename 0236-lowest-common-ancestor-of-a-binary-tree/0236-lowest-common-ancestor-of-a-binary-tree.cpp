/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           if(root == NULL)
        {
            return NULL;
        }
        
        if(root == p || root == q)
        {
            return root;
        }
        
        TreeNode* left1 = lowestCommonAncestor(root->left,p,q);
        TreeNode* right1 = lowestCommonAncestor(root->right,p,q);
        
        if(left1 and right1)
        {
            return root;
        }
        if(left1==NULL and right1!=NULL)
        {
            return right1;
        }
        if(left1!=NULL and right1==NULL)
        {
            return left1;
        }
        else
        {
            return NULL;
        }
    }
};