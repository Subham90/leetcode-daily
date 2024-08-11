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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,0}); // we are following 0 based indexing
        long ans = 1;
        while(!q.empty())
        {
            long len = q.size();
            long left = q.front().second;
            long right = q.back().second;
            ans = max(ans,right-left+1);
            
            for(int i=0;i<len;i++)
            {
               auto it = q.front();
               q.pop();
                if(it.first->left)
                {
                     q.push({it.first->left, (long)2*it.second+1});
                }
                if(it.first->right)
                {
                     q.push({it.first->right, (long)2*it.second+2});
                }
            }
        }
        return ans;
    }
};